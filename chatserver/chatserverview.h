#ifndef CHATSERVERVIEW_H
#define CHATSERVERVIEW_H

#include <QWidget>
#include "ui_chatserverview.h"

class ChatServerView : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServerView();
    ~ChatServerView();
    Ui::ChatServerView *getUI();

signals:
    bool userWantStartServer(int port);
    void userWantKillServer();

private slots:
    void onTumblerValueChanged(int value);

private:
    Ui::ChatServerView *ui;
};

#endif // CHATSERVERVIEW_H
