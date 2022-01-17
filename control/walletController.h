#include <iostream>
#include "model/wallet.h"

using namespace std;

class WalletController{

public: 
    long getMoneyAmount(int ID);
    void  deposit(long amount, int ID);
    void withdraw(long amount, int ID);
};