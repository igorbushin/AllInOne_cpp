#ifndef CHATCLIENTCONTROLLER_H
#define CHATCLIENTCONTROLLER_H

#include "chatclientview.h"
#include "chatclientmodel.h"

class ChatClientController
{

public:
    ChatClientController();
    ~ChatClientController();
    ChatClientView *getView();

private:
    ChatClientView *view = new ChatClientView;
    ChatClientModel *model = new ChatClientModel;
};

#endif // CHATCLIENTCONTROLLER_H
