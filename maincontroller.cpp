#include "maincontroller.h"
#include "chatclient/chatclientcontroller.h"
#include "chatserver/chatservercontroller.h"

MainController::MainController()
{
    mainWindow.addTab((new ChatServerController)->getView(), "Chat server");
    mainWindow.addTab((new ChatClientController)->getView(), "Chat client");
    mainWindow.show();
}
