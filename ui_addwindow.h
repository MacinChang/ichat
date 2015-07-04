/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *listWidget;

    void setupUi(QFrame *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName(QStringLiteral("AddWindow"));
        AddWindow->resize(400, 300);
        AddWindow->setFrameShape(QFrame::StyledPanel);
        AddWindow->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(AddWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 20, 231, 31));
        pushButton = new QPushButton(AddWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 20, 81, 31));
        listWidget = new QListWidget(AddWindow);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 60, 371, 192));

        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QFrame *AddWindow)
    {
        AddWindow->setWindowTitle(QApplication::translate("AddWindow", "Frame", 0));
        pushButton->setText(QApplication::translate("AddWindow", "\346\237\245\346\211\276", 0));
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
