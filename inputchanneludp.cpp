#include "inputchanneludp.h"

InputChannelUdp::InputChannelUdp(std::string ip , uint32_t port):
    UdpChannel(ip, port)
{

}

std::string& InputChannelUdp::receiveBytes()
{

    int errorBind = bind(_socket_connect, (struct sockaddr*)&addr, sizeof (addr));
    if  (errorBind < 0){
        std::cout <<"error bind: "<< errno << std::endl;

    }

    char buffer[1024];
    struct sockaddr_in client;
    int len = sizeof(client);
    ssize_t bytes_received  = recvfrom(_socket_connect, (char*)buffer, sizeof(buffer), MSG_WAITALL,
                                       (struct sockaddr *)&client, reinterpret_cast<socklen_t *>(&len));
    if(bytes_received < 0 )
    {
        std::cout << "byte_received error: "<< errno <<std::endl;
    }

    _msg.setData(buffer, bytes_received);

#ifdef DEBUG
    std::cout <<" Received message: " << buffer
              <<" IP Address : "<<inet_ntoa(client.sin_addr)
              <<" Port Number : "<<ntohs(client.sin_port)<<  std::endl;
#endif

    return _msg._byteArray;
}

void InputChannelUdp::closeConnection()
{
    close(_socket_connect);
}


