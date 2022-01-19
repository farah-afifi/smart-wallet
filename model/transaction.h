#ifndef Transaction_H
#define Transaction_H

#include <iostream>
using namespace std;

class Transaction{
private:
    int userID;
    string transactionType;
    long moneyAmount;
    string dateTimeOfTransaction;

public:
    Transaction(int ID, string type, long Amount, string dateTime);
    string getType();
    long getAmount();
    string getDate();
};
#endif