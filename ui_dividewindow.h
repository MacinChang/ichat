/********************************************************************************
** Form generated from reading UI file 'dividewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIVIDEWINDOW_H
#define UI_DIVIDEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DivideWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *DivideWindow)
    {
        if (DivideWindow->objectName().isEmpty())
            DivideWindow->setObjectName(QStringLiteral("DivideWindow"));
        DivideWindow->resize(401, 273);
        pushButton = new QPushButton(DivideWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 240, 75, 23));
        pushButton_2 = new QPushButton(DivideWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 240, 75, 23));
        label = new QLabel(DivideWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(113, 31, 61, 31));
        label_4 = new QLabel(DivideWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(113, 90, 54, 12));
        lineEdit = new QLineEdit(DivideWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 35, 151, 25));
        comboBox = new QComboBox(DivideWindow);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(180, 85, 151, 25));
        label_5 = new QLabel(DivideWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 150, 54, 12));
        label_6 = new QLabel(DivideWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 190, 111, 21));
        label_3 = new QLabel(DivideWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 71, 71));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/head.jpg")));
        label_3->setScaledContents(true);
        label_2 = new QLabel(DivideWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 54, 12));
        label_7 = new QLabel(DivideWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 170, 71, 16));
        label_8 = new QLabel(DivideWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 110, 81, 20));

        retranslateUi(DivideWindow);

        QMetaObject::connectSlotsByName(DivideWindow);
    } // setupUi

    void retranslateUi(QDialog *DivideWindow)
    {
        DivideWindow->setWindowTitle(QApplication::translate("DivideWindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("DivideWindow", "\345\256\214\346\210\220", 0));
        pushButton_2->setText(QApplication::translate("DivideWindow", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("DivideWindow", "\345\244\207\346\263\250\345\247\223\345\220\215\357\274\232", 0));
        label_4->setText(QApplication::translate("DivideWindow", "\345\210\206\347\273\204\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DivideWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0)
         << QApplication::translate("DivideWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0)
         << QApplication::translate("DivideWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0)
         << QApplication::translate("DivideWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0)
         << QApplication::translate("DivideWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0)
        );
        label_5->setText(QApplication::translate("DivideWindow", "\346\200\247\345\210\253\357\274\232\347\224\267", 0));
        label_6->setText(QApplication::translate("DivideWindow", "\346\211\200\345\234\250\345\234\260\357\274\232\346\271\226\345\214\227 \346\255\246\346\261\211", 0));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("DivideWindow", "66666", 0));
        label_7->setText(QApplication::translate("DivideWindow", "\345\271\264\351\276\204\357\274\23219\345\262\201", 0));
        label_8->setText(QApplication::translate("DivideWindow", "\345\215\216\347\247\221\345\244\247\350\265\214\345\234\243", 0));
    } // retranslateUi

};

namespace Ui {
    class DivideWindow: public Ui_DivideWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIVIDEWINDOW_H
