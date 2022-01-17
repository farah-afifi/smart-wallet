#include "transactionController.h"
#include "repositoriesDB/transactionsRepository.h"

void TransactionController::makeTransaction(int ID, string type, long Amount){
    int status = TransactionRepository().InsertTransaction(ID, type, Amount);
    if(status != -1)
        cout << "transaction Added successfully\n";
    else
        cout << "error occured!\n";

}
void TransactionController::getTransactions(int ID){
    vector<Transaction> transactions;
    transactions = TransactionRepository().getTransactions(ID);
    if(transactions.size() != 0)
        cout <<"transctions fetched!\n";
    else
        cout <<"error occured\n";
}
