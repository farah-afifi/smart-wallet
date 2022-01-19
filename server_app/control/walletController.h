#include <iostream>
#include "model/wallet.h"
#include "tcpConnections/tcpstream.h"

using namespace std;

class WalletController{

public: 
    void getMoneyAmount(TCPStreamInfo* stream,int ID);
    void  deposit(long amount, int ID);
    void withdraw(long amount, int ID);
};