#include "userRepository.h"
#include <mutex>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <sstream>
User userRepository::getUserUsingID(int ID){
   mutex mtx;
   mtx.lock();
//------------------------------------------
    string query;
    sqlite3* db;
    sqlite3_stmt*        stmt;

   int ret = sqlite3_open("smartWallet.db", &db);
   
   if( ret ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return User();
   } 
   string sql = "select name, nationl_id from users where ID =";
   ostringstream oss;
   oss << sql << ID <<";";
   query = oss.str();

   int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, 0);

   if(rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
      return User();
   }
   rc = sqlite3_step(stmt);
   if(sqlite3_column_type(stmt,0) == SQLITE_NULL)
      return User();

   string name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0 )));
   string nationalID = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1 )));

   fprintf(stderr, "\n");
   sqlite3_finalize(stmt);
   sqlite3_close(db);

//------------------------------------------
   mtx.unlock();   
   return User(ID, name, nationalID);
}
User userRepository::getUserUsingNationalIDAndPassword(char* nationalID , char*  password){
   mutex mtx;
   mtx.lock();
//------------------------------------------
    string query;
    sqlite3* db;
    sqlite3_stmt*        stmt;

   int ret = sqlite3_open("smartWallet.db", &db);
   
   if( ret ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return User();
   } 
   string sql = "select name, ID from users where nationl_id = '";
   ostringstream oss;
   oss << sql << nationalID << "' AND PasswordHash = '" << password <<"';";
   query = oss.str();

   int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, 0);

   if(rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
      return User();
   }
   rc = sqlite3_step(stmt);
   if(sqlite3_column_type(stmt,0) == SQLITE_NULL)
      return User();

   string name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0 )));
   int ID = sqlite3_column_int(stmt,1 );

   fprintf(stderr, "\n");
   sqlite3_finalize(stmt);
   sqlite3_close(db);

//------------------------------------------
   mtx.unlock();   
   return User(ID, name, nationalID);
}
int userRepository::InsertUser(char* name, char* nationalID, char* password){
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
      return(-1);
   } 

   /* Create SQL statement */

   string sql = "INSERT INTO users(name, nationl_id, PasswordHash) VALUES ('";
   ostringstream oss;
   oss << sql << name << "', '" << nationalID <<"','" <<password <<"');";
   query = oss.str();
   int id;
   /* Execute SQL statement */
   ret = sqlite3_exec(database, query.c_str(), 0,0, &ErrMsg);
   
   if( ret != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", ErrMsg);
      sqlite3_free(ErrMsg);
      return -1;
   } else {
      id  = sqlite3_last_insert_rowid(database);
      string query2 = "INSERT INTO wallet VALUES (";//must insert into wallet first
      ostringstream oss;
      oss << query2 << id <<  ", 0 );";
      query2 = oss.str();
      ret = sqlite3_exec(database, query2.c_str(), 0,0, &ErrMsg);
   
      if( ret != SQLITE_OK ){
         fprintf(stderr, "SQL error inserting wallet: %s\n", ErrMsg);
         sqlite3_free(ErrMsg);
         return -1;
      }
   }
   sqlite3_close(database);

//------------------------------------------
   mtx.unlock();
   return id;

}