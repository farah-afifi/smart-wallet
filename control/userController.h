
#include <iostream>
#include "model/user.h"
#include "tcpConnections/tcpstream.h"

using namespace std;

class UserController{
    User user;

public:
    int getID();
    string getName();
    string getNationalID();
    void  logIn(TCPStreamInfo* stream);
    void  signUp(TCPStreamInfo* stream);
    void getUserInfo(TCPStreamInfo* stream, int ID);
};