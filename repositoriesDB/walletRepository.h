#include <model/wallet.h>
#include <iostream>

using namespace std;

class WalletRepository{
public:
    long getMoneyAmount(int ID);
    long changeMoneyAmount(long newMoneyAmount);
};