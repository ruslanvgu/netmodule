#ifndef NETMODULE_H
#define NETMODULE_H


#include "inputchanneludp.h"

class NetModule
{
public:
    NetModule();
    void createUdp(std::string ip, uint32_t port);

private:

};

#endif // NETMODULE_H
