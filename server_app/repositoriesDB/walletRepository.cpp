#include "walletRepository.h"
#include <mutex>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <sstream>
long WalletRepository::getMoneyAmount(int ID){
    mutex mtx;
    mtx.lock();
//------------------------------------------
    string query;
    sqlite3* db;
    sqlite3_stmt*        stmt;

    if (sqlite3_open ("smartWallet.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database.\n");
        return -1;
    }
   string sql = "select money_amount from wallet where user_ID = ";
   ostringstream oss;
   oss << sql << ID <<";";
   query = oss.str();

   int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, 0);

   if(rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
      return -1;
   }
   rc = sqlite3_step(stmt);
   if(sqlite3_column_type(stmt,0) == SQLITE_NULL)
      return -1;

   long amountOfMoney = sqlite3_column_int(stmt,0 );

   fprintf(stderr, "\n");
   sqlite3_finalize(stmt);
   sqlite3_close(db);

//------------------------------------------
   mtx.unlock();   
   return amountOfMoney ;
}
int WalletRepository::changeMoneyAmount(int ID, long newMoneyAmount){
    mutex mtx;
    mtx.lock();
    //------------------------------------------
    string query;
    sqlite3* db;
    sqlite3_stmt* stmt;

    if (sqlite3_open ("smartWallet.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database.\n");
        return -1;
    }
    string sql = "UPDATE wallet SET money_amount = ";
    ostringstream oss;
    oss << sql << newMoneyAmount << " WHERE user_ID = " << ID <<";" ;
    query = oss.str();

    int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, 0);

    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    rc = sqlite3_step(stmt);

    fprintf(stderr, "\n");
    sqlite3_finalize(stmt);

    //------------------------------------------
    mtx.unlock();   
    return 1;
}