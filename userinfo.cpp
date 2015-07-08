#include "userinfo.h"
#include "ui_userinfo.h"
#include "QMessageBox"
#include "QFileDialog"
#include <QMouseEvent>
#include <QJsonArray>
#include <QJsonObject>
#include <QScriptEngine>
#include <QScriptValueIterator>
#include <QtGui>
#include <QDrag>
#include <Level.h>

bool flag=false;  //全局旗子用来判断资料是否保存
bool flagClose = false;

UserInfo::UserInfo(QString account, QWidget *parent) :
    QDialog(parent),myaccount(account),
    ui(new Ui::UserInfo)
{

    ui->setupUi(this);
    QIcon winIcon(":/images/image/ichat.png");
    this->setWindowIcon(winIcon);
    //设置窗口不可拉伸
    this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());

    //从服务器端获取用户信息
        manager1 = new QNetworkAccessManager(this);  //获取信息的manager
        manager2 = new QNetworkAccessManager(this);   //发送信息的manager
        manager3 = new QNetworkAccessManager(this);     //修改头像的manager
        QObject::connect(manager1, SIGNAL(finished(QNetworkReply*)),
                   this, SLOT(finishedSlot(QNetworkReply*)));
          QUrl url("http://182.92.69.19/ichat-server/public/user/get-info");
          QByteArray MyAccount = myaccount.toLocal8Bit();
          QByteArray append("account="+MyAccount);


          manager1->post(QNetworkRequest(url),append);
     //向服务器端发送改变后的用户信息
          QObject::connect(manager2, SIGNAL(finished(QNetworkReply*)),
                    this, SLOT(uploadfinishedSlot(QNetworkReply*)));
     //向服务器端发送改变后的头像
          QObject::connect(manager3, SIGNAL(finished(QNetworkReply*)),
                    this, SLOT(faceuploadfinishedsolt(QNetworkReply*)));
     //为下拉列表提供选项
     int month;
    for(int year=1900;year<=2015;year++){
        ui->YearCombo->addItem(QString::number(year));
    }

    for(month=1;month<=12;month++){
        ui->MonthCombo->addItem(QString::number(month));
    }

    if(month==0||month==2||month==4||month==6||month==7||month==9||month==11){
    for(int date=1;date<=31;date++){
        ui->DateCombo->addItem(QString::number(date));
    }
        }
    else if(month==1){
        for(int date=1;date<=28;date++){
            ui->DateCombo->addItem(QString::number(date));
        }
    }
    else {
        for(int date=1;date<=30;date++){
            ui->DateCombo->addItem(QString::number(date));
    }
        }

    hp<<"海南"<<"湖南";
    hc1<<"海口"<<"三亚";
    hc2<<"长沙"<<"岳阳";
    ha1<<"琼山"<<"府城";
    ha2<<"南山"<<"亚龙";
    ha3<<"岳麓"<<"雨花";
    ha4<<"君山"<<"岳楼";

    lp<<"湖北"<<"山东";
    lc1<<"武汉"<<"襄阳";
    lc2<<"济南"<<"青岛";
    la1<<"洪山"<<"武昌";
    la2<<"襄城"<<"樊城";
    la3<<"章丘"<<"历下";
    la4<<"崂山"<<"黄岛";

    ui->HomeP->addItems(hp);
    ui->HomeC->addItems(hc1);
    ui->HomeL->addItems(ha1);
    ui->LocalP->addItems(lp);
    ui->LocalC->addItems(lc1);
    ui->LocalL->addItems(la1);

    ui->SexCombo->addItem("FeMale");
    ui->SexCombo->addItem("Male");


    //设置信息为只读，按了修改资料的按钮后设为可编辑
    //其中等级，账号不可修改
   // ui->LvList->setEnabled(false);
    ui->NameEdit->setReadOnly(true);
    ui->SignEdit->setReadOnly(true);
    ui->AgeEdit->setReadOnly(true);
    ui->SexCombo->setEnabled(false);
    ui->PhoneEdit->setReadOnly(true);
    ui->HomeP->setEnabled(false);
    ui->HomeC->setEnabled(false);
    ui->HomeL->setEnabled(false);
    ui->LocalP->setEnabled(false);
    ui->LocalC->setEnabled(false);
    ui->LocalL->setEnabled(false);
    ui->SaveButton->setEnabled(false);
    ui->YearCombo->setEnabled(false);
    ui->MonthCombo->setEnabled(false);
    ui->DateCombo->setEnabled(false);

}


UserInfo::~UserInfo()
{
    delete ui;
}

