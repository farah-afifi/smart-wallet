#include "userRepository.h"
#include <mutex>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <sstream>
unsigned long long quickhash64(const char *str, unsigned long long mix = 0)
{ // set 'mix' to some value other than zero if you want a tagged hash          
    const unsigned long long mulp = 2654435789;
    mix ^= 104395301;
    while(*str)
        mix += (*str++ * mulp) ^ (mix >> 23);

    return mix ^ (mix << 37);
}
static int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
User userRepository::getUser(int ID , string password){
    string query;
    sqlite3* db;
    sqlite3_stmt*        stmt;
    int                  row = 0;
    int                  bytes;
    const unsigned char* text;

    if (sqlite3_open ("smartWallet.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database.\n");
        return User();
    }
   string sql = "select name, nationl_id from users where id =";
   ostringstream oss;
   oss << sql << ID << " AND PasswordHash = '" << password <<"';";
   query = oss.str();

   printf("Query: %s\n", query.c_str());
   int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, 0);

   if(rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
      return User();
   }
   rc = sqlite3_step(stmt);

   string name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0 )));
   string nationalID = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1 )));

   fprintf(stderr, "\n");
   sqlite3_finalize(stmt);

   return User(ID, name, nationalID);
}
int userRepository::InsertUser(string name, string nationalID, string password){
    mutex mtx;
    mtx.lock();
//------------------------------------------
   sqlite3 *database;
   char *ErrMsg = 0;
   string query;

   /* Open database */
      int ret = sqlite3_open("smartWallet.db", &database);
   
   if( ret ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(database));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   query = "INSERT INTO users(name, nationl_id, PasswordHash) VALUES ('"+ name +"', '"+ nationalID+"','"+password+"');";


   int id;
   /* Execute SQL statement */
   ret = sqlite3_exec(database, query.c_str(), callback,0, &ErrMsg);
   
   if( ret != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", ErrMsg);
      sqlite3_free(ErrMsg);
   } else {
      id  = sqlite3_last_insert_rowid(database);
      fprintf(stdout, "Record with ID %d has been created successfully\n",id);
   }
   sqlite3_close(database);

//------------------------------------------
   mtx.unlock();
   return id;

}