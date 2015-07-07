/********************************************************************************
** Form generated from reading UI file 'confirmwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMWINDOW_H
#define UI_CONFIRMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_confirmWindow
{
public:
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *confirmWindow)
    {
        if (confirmWindow->objectName().isEmpty())
            confirmWindow->setObjectName(QStringLiteral("confirmWindow"));
        confirmWindow->resize(400, 300);
        label_3 = new QLabel(confirmWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 20, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/head.jpg")));
        label_3->setScaledContents(true);
        label = new QLabel(confirmWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 100, 81, 20));
        label_2 = new QLabel(confirmWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 120, 54, 12));
        label_4 = new QLabel(confirmWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 140, 54, 12));
        label_5 = new QLabel(confirmWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 160, 71, 16));
        label_6 = new QLabel(confirmWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 180, 111, 21));
        label_7 = new QLabel(confirmWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(130, 15, 111, 21));
        textBrowser = new QTextBrowser(confirmWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(125, 40, 261, 71));
        textBrowser->setReadOnly(false);
        pushButton = new QPushButton(confirmWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 250, 75, 23));
        pushButton_2 = new QPushButton(confirmWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 250, 75, 23));

        retranslateUi(confirmWindow);

        QMetaObject::connectSlotsByName(confirmWindow);
    } // setupUi

    void retranslateUi(QDialog *confirmWindow)
    {
        confirmWindow->setWindowTitle(QApplication::translate("confirmWindow", "Dialog", 0));
        label_3->setText(QString());
        label->setText(QApplication::translate("confirmWindow", "\345\215\216\347\247\221\345\244\247\350\265\214\345\234\243", 0));
        label_2->setText(QApplication::translate("confirmWindow", "66666", 0));
        label_4->setText(QApplication::translate("confirmWindow", "\346\200\247\345\210\253\357\274\232\347\224\267", 0));
        label_5->setText(QApplication::translate("confirmWindow", "\345\271\264\351\276\204\357\274\23219\345\262\201", 0));
        label_6->setText(QApplication::translate("confirmWindow", "\346\211\200\345\234\250\345\234\260\357\274\232\346\271\226\345\214\227 \346\255\246\346\261\211", 0));
        label_7->setText(QApplication::translate("confirmWindow", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\344\277\241\346\201\257\357\274\232", 0));
        textBrowser->setHtml(QApplication::translate("confirmWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\210\221\346\230\257...</p></body></html>", 0));
        pushButton->setText(QApplication::translate("confirmWindow", "\344\270\213\344\270\200\346\255\245", 0));
        pushButton_2->setText(QApplication::translate("confirmWindow", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class confirmWindow: public Ui_confirmWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMWINDOW_H
