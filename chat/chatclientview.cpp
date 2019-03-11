#include "chatclientview.h"
#include "ui_chatclientview.h"
#include <QSplitter>

ChatClientView::ChatClientView(ChatClientModel *model) :
    ui(new Ui::ChatClientView)
{
    //setup ui
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    QSplitter *splitter = new QSplitter;
    chatEdit->setEnabled(false);
    usersListWidget->setEnabled(false);
    splitter->addWidget(chatEdit);
    splitter->addWidget(usersListWidget);
    ui->topLayout->addWidget(splitter);

    //ui signals
    connect(ui->loginButton, &QPushButton::clicked, this, [=](){
        QString name = ui->nameEdit->text();
        QString address = ui->addressEdit->text();
        int port = ui->portEdit->value();
        model->tryConnect(name, address, port);
    });
    connect(ui->sayButton, &QPushButton::clicked, this, [=](){
        model->sendMessage(ui->messageEdit->text());
        ui->messageEdit->clear();
        ui->messageEdit->setFocus();
    });
    connect(ui->logoutButton, &QPushButton::clicked, model, &ChatClientModel::disconnect);

    //model signals
    connect(model, &ChatClientModel::usersListChanged, this, [=](const QStringList &usersList){
        usersListWidget->clear();
        foreach(QString user, usersList){
            new QListWidgetItem(user, usersListWidget);
        }
    });
    connect(model, &ChatClientModel::reciveMessage, this, [=](const QString &sender, const QString &message) {
        chatEdit->append("<b>" + sender + "</b>:" + message);
    });
    connect(model, &ChatClientModel::connected, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->chatPage);
    });
    connect(model, &ChatClientModel::disconnected, this, [=](){
        ui->stackedWidget->setCurrentWidget(ui->loginPage);
    });
}

ChatClientView::~ChatClientView()
{
    delete ui;
}
