#include "chatmsgdlg.h"
#include "ui_chatmsgdlg.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "chatwindow.h"

chatMsgDlg::chatMsgDlg(QString a,QString b,QWidget *parent) :
    QWidget(parent),a(a),b(b),
    ui(new Ui::chatMsgDlg)
{
    ui->setupUi(this);


    //隐藏标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->label_3->setText("<font color=white>聊天记录</font>");

    QSqlQuery query;
    QString command1 = "select id,time,speakerId,listenerId,chatmessage from chatmsg where speakerId= \""+a+"\" and listenerId = \""+b+"\" or speakerId= \""+b+"\" and listenerId = \""+a+"\"";
    query.exec(command1);

    //query.next()指向查找到的第一条记录，然后每次后移一条记录
    while(query.next())
    {
        //query.value(0)是id的值，将其转换为int型
        int value0 = query.value(0).toInt();
        QString value1 = query.value(1).toString();
        QString value2 = query.value(2).toString();
        QString value4 = query.value(4).toString();
        //输出两个值

        ui->textBrowser->append(value2+"("+value1+")");
        ui->textBrowser->append(value4);
    }
    dragPosition = QPoint(-1,-1);
    QIcon icon(":/images/image/logo.png");
    this->setWindowIcon(icon);
    this->setWindowTitle("聊天记录");
}

chatMsgDlg::~chatMsgDlg()
{
    delete ui;
}

void chatMsgDlg::on_pushButton_clicked()
{
    this->close();
}
void chatMsgDlg::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = e->globalPos()-frameGeometry().topLeft();
        QPoint p = e->pos();
        e->accept();
    }
    else dragPosition = QPoint(-1,-1);
}

void chatMsgDlg::mouseMoveEvent(QMouseEvent *e)
{
    if(dragPosition != QPoint(-1,-1)){
        move(e->globalPos()-dragPosition);
    }
    e->accept();

}
void chatMsgDlg::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = QPoint(-1,-1);
        e->accept();
    }
}
