#include "chatservercontroller.h"
#include <QTextEdit>

ChatServerController::ChatServerController()
{
    //ui signals
    QObject::connect(view, &ChatServerView::userWantStartServer, model, &ChatServerModel::run);
    QObject::connect(view, &ChatServerView::userWantKillServer, model, &ChatServerModel::kill);

    //model signals
    QObject::connect(model, &ChatServerModel::somethingHappened, view->getUI()->logEdit, &QTextEdit::append);
}

ChatServerView *ChatServerController::getView()
{
    return view;
}
