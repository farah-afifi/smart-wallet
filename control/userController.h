
#include <iostream>
#include "model/user.h"

using namespace std;

class UserController{
    User user;

public:
    int getID();
    string getName();
    string getNationalID();
    void  logIn(string nationalID, string password);
    void  signUp(string name, string nationalID, string password);
};