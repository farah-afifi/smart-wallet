#include "transactionController.h"

void TransactionController::makeTransaction(string descr, long amount, int typeOfTransaction){
    //talk to DB (add transaction with id to db)
    Transactions.push_back(Transaction(descr,amount,typeOfTransaction));
}
vector<Transaction> TransactionController::getTransactions(string ID){
    //talk to db and get all transactiosn using ID
    return {};
}
