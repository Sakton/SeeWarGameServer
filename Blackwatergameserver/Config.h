#ifndef CONFIG_H
#define CONFIG_H
#include <QString>

namespace ConfigServer {

constexpr int PORT = 50080;
constexpr int COUNT_THREADS = 10;

//имена полей для JSON
enum TypeJsonMessage {
    START_JSON = 0,
    FIRE_JSON,
    ANSWER_FIRE_JSON,
    MESSAGE_JSON
};

const QString Name_User = "nameUser";
const QString Id_Game = "idGame";
const QString Fire_To_Cell = "fireCell";
const QString Message = "message";
const QString State_Game = "stateGame";

} //namespace ConfigUdpServer

#endif // CONFIG_H
