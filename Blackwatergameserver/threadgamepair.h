#ifndef THREADGAMEPAIR_H
#define THREADGAMEPAIR_H
#include <QRunnable>

class QTcpSocket;

class ThreadGamePair : public QRunnable
{
public:

    ThreadGamePair(qintptr firstGamerSocketDescriptor,
        qintptr secondGamerSocketDescriptor, int gameId);

    // QRunnable interface
public:
    void run() override;

private:
    qintptr m_firstGamerSocketDescriptor;
    qintptr m_secondGamerSocketDescriptor;
    QTcpSocket *m_firstGamerSocket;
    QTcpSocket *m_secondGamerSocket;
    int m_gameId;


};

#endif // THREADGAMEPAIR_H
