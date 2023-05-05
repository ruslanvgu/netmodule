#ifndef UDPCHANNEL_H
#define UDPCHANNEL_H

#include "headers.h"

//#define DEBUG

struct message{
    size_t _count;
    std::string _byteArray;
    size_t _size;

    message(): _count(0),_size(0)
    {}
    void setData(char* byteArray, size_t size){
        if(_count == std::numeric_limits<size_t>::max())
            _count = 0;
        else
            _count++;
        _byteArray.clear();
        _byteArray.append(byteArray,size) ;
        _size = size;
    }

};

class UdpChannel
{
public:
    UdpChannel(std::string ip, uint32_t port);
protected:
    message _msg;
    int _socket_connect;
    struct sockaddr_in addr;
private:
};

#endif // UDPCHANNEL_H
