#include "userController.h"
#include "repositoriesDB/userRepository.h"
int UserController::getID(){
    return user.getID();
}

string UserController::getName(){
    return user.getName();
}

string UserController::getNationalID(){
    return user.getNationalID();
}
void  UserController::logIn(string nationalID, string password){
    UserController::user = userRepository().getUser(nationalID, password);
    if(user.getID() == 0)
        cout <<"your password or natoinal ID is incorrect!\n";
    else {
        cout << "logged in successfully!\n";
        //todo view of this user
        //will call wallet view of said user with ID gotten
    }
}
void  UserController::signUp(string name, string nationalID, string password){
    if(name == "" || nationalID == "" || password == "" ){
        if(name == "")
            cout << "please enter your name!\n";
        if( nationalID == "")
            cout << "Please enter your national ID!\n";
        if(password == "")
            cout << "Password cant be empty!\n";
    }
    else{
        int id = userRepository().InsertUser(name, nationalID, password);
        if(id == -1){
            cout << "this national ID has been used before!\nYou can login directly using you national ID\n";
        }
        else{
            //todo view of this user
            //will call wallet view of said user with ID gotten
            cout <<"signed up successfully\n";
            user = User(id,name, nationalID);
        }
    }
}