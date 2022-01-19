#include <iostream>
#include <vector>
#include "model/transaction.h"
#include "tcpConnections/tcpstream.h"

using namespace std;
class TransactionController{

public:
    void makeTransaction(int ID, string type, long Amount);
    void getTransactions(TCPStreamInfo* stream,int ID);
};