//从本地选择头像修改
void UserInfo::on_FaceButton_clicked(){
   QByteArray ba;
   QBuffer   buf(&ba);
   QByteArray MyAccount = myaccount.toLocal8Bit();
   QString fileName = QFileDialog::getOpenFileName(this);
   if(fileName!=NULL){
   QImage img(fileName);
   ui->FaceButton->setIcon(QPixmap::fromImage(img));
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
   QByteArray append("account="+MyAccount+"&head="+head);
   manager3->post(QNetworkRequest(url),append);
      }
  }

//按下保存资料按钮，执行保存操作，并将编辑框和保存按钮设为不可用
void UserInfo::on_SaveButton_clicked(){
    QByteArray account,nickname,signature,gender,age,phone,hometown,location,birth;
    QString sex,home,local,birthday,BirthYear,BirthMonth,BirthDate;
    int HomeP,HomeC,HomeL,LocalP,LocalC,LocalL;
      account = (ui->AccountList->text()).toLocal8Bit();
      nickname = (ui->NameEdit->text()).toLocal8Bit();
      signature =  (ui->SignEdit->text()).toLocal8Bit();
      sex    =  QString::number(ui->SexCombo->currentIndex());
      gender = sex.toLocal8Bit();
      age    = (ui->AgeEdit->text()).toLocal8Bit();
      phone  = (ui->PhoneEdit->text()).toLocal8Bit();
      HomeP  = ui->HomeP->currentIndex();
      HomeC  = ui->HomeC->currentIndex();
      HomeL  = ui->HomeL->currentIndex();
      LocalP = ui->LocalP->currentIndex();
      LocalC = ui->LocalC->currentIndex();
      LocalL = ui->LocalL->currentIndex();
      home = QString::number(HomeP*100+HomeC*10+HomeL);
      local = QString::number(LocalP*100+LocalC*10+LocalL);
      hometown = home.toLocal8Bit();
      location = local.toLocal8Bit();
      BirthYear  = QString::number(ui->YearCombo->currentIndex()+1900);
      BirthMonth = QString::number(ui->MonthCombo->currentIndex()+1);
      BirthDate  = QString::number(ui->DateCombo->currentIndex()+1);
      birthday   = BirthYear+"-"+BirthMonth+"-"+BirthDate;
      birth      = birthday.toLocal8Bit();
      QUrl url("http://182.92.69.19/ichat-server/public/user/set-info");
      QByteArray append("account="+account+"&nickname="+nickname+"&signature="+signature+
                      "&gender="+gender+"&age="+age+"&phone="+phone+
                        "&home="+hometown+"&location="+location+"&birth="+birth);
      manager2->post(QNetworkRequest(url),append);


}


//关闭窗口时提示是否保存资料
void UserInfo::on_CloseButton_clicked(){
   QString modyY,modyM,modyD,modyHP,modyHC,modyHL,modyLP,modyLC,modyLL,modySex;
   modyHP = ui->HomeP->currentText();
   modyHC = ui->HomeC->currentText();
   modyHL = ui->HomeL->currentText();
   modyLP = ui->LocalP->currentText();
   modyLC = ui->LocalC->currentText();
   modyLL = ui->LocalL->currentText();
   modyY = ui->YearCombo->currentText();
   modyM = ui->MonthCombo->currentText();
   modyD = ui->DateCombo->currentText();
   modySex = ui->SexCombo->currentText();
  if((ui->AgeEdit->isModified()||ui->NameEdit->isModified()||(preY!=modyY)||ui->SignEdit->isModified()||
          (preM!=modyM)||(preD!=modyD)||(preHP!=modyHP)||(preHC!=modyHC)||(preHL!=modyHL)
          ||(preLP!=modyLP)||(preLC!=modyLC)||(preLL!=modyLL)||(preSex!=modySex)||
          ui->PhoneEdit->isModified())&&(!flag)){   //资料被编辑且没按保存修改
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
                 flagClose = true;
             }
             else if (box.clickedButton() == cancelBtn)
                      box.close();
             else if(box.clickedButton()== noBtn){
                       this->close();
             }
                    }
           else {    //保存了资料或者未编辑 直接退出
      emit userInfoChanged();
       this->close();

         }

}




 //编辑资料按钮按下后各编辑框设置为可编辑，保存资料按钮设为可用
