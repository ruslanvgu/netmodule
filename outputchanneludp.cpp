#include "outputchanneludp.h"

OutputChannelUdp::OutputChannelUdp(std::string ip , uint32_t port):
    UdpChannel(ip,port)
{

}

size_t OutputChannelUdp::sendByte(const std::string& byteArray)
{
     size_t result = sendto(_socket_connect, byteArray.c_str(), byteArray.length(), 0, (struct sockaddr*)&addr, sizeof(addr));
     if(result == 0)
     {
         std::cout  << "Failed to send message" << std::endl;
         return result;
     }
     return  result;
}

void OutputChannelUdp::closeConnection()
{
    close( _socket_connect);
}
