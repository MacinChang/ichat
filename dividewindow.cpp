#include "dividewindow.h"
#include "ui_dividewindow.h"
#include "QtScript/QScriptValue"
#include "QtScript/QScriptEngine"
#include "QtScript/QScriptValueIterator"
DivideWindow::DivideWindow(QString myAccount, QString verifyInfo, QString data,QWidget *parent) :
    QDialog(parent),re(data), myAccount(myAccount), verifyInfo(verifyInfo),
    ui(new Ui::DivideWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate("value="+re);
    QScriptValueIterator it(sc);
    it.next();
    it.next();
    QString account=it.value().toString();
    ui->label_2->setText(account);
    it.next();
    QString nickname=it.value().toString();
    ui->label_8->setText(nickname);
    it.next();
    //设置头像，以后再写
    it.next();
    it.next();it.next();
    QString sex=it.value().toString();
    ui->label_5->setText("性别  "+sex);
    it.next();
    QString age=it.value().toString();
    ui->label_7->setText("年龄  "+age);
    it.next();it.next();it.next();
    QString location=it.value().toString();
    ui->label_6->setText("所在地  "+location);
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

DivideWindow::~DivideWindow()
{
    delete ui;
}

void DivideWindow::on_pushButton_2_clicked()
{
    this->close();
}

void DivideWindow::on_pushButton_clicked()
{
    QByteArray remark=ui->lineEdit->text().toLocal8Bit();
    QString s = ui->label_2->text();
    QByteArray to = ui->label_2->text().toLocal8Bit();
    QByteArray from  = myAccount.toLocal8Bit();
    QByteArray info = verifyInfo.toLocal8Bit();
    QUrl url("http://182.92.69.19/ichat-server/public/user/add-contact");
    //QByteArray append("account=66666&password=changsha");
    QByteArray append("from=" + from + "&to=" + to + "&info=" + info + "&remark=" + remark);
    QNetworkReply* reply = nam->post(QNetworkRequest(url), append);
    //发送添加好友消息

}
void DivideWindow::replyFinished(QNetworkReply *reply){
    QVariant vRes = reply->readAll();
    //QVariant codeV = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    QString  res = vRes.toString();
    if(res == "true"){
        this->close();
        afw = new AddFinishedWindow();
        afw->show();
    }
}
