#include "connectionStream.h"

TCPStreamInfo* ConnectionStream::getStream( char *argv[]) {
    TCPConnector *connector = new TCPConnector();
    ConnectionStream:: stream = connector->connect(argv[2], atoi(argv[1]));
    return stream;
}
TCPStreamInfo* ConnectionStream::getStream(){
    return ConnectionStream::stream;
}

ConnectionStream:: ~ConnectionStream (){
    delete ConnectionStream::stream;
}