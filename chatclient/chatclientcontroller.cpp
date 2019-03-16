#include "chatclientcontroller.h"

ChatClientController::ChatClientController()
{
    //ui signals
    QObject::connect(view, &ChatClientView::userWantConnect, model, &ChatClientModel::tryConnect);
    QObject::connect(view, &ChatClientView::userWantSendMessage, model, &ChatClientModel::sendMessage);
    QObject::connect(view->getUI()->logoutButton, &QPushButton::clicked, model, &ChatClientModel::disconnect);

    //model signals
    QObject::connect(model, &ChatClientModel::usersListChanged, view, &ChatClientView::onUsersListChanged);
    QObject::connect(model, &ChatClientModel::recivedMessage, view, &ChatClientView::onRecivedMessage);
    QObject::connect(model, &ChatClientModel::connected, view, &ChatClientView::onConnected);
}

ChatClientController::~ChatClientController()
{
    delete view;
    delete model;
}

ChatClientView *ChatClientController::getView()
{
    return view;
}
