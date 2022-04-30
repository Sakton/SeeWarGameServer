#include "gamer.h"

Gamer::Gamer(qintptr descriptor, int number, QObject *parent)
    : QTcpSocket(parent),  m_descriptor{descriptor}, m_poryadkovyiNumber{number}
{
    setSocketDescriptor(m_descriptor);
}

int Gamer::poryadkovyiNumber() const
{
    return m_poryadkovyiNumber;
}
