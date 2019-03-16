#include "chatclientview.h"
#include <QSplitter>
#include <QAbstractItemView>

ChatClientView::ChatClientView() :
    ui(new Ui::ChatClientView)
{
    //setup ui
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->loginPage);
    QSplitter *splitter = new QSplitter;
    chatEdit->setReadOnly(true);
    usersListWidget->setSelectionMode(QAbstractItemView::NoSelection);
    splitter->addWidget(chatEdit);
    splitter->addWidget(usersListWidget);
    ui->topLayout->addWidget(splitter);
    QObject::connect(ui->loginButton, &QPushButton::clicked, this, &ChatClientView::loginButtonClicked);
    QObject::connect(ui->sayButton, &QPushButton::clicked, this, &ChatClientView::sayButtonClicked);
}

ChatClientView::~ChatClientView()
{
    delete ui;
}

Ui::ChatClientView *ChatClientView::getUI()
{
    return ui;
}

void ChatClientView::sayButtonClicked()
{
    emit userWantSendMessage(ui->messageEdit->text());
    ui->messageEdit->clear();
    ui->messageEdit->setFocus();
}

void ChatClientView::loginButtonClicked()
{
    QString name = ui->nameEdit->text();
    QString address = ui->addressEdit->text();
    int port = ui->portEdit->value();
    emit userWantConnect(name, address, port);
}

void ChatClientView::onConnected(bool isConnected)
{
    ui->stackedWidget->setCurrentWidget(isConnected ? ui->chatPage : ui->loginPage);
}

void ChatClientView::onRecivedMessage(const QString &sender, const QString &message)
{
    chatEdit->append("<b>" + sender + "</b>:" + message);
}

void ChatClientView::onUsersListChanged(const QStringList &usersList)
{
    usersListWidget->clear();
    foreach(QString user, usersList){
        new QListWidgetItem(QPixmap(":/user.png"), user, usersListWidget);
    }
}
