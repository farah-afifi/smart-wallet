#include "transaction.h"   
Transaction::Transaction(int ID, string type, long Amount, string dateTime)
{
    userID = ID;
    moneyAmount = Amount;
    transactionType = type;
    dateTimeOfTransaction = dateTime;
}
