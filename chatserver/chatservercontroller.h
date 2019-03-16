#ifndef CHATSERVERCONTROLLER_H
#define CHATSERVERCONTROLLER_H

#include "chatserverview.h"
#include "chatservermodel.h"

class ChatServerController
{

public:
    ChatServerController();
    ~ChatServerController();
    ChatServerView *getView();

private:
    ChatServerView *view = new ChatServerView;
    ChatServerModel *model = new ChatServerModel;
};

#endif // CHATSERVERCONTROLLER_H
