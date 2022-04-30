#include "threadgamepair.h"
#include <QTcpSocket>

ThreadGamePair::ThreadGamePair(qintptr firstGamerSocketDescriptor,
    qintptr secondGamerSocketDescriptor, int gameId)
    : m_firstGamerSocketDescriptor{firstGamerSocketDescriptor},
    m_secondGamerSocketDescriptor{secondGamerSocketDescriptor},
    m_gameId{gameId}
{
    m_firstGamerSocket = new QTcpSocket();
    m_firstGamerSocket->setSocketDescriptor(m_firstGamerSocketDescriptor);

    m_secondGamerSocket = new QTcpSocket();
    m_secondGamerSocket->setSocketDescriptor(m_secondGamerSocketDescriptor);

}

void ThreadGamePair::run()
{
    qDebug() << "ThreadGamePair::run()";
    qDebug() << "ThreadGamePair::m_firstGamerSocket = " << m_firstGamerSocket << " : descriptor = " << m_firstGamerSocketDescriptor;
    qDebug() << "ThreadGamePair::m_secondGamerSocket = " << m_secondGamerSocket << " : descriptor = " << m_secondGamerSocketDescriptor;
}
