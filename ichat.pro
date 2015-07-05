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
    chatwindow.cpp \
    addwindow.cpp \
    useritem.cpp \
    mylistwidget.cpp \
    grouplistwidget.cpp

HEADERS  += \
    logindialog.h \
    mainpanel.h \
    chatwindow.h \
    addwindow.h \
    useritem.h \
    mylistwidget.h \
    grouplistwidget.h

FORMS    += \
    logindialog.ui \
    mainpanel.ui \
    chatwindow.ui \
    addwindow.ui \
    useritem.ui

RESOURCES += \
    resource.qrc
