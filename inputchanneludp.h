#ifndef INPUTCHANNELUDP_H
#define INPUTCHANNELUDP_H
#include <udpchannel.h>

class InputChannelUdp : public UdpChannel
{
public:
    InputChannelUdp(std::string ip, uint32_t port, const void* output);
};

#endif // INPUTCHANNELUDP_H
