#include "gamepair.h"
#include "gamer.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include "Config.h"

GamePair::GamePair(qintptr firstGamerSocketDescriptor, qintptr secondGamerSocketDescriptor, int gameId, QObject *parent)
    : QThread(parent),
    m_firstGamerSocketDescriptor{firstGamerSocketDescriptor},
    m_secondGamerSocketDescriptor{secondGamerSocketDescriptor},
    m_gameId{gameId}
{
}

GamePair::~GamePair()
{
    m_firstGamer->deleteLater();
    m_secondGamer->deleteLater();
}

void GamePair::onReadyReadFirstGamer()
{
    QByteArray mes = m_firstGamer->readAll();
    m_secondGamer->write(mes);
}

void GamePair::onReadyReadSecondGamer()
{
    QByteArray mes = m_secondGamer->readAll();
    m_firstGamer->write(mes);
}

void GamePair::onDisconnectedFirstGamer()
{

}

void GamePair::onDisconnectedSecondGamer()
{

}

void GamePair::run()
{
    m_firstGamer = new Gamer(m_firstGamerSocketDescriptor, 0);
    //FIXME - Qt::DirectConnection - обязательно, чтоб работало в потоке
    connect(m_firstGamer, &Gamer::readyRead, this, &GamePair::onReadyReadFirstGamer, Qt::DirectConnection);
    m_secondGamer = new Gamer(m_secondGamerSocketDescriptor, 1);
    connect(m_secondGamer, &Gamer::readyRead, this, &GamePair::onReadyReadSecondGamer, Qt::DirectConnection);
    //Json отправляем Id игры

//    QJsonObject startObject;
//    startObject.insert( ConfigServer::Id_Game, m_gameId );
//    QJsonDocument doc;
//    doc.setObject(startObject);
//    QByteArray a{ doc.toJson() };
//    m_firstGamer->write(doc.toJson());
//    m_secondGamer->write(doc.toJson());

    //FIXME - запуск цикла обработки событий в отдельном потоке
    exec();
}
