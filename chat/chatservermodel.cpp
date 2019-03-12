#include "chatservermodel.h"

ChatServerModel::ChatServerModel(QObject *parent) : QTcpServer(parent)
{
}

bool ChatServerModel::run(int port)
{
    bool success = listen(QHostAddress::Any, static_cast<quint16>(port));
    emit somethingHappened(success ? "Run" : "Could not listen port " + QString(port));
    return success;
}

void ChatServerModel::kill()
{
    foreach(QTcpSocket *client, clients){
        client->close();
    }
    close();
}

void ChatServerModel::incomingConnection(int socketfd)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);
    emit somethingHappened("New client from:" + client->peerAddress().toString());
    connect(client, &QTcpSocket::readyRead, this, &ChatServerModel::socketReadyRead);
    connect(client, &QTcpSocket::disconnected, this, &ChatServerModel::socketDisconnected);
}

void ChatServerModel::socketReadyRead()
{
    QTcpSocket *client = dynamic_cast<QTcpSocket*>(sender());
    while(client->canReadLine())
    {
        QString line = QString::fromUtf8(client->readLine()).trimmed();

        QRegExp meRegex("^/me:(.*)$");
        if(meRegex.indexIn(line) != -1)
        {
            QString user = meRegex.cap(1);
            emit somethingHappened("User:" + user);
            users[client] = user;
            foreach(QTcpSocket *client, clients)
                client->write(QString("Server:" + user + " has joined.\n").toUtf8());
            sendUserList();
        }
        else if(users.contains(client))
        {
            QString message = line;
            QString user = users[client];
            emit somethingHappened("User:" + user + " Message:" + message);
            foreach(QTcpSocket *otherClient, clients)
                otherClient->write(QString(user + ":" + message + "\n").toUtf8());
        }
        else
        {
            emit somethingHappened("Got bad message from client:" + client->peerAddress().toString() + "|" +  line);
        }
    }
}

void ChatServerModel::socketDisconnected()
{
    QTcpSocket *client = dynamic_cast<QTcpSocket*>(sender());
    emit somethingHappened("Client disconnected:" + client->peerAddress().toString());

    clients.remove(client);

    QString user = users[client];
    users.remove(client);

    sendUserList();
    foreach(QTcpSocket *client, clients)
        client->write(QString("Server:" + user + " has left.\n").toUtf8());
}

void ChatServerModel::sendUserList()
{
    QStringList userList;
    foreach(QString user, users.values())
        userList << user;

    foreach(QTcpSocket *client, clients)
        client->write(QString("/users:" + userList.join(",") + "\n").toUtf8());
}
