#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include <headers.h>

class Channel{
    uint32_t _id;
    uint32_t _protocol;
    std::string _ip;
    uint32_t _port;
    bool _status;
public:
    Channel(uint32_t id,uint32_t protocol,std::string ip,uint32_t port,bool status):
        _id(id),_protocol(protocol),_ip(ip),_port(port),_status(status)
    {}
};

class Connections
{

    std::map<uint32_t, Channel> table;
public:
    Connections();

};

#endif // CONNECTIONS_H
