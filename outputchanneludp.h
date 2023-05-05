#ifndef OUTPUTCHANNELUDP_H
#define OUTPUTCHANNELUDP_H
#include <udpchannel.h>

class OutputChannelUdp : public UdpChannel
{
public:
    OutputChannelUdp(std::string ip, uint32_t port);
    size_t sendByte(const std::string& byteArray );
    void closeConnection();
};

#endif // OUTPUTCHANNELUDP_H
