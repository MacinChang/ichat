/********************************************************************************
** Form generated from reading UI file 'groupinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPINFO_H
#define UI_GROUPINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupInfo
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *EditButton;
    QPushButton *SaveButton;
    QPushButton *CloseButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *IntroEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextEdit *AnnounceEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *NameEdit;
    QLabel *label_7;
    QLabel *label_12;
    QLabel *GroupAccount;
    QLabel *label_3;
    QPushButton *GroupFaceBtn;
    QLabel *SetUpDate;

    void setupUi(QDialog *GroupInfo)
    {
        if (GroupInfo->objectName().isEmpty())
            GroupInfo->setObjectName(QStringLiteral("GroupInfo"));
        GroupInfo->resize(455, 549);
        horizontalLayoutWidget = new QWidget(GroupInfo);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(210, 450, 239, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        EditButton = new QPushButton(horizontalLayoutWidget);
        EditButton->setObjectName(QStringLiteral("EditButton"));

        horizontalLayout->addWidget(EditButton);

        SaveButton = new QPushButton(horizontalLayoutWidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));

        horizontalLayout->addWidget(SaveButton);

        CloseButton = new QPushButton(horizontalLayoutWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));

        horizontalLayout->addWidget(CloseButton);

        horizontalLayoutWidget_2 = new QWidget(GroupInfo);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(60, 270, 321, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        IntroEdit = new QTextEdit(horizontalLayoutWidget_2);
        IntroEdit->setObjectName(QStringLiteral("IntroEdit"));

        horizontalLayout_2->addWidget(IntroEdit);

        horizontalLayoutWidget_3 = new QWidget(GroupInfo);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(60, 360, 321, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        AnnounceEdit = new QTextEdit(horizontalLayoutWidget_3);
        AnnounceEdit->setObjectName(QStringLiteral("AnnounceEdit"));

        horizontalLayout_3->addWidget(AnnounceEdit);

        layoutWidget = new QWidget(GroupInfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 230, 261, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        NameEdit = new QLineEdit(layoutWidget);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));

        horizontalLayout_4->addWidget(NameEdit);

        label_7 = new QLabel(GroupInfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 100, 48, 16));
        label_12 = new QLabel(GroupInfo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(60, 180, 24, 16));
        GroupAccount = new QLabel(GroupInfo);
        GroupAccount->setObjectName(QStringLiteral("GroupAccount"));
        GroupAccount->setGeometry(QRect(224, 50, 60, 16));
        label_3 = new QLabel(GroupInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 50, 24, 16));
        GroupFaceBtn = new QPushButton(GroupInfo);
        GroupFaceBtn->setObjectName(QStringLiteral("GroupFaceBtn"));
        GroupFaceBtn->setGeometry(QRect(224, 142, 72, 68));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/12.png"), QSize(), QIcon::Normal, QIcon::Off);
        GroupFaceBtn->setIcon(icon);
        GroupFaceBtn->setIconSize(QSize(60, 60));
        GroupFaceBtn->setFlat(true);
        SetUpDate = new QLabel(GroupInfo);
        SetUpDate->setObjectName(QStringLiteral("SetUpDate"));
        SetUpDate->setGeometry(QRect(224, 100, 54, 12));

        retranslateUi(GroupInfo);

        QMetaObject::connectSlotsByName(GroupInfo);
    } // setupUi

    void retranslateUi(QDialog *GroupInfo)
    {
        GroupInfo->setWindowTitle(QApplication::translate("GroupInfo", "\347\276\244\350\265\204\346\226\231", 0));
        EditButton->setText(QApplication::translate("GroupInfo", "\344\277\256\346\224\271\350\265\204\346\226\231", 0));
        SaveButton->setText(QApplication::translate("GroupInfo", "\344\277\235\345\255\230\344\277\256\346\224\271", 0));
        CloseButton->setText(QApplication::translate("GroupInfo", "\345\205\263\351\227\255", 0));
        label_2->setText(QApplication::translate("GroupInfo", "\347\276\244\344\273\213\347\273\215", 0));
        label_4->setText(QApplication::translate("GroupInfo", "\347\276\244\345\205\254\345\221\212", 0));
        label_6->setText(QApplication::translate("GroupInfo", "\347\276\244\345\220\215", 0));
        label_7->setText(QApplication::translate("GroupInfo", "\345\210\233\345\273\272\346\227\266\351\227\264", 0));
        label_12->setText(QApplication::translate("GroupInfo", "\345\244\264\345\203\217", 0));
        GroupAccount->setText(QApplication::translate("GroupInfo", "1016862375", 0));
        label_3->setText(QApplication::translate("GroupInfo", "\347\276\244\345\217\267", 0));
        GroupFaceBtn->setText(QString());
        SetUpDate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GroupInfo: public Ui_GroupInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPINFO_H
