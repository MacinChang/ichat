#include "logindialog.h"
#include "ui_logindialog.h"
#include "mainpanel.h"
#include <QObject>
#include <QString>
#include <QMessageBox>
#include <QDesktopServices>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //this->setFixedSize(860, 670);
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SubWindow);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    QUrl url("http://182.92.69.19/ichat-server/public/user/login");


    account = ui->usrLineEdit->text();
    password = ui->pwdLineEdit->text();

    QByteArray usr = account.toLocal8Bit();
    QByteArray pwd = password.toLocal8Bit();
    QByteArray append("account="+usr+"&password="+pwd);
    QNetworkReply* reply = nam->post(QNetworkRequest(url), append);
    QString s;
}

void LoginDialog::replyFinished(QNetworkReply *reply){
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();
    if(res == "false"){
        //ui->textBrowser_2->setText(res);
        QMessageBox::warning(this, tr("Waring"),
                                    tr("user name or password error!"),
                                    QMessageBox::Yes);
              // 清空内容并定位光标
              ui->usrLineEdit->clear();
              ui->pwdLineEdit->clear();
              ui->usrLineEdit->setFocus();
    }
    else{
        MainPanel *mp = new MainPanel(account);
        mp->show();
        this->close();

    }

}



void LoginDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = QPoint(-1, -1);
        event->accept();
    }
}

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() &Qt::LeftButton)
    {
        if (dragPosition != QPoint(-1, -1))
            move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void LoginDialog::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("http://182.92.69.19/ichat-server/public/user/register")));
}

void LoginDialog::on_closeBtn_clicked()
{
    accept();
}
