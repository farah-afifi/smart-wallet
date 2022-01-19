#ifndef CONNECTION_STREAM_H
#define CONNECTION_STREAM_H

#include <string>
#include <vector>
#include "../../server_app/tcpConnections/tcpconnector.h"
#include "../../server_app/tcpConnections/tcpstream.h"

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