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
void  UserController::logIn(TCPStreamInfo* stream){
    char nationalID[50]; 
    char password[50];
    stream->receive(nationalID, 50);
    stream->receive(password, 50);
    UserController::user = userRepository().getUserUsingNationalIDAndPassword(nationalID, password);
    if(user.getID() == 0){
        cout <<"your password or natoinal ID is incorrect!\n";
        stream->send("ERROR", 10);
    }
    else {
        cout << "logged in successfully!\n";
        stream->send("SUCCESS", 10);
        stream->send(to_string(user.getID()).c_str(), 50);
    }
}
void  UserController::signUp(TCPStreamInfo* stream){    
    char name[50];     
    char nationalID[50]; 
    char password[50];
    stream->receive(name, 50);
    stream->receive(nationalID, 50);
    stream->receive(password, 50);

    int id = userRepository().InsertUser(name, nationalID, password);
    if(id == -1){
        stream->send("ERROR", 10);
    }
    else{
        //todo view of this user
        //will call wallet view of said user with ID gotten
        stream->send("SUCCESS", 10);
        cout <<"signed up successfully\n";
        user = User(id,name, nationalID);
    }
    
}
void  UserController::getUserInfo(TCPStreamInfo* stream, int ID){ 
    UserController::user = userRepository().getUserUsingID(ID);
     if(user.getID() == 0){
        //your password or natoinal ID is incorrect!
        stream->send("ERROR", 10);
    }
    else {
        cout << "server: successful retrieval of info!\n";
        stream->send("SUCCESS", 10);
        stream->send(user.getName().c_str(), 50);
        stream->send(user.getNationalID().c_str(), 50);
    }
}   
