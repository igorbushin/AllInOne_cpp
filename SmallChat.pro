QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmallChat

DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE = app

CONFIG += c++17

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        maincontroller.cpp \
        chatclient/chatclientview.cpp \
        chatclient/chatclientmodel.cpp \
        chatclient/chatclientcontroller.cpp \
        chatserver/chatserverview.cpp \
        chatserver/chatservermodel.cpp \
        chatserver/chatservercontroller.cpp

HEADERS += \
        mainwindow.h \
        maincontroller.h \
        chatclient/chatclientview.h \
        chatclient/chatclientmodel.h \
        chatclient/chatclientcontroller.h \
        chatserver/chatserverview.h \
        chatserver/chatservermodel.h \
        chatserver/chatservercontroller.h

FORMS += \
        mainwindow.ui \
        chatclient/chatclientview.ui \
        chatserver/chatserverview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

DISTFILES += \
    .gitignore
