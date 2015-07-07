/********************************************************************************
** Form generated from reading UI file 'addfinishedwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFINISHEDWINDOW_H
#define UI_ADDFINISHEDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddFinishedWindow
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *AddFinishedWindow)
    {
        if (AddFinishedWindow->objectName().isEmpty())
            AddFinishedWindow->setObjectName(QStringLiteral("AddFinishedWindow"));
        AddFinishedWindow->resize(400, 300);
        pushButton = new QPushButton(AddFinishedWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 242, 101, 41));
        label = new QLabel(AddFinishedWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 191, 61));

        retranslateUi(AddFinishedWindow);

        QMetaObject::connectSlotsByName(AddFinishedWindow);
    } // setupUi

    void retranslateUi(QDialog *AddFinishedWindow)
    {
        AddFinishedWindow->setWindowTitle(QApplication::translate("AddFinishedWindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("AddFinishedWindow", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("AddFinishedWindow", "\345\245\275\345\217\213\347\224\263\350\257\267\345\267\262\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFinishedWindow: public Ui_AddFinishedWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFINISHEDWINDOW_H
