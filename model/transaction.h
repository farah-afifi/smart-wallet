#include <iostream>
#include <chrono>
using namespace std;

class Transaction{
private:
    string transactionDescription;
    long amount;
    enum TransactionType{ withdraw, deposit};
    TransactionType transactionType;

public:
    Transaction(string descr, long Amount, int type);
};