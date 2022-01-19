#include "transactionsRepository.h"
#include <mutex>
#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string>
#include <sstream>

vector<Transaction> TransactionRepository:: getTransactions(int ID){
string query;
    sqlite3* db;
    sqlite3_stmt* stmt;

    if (sqlite3_open ("smartWallet.db", &db) != SQLITE_OK) {
        fprintf(stderr, "Error opening database.\n");
        return {};
    }
    string sql = "select transaction_type, money_amount, date_time from transactions where user_ID =";
    ostringstream oss;
    oss << sql << ID << ";";
    query = oss.str();

    //printf("Query: %s\n", query.c_str());
    int rc = sqlite3_prepare(db, query.c_str(), -1, &stmt, 0);

    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return {};
    }
    rc = sqlite3_step(stmt);

    long amount;
    string dateTime;
    string transactionType;
    vector<Transaction> transactions;
    while(rc == SQLITE_ROW)
    {
        transactionType = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0 )));
        amount = sqlite3_column_int64(stmt,1);
        dateTime = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt,2 )));
        
        cout << transactionType <<' ' << amount << ' ' << dateTime << endl;
        transactions.push_back(Transaction(ID,transactionType,amount,dateTime));
        rc = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);

   return transactions;
}
int  TransactionRepository:: InsertTransaction(int ID, string type, long Amount){
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
   query = "INSERT INTO transactions VALUES (";
   ostringstream oss;
   oss << query << ID << ", " << Amount <<",'" <<type <<"',CURRENT_TIMESTAMP);";
   query = oss.str();

   /* Execute SQL statement */
   ret = sqlite3_exec(database, query.c_str(), 0,0, &ErrMsg);
   
   if( ret != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", ErrMsg);
      sqlite3_free(ErrMsg);
      return -1;
   }
    sqlite3_close(database);
    mtx.unlock();
    return 1;

}