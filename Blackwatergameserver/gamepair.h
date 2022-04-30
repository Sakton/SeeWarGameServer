#ifndef GAMEPAIR_H
#define GAMEPAIR_H
#include <QThread>

class QTcpSocket;
class Gamer;

class GamePair : public QThread
{
    Q_OBJECT
public:
    GamePair( qintptr firstGamerSocketDescriptor, qintptr secondGamerSocketDescriptor,  int gameId, QObject *parent = nullptr );
    ~GamePair();

public slots:
    void onReadyReadFirstGamer();
    void onReadyReadSecondGamer();
    void onDisconnectedFirstGamer();
    void onDisconnectedSecondGamer();

    // QThread interface
protected:
    void run() override;

private:
    qintptr m_firstGamerSocketDescriptor;
    qintptr m_secondGamerSocketDescriptor;
    Gamer *m_firstGamer;
    Gamer *m_secondGamer;
    int m_gameId;
};

#endif // GAMEPAIR_H
