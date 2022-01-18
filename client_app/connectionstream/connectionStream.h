#ifndef CONNECTION_STREAM_H
#define CONNECTION_STREAM_H

#include <string>
#include "../../tcpConnections/tcpconnector.h"
#include "../../tcpConnections/tcpstream.h"

class ConnectionStream{
    static TCPStreamInfo* stream;

public :
    ConnectionStream(){}
    ~ConnectionStream();

    TCPStreamInfo* getStream(char *argv[]);
    TCPStreamInfo* getStream();
};

#endif