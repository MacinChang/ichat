/********************************************************************************
** Form generated from reading UI file 'additems.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMS_H
#define UI_ADDITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddItems
{
public:
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *AddItems)
    {
        if (AddItems->objectName().isEmpty())
            AddItems->setObjectName(QStringLiteral("AddItems"));
        AddItems->resize(371, 90);
        label_3 = new QLabel(AddItems);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/head.jpg")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(AddItems);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 30, 181, 20));
        pushButton = new QPushButton(AddItems);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 52, 75, 31));

        retranslateUi(AddItems);

        QMetaObject::connectSlotsByName(AddItems);
    } // setupUi

    void retranslateUi(QWidget *AddItems)
    {
        AddItems->setWindowTitle(QApplication::translate("AddItems", "Form", 0));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("AddItems", "\347\224\237\346\227\266\344\275\225\345\277\205\344\271\205\347\235\241\357\274\214\346\255\273\345\220\216\350\207\252\344\274\232\351\225\277\347\234\240", 0));
        pushButton->setText(QApplication::translate("AddItems", "\345\212\240\344\270\272\345\245\275\345\217\213", 0));
    } // retranslateUi

};

namespace Ui {
    class AddItems: public Ui_AddItems {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMS_H
