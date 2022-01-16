
#include <stdio.h>
#include <stdlib.h>
#include "tcpConnections/tcpacceptor.h"
#include "control/userController.h"
int main(int argc, char** argv)
{
    UserController uc = UserController();
    uc.signUp("farah", "nanana1", "fdsa");
    uc.logIn("nanaa","fdsa");
    // userRepository ur ;
    // int id = ur.InsertUser("name", "nationalID34", "password");
    // ur.getUser(id,"password");

    /*if (argc < 2 || argc > 4) {
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
                char line[256];
                stream->send("Hey! do you already have an account??",150);

                while ((len = stream->receive(line, sizeof(line))) > 0) {
                    line[len] = 0;
                    printf("server received - %s\n", line);
                    stream->send("I recieved what you said",50);
                }
                delete stream;
            }
        }
    }*/
    
}

