#include "groupinfo.h"
#include "ui_groupinfo.h"
#include "QMessageBox"
#include "QFileDialog"

//旗子判断资料是否被修改
bool flag2=false;

GroupInfo::GroupInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupInfo)
{

    //设置窗口不可拉伸
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    //从服务端获取群资料并显示
    ui->AnnounceEdit->setText(tr("明天上交数学作业"));
    ui->IntroEdit->setText(tr("本群用于班内同学学习交流"));
    ui->NameEdit->setText(tr("四年四班"));
    //设置为只读
    ui->AnnounceEdit->setReadOnly(true);
    ui->IntroEdit->setReadOnly(true);
    ui->NameEdit->setReadOnly(true);
    ui->SaveButton->setEnabled(false);

}

GroupInfo::~GroupInfo()
{
    delete ui;
}

void GroupInfo::SaveChange()
{
    //将保存的数据发送到服务器端
   QString Name,Introduction,Announcement;
   Name = ui->NameEdit->text();
   Introduction = ui->IntroEdit->toPlainText();
   Announcement = ui->AnnounceEdit->toPlainText();
   flag2=true;
}

void GroupInfo::on_SaveButton_clicked()
{
    SaveChange();
    QMessageBox::information(this, QObject::tr("提示"),
                              QObject::tr("修改成功"),
                              QMessageBox::Yes);
    ui->AnnounceEdit->setReadOnly(true);
    ui->IntroEdit->setReadOnly(true);
    ui->NameEdit->setReadOnly(true);
    ui->SaveButton->setEnabled(false);
}

void GroupInfo::on_CloseButton_clicked()
{
    //如果Edit中的内容被更改而且没有按保存按钮则弹出警告框
   if((ui->NameEdit->isModified()||ui->IntroEdit->document()->isModified()
           ||ui->AnnounceEdit->document()->isModified())&&(!flag2)){
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
   else {    //保存资料后或者未编辑则直接退出
          this->close();
   }

}



void GroupInfo::on_GroupFaceBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName!=NULL){
      QPixmap qpx(fileName);
      ui->GroupFaceBtn->setIcon(qpx);
        }
}

void GroupInfo::on_EditButton_clicked()
{
    //资料变为可编辑，保存按钮可用
  ui->AnnounceEdit->setReadOnly(false);
  ui->IntroEdit->setReadOnly(false);
  ui->NameEdit->setReadOnly(false);
   ui->SaveButton->setEnabled(true);
}
