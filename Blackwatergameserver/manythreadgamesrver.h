#ifndef MANYTHREADGAMESRVER_H
#define MANYTHREADGAMESRVER_H
#include <QTcpServer>
#include <QQueue>
#include "gamepair.h"

class QThread;
class GamePair;

class ManyThreadGameSrver : public QTcpServer
{
    Q_OBJECT
public:
    ManyThreadGameSrver();

    // QTcpServer interface
    protected:
    void incomingConnection(qintptr handle) override;

private:

    QHash<quint64, GamePair*> games;
    QQueue <quintptr> clients;
    static int m_gameId;
};

#endif // MANYTHREADGAMESRVER_H
