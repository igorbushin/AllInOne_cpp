#include "chatserverview.h"
#include "ui_chatserverview.h"
#include <QSlider>

ChatServerView::ChatServerView(ChatServerModel *model) :
    ui(new Ui::ChatServerView)
{
    ui->setupUi(this);

    //ui signals
    connect(ui->tumbler, &QSlider::valueChanged, this, [=](int newValue){
        if(newValue) {
            bool success = model->run(ui->portEdit->value());
            if(!success) {
                ui->tumbler->blockSignals(true);
                ui->tumbler->setValue(0);
                ui->tumbler->blockSignals(false);
            }
        }
        else {
            model->kill();
        }
    });

    //model signals
    connect(model, &ChatServerModel::somethingHappened, ui->logEdit, &QTextEdit::append);
}

ChatServerView::~ChatServerView()
{
    delete ui;
}
