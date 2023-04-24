#include <QCoreApplication>
#include "netmodule.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    NetModule server;

    return a.exec();
}
