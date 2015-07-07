#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T01:57:10
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += script
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ichat
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    mainpanel.cpp \
    userlistitem.cpp \
    chatwindow.cpp \
    addwindow.cpp \
    additems.cpp \
    dividewindow.cpp \
    confirmwindow.cpp \
    addfinishedwindow.cpp \
    userinfo.cpp \
    groupinfo.cpp \
    friendinfo.cpp

HEADERS  += \
    logindialog.h \
    mainpanel.h \
    userlistitem.h \
    chatwindow.h \
    addwindow.h \
    additems.h \
    dividewindow.h \
    confirmwindow.h \
    addfinishedwindow.h \
    userinfo.h \
    groupinfo.h \
    friendinfo.h

FORMS    += \
    logindialog.ui \
    mainpanel.ui \
    userlistitem.ui \
    chatwindow.ui \
    addwindow.ui \
    additems.ui \
    dividewindow.ui \
    confirmwindow.ui \
    addfinishedwindow.ui \
    userinfo.ui \
    groupinfo.ui \
    friendinfo.ui

RESOURCES += \
    resource.qrc
QT  += network
QT  += script
