#include "walletController.h"
#include "transactionController.h"
#include "repositoriesDB/walletRepository.h"

long WalletController::getMoneyAmount(int ID)
{
    //ID;
    long amount = WalletRepository().getMoneyAmount(ID);
    if (amount != -1)
        cout << "you have " << amount << " in your account\n";
    else
        cout << "error";
    return amount;
}
void WalletController::deposit(long amount, int ID)
{
    //todo: talk to db to update amount
    long curAmount = WalletRepository().getMoneyAmount(ID);
    if (WalletRepository().changeMoneyAmount(ID, curAmount + amount) != -1)
    {
        cout << "money deposit succeeded\nyou now have " << amount + curAmount
             << " in your wallet\n";
        TransactionController().makeTransaction(ID, "Deposit", amount);
    }
    else
        cout << "error";
}
void WalletController::withdraw(long amount, int ID)
{
    //todo: tlak to db to update amouunt
    long curAmount = WalletRepository().getMoneyAmount(ID);
    if (curAmount - amount < 0)
    {
        cout << "you cant withdraw more than you have!\n";
        return;
    }
    if (WalletRepository().changeMoneyAmount(ID, curAmount - amount) != -1)
    {
        cout << "money withdrawal succeeded\nyou now have " << curAmount - amount
             << " in your wallet\n";
        TransactionController().makeTransaction(ID, "Withdraw", amount);
    }
    else
        cout << "error";
}