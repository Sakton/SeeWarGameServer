#include "mygameserver.h"
#include <QDebug>
#include <QTcpServer>
#include <QByteArray>
#include <QDataStream>
#include <QTcpSocket>
#include <QRegExp>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextCodec>
#include "Config.h"
#include <QThreadPool>
#include "threadgamepair.h"

quint64 MyGameServer::gameId{0};

MyGameServer::MyGameServer(int countThreads, QObject *parent)
    : QTcpServer{parent}, m_threads{countThreads}, m_rrcounter{0}
{
    threadPool = new QThreadPool(this);
    qDebug() << "Server";
    if(!listen(QHostAddress::Any, ConfigServer::PORT))
        qDebug() << "Error: " << errorString();
    qDebug() << "Server OK";
}

void MyGameServer::incomingConnection(qintptr handle)
{
    qDebug() << "incomingConnection();";
    qDebug() << "handle" << handle;
    clients.enqueue(handle);
    for(auto el : clients){
        qDebug() << el;
    }
    if(clients.count() >= 2) {
        qDebug() << "paraStart";
        ThreadGamePair *para = new ThreadGamePair(clients.dequeue(), clients.dequeue(), gameId++);
        threadPool->start(para);
    }
}

void MyGameServer::createPairsGamers()
{
    qDebug() << "createPairsGamers()";
}

//void MyGameServer::initThreads()
//{

//}
