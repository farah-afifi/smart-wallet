#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <vector>
#include "transaction.h"
using namespace std;

class Wallet
{
private:
    string IDofItsOwner;
    long moneyAmount;

    Wallet(string ID, long Amount);

public: 
    long getMoneyAmount();
    void  deposit(long amount);
    void withdraw(long amount);
};
#endif