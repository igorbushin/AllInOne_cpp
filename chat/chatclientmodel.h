#ifndef CHATCLIENTCHATCLIENTMODEL_H
#define CHATCLIENTCHATCLIENTMODEL_H

#include <QObject>
#include <QTcpSocket>

class ChatClientModel : public QObject
{
    Q_OBJECT

public:
    explicit ChatClientModel(QObject *parent = nullptr);

signals:
    void connected();
    void disconnected();
    void reciveMessage(const QString &sender, const QString &message);
    void usersListChanged(const QStringList &usersList);

public slots:
    void tryConnect(const QString &name, const QString &address, int port);
    void sendMessage(const QString &message);
    void disconnect();

private slots:
    void socketReadyRead();
    void socketConnected();
    void socketDisconnected();

private:
    QString name;
    QTcpSocket *socket;
};

#endif // CHATCLIENTCHATCLIENTMODEL_H
