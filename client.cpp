#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "tcpConnections/tcpconnector.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    int len;
    string message;
    char line[256];
    TCPConnector *connector = new TCPConnector();
    TCPStreamInfo *stream = connector->connect(argv[2], atoi(argv[1]));

    
    if (stream)
    {
        cout <<"what's your name;)\n";
        string name;
        getline(cin, name);
    
        len = stream->receive(line, sizeof(line));
        printf("client received - %s\n", line);
        while ( message != "-1")
        {

            getline(cin, message);
            stream->send(message.c_str(), message.size());
            len = stream->receive(line, sizeof(line));
            line[len] = 0;
            printf("client received - %s\n", line);
        }
        delete stream;

    }

    exit(0);
}
