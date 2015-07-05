/********************************************************************************
** Form generated from reading UI file 'userlistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLISTITEM_H
#define UI_USERLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserListItem
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *UserListItem)
    {
        if (UserListItem->objectName().isEmpty())
            UserListItem->setObjectName(QStringLiteral("UserListItem"));
        UserListItem->resize(240, 59);
        label = new QLabel(UserListItem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 10, 121, 16));
        label_2 = new QLabel(UserListItem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 30, 181, 20));
        label_3 = new QLabel(UserListItem);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 41, 41));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/head.jpg")));
        label_3->setScaledContents(true);

        retranslateUi(UserListItem);

        QMetaObject::connectSlotsByName(UserListItem);
    } // setupUi

    void retranslateUi(QWidget *UserListItem)
    {
        UserListItem->setWindowTitle(QApplication::translate("UserListItem", "Form", 0));
        label->setText(QApplication::translate("UserListItem", "MACINCHANG", 0));
        label_2->setText(QApplication::translate("UserListItem", "\347\224\237\346\227\266\344\275\225\345\277\205\344\271\205\347\235\241\357\274\214\346\255\273\345\220\216\350\207\252\344\274\232\351\225\277\347\234\240", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserListItem: public Ui_UserListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTITEM_H