void UserInfo::on_EditButton_clicked(){
    ui->NameEdit->setReadOnly(false);
    ui->SexCombo->setEnabled(true);
    ui->AgeEdit->setReadOnly(false);
    ui->SignEdit->setReadOnly(false);
    ui->HomeP->setEnabled(true);
    ui->HomeC->setEnabled(true);
    ui->HomeL->setEnabled(true);
    ui->LocalP->setEnabled(true);
    ui->LocalC->setEnabled(true);
    ui->LocalL->setEnabled(true);
    ui->PhoneEdit->setReadOnly(false);
    ui->YearCombo->setEnabled(true);
    ui->MonthCombo->setEnabled(true);
    ui->DateCombo->setEnabled(true);
    ui->SaveButton->setEnabled(true);

}




//服务器接收的槽函数
void UserInfo::finishedSlot(QNetworkReply *reply){
    int i=0;
    QString usrInfo[20];
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
            usrInfo[i]=value;
            i++;
     }

        //显示在资料卡上
    ui->AccountList->setText(usrInfo[1]);   //账号
    ui->NameEdit->setText(usrInfo[2]);   //昵称

     //头像
    QByteArray head,face;
    QString str(usrInfo[3]);
    int j = str.indexOf('-');
    while(j!=-1){
        str[j] = '+';
        j = str.indexOf('-');
    }
    head = QByteArray::fromBase64(str.toLatin1());
    face = qUncompress(head);
    QImage img;
    img.loadFromData(face);
    ui->FaceButton->setIcon(QPixmap::fromImage(img));

    //签名
    if(ui->SignEdit->text() == "null"){
      ui->SignEdit->setText(" ");
    }
    ui->SignEdit->setText(usrInfo[4]);

    //等级
    Level lv;
        lv.LoadLevel(usrInfo[5]);
        int sunN,moonN,starN;
        int windowX = 90;
        QImage Sun(":/images/image/sun.png"),
               Moon(":/images/image/moon.png"),
               Star(":/images/image/star.png");
         sunN = lv.sun;
         moonN = lv.moon;
         starN = lv.star;
         QLabel *sun[3],*moon[3],*star[3];
         for(int i=0;i<3;i++){
             sun[i] = new QLabel();
             sun[i]->setPixmap(QPixmap::fromImage(Sun));
             sun[i]->setParent(this);
             moon[i] = new QLabel();
             moon[i]->setPixmap(QPixmap::fromImage(Moon));
             moon[i]->setParent(this);
             star[i] = new QLabel();
             star[i]->setPixmap(QPixmap::fromImage(Star));
             star[i]->setParent(this);
         }
         for(int i=0;i<sunN;i++){
             sun[i]->setGeometry(windowX,100,24,16);
             sun[i]->show();
             windowX += 24;
         }
         for(int i=0;i<moonN;i++){
             moon[i]->setGeometry(windowX,100,24,16);
             moon[i]->show();
             windowX += 24;
         }
         for(int i=0;i<starN;i++){
             star[i]->setGeometry(windowX,100,24,16);
             star[i]->show();
             windowX += 24;
         }

   //性别
    ui->SexCombo->setCurrentIndex(usrInfo[6].toInt());
    //年龄
    ui->AgeEdit->setText(usrInfo[7]);
    //电话
    ui->PhoneEdit->setText(usrInfo[8]);
    //故乡和所在地
    int home,homeP,homeC,homeL,local,localP,localC,localL,homePx,homePy,localPx,localPy;
    home = usrInfo[9].toInt();
    homeP=home/100;
    homePx=home-homeP*100;
    homeC=homePx/10;
    homePy=homePx-homeC*10;
    homeL=homePy;
    local = usrInfo[10].toInt();
    localP=local/100;
    localPx=local-localP*100;
    localC=localPx/10;
    localPy=localPx-localC*10;
    localL=localPy;
    ui->HomeP->setCurrentIndex(homeP);
    ui->LocalP->setCurrentIndex(localP);
   if(ui->HomeP->currentText()=="海南"){
       ui->HomeC->clear();
       ui->HomeC->addItems(hc1);
       ui->HomeC->setCurrentIndex(homeC);
       if(ui->HomeC->currentText()=="海口"){
           ui->HomeL->clear();
           ui->HomeL->addItems(ha1);
           ui->HomeL->setCurrentIndex(homeL);
       }
       else if(ui->HomeC->currentText()=="三亚"){
           ui->HomeL->clear();
           ui->HomeL->addItems(ha2);
           ui->HomeL->setCurrentIndex(homeL);
       }
    }

   else if(ui->HomeP->currentText()=="湖南"){
       ui->HomeC->clear();
       ui->HomeC->addItems(hc2);
        ui->HomeC->setCurrentIndex(homeC);
        if(ui->HomeC->currentText()=="长沙"){
            ui->HomeL->clear();
            ui->HomeL->addItems(ha3);
            ui->HomeL->setCurrentIndex(homeL);
        }
        else if(ui->HomeC->currentText()=="岳阳"){
            ui->HomeL->clear();
            ui->HomeL->addItems(ha4);
            ui->HomeL->setCurrentIndex(homeL);
        }
   }

   if(ui->LocalP->currentText()=="湖北"){
       ui->LocalC->clear();
       ui->LocalC->addItems(lc1);
       ui->LocalC->setCurrentIndex(localC);
       if(ui->LocalC->currentText()=="武汉"){
           ui->LocalL->clear();
           ui->LocalL->addItems(la1);
           ui->LocalL->setCurrentIndex(localL);
       }
       else if(ui->LocalC->currentText()=="襄阳"){
           ui->LocalL->clear();
           ui->LocalL->addItems(la2);
           ui->LocalL->setCurrentIndex(localL);
       }
    }

   else if(ui->LocalP->currentText()=="山东"){
       ui->LocalC->clear();
       ui->LocalC->addItems(lc2);
       ui->LocalC->setCurrentIndex(localC);
       if(ui->LocalC->currentText()=="济南"){
           ui->LocalL->clear();
           ui->LocalL->addItems(la3);
           ui->LocalL->setCurrentIndex(localL);
       }
       else if(ui->LocalC->currentText()=="青岛"){
           ui->LocalL->clear();
           ui->LocalL->addItems(la4);
           ui->LocalL->setCurrentIndex(localL);
       }
    }
    //生日
   if(usrInfo[11] == "null"){
       ui->YearCombo->setCurrentIndex(0);
       ui->MonthCombo->setCurrentIndex(0);
       ui->DateCombo->setCurrentIndex(0);
   }
   else{
       QStringList birthlist = usrInfo[11].split("-");
       ui->YearCombo->setCurrentIndex(birthlist[0].toInt()-1900);
       ui->MonthCombo->setCurrentIndex((birthlist[1].toInt())-1);
       ui->DateCombo->setCurrentIndex((birthlist[2].toInt())-1);
   }


   //获取目前的生日和所在地信息用于判断关闭窗口时提示是否保存
   preY = ui->YearCombo->currentText();
   preM = ui->MonthCombo->currentText();
   preD = ui->DateCombo->currentText();
   preHP = ui->HomeP->currentText();
   preHC = ui->HomeC->currentText();
   preHL = ui->HomeL->currentText();
   preLP = ui->LocalP->currentText();
   preLC = ui->LocalC->currentText();
   preLL = ui->LocalL->currentText();
   preSex = ui->SexCombo->currentText();
}


