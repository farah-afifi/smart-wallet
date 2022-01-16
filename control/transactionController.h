#include <iostream>
#include <vector>
#include "model/transaction.h"

using namespace std;
class TransactionController{
private:
    vector<Transaction> Transactions;
    string ID;
public:
    void makeTransaction(string descr, long amount, int typeOfTransaction);
    vector<Transaction> getTransactions(string ID);
};