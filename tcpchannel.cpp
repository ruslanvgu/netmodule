#include "tcpchannel.h"

TcpChannel::TcpChannel(std::string ip, uint32_t port, uint32_t queueQuery):
    _ip(ip),
    _port(port),
    _queueQuery(queueQuery)
{

    int socket_connect = socket(AF_INET, SOCK_STREAM, 0 );

    struct sockaddr_in client_addr;
    struct sockaddr_in addr;

    addr.sin_family =  AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = inet_addr(_ip.c_str());
    //addr.sin_addr.s_addr = htonl(INADDR_ANY);
    /*in_addr ip_to_num; //преобразование ip в нужный формат
    int errorTransformation = inet_pton(AF_INET, _ip.c_str(), &ip_to_num);
    if(errorTransformation != 0)
    {
        std::cout <<"error inet_pton: "<< errno <<std::endl;
        //std::cout << "Error in IP translation to special numeric format" << std::endl;
        return;
    }
    addr.sin_addr = ip_to_num;*/

    int errorBind = bind(socket_connect,(struct sockaddr*) &addr, sizeof (addr) );
    if(errorBind < 0){
        std::cout <<"error bind: "<< errno << std::endl;
        return;
    }

    int listen_status = listen(socket_connect, queueQuery);
    if(listen_status < 0){
        std::cout <<"error listen: "<< errno <<" status "<<listen_status<< std::endl;
        return;
    }

    socklen_t cs_addrsize = sizeof (client_addr);
    int new_sock = accept(socket_connect, (struct sockaddr *) &client_addr, &cs_addrsize);//слушающий сокет и структура клиента
    if(new_sock < 0){
        std::cout << "error accept: "<< errno << std::endl;
        //return;
    }

    char buffer[256];
    while(1)
    {
        int len = recv(new_sock, buffer, sizeof(buffer), 0);
        std::cout << buffer<<std::endl;
#ifdef DEGUG
        std::cout << new_sock<<inet_ntoa(client_addr.sin_addr)<<client_addr.sin_port;
#endif
        _connections.push_back( {new_sock,inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port)} );
    }
}
