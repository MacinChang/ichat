#include "addwindow.h"
#include "ui_addwindow.h"
#include "QtScript/QScriptValue"
#include "QtScript/QScriptEngine"
#include "QtScript/QScriptValueIterator"
AddWindow::AddWindow(QString myAccount, QWidget *parent) :
    QFrame(parent), myAccount(myAccount),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(clicked()), this, SLOT(headPressEventSlot()));
    ui->label->setText("<font color=white>请输入ichat号：</font>");
    ui->label_2->hide();
    ui->faceButton->hide();
    ui->label_4->hide();
    ui->pushButton_2->hide();
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
    this,SLOT(replyFinished(QNetworkReply*)));
    this->setWindowFlags(Qt::FramelessWindowHint);
}

AddWindow::~AddWindow()
{
    delete ui;
}

//获取要查找的帐号。。。及查找
void AddWindow::on_pushButton_clicked()
{
    //获取输入的帐号
    QString s;
    s=ui->lineEdit->text();
    s="account="+s;
    //到服务器数据库去查。。。
    QUrl url("http://182.92.69.19/ichat-server/public/user/find-contact");
    QByteArray append=s.toLatin1();
    manager->post(QNetworkRequest(url),append);
  /*  bool IsFind=0;   //用来判断是否有该用户
    if(IsFind)
    {
    AddItems *myitem = new AddItems(ui->listWidget);
    myitem->move(0,0);
    }
    else
    {
        QLabel * text=new QLabel(ui->listWidget);
        text->setText(QObject::tr("不存在该用户,请重新输入！"));

        text->show();
    }*/
}

void AddWindow::replyFinished(QNetworkReply *reply)
{
    QVariant statusCodev = reply->readAll();
    str = statusCodev.toString();
    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate("value="+str);
    QScriptValueIterator it(sc);
    it.next();
    QString Id=it.value().toString();
    if(Id=="Parse error")
    {
        ui->textBrowser->clear();
        ui->label_2->hide();
        ui->faceButton->hide();
        ui->label_4->hide();
        ui->pushButton_2->hide();
        QString c="不存在该用户，请重新输入";
        ui->textBrowser->setText(c);
    }
    else{
        ui->textBrowser->clear();
        it.next();
        it.next();
        QString nickname=it.value().toString();
        ui->label_2->setText(nickname);
        it.next();
        //头像处理
        QByteArray head,face;
                QString str(it.value().toString());
                int j = str.indexOf('-');
                while(j!=-1){
                    str[j] = '+';
                    j = str.indexOf('-');
                }
                head = QByteArray::fromBase64(str.toLatin1());
                face = qUncompress(head);
                QImage img;
                img.loadFromData(face);
                ui->faceButton->setIcon(QPixmap::fromImage(img));


        it.next();
        QString signature=it.value().toString();
        ui->label_4->setText(signature);
        ui->label_2->show();
        ui->faceButton->show();
        ui->label_4->show();
        ui->pushButton_2->show();
    }
    /*while (it.hasNext()){
        it.next();
        qDebug()<<it.name()<<":"<<it.value().toString();
    }*/
}


//显示资料卡
void AddWindow::on_faceButton_clicked()
{

}

//添加好友
void AddWindow::on_pushButton_2_clicked()
{
    cw=new confirmWindow(str, myAccount);
    cw->show();
}
