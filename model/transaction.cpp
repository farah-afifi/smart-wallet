#include "transaction.h"   
Transaction:: Transaction(string descr, long Amount, int type){
    transactionDescription = descr;
    amount = Amount;
    if(type == 0)
        transactionType = withdraw;
    else    transactionType = deposit; 
}
