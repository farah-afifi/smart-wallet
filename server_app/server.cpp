
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "tcpConnections/tcpacceptor.h"
#include "control/walletController.h"
#include "control/transactionController.h"
#include "control/userController.h"

void login(TCPStreamInfo* stream); //wrapper for user controller
void signUp(TCPStreamInfo* stream); //wrapper for user controller
void getInfo(TCPStreamInfo* stream); //wrapper for all controllers
void deposit(TCPStreamInfo* stream);
void withdraw(TCPStreamInfo* stream);

int main(int argc, char** argv)
{
if (argc < 2 || argc > 4) {
        printf("usage: server <port> [<ip>]\n");
        exit(1);
    }

    TCPStreamInfo* stream = NULL;
    TCPAcceptor* acceptor = NULL;
    if (argc == 3) {
        acceptor = new TCPAcceptor(atoi(argv[1]), argv[2]);
    }
    else {
        acceptor = new TCPAcceptor(atoi(argv[1]));
    }
    if (acceptor->start() == 0) {
        
        while (1) {
            stream = acceptor->accept();
            if (stream != NULL) {
                ssize_t len;
                char line[50];

                if((len = stream->receive(line, 50)) > 0) {
                    line[len] = 0;
                    printf("server received - %s\n", line);
                    if(strncmp(line,"login command",13) == 0 ){
                        login(stream);
                    }
                    else if(strcmp(line,"sign up command") == 0){
                        signUp(stream);
                    }
                    else if(strcmp(line,"get info command") == 0){
                        getInfo(stream);
                    }
                    else if(strcmp(line,"deposit command") == 0){
                        deposit(stream);
                    }
                    else if(strcmp(line,"withdraw command") == 0){
                        withdraw(stream);
                    }
                    
                    //stream->send("I recieved what you said",50);
                }
                delete stream;
            }
        }
    }
    
}
void login(TCPStreamInfo* stream){ //wrapper for user controller
    UserController userControl;
    userControl.logIn(stream);
}
void signUp(TCPStreamInfo* stream){ //wrapper for user controller
    UserController userControl;
    userControl.signUp(stream);
}
void getInfo(TCPStreamInfo* stream){ //wrapper for all controllers
    char ID[50];
    stream->receive(ID, 50);

    UserController userControl;
    userControl.getUserInfo(stream,atoi(ID));

    WalletController walletcontrol;
    walletcontrol.getMoneyAmount(stream, atoi(ID));

    TransactionController transactionControl;
    transactionControl.getTransactions( stream, atoi(ID));
}
void deposit(TCPStreamInfo* stream){
    char ID[50];
    char Amount[500];
    stream->receive(ID, 50);
    stream->receive(Amount, 50);

    WalletController walletControl;
    walletControl.deposit(atol(Amount), atoi(ID));
}
void withdraw(TCPStreamInfo* stream){
    char ID[50];
    char Amount[500];
    stream->receive(ID, 50);
    stream->receive(Amount, 50);

    WalletController walletControl;
    walletControl.withdraw(atol(Amount), atoi(ID));

}