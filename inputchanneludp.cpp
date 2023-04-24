#include "inputchanneludp.h"

InputChannelUdp::InputChannelUdp(std::string ip , uint32_t port, const void* output):
    UdpChannel(ip, port, output)
{


}
