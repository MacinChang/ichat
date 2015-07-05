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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QFrame *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName(QStringLiteral("AddWindow"));
        AddWindow->resize(408, 300);
        AddWindow->setFrameShape(QFrame::StyledPanel);
        AddWindow->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(AddWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 20, 171, 31));
        pushButton = new QPushButton(AddWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 20, 81, 31));
        label = new QLabel(AddWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 91, 21));
        textBrowser = new QTextBrowser(AddWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 60, 361, 192));
        label_3 = new QLabel(AddWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 70, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/head.jpg")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(AddWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 70, 121, 16));
        label_4 = new QLabel(AddWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 90, 181, 20));
        pushButton_2 = new QPushButton(AddWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 110, 75, 31));

        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QFrame *AddWindow)
    {
        AddWindow->setWindowTitle(QApplication::translate("AddWindow", "Frame", 0));
        pushButton->setText(QApplication::translate("AddWindow", "\346\237\245\346\211\276", 0));
        label->setText(QApplication::translate("AddWindow", "\350\257\267\350\276\223\345\205\245ichat\345\217\267\357\274\232", 0));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("AddWindow", "MACINCHANG", 0));
        label_4->setText(QApplication::translate("AddWindow", "\347\224\237\346\227\266\344\275\225\345\277\205\344\271\205\347\235\241\357\274\214\346\255\273\345\220\216\350\207\252\344\274\232\351\225\277\347\234\240", 0));
        pushButton_2->setText(QApplication::translate("AddWindow", "\345\212\240\344\270\272\345\245\275\345\217\213", 0));
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
