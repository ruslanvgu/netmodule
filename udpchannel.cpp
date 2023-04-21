#include "udpchannel.h"

UdpChannel::UdpChannel(std::string ip, uint32_t port)
{

    socket_connect = socket(AF_INET, SOCK_DGRAM ,0);
    if(socket_connect < 0){
        std::cout << "Error make socket" <<std::endl;
    }

    struct sockaddr_in addr_local;
    memset(&addr_local, 0, sizeof(addr_local));
    addr_local.sin_family = AF_INET;
    addr_local.sin_addr.s_addr = inet_addr(ip.c_str());
    addr_local.sin_port = htons(port);
   /* if (inet_aton(ip.c_str(), &addr_local.sin_addr) == 0) {
      std::cerr << "Ошибка при конвертации IP-адреса" << std::endl;
      return ;
    }*/

    int errorBind = bind(socket_connect, (struct sockaddr*)&addr_local, sizeof (addr_local));
    if  (errorBind < 0){
        std::cout <<"error bind: "<< errno << std::endl;
        return;
    }

    char buffer[1024];
    struct sockaddr_in client;

    while(true)
    {
        int len = sizeof(client);
        ssize_t bytes_received  = recvfrom(socket_connect,(char*)buffer,sizeof(buffer),MSG_WAITALL,
                                       (struct sockaddr *)&client, reinterpret_cast<socklen_t *>(&len));
        if(bytes_received < 0 )
            std::cout << "byte_received error: "<<errno <<std::endl;
        std::string message(buffer, bytes_received);

#ifdef DEBUG
        std::cout << "Received message: " << buffer <<" IP Address :"<<inet_ntoa(client.sin_addr)<<" Port Number :"<<ntohs(client.sin_port)<<  std::endl;
#endif
    }





}


