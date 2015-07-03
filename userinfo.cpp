#include "userinfo.h"
#include "ui_userinfo.h"
#include "QMessageBox"
#include "QFileDialog"

//用户账号、用户等级从服务器端获得且不可修改

bool flag=false;  //全局旗子用来判断资料是否保存

UserInfo::UserInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfo)
{
    //设置窗口不可拉伸
    ui->setupUi(this);
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

    //从服务器端获取用户信息并显示
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

    //获取之前的生日信息
   preY = ui->YearCombo->currentText();
   preM = ui->MonthCombo->currentText();
   preD = ui->DateCombo->currentText();

    //设置信息为只读，按了修改资料的按钮后设为可编辑
    ui->NameEdit->setReadOnly(true);
    ui->AgeEdit->setReadOnly(true);
    ui->SexEdit->setReadOnly(true);
    ui->PhoneEdit->setReadOnly(true);
    ui->HomeEdit->setReadOnly(true);
    ui->LocationEdit->setReadOnly(true);
    ui->SchoolEdit->setReadOnly(true);
    ui->SaveButton->setEnabled(false);
    ui->YearCombo->setEnabled(false);
    ui->MonthCombo->setEnabled(false);
    ui->DateCombo->setEnabled(false);

}

UserInfo::~UserInfo()
{
    delete ui;
}



void UserInfo::on_SaveButton_clicked()
{
    //按下保存资料按钮，执行保存操作，并将编辑框和保存按钮设为不可用
    SaveChange();
    QMessageBox::information(this, QObject::tr("提示"),
                              QObject::tr("修改成功"),
                              QMessageBox::Yes);
    ui->SaveButton->setEnabled(false);
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
    flag=true;            //如果按了保存修改的按钮，旗子改为true
}

void UserInfo::on_CloseButton_clicked()
{
   QString modyY,modyM,modyD;
   modyY = ui->YearCombo->currentText();
   modyM = ui->MonthCombo->currentText();
   modyD = ui->DateCombo->currentText();
  //头像更改
  if((ui->AgeEdit->isModified()||ui->NameEdit->isModified()||(preY!=modyY)||
          (preM!=modyM)||(preD!=modyD)||
          ui->HomeEdit->isModified()||ui->LocationEdit->isModified()||
          ui->PhoneEdit->isModified()||ui->SexEdit->isModified()||
          ui->SchoolEdit->isModified())&&(!flag)){   //资料被编辑且没按保存修改
             QMessageBox box;
             box.setWindowTitle(QObject::tr("提示"));
             box.setIcon(QMessageBox::Warning);
             box.setText(QObject::tr("您已对设置进行了修改，是否保存？"));
             QPushButton *yesBtn = box.addButton(QObject::tr("Yes"),
                              QMessageBox::YesRole);
             QPushButton *noBtn = box.addButton(QObject::tr("No"),
                              QMessageBox::NoRole);
             QPushButton *cancelBtn = box.addButton(QObject::tr("Cancel"),
                              QMessageBox::RejectRole);
             box.exec();
             if (box.clickedButton() == yesBtn){
                 SaveChange();
                 this->close();
             }
             else if (box.clickedButton() == cancelBtn)
                      box.close();
             else if(box.clickedButton()== noBtn){
                       this->close();
             }
                    }
           else {    //保存了资料或者未编辑 直接退出
       this->close();
         }
}

void UserInfo::SaveChange()
{
    //将编辑的资料存在变量中用于向服务器发送
   QString Name,Sex,BirthYear,BirthMonth,BirthDate,Age,Location,Home,Phone,School;
   Name = ui->NameEdit->text();
   Sex = ui->SexEdit->text();
   Age = ui->AgeEdit->text();
   Location = ui->LocationEdit->text();
   Home = ui->HomeEdit->text();
   Phone = ui->PhoneEdit->text();
   School = ui->SchoolEdit->text();
   BirthYear = ui->YearCombo->currentText();
   BirthMonth = ui->MonthCombo->currentText();
   BirthDate = ui->DateCombo->currentText();

}



void UserInfo::on_EditButton_clicked()
{
   //编辑资料按钮按下后各编辑框设置为可编辑，保存资料按钮设为可用
    ui->NameEdit->setReadOnly(false);
    ui->SexEdit->setReadOnly(false);
    ui->AgeEdit->setReadOnly(false);
    ui->LocationEdit->setReadOnly(false);
    ui->HomeEdit->setReadOnly(false);
    ui->PhoneEdit->setReadOnly(false);
    ui->SchoolEdit->setReadOnly(false);

    ui->YearCombo->setEnabled(true);
    ui->MonthCombo->setEnabled(true);
    ui->DateCombo->setEnabled(true);

    ui->SaveButton->setEnabled(true);

}



void UserInfo::on_FaceButton_clicked()
{
    //从本地选择头像修改
 QString fileName = QFileDialog::getOpenFileName(this);
 if(fileName!=NULL){
   QPixmap qpx(fileName);
   ui->FaceButton->setIcon(qpx);
     }
}









