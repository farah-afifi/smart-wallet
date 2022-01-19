#ifndef CONNECTION_STREAM_H
#define CONNECTION_STREAM_H

#include <string>
#include <vector>
#include "../../tcpConnections/tcpconnector.h"
#include "../../tcpConnections/tcpstream.h"

class ConnectionStream{

public :
    TCPStreamInfo* connStream;
    static char ** argv;
    ConnectionStream(){}
    ~ConnectionStream();

    TCPStreamInfo* getStream(char *argv[]);
    TCPStreamInfo* getStream();
};
#endif