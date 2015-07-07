#include "groupinfo.h"
#include "ui_groupinfo.h"
#include "QMessageBox"
#include "QFileDialog"

//旗子判断资料是否被修改
bool flag2=false;
bool flagClose2 = false;

GroupInfo::GroupInfo(QString groupaccount,QWidget *parent) :
    QDialog(parent),groupAccount(groupaccount),
    ui(new Ui::GroupInfo)
{

    //设置窗口不可拉伸
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());


    manager1 = new QNetworkAccessManager(this);
    manager2 = new QNetworkAccessManager(this);
    manager3 = new QNetworkAccessManager(this);
    QObject::connect(manager1, SIGNAL(finished(QNetworkReply*)),
                       this, SLOT(finishedSlot(QNetworkReply*)));
              QUrl url("http://182.92.69.19/ichat-server/public/user/get-info");
              QByteArray GAccount = groupAccount.toLocal8Bit();
              QByteArray append("account="+GAccount);

              QNetworkReply* reply = manager1->post(QNetworkRequest(url),append);
     //向服务器端发送改变后的用户信息
              QObject::connect(manager2, SIGNAL(finished(QNetworkReply*)),
                                this, SLOT(uploadfinishedSlot(QNetworkReply*)));
      //向服务器端发送改变后的头像
              QObject::connect(manager3, SIGNAL(finished(QNetworkReply*)),
                                this, SLOT(faceuploadfinishedsolt(QNetworkReply*)));

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



void GroupInfo::on_SaveButton_clicked()
{

    QByteArray account,groupname,groupannounce,groupintroduce;
            account = (ui->GroupAccount->text()).toLocal8Bit();
            groupname = (ui->NameEdit->text()).toLocal8Bit();
            groupannounce =(ui->AnnounceEdit->toPlainText()).toLocal8Bit();
            groupintroduce = (ui->IntroEdit->toPlainText()).toLocal8Bit();

          QUrl url("http://182.92.69.19/ichat-server/public/user/set-info");
          QByteArray append();
       //   QNetworkReply* reply = manager2->post(QNetworkRequest(url),append);
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
            on_SaveButton_clicked();
            flagClose2 = true;
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


 //修改群头像
void GroupInfo::on_GroupFaceBtn_clicked()
{
      QByteArray ba;
      QBuffer   buf(&ba);
      QByteArray GroupAccount = groupAccount.toLocal8Bit();
      QString fileName = QFileDialog::getOpenFileName(this);
      if(fileName!=NULL){
      QImage img(fileName);
      ui->GroupFaceBtn->setIcon(QPixmap::fromImage(img));
      //将图片转成base64编码
      img.save(&buf,"JPG");
      QByteArray cc = qCompress(ba,1);
      QByteArray hh = cc.toBase64();
      QString faceCode(hh);
      //上传到服务器时 +号会莫名其妙消失，先将它们都替换成- 获取的时候再转成 +
      int j = faceCode.indexOf('+');
      while(j!=-1){
          faceCode[j] = '-';
          j = faceCode.indexOf('+');
      }

      //qDebug()<<faceCode;
      QByteArray head = faceCode.toLocal8Bit();
      //qDebug()<<head;
      //上传到服务器
      QUrl url("http://182.92.69.19/ichat-server/public/user/set-head");
      QByteArray append("account="+GroupAccount+"&head="+head);
      QNetworkReply* reply = manager3->post(QNetworkRequest(url),append);
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

    //服务器接收的槽函数
void GroupInfo::finishedSlot(QNetworkReply *reply)
{
    int i=0;
    QString groupInfo[10];
    //从服务器端获取信息
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();
    QScriptValue sc;
        QScriptEngine engine;
        sc = engine.evaluate("value = " + res);
        QScriptValueIterator it(sc);
        while(it.hasNext()){
            it.next();
            QString id = it.name();
            QString value = it.value().toString();
            groupInfo[i]=value;
            i++;
     }

        //显示在资料卡上

    ui->GroupAccount->setText(groupInfo[1]);   //账号
    ui->NameEdit->setText(groupInfo[2]);   //群名
    ui->AnnounceEdit->setText(groupInfo[3]);  //群公告
    ui->IntroEdit->setText(groupInfo[4]);   //群介绍
    ui->SetUpDate->setText(groupInfo[11]);   //创建日期
     //头像
    QByteArray head,face;
    QString str(groupInfo[6]);
    int j = str.indexOf('-');
    while(j!=-1){
        str[j] = '+';
        j = str.indexOf('-');
    }
    head = QByteArray::fromBase64(str.toLatin1());
    face = qUncompress(head);
    QImage img;
    img.loadFromData(face);
    ui->GroupFaceBtn->setIcon(QPixmap::fromImage(img));

}

   //向服务器发送的槽函数
void GroupInfo::uploadfinishedSlot(QNetworkReply *reply)
{
    QMessageBox::information(this, QObject::tr("提示"),
                              QObject::tr("修改成功"),
                              QMessageBox::Yes);

    ui->SaveButton->setEnabled(false);
    ui->NameEdit->setReadOnly(true);
    ui->AnnounceEdit->setReadOnly(true);
    ui->IntroEdit->setReadOnly(true);
    flag2=true;
   if(flagClose2){
       this->close();
   }
}
