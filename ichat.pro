#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T01:57:10
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ichat
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    mainpanel.cpp \
    chatwindow.cpp \
    addwindow.cpp \
    useritem.cpp \
    renamedialog.cpp \
    deleteconfirmdialog.cpp \
    newgroupdialog.cpp \
    changegroupdialog.cpp

HEADERS  += \
    logindialog.h \
    mainpanel.h \
    chatwindow.h \
    addwindow.h \
    useritem.h \
    renamedialog.h \
    deleteconfirmdialog.h \
    newgroupdialog.h \
    changegroupdialog.h

FORMS    += \
    logindialog.ui \
    mainpanel.ui \
    chatwindow.ui \
    addwindow.ui \
    useritem.ui \
    renamedialog.ui \
    deleteconfirmdialog.ui \
    newgroupdialog.ui \
    changegroupdialog.ui

RESOURCES += \
    resource.qrc
