#ifndef CONNECTIONS_H
#define CONNECTIONS_H

#include "headers.h"

class Connection
{
    uint32_t id;
    int _socket;
    std::string _ip;
    uint32_t _port;
    std::string type;

public:
    Connections();
};

class Connections
{
public:
    Connections();

private:
    std::unordered_map<int,Connection> table;
};

#endif // CONNECTIONS_H
