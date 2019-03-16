#ifndef CHATCLIENTVIEW_H
#define CHATCLIENTVIEW_H

#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include "ui_chatclientview.h"

class ChatClientView : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClientView();
    ~ChatClientView();
    Ui::ChatClientView *getUI();

signals:
    void userWantConnect(const QString &name, const QString &address, int port);
    void userWantSendMessage(const QString &message);

public slots:
    void onConnected(bool isConnected);
    void onRecivedMessage(const QString &sender, const QString &message);
    void onUsersListChanged(const QStringList &usersList);

private slots:
    void sayButtonClicked();
    void loginButtonClicked();

private:
    Ui::ChatClientView *ui;
    QListWidget *usersListWidget = new QListWidget;
    QTextEdit *chatEdit = new QTextEdit;
};

#endif // CHATCLIENTVIEW_H
