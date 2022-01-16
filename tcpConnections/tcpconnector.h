

#ifndef __tcpconnector_h__
#define __tcpconnector_h__

#include <netinet/in.h>
#include "tcpstream.h"

class TCPConnector
{
  public:
    TCPStreamInfo* connect(const char* server, int port);
        
  private:
    int resolveHostName(const char* host, struct in_addr* addr);
};

#endif
