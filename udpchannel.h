#ifndef UDPCHANNEL_H
#define UDPCHANNEL_H

#include "headers.h"

#define DEBUG

class UdpChannel
{
public:
    UdpChannel(std::string ip, uint32_t port);
private:
    int socket_connect;
};

#endif // UDPCHANNEL_H
