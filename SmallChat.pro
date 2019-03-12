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
        chat/chatclientview.cpp \
        chat/chatclientmodel.cpp \
        chat/chatserverview.cpp \
        chat/chatservermodel.cpp

HEADERS += \
        mainwindow.h \
        chat/chatclientview.h \
        chat/chatclientmodel.h \
        chat/chatserverview.h \
        chat/chatservermodel.h

FORMS += \
        mainwindow.ui \
        chat/chatclientview.ui \
        chat/chatserverview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

DISTFILES += \
    .gitignore