//向服务器发送修改后资料的槽函数
 void UserInfo::uploadfinishedSlot(QNetworkReply*){
     QMessageBox::information(this, QObject::tr("提示"),
                               QObject::tr("修改成功"),
                               QMessageBox::Yes);

     ui->SaveButton->setEnabled(false);
     ui->NameEdit->setReadOnly(true);
     ui->AgeEdit->setReadOnly(true);
     ui->SexCombo->setEnabled(false);
     ui->SignEdit->setReadOnly(true);
     ui->PhoneEdit->setReadOnly(true);
     ui->HomeP->setEnabled(false);
     ui->HomeC->setEnabled(false);
     ui->HomeL->setEnabled(false);
     ui->LocalP->setEnabled(false);
     ui->LocalC->setEnabled(false);
     ui->LocalL->setEnabled(false);
     ui->YearCombo->setEnabled(false);
     ui->MonthCombo->setEnabled(false);
     ui->DateCombo->setEnabled(false);
     flag=true;
    if(flagClose){
        this->close();
    }

 }

 //头像修改成功后的槽函数
void UserInfo::faceuploadfinishedsolt(QNetworkReply *)
{
     QMessageBox::information(this, QObject::tr("提示"),
                               QObject::tr("修改头像成功"),
                               QMessageBox::Yes);
}


//移动窗口
void UserInfo::mouseReleaseEvent(QMouseEvent *event){

    if (event->button() == Qt::LeftButton)
    {
        dragPosition = QPoint(-1, -1);
        event->accept();
    }
}

void UserInfo::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void UserInfo::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() &Qt::LeftButton)
    {
        if (dragPosition != QPoint(-1, -1))
            move(event->globalPos() - dragPosition);
        event->accept();
    }
}




