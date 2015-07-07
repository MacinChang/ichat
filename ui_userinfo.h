/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

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

class Ui_UserInfo
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *SaveButton;
    QPushButton *EditButton;
    QComboBox *YearCombo;
    QLabel *label_14;
    QComboBox *MonthCombo;
    QLabel *label_15;
    QComboBox *DateCombo;
    QLabel *label_16;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_7;
    QLineEdit *SignEdit;
    QLineEdit *PhoneEdit;
    QLineEdit *AgeEdit;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *AccountList;
    QLabel *label;
    QLabel *label_12;
    QLabel *label_3;
    QPushButton *FaceButton;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *NameEdit;
    QComboBox *SexCombo;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_18;
    QComboBox *HomeP;
    QComboBox *HomeC;
    QComboBox *HomeL;
    QPushButton *CloseButton;
    QPushButton *pushButton;
    QComboBox *LocalP;
    QComboBox *LocalC;
    QComboBox *LocalL;
    QLabel *label_10;
    QLabel *label_17;
    QLabel *label_21;
    QListWidget *LvList;

    void setupUi(QDialog *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QStringLiteral("UserInfo"));
        UserInfo->resize(459, 562);
        horizontalLayoutWidget = new QWidget(UserInfo);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 519, 272, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SaveButton = new QPushButton(horizontalLayoutWidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/image/savechangeBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveButton->setIcon(icon);
        SaveButton->setIconSize(QSize(120, 40));
        SaveButton->setFlat(true);

        horizontalLayout->addWidget(SaveButton);

        EditButton = new QPushButton(horizontalLayoutWidget);
        EditButton->setObjectName(QStringLiteral("EditButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/image/changeBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditButton->setIcon(icon1);
        EditButton->setIconSize(QSize(120, 39));
        EditButton->setFlat(true);

        horizontalLayout->addWidget(EditButton);

        YearCombo = new QComboBox(UserInfo);
        YearCombo->setObjectName(QStringLiteral("YearCombo"));
        YearCombo->setGeometry(QRect(89, 321, 69, 20));
        label_14 = new QLabel(UserInfo);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(164, 321, 16, 16));
        MonthCombo = new QComboBox(UserInfo);
        MonthCombo->setObjectName(QStringLiteral("MonthCombo"));
        MonthCombo->setGeometry(QRect(182, 321, 69, 20));
        label_15 = new QLabel(UserInfo);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(257, 321, 16, 16));
        DateCombo = new QComboBox(UserInfo);
        DateCombo->setObjectName(QStringLiteral("DateCombo"));
        DateCombo->setGeometry(QRect(275, 321, 69, 20));
        label_16 = new QLabel(UserInfo);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(350, 321, 16, 16));
        label_2 = new QLabel(UserInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 240, 48, 16));
        label_4 = new QLabel(UserInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 280, 24, 16));
        label_6 = new QLabel(UserInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(49, 347, 24, 16));
        label_9 = new QLabel(UserInfo);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 470, 36, 16));
        label_7 = new QLabel(UserInfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 380, 36, 16));
        SignEdit = new QLineEdit(UserInfo);
        SignEdit->setObjectName(QStringLiteral("SignEdit"));
        SignEdit->setGeometry(QRect(90, 240, 311, 20));
        PhoneEdit = new QLineEdit(UserInfo);
        PhoneEdit->setObjectName(QStringLiteral("PhoneEdit"));
        PhoneEdit->setGeometry(QRect(92, 380, 133, 20));
        AgeEdit = new QLineEdit(UserInfo);
        AgeEdit->setObjectName(QStringLiteral("AgeEdit"));
        AgeEdit->setGeometry(QRect(91, 347, 133, 20));
        label_8 = new QLabel(UserInfo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(49, 422, 24, 16));
        label_5 = new QLabel(UserInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 320, 24, 16));
        AccountList = new QLabel(UserInfo);
        AccountList->setObjectName(QStringLiteral("AccountList"));
        AccountList->setGeometry(QRect(90, 70, 111, 16));
        label = new QLabel(UserInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 100, 24, 16));
        label_12 = new QLabel(UserInfo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 150, 24, 16));
        label_3 = new QLabel(UserInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 70, 24, 16));
        FaceButton = new QPushButton(UserInfo);
        FaceButton->setObjectName(QStringLiteral("FaceButton"));
        FaceButton->setGeometry(QRect(90, 130, 61, 61));
        FaceButton->setIconSize(QSize(60, 60));
        FaceButton->setFlat(true);
        label_11 = new QLabel(UserInfo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 0, 471, 571));
        label_11->setLayoutDirection(Qt::LeftToRight);
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/images/image/information.png")));
        label_13 = new QLabel(UserInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 200, 24, 16));
        NameEdit = new QLineEdit(UserInfo);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setGeometry(QRect(90, 200, 133, 20));
        SexCombo = new QComboBox(UserInfo);
        SexCombo->setObjectName(QStringLiteral("SexCombo"));
        SexCombo->setGeometry(QRect(90, 280, 69, 22));
        label_20 = new QLabel(UserInfo);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(358, 421, 16, 16));
        label_19 = new QLabel(UserInfo);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(263, 421, 16, 16));
        label_18 = new QLabel(UserInfo);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(168, 421, 16, 16));
        HomeP = new QComboBox(UserInfo);
        HomeP->setObjectName(QStringLiteral("HomeP"));
        HomeP->setGeometry(QRect(93, 421, 69, 20));
        HomeC = new QComboBox(UserInfo);
        HomeC->setObjectName(QStringLiteral("HomeC"));
        HomeC->setGeometry(QRect(188, 421, 69, 20));
        HomeL = new QComboBox(UserInfo);
        HomeL->setObjectName(QStringLiteral("HomeL"));
        HomeL->setGeometry(QRect(283, 421, 69, 20));
        CloseButton = new QPushButton(UserInfo);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(430, 0, 31, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/image/\345\217\211 - \345\211\257\346\234\254.png"), QSize(), QIcon::Normal, QIcon::Off);
        CloseButton->setIcon(icon2);
        CloseButton->setIconSize(QSize(23, 23));
        CloseButton->setFlat(true);
        pushButton = new QPushButton(UserInfo);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(404, 0, 31, 23));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/image/small.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setIconSize(QSize(23, 23));
        pushButton->setFlat(true);
        LocalP = new QComboBox(UserInfo);
        LocalP->setObjectName(QStringLiteral("LocalP"));
        LocalP->setGeometry(QRect(93, 471, 69, 20));
        LocalC = new QComboBox(UserInfo);
        LocalC->setObjectName(QStringLiteral("LocalC"));
        LocalC->setGeometry(QRect(188, 471, 69, 20));
        LocalL = new QComboBox(UserInfo);
        LocalL->setObjectName(QStringLiteral("LocalL"));
        LocalL->setGeometry(QRect(283, 471, 69, 20));
        label_10 = new QLabel(UserInfo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(168, 471, 18, 16));
        label_17 = new QLabel(UserInfo);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(263, 471, 16, 16));
        label_21 = new QLabel(UserInfo);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(358, 471, 16, 16));
        LvList = new QListWidget(UserInfo);
        LvList->setObjectName(QStringLiteral("LvList"));
        LvList->setGeometry(QRect(90, 100, 201, 21));
        LvList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LvList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LvList->setSelectionMode(QAbstractItemView::NoSelection);
        LvList->setTextElideMode(Qt::ElideRight);
        LvList->setFlow(QListView::LeftToRight);
        label_11->raise();
        horizontalLayoutWidget->raise();
        YearCombo->raise();
        label_14->raise();
        MonthCombo->raise();
        label_15->raise();
        DateCombo->raise();
        label_16->raise();
        label_2->raise();
        label_4->raise();
        label_6->raise();
        label_9->raise();
        label_7->raise();
        SignEdit->raise();
        PhoneEdit->raise();
        AgeEdit->raise();
        label_8->raise();
        label_5->raise();
        AccountList->raise();
        label->raise();
        label_12->raise();
        label_3->raise();
        FaceButton->raise();
        label_13->raise();
        NameEdit->raise();
        SexCombo->raise();
        label_20->raise();
        label_19->raise();
        label_18->raise();
        HomeP->raise();
        HomeC->raise();
        HomeL->raise();
        CloseButton->raise();
        pushButton->raise();
        LocalP->raise();
        LocalC->raise();
        LocalL->raise();
        label_10->raise();
        label_17->raise();
        label_21->raise();
        LvList->raise();

        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QDialog *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "\344\270\252\344\272\272\350\265\204\346\226\231", 0));
        SaveButton->setText(QString());
        EditButton->setText(QString());
        label_14->setText(QApplication::translate("UserInfo", "\345\271\264", 0));
        label_15->setText(QApplication::translate("UserInfo", "\346\234\210", 0));
        label_16->setText(QApplication::translate("UserInfo", "\346\227\245", 0));
        label_2->setText(QApplication::translate("UserInfo", "\344\270\252\346\200\247\347\255\276\345\220\215", 0));
        label_4->setText(QApplication::translate("UserInfo", "\346\200\247\345\210\253", 0));
        label_6->setText(QApplication::translate("UserInfo", "\345\271\264\351\276\204", 0));
        label_9->setText(QApplication::translate("UserInfo", "\346\211\200\345\234\250\345\234\260", 0));
        label_7->setText(QApplication::translate("UserInfo", "\346\211\213\346\234\272\345\217\267", 0));
        SignEdit->setText(QString());
        label_8->setText(QApplication::translate("UserInfo", "\346\225\205\344\271\241", 0));
        label_5->setText(QApplication::translate("UserInfo", "\347\224\237\346\227\245", 0));
        AccountList->setText(QString());
        label->setText(QApplication::translate("UserInfo", "\347\255\211\347\272\247", 0));
        label_12->setText(QApplication::translate("UserInfo", "\345\244\264\345\203\217", 0));
        label_3->setText(QApplication::translate("UserInfo", "\350\264\246\345\217\267", 0));
        FaceButton->setText(QString());
        label_11->setText(QString());
        label_13->setText(QApplication::translate("UserInfo", "\346\230\265\347\247\260", 0));
        label_20->setText(QApplication::translate("UserInfo", "\345\214\272", 0));
        label_19->setText(QApplication::translate("UserInfo", "\345\270\202", 0));
        label_18->setText(QApplication::translate("UserInfo", "\347\234\201", 0));
        CloseButton->setText(QString());
        pushButton->setText(QString());
        label_10->setText(QApplication::translate("UserInfo", "\347\234\201", 0));
        label_17->setText(QApplication::translate("UserInfo", "\345\270\202", 0));
        label_21->setText(QApplication::translate("UserInfo", "\345\214\272", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
