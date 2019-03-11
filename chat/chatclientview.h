#ifndef CHATCLIENTVIEW_H
#define CHATCLIENTVIEW_H

#include <QWidget>
#include <QListWidget>
#include <QTextEdit>
#include "chatclientmodel.h"

namespace Ui {
class ChatClientView;
}

class ChatClientView : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClientView(ChatClientModel *model);
    ~ChatClientView();

private:
    Ui::ChatClientView *ui;
    QListWidget *usersListWidget = new QListWidget;
    QTextEdit *chatEdit = new QTextEdit;
};

#endif // CHATCLIENTVIEW_H
