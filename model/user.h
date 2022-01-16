#include <iostream>
#include <vector>

using namespace std;
class User{
    int ID;
    string name;
    string nationalID;


public:
    User(int id, string Name, string NationalID );
    User(){};
    int getID();
    string getName();
    string getNationalID();
};