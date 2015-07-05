#include "dividewindow.h"
#include "ui_dividewindow.h"
#include "QtScript/QScriptValue"
#include "QtScript/QScriptEngine"
#include "QtScript/QScriptValueIterator"
DivideWindow::DivideWindow(QString data,QWidget *parent) :
    QDialog(parent),re(data),
    ui(new Ui::DivideWindow)
{
    ui->setupUi(this);
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
    QString remark=ui->lineEdit->text();
    //发送添加好友消息

}
