/********************************************************************************
** Form generated from reading UI file 'friendinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDINFO_H
#define UI_FRIENDINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendInfo
{
public:
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_14;
    QComboBox *DateCombo;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *AgeEdit;
    QComboBox *SexCombo;
    QLineEdit *NameEdit;
    QPushButton *FaceButton;
    QLabel *label_16;
    QComboBox *MonthCombo;
    QLabel *label;
    QLineEdit *SignEdit;
    QLabel *AccountList;
    QLabel *label_15;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *LocalP;
    QLabel *label_21;
    QComboBox *LocalC;
    QLabel *label_22;
    QComboBox *LocalL;
    QLabel *label_23;
    QComboBox *YearCombo;
    QLabel *label_7;
    QLineEdit *PhoneEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *HomeP;
    QLabel *label_18;
    QComboBox *HomeC;
    QLabel *label_19;
    QComboBox *HomeL;
    QLabel *label_20;
    QLabel *label_13;
    QPushButton *ConfirmButton;
    QPushButton *smallButton;
    QListWidget *LvList;
    QLabel *label_10;

    void setupUi(QDialog *FriendInfo)
    {
        if (FriendInfo->objectName().isEmpty())
            FriendInfo->setObjectName(QStringLiteral("FriendInfo"));
        FriendInfo->resize(451, 490);
        label_3 = new QLabel(FriendInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 70, 24, 16));
        label_12 = new QLabel(FriendInfo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 150, 24, 16));
        label_14 = new QLabel(FriendInfo);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(164, 301, 16, 16));
        DateCombo = new QComboBox(FriendInfo);
        DateCombo->setObjectName(QStringLiteral("DateCombo"));
        DateCombo->setGeometry(QRect(275, 301, 69, 20));
        label_4 = new QLabel(FriendInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(49, 271, 24, 16));
        label_2 = new QLabel(FriendInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 240, 48, 16));
        AgeEdit = new QLineEdit(FriendInfo);
        AgeEdit->setObjectName(QStringLiteral("AgeEdit"));
        AgeEdit->setGeometry(QRect(91, 327, 133, 20));
        SexCombo = new QComboBox(FriendInfo);
        SexCombo->setObjectName(QStringLiteral("SexCombo"));
        SexCombo->setGeometry(QRect(90, 270, 69, 22));
        NameEdit = new QLineEdit(FriendInfo);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setGeometry(QRect(90, 200, 133, 20));
        FaceButton = new QPushButton(FriendInfo);
        FaceButton->setObjectName(QStringLiteral("FaceButton"));
        FaceButton->setGeometry(QRect(90, 130, 61, 61));
        FaceButton->setIconSize(QSize(60, 60));
        FaceButton->setFlat(true);
        label_16 = new QLabel(FriendInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(350, 301, 16, 16));
        MonthCombo = new QComboBox(FriendInfo);
        MonthCombo->setObjectName(QStringLiteral("MonthCombo"));
        MonthCombo->setGeometry(QRect(182, 301, 69, 20));
        label = new QLabel(FriendInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 100, 24, 16));
        SignEdit = new QLineEdit(FriendInfo);
        SignEdit->setObjectName(QStringLiteral("SignEdit"));
        SignEdit->setGeometry(QRect(90, 240, 311, 20));
        AccountList = new QLabel(FriendInfo);
        AccountList->setObjectName(QStringLiteral("AccountList"));
        AccountList->setGeometry(QRect(90, 70, 60, 16));
        label_15 = new QLabel(FriendInfo);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(257, 301, 16, 16));
        label_9 = new QLabel(FriendInfo);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(49, 411, 36, 16));
        label_5 = new QLabel(FriendInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 300, 24, 16));
        label_6 = new QLabel(FriendInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(49, 327, 24, 16));
        label_8 = new QLabel(FriendInfo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(49, 383, 24, 16));
        layoutWidget = new QWidget(FriendInfo);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(88, 410, 275, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        LocalP = new QComboBox(layoutWidget);
        LocalP->setObjectName(QStringLiteral("LocalP"));

        horizontalLayout_3->addWidget(LocalP);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_3->addWidget(label_21);

        LocalC = new QComboBox(layoutWidget);
        LocalC->setObjectName(QStringLiteral("LocalC"));

        horizontalLayout_3->addWidget(LocalC);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_3->addWidget(label_22);

        LocalL = new QComboBox(layoutWidget);
        LocalL->setObjectName(QStringLiteral("LocalL"));

        horizontalLayout_3->addWidget(LocalL);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_3->addWidget(label_23);

        YearCombo = new QComboBox(FriendInfo);
        YearCombo->setObjectName(QStringLiteral("YearCombo"));
        YearCombo->setGeometry(QRect(89, 301, 69, 20));
        label_7 = new QLabel(FriendInfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(49, 355, 36, 16));
        PhoneEdit = new QLineEdit(FriendInfo);
        PhoneEdit->setObjectName(QStringLiteral("PhoneEdit"));
        PhoneEdit->setGeometry(QRect(91, 355, 133, 20));
        layoutWidget_2 = new QWidget(FriendInfo);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(88, 380, 275, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        HomeP = new QComboBox(layoutWidget_2);
        HomeP->setObjectName(QStringLiteral("HomeP"));

        horizontalLayout_2->addWidget(HomeP);

        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_2->addWidget(label_18);

        HomeC = new QComboBox(layoutWidget_2);
        HomeC->setObjectName(QStringLiteral("HomeC"));

        horizontalLayout_2->addWidget(HomeC);

        label_19 = new QLabel(layoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_2->addWidget(label_19);

        HomeL = new QComboBox(layoutWidget_2);
        HomeL->setObjectName(QStringLiteral("HomeL"));

        horizontalLayout_2->addWidget(HomeL);

        label_20 = new QLabel(layoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_2->addWidget(label_20);

        label_13 = new QLabel(FriendInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 200, 24, 16));
        ConfirmButton = new QPushButton(FriendInfo);
        ConfirmButton->setObjectName(QStringLiteral("ConfirmButton"));
        ConfirmButton->setGeometry(QRect(420, 0, 31, 23));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/image/\345\217\211 - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfirmButton->setIcon(icon);
        ConfirmButton->setIconSize(QSize(23, 23));
        ConfirmButton->setFlat(true);
        smallButton = new QPushButton(FriendInfo);
        smallButton->setObjectName(QStringLiteral("smallButton"));
        smallButton->setGeometry(QRect(394, 0, 31, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/image/small.png"), QSize(), QIcon::Normal, QIcon::Off);
        smallButton->setIcon(icon1);
        smallButton->setIconSize(QSize(23, 23));
        smallButton->setFlat(true);
        LvList = new QListWidget(FriendInfo);
        LvList->setObjectName(QStringLiteral("LvList"));
        LvList->setGeometry(QRect(90, 100, 131, 21));
        LvList->setFlow(QListView::LeftToRight);
        label_10 = new QLabel(FriendInfo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 0, 455, 488));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/images/image/friendInfor.png")));
        label_10->raise();
        label_3->raise();
        label_12->raise();
        label_14->raise();
        DateCombo->raise();
        label_4->raise();
        label_2->raise();
        AgeEdit->raise();
        SexCombo->raise();
        NameEdit->raise();
        FaceButton->raise();
        label_16->raise();
        MonthCombo->raise();
        label->raise();
        SignEdit->raise();
        AccountList->raise();
        label_15->raise();
        label_9->raise();
        label_5->raise();
        label_6->raise();
        label_8->raise();
        layoutWidget->raise();
        YearCombo->raise();
        label_7->raise();
        PhoneEdit->raise();
        layoutWidget_2->raise();
        label_13->raise();
        ConfirmButton->raise();
        smallButton->raise();
        LvList->raise();

        retranslateUi(FriendInfo);

        QMetaObject::connectSlotsByName(FriendInfo);
    } // setupUi

    void retranslateUi(QDialog *FriendInfo)
    {
        FriendInfo->setWindowTitle(QApplication::translate("FriendInfo", "\345\245\275\345\217\213\350\265\204\346\226\231", 0));
        label_3->setText(QApplication::translate("FriendInfo", "\350\264\246\345\217\267", 0));
        label_12->setText(QApplication::translate("FriendInfo", "\345\244\264\345\203\217", 0));
        label_14->setText(QApplication::translate("FriendInfo", "\345\271\264", 0));
        label_4->setText(QApplication::translate("FriendInfo", "\346\200\247\345\210\253", 0));
        label_2->setText(QApplication::translate("FriendInfo", "\344\270\252\346\200\247\347\255\276\345\220\215", 0));
        FaceButton->setText(QString());
        label_16->setText(QApplication::translate("FriendInfo", "\346\227\245", 0));
        label->setText(QApplication::translate("FriendInfo", "\347\255\211\347\272\247", 0));
        SignEdit->setText(QString());
        AccountList->setText(QString());
        label_15->setText(QApplication::translate("FriendInfo", "\346\234\210", 0));
        label_9->setText(QApplication::translate("FriendInfo", "\346\211\200\345\234\250\345\234\260", 0));
        label_5->setText(QApplication::translate("FriendInfo", "\347\224\237\346\227\245", 0));
        label_6->setText(QApplication::translate("FriendInfo", "\345\271\264\351\276\204", 0));
        label_8->setText(QApplication::translate("FriendInfo", "\346\225\205\344\271\241", 0));
        label_21->setText(QApplication::translate("FriendInfo", "\347\234\201", 0));
        label_22->setText(QApplication::translate("FriendInfo", "\345\270\202", 0));
        label_23->setText(QApplication::translate("FriendInfo", "\345\214\272", 0));
        label_7->setText(QApplication::translate("FriendInfo", "\346\211\213\346\234\272\345\217\267", 0));
        label_18->setText(QApplication::translate("FriendInfo", "\347\234\201", 0));
        label_19->setText(QApplication::translate("FriendInfo", "\345\270\202", 0));
        label_20->setText(QApplication::translate("FriendInfo", "\345\214\272", 0));
        label_13->setText(QApplication::translate("FriendInfo", "\346\230\265\347\247\260", 0));
        ConfirmButton->setText(QString());
        smallButton->setText(QString());
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendInfo: public Ui_FriendInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDINFO_H
