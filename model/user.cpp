#include "user.h"

int User::getID(){
    return ID;
}
string User::getName(){
    return name;
}
string User::getNationalID(){
    return nationalID;
}
User::User(int id, string Name, string NationalID ) : ID(id),name(Name),nationalID(NationalID){}