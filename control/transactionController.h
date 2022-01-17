#include <iostream>
#include <vector>
#include "model/transaction.h"

using namespace std;
class TransactionController{

public:
    void makeTransaction(int ID, string type, long Amount);
    void getTransactions(int ID);
};