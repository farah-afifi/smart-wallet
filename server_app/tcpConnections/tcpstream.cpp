

#include <arpa/inet.h>
#include<iostream>
#include "tcpstream.h"

TCPStreamInfo::TCPStreamInfo(int sd, struct sockaddr_in* address) : m_sd(sd) {
    char ip[50];
    inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr), ip, sizeof(ip)-1);
    m_peerIP = ip;
    m_peerPort = ntohs(address->sin_port);
}

TCPStreamInfo::~TCPStreamInfo()
{
    close(m_sd);
}

ssize_t TCPStreamInfo::send(const char* buffer, size_t len) 
{
    return write(m_sd, buffer, len);
}

ssize_t TCPStreamInfo::receive(char* buffer, size_t len) 
{
    return read(m_sd, buffer, len);

}

string TCPStreamInfo::getPeerIP() 
{
    return m_peerIP;
}

int TCPStreamInfo::getPeerPort() 
{
    return m_peerPort;
}
