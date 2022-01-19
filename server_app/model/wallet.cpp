#include "wallet.h"
    
Wallet::Wallet(string ID, long Amount){
    IDofItsOwner = ID;
    moneyAmount = Amount;
}
long Wallet::getMoneyAmount(){
    return moneyAmount;
}
void Wallet::deposit(long amount){
    moneyAmount += amount;
}
void Wallet::withdraw(long amount){
    moneyAmount -= amount;
}