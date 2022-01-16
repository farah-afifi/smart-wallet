#include <iostream>
#include "model/wallet.h"

using namespace std;

class WalletController{
    Wallet userWallet;

public: 
    long getMoneyAmount(string ID);
    void  deposit(long amount, string ID);
    void withdraw(long amount, string ID);
};