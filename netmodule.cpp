#include "netmodule.h"


NetModule::NetModule()

{
    char *output = (char*)malloc(1000);
    InputChannelUdp* udp = new InputChannelUdp("127.0.0.1",12345,output);


}
