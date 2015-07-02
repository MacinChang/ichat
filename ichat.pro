#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T01:57:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ichat
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    mainpanel.cpp \
    userlistitem.cpp \
    chatwindow.cpp \
    addwindow.cpp \
    userinfo.cpp \
    groupinfo.cpp

HEADERS  += \
    logindialog.h \
    mainpanel.h \
    userlistitem.h \
    chatwindow.h \
    addwindow.h \
    userinfo.h \
    groupinfo.h

FORMS    += \
    logindialog.ui \
    mainpanel.ui \
    userlistitem.ui \
    chatwindow.ui \
    addwindow.ui \
    userinfo.ui \
    groupinfo.ui

RESOURCES += \
    resource.qrc
