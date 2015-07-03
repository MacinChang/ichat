#include "friendinfo.h"
#include "ui_friendinfo.h"

FriendInfo::FriendInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendInfo)
{

    ui->setupUi(this);
       //设置窗口不可拉伸
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

     //为下拉列表提供选项
    for(int year=1900;year<=2015;year++){
        ui->YearCombo->addItem(QString::number(year));
    }
    for(int month=1;month<=12;month++){
        ui->MonthCombo->addItem(QString::number(month));
    }
    for(int date=1;date<=31;date++){
        ui->DateCombo->addItem(QString::number(date));
    }

    //从服务器端获取好友信息并显示
    ui->NameEdit->setText(tr("W"));
    ui->AgeEdit->setText(tr("20"));
    ui->SexEdit->setText(tr("Male"));
    ui->PhoneEdit->setText(tr("15109809238"));
    ui->HomeEdit->setText(tr("Haikou"));
    ui->LocationEdit->setText(tr("Wuhan"));
    ui->SchoolEdit->setText(tr("HUST"));
    ui->YearCombo->setCurrentIndex(95);
    ui->MonthCombo->setCurrentIndex(7);
    ui->DateCombo->setCurrentIndex(18);

    //设置为只读，并不可改
    ui->NameEdit->setReadOnly(true);
    ui->AgeEdit->setReadOnly(true);
    ui->SexEdit->setReadOnly(true);
    ui->PhoneEdit->setReadOnly(true);
    ui->HomeEdit->setReadOnly(true);
    ui->LocationEdit->setReadOnly(true);
    ui->SchoolEdit->setReadOnly(true);
    ui->YearCombo->setEnabled(false);
    ui->MonthCombo->setEnabled(false);
    ui->DateCombo->setEnabled(false);
}

FriendInfo::~FriendInfo()
{
    delete ui;
}

void FriendInfo::on_ConfirmButton_clicked()
{
    this->close();
}
