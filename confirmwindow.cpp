#include "confirmwindow.h"
#include "ui_confirmwindow.h"
#include "QtScript/QScriptValue"
#include "QtScript/QScriptEngine"
#include "QtScript/QScriptValueIterator"
confirmWindow::confirmWindow(QString data, QString myAccount, QWidget *parent) :
    QDialog(parent),receivedData(data), myAccount(myAccount),
    ui(new Ui::confirmWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
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
    //设置头像
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
    it.next();it.next();
    QString sex=it.value().toString();
    ui->label_4->setText("性别  "+sex);
    it.next();
    QString age=it.value().toString();
    ui->label_5->setText("年龄  "+age);
    it.next();it.next();it.next();
    QString location=it.value().toString();
    ui->label_6->setText("所在地  "+location);
}

confirmWindow::~confirmWindow()
{
    delete ui;
}


void confirmWindow::on_pushButton_clicked()
{
    QString info =ui->textBrowser->toPlainText();//获取验证信息
    dw=new DivideWindow(myAccount, info, receivedData);
    dw->show();
    this->close();
}


void confirmWindow::on_pushButton_2_clicked()
{
    this->close();
}

