#include "chatserverview.h"
#include <QSlider>

ChatServerView::ChatServerView() :
    ui(new Ui::ChatServerView)
{
    ui->setupUi(this);
    QObject::connect(ui->tumbler, &QSlider::valueChanged, this, &ChatServerView::onTumblerValueChanged);
}

ChatServerView::~ChatServerView()
{
    delete ui;
}

Ui::ChatServerView *ChatServerView::getUI()
{
    return ui;
}

void ChatServerView::onTumblerValueChanged(int value)
{
    if(value) {
        bool success = emit userWantStartServer(ui->portEdit->value());
        if(!success) {
            ui->tumbler->blockSignals(true);
            ui->tumbler->setValue(0);
            ui->tumbler->blockSignals(false);
        }
    }
    else {
        emit userWantKillServer();
    }
}
