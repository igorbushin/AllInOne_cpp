#include "maincontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainController mainController;
    return a.exec();
}
