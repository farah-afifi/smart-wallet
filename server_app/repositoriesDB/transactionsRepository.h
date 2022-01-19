#include <iostream>
#include <vector>
#include "model/transaction.h"
using namespace std;

class TransactionRepository{
public :
    static vector<Transaction> getTransactions(int ID);
    static int InsertTransaction(int ID, string type, long Amount);
};