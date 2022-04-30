#include "manythreadgamesrver.h"
#include "Config.h"

int ManyThreadGameSrver::m_gameId{0};

ManyThreadGameSrver::ManyThreadGameSrver()
{
    if(!listen(QHostAddress::Any, ConfigServer::PORT))
        qDebug() << "Error server";
    qDebug() << "ManyThreadGameSrver OK";
}

void ManyThreadGameSrver::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection handle = " << handle;
    clients.enqueue(handle);
    while(clients.count() >= 2) {
        GamePair *pair = new GamePair(clients.dequeue(), clients.dequeue(), m_gameId++, this);
        games[m_gameId] = pair;
        pair->start();
    }
}
