#include <iostream>
#include "model/user.h"
using namespace std;

class userRepository{
public :
    static User getUser(string nationalID, string password);
    static int InsertUser(string name, string nationalID, string password);
};