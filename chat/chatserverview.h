#ifndef CHATSERVERVIEW_H
#define CHATSERVERVIEW_H

#include <QWidget>
#include "chatservermodel.h"
namespace Ui {
class ChatServerView;
}

class ChatServerView : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServerView(ChatServerModel *model);
    ~ChatServerView();

private:
    Ui::ChatServerView *ui;
};

#endif // CHATSERVERVIEW_H
