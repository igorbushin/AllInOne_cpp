#include "chatclientmodel.h"

ChatClientModel::ChatClientModel(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &ChatClientModel::socketReadyRead);
    connect(socket, &QTcpSocket::connected, this, &ChatClientModel::socketConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ChatClientModel::socketDisconnected);
}

void ChatClientModel::tryConnect(const QString &name, const QString &address, int port)
{
    this->name = name;
    socket->connectToHost(address, static_cast<quint16>(port));
}

void ChatClientModel::sendMessage(const QString &message)
{
    socket->write(QString(message + "\n").toUtf8());
}

void ChatClientModel::disconnect()
{
    socket->disconnectFromHost();
}

void ChatClientModel::socketReadyRead()
{
    while(socket->canReadLine()) {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        QRegExp messageRegex("^([^:]*):(.*)$");// "username:The message"
        QRegExp usersRegex("^/users:(.*)$");
        if(usersRegex.indexIn(line) != -1) {
            QStringList usersList = usersRegex.cap(1).split(",");
            emit usersListChanged(usersList);
        }
        else if(messageRegex.indexIn(line) != -1) {
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);
            emit recivedMessage(user, message);
        }
    }
}

void ChatClientModel::socketConnected()
{
    emit connected(true);
    socket->write(QString("/me:" + name + "\n").toUtf8());
}

void ChatClientModel::socketDisconnected()
{
    emit connected(false);
}
