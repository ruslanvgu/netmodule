#ifndef TCPCHANNEL_H
#define TCPCHANNEL_H

#include "headers.h"


#define DEGUG

class Client{
    int _socket;
    std::string _ip;
    uint32_t _port;
public:
    Client(int socket, std::string ip, uint32_t port ):
        _socket(socket),
        _ip(ip),
        _port(port)

    {}
};

class TcpChannel
{
public:
    TcpChannel(std::string ip, uint32_t port, uint32_t queueQuery);
private:
    uint32_t _port;
    std::string _ip;
    uint32_t _queueQuery;
    std::list<Client> _connections;
};

#endif // TCPCHANNEL_H
