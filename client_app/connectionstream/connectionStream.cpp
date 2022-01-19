#include "connectionStream.h"

TCPStreamInfo* ConnectionStream::getStream( char *argV[]) {
    TCPConnector *connector = new TCPConnector();
    ConnectionStream:: argv = argV;
    connStream = connector->connect(argV[2], atoi(argV[1]));
    return connStream;
}
TCPStreamInfo* ConnectionStream::getStream(){
    TCPConnector *connector = new TCPConnector();
    connStream = connector->connect(argv[2], atoi(argv[1]));
    return connStream;
}

ConnectionStream:: ~ConnectionStream (){
    delete connStream;
}
char** ConnectionStream::argv =  new char*;