//修改故乡
void UserInfo::on_HomeP_activated(){


    if(ui->HomeP->currentText()=="海南"){
        ui->HomeP->clear();
        ui->HomeP->addItems(hp);
         ui->HomeC->setCurrentIndex(0);

         ui->HomeC->clear();
         ui->HomeC->addItems(hc1);

         ui->HomeL->clear();
         ui->HomeL->addItems(ha1);

    }
   else if(ui->HomeP->currentText()=="湖南"){
        ui->HomeP->clear();
        ui->HomeP->addItems(hp);
        ui->HomeP->setCurrentIndex(1);

        ui->HomeC->clear();
        ui->HomeC->addItems(hc2);


        ui->HomeL->clear();
        ui->HomeL->addItems(ha3);

}
}

void UserInfo::on_HomeC_activated()
{

    if(ui->HomeC->currentText()=="海口"){
      ui->HomeC->clear();
      ui->HomeC->addItems(hc1);
      ui->HomeC->setCurrentIndex(0);

      ui->HomeL->clear();
      ui->HomeL->addItems(ha1);
    }
    else if(ui->HomeC->currentText()=="三亚"){
        ui->HomeC->clear();
        ui->HomeC->addItems(hc1);
        ui->HomeC->setCurrentIndex(1);

        ui->HomeL->clear();
        ui->HomeL->addItems(ha2);
    }
    else if(ui->HomeC->currentText()=="长沙"){
        ui->HomeC->clear();
        ui->HomeC->addItems(hc2);
        ui->HomeC->setCurrentIndex(0);

        ui->HomeL->clear();
        ui->HomeL->addItems(ha3);
    }
    else if(ui->HomeC->currentText()=="岳阳"){
        ui->HomeC->clear();
        ui->HomeC->addItems(hc2);
        ui->HomeC->setCurrentIndex(1);

        ui->HomeL->clear();
        ui->HomeL->addItems(ha4);
    }

}


//修改所在地
void UserInfo::on_LocalP_activated()
{

    if(ui->LocalP->currentText()=="湖北"){
        ui->LocalP->clear();
        ui->LocalP->addItems(lp);
         ui->LocalC->setCurrentIndex(0);

         ui->LocalC->clear();
         ui->LocalC->addItems(lc1);

         ui->LocalL->clear();
         ui->LocalL->addItems(la1);

    }
   else if(ui->LocalP->currentText()=="山东"){
        ui->LocalP->clear();
        ui->LocalP->addItems(lp);
        ui->LocalP->setCurrentIndex(1);

        ui->LocalC->clear();
        ui->LocalC->addItems(lc2);


        ui->LocalL->clear();
        ui->LocalL->addItems(la3);

}
}

void UserInfo::on_LocalC_activated()
{

    if(ui->LocalC->currentText()=="武汉"){
      ui->LocalC->clear();
      ui->LocalC->addItems(lc1);
      ui->LocalC->setCurrentIndex(0);

      ui->LocalL->clear();
      ui->LocalL->addItems(la1);
    }
    else if(ui->LocalC->currentText()=="襄阳"){
        ui->LocalC->clear();
        ui->LocalC->addItems(lc1);
        ui->LocalC->setCurrentIndex(1);

        ui->LocalL->clear();
        ui->LocalL->addItems(la2);
    }
    else if(ui->LocalC->currentText()=="济南"){
        ui->LocalC->clear();
        ui->LocalC->addItems(lc2);
        ui->LocalC->setCurrentIndex(0);

        ui->LocalL->clear();
        ui->LocalL->addItems(la3);
    }
    else if(ui->LocalC->currentText()=="青岛"){
        ui->LocalC->clear();
        ui->LocalC->addItems(lc2);
        ui->LocalC->setCurrentIndex(1);

        ui->LocalL->clear();
        ui->LocalL->addItems(la4);
    }

}
 //根据选择的月份判断天数
void UserInfo::on_MonthCombo_activated()
{
    int month;
    month = ui->MonthCombo->currentIndex();
     ui->DateCombo->clear();
    if(month==0||month==2||month==4||month==6||month==7||month==9||month==11){
    for(int date=1;date<=31;date++){
        ui->DateCombo->addItem(QString::number(date));
    }
        }
    else if(month==1){
        for(int date=1;date<=28;date++){
            ui->DateCombo->addItem(QString::number(date));
        }
    }
    else {
        for(int date=1;date<=30;date++){
            ui->DateCombo->addItem(QString::number(date));
    }
        }

}
     //最小化
void UserInfo::on_pushButton_clicked()
{
   this->showMinimized();
}
