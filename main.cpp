#include <QCoreApplication>
#include "inputchanneludp.h"
#include "outputchanneludp.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    OutputChannelUdp channel2("127.0.0.1",12345);
    while(true)
    {
        std::string str;
        std::cout <<"input string " <<std::endl;
        std::cin >> str;
        size_t size = channel2.sendByte(str);
        if(size)
        {
            std::cout <<" send "<<size << std::endl;
        }

//        std::string msg1 = channel1.receiveBytes();
//        if(!msg1.empty())
//        {
//            std::cout <<" m1: "<< msg1 <<" size: "<<msg1.size() << std::endl;
//        }

    }

    return a.exec();
}
