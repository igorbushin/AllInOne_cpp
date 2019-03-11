#ifndef CHATCHATSERVERMODEL_H
#define CHATCHATSERVERMODEL_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

class ChatServerModel : public QTcpServer
{
    Q_OBJECT
public:
    explicit ChatServerModel(QObject *parent = nullptr);
    bool run(int port);
    void kill();

signals:
    void somethingHappened(const QString &message);

private slots:
    void socketReadyRead();
    void socketDisconnected();
    void sendUserList();

protected:
    void incomingConnection(int socketfd);

private:
    QSet<QTcpSocket*> clients;
    QMap<QTcpSocket*, QString> users;
};

#endif // CHATCHATSERVERMODEL_H
