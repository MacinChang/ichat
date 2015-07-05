#include "confirmwindow.h"
#include "ui_confirmwindow.h"
#include "QtScript/QScriptValue"
#include "QtScript/QScriptEngine"
#include "QtScript/QScriptValueIterator"
confirmWindow::confirmWindow(QString myAccount, QString data,QWidget *parent) :
    QDialog(parent),receivedData(data), myAccount(myAccount),
    ui(new Ui::confirmWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate("value="+receivedData);
    QScriptValueIterator it(sc);

    it.next();
    it.next();
    QString account=it.value().toString();
    ui->label_2->setText(account);
    it.next();
    QString nickname=it.value().toString();
    ui->label->setText(nickname);
    it.next();
    //设置头像，以后再写
    it.next();
    it.next();it.next();
    QString sex=it.value().toString();
    ui->label_4->setText("性别  "+sex);
    it.next();
    QString age=it.value().toString();
    ui->label_5->setText("年龄  "+age);
    it.next();it.next();it.next();
    QString location=it.value().toString();
    ui->label_6->setText("所在地  "+location);
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

confirmWindow::~confirmWindow()
{
    delete ui;
}


void confirmWindow::on_pushButton_clicked()
{
    QByteArray info =ui->textBrowser->toPlainText().toLocal8Bit();//获取验证信息
    QByteArray from = myAccount.toLocal8Bit();
   // QByteArray to =
    dw=new DivideWindow(receivedData);
    dw->show();
}
void confirmWindow::replyFinished(QNetworkReply *){

}

void confirmWindow::on_pushButton_2_clicked()
{
    this->close();
}
