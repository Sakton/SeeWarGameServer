#ifndef MYGAMESERVER_H
#define MYGAMESERVER_H
#include <QTcpServer>
#include <QQueue>
#include "Config.h"


class QThread;
class Worker;
class QThreadPool;

class MyGameServer : public QTcpServer
{
    Q_OBJECT
public:
    MyGameServer(int countTreads = ConfigServer::COUNT_THREADS, QObject *parent = nullptr);

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;

private:
    void createPairsGamers();


private:
    static quint64 gameId;
    //Для 1 соединени
    QQueue<qintptr> clients;
    //
    QVector<QThread*> m_threads;
    quint16 m_countTreads;
    quint16 m_rrcounter;

    //***
    QThreadPool *threadPool;

};

#endif // MYGAMESERVER_H
