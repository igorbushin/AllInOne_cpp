QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AllInOne_cpp

DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE = app

CONFIG += c++17

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

DISTFILES += \
    .gitignore
