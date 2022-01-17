#include <model/wallet.h>
#include <iostream>

using namespace std;

class WalletRepository{
public:
    static long getMoneyAmount(int ID);
    static int changeMoneyAmount(int ID, long newMoneyAmount);
};