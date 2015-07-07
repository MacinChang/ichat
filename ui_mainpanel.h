/********************************************************************************
** Form generated from reading UI file 'mainpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPANEL_H
#define UI_MAINPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainPanel
{
public:
    QPushButton *btnAdd;
    QPushButton *btnContact;
    QPushButton *btnGroup;
    QListWidget *listWidgetContact;

    void setupUi(QFrame *MainPanel)
    {
        if (MainPanel->objectName().isEmpty())
            MainPanel->setObjectName(QStringLiteral("MainPanel"));
        MainPanel->resize(233, 367);
        MainPanel->setFrameShape(QFrame::StyledPanel);
        MainPanel->setFrameShadow(QFrame::Raised);
        btnAdd = new QPushButton(MainPanel);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(150, 332, 75, 31));
        btnContact = new QPushButton(MainPanel);
        btnContact->setObjectName(QStringLiteral("btnContact"));
        btnContact->setGeometry(QRect(0, 0, 81, 41));
        btnGroup = new QPushButton(MainPanel);
        btnGroup->setObjectName(QStringLiteral("btnGroup"));
        btnGroup->setGeometry(QRect(80, 0, 81, 41));
        listWidgetContact = new QListWidget(MainPanel);
        listWidgetContact->setObjectName(QStringLiteral("listWidgetContact"));
        listWidgetContact->setGeometry(QRect(0, 50, 256, 261));

        retranslateUi(MainPanel);
        QObject::connect(btnAdd, SIGNAL(clicked()), MainPanel, SLOT(update()));

        QMetaObject::connectSlotsByName(MainPanel);
    } // setupUi

    void retranslateUi(QFrame *MainPanel)
    {
        MainPanel->setWindowTitle(QApplication::translate("MainPanel", "Frame", 0));
        btnAdd->setText(QApplication::translate("MainPanel", "\346\267\273\345\212\240\345\245\275\345\217\213", 0));
        btnContact->setText(QApplication::translate("MainPanel", "\350\201\224\347\263\273\344\272\272", 0));
        btnGroup->setText(QApplication::translate("MainPanel", "\347\276\244", 0));
    } // retranslateUi

};

namespace Ui {
    class MainPanel: public Ui_MainPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPANEL_H
