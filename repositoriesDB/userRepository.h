#include <iostream>
#include "model/user.h"
using namespace std;

class userRepository{
public :
    User getUser(int ID, string password);
    int InsertUser(string name, string nationalID, string password);
};