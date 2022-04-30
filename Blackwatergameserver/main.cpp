#include <QCoreApplication>
//#include "mygameserver.h"
#include "manythreadgamesrver.h"
#include "Config.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //MyGameServer s;
    ManyThreadGameSrver server;
    return a.exec();
}
