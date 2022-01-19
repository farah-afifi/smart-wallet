#include <iostream>
#include "model/user.h"
using namespace std;

class userRepository{
public :
    static User getUserUsingNationalIDAndPassword(char*  nationalID, char*  password);
    static User getUserUsingID(int ID);
    static int InsertUser(char* name, char* nationalID, char* password);
};