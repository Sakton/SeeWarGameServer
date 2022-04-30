#ifndef GAMER_H
#define GAMER_H
#include <QTcpSocket>

class Gamer : public QTcpSocket
{
public:
    Gamer(qintptr descriptor, int number, QObject *parent = nullptr);
    int poryadkovyiNumber() const;

private:
    qintptr m_descriptor;
    int m_poryadkovyiNumber;
};

#endif // GAMER_H
