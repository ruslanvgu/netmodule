#include "udpchannel.h"

UdpChannel::UdpChannel(std::string ip, uint32_t port)
{
    // init
    _socket_connect = socket(AF_INET, SOCK_DGRAM ,0);
    if(_socket_connect < 0){
        std::cout << "Error make socket" <<std::endl;
    }

   // struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(port);



}


