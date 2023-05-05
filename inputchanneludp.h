#ifndef INPUTCHANNELUDP_H
#define INPUTCHANNELUDP_H
#include <udpchannel.h>

class InputChannelUdp : public UdpChannel
{
public:
    InputChannelUdp(std::string ip, uint32_t port);
    std::string& receiveBytes();
    void closeConnection();
};

#endif // INPUTCHANNELUDP_H
