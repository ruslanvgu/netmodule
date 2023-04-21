#ifndef INPUTCHANNELUDP_H
#define INPUTCHANNELUDP_H
#include <udpchannel.h>

class InputChannelUdp : public UdpChannel
{
public:
    InputChannelUdp(std::string ip, uint32_t port);
};

#endif // INPUTCHANNELUDP_H
