#include "netmodule.h"


NetModule::NetModule()

{



}

void NetModule::createUdp(std::string ip, uint32_t port)
{

    InputChannelUdp* udp = new InputChannelUdp(ip,port);

}


