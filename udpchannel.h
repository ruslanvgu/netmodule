#ifndef UDPCHANNEL_H
#define UDPCHANNEL_H

#include "headers.h"

#define DEBUG

class UdpChannel
{
public:
    UdpChannel(std::string ip, uint32_t port, const void * output);
private:
    int socket_connect;
    const void* _output;
};

#endif // UDPCHANNEL_H
