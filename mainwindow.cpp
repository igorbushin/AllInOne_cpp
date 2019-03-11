#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chat/chatclientview.h"
#include "chat/chatserverview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(new ChatClientView(new ChatClientModel), "Chat client");
    ui->tabWidget->addTab(new ChatServerView(new ChatServerModel), "Chat server");
}

MainWindow::~MainWindow()
{
    delete ui;
}
