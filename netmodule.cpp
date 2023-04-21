#include "netmodule.h"


NetModule::NetModule()

{
    InputChannelUdp* udp = new InputChannelUdp("127.0.0.1",12345);


}
