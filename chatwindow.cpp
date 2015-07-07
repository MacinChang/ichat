#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "userlistitem.h"
#include <qdatetime.h>
#include "QFileDialog"
ChatWindow::ChatWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    m_animation = new QPropertyAnimation(this,"pos");
    UserListItem *myitem = new UserListItem(this);
    myitem->move(5, 5);
    //sender = new QUdpSocket(this);
    //connect(sender, SIGNAL(readyRead()),this, SLOT(readBackData()));
    receiveUdpSocket = new QUdpSocket(this);
    connect(receiveUdpSocket, SIGNAL(readyRead()),this, SLOT(receiveData()));
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::receiveData(){
    QByteArray data;
    //while(receiveUdp)
    while(receiveUdpSocket->hasPendingDatagrams()){
            data.resize(receiveUdpSocket->pendingDatagramSize());
            QHostAddress addr;
            quint16 port;
            receiveUdpSocket->readDatagram(data.data(), data.size(), &addr, &port);
        }
    QString str = data.data();
    ui->textBrowser_2->setText(str);
    QByteArray self = "12345";
    QByteArray datas("{\"user_id\":" + self + ",\"u\":\"receive\"}");
    receiveUdpSocket->writeDatagram(datas.data(), datas .size(), QHostAddress::LocalHost, 10008);
}

void ChatWindow::on_pushButton_clicked()
{
    QByteArray self = "12345";
    QByteArray data("{\"user_id\":" + self + ",\"u\":\"receive\"}");
    receiveUdpSocket->writeDatagram(data.data(), data.size(), QHostAddress::LocalHost, 10008);
    //获取系统现在的时间并设置显示格式
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("hh:mm:ss");
    //显示时间和聊天记录........
    QString c=ui->textBrowser_2->toPlainText();
    if(c!=NULL)
    {
        //ui->textBrowser->setAlignment(Qt::AlignHCenter); //时间居中
        ui->textBrowser->append(current_date);
        //ui->textBrowser->setAlignment(Qt::AlignRight); //发送的信息右对齐
        ui->textBrowser->append(c);
        ui->textBrowser_2->clear();
    }
}

//将图片路径转换为html
void ChatWindow::imgPathToHtml(QString &path)
    {
         path = QString("<img src=\"%1\"/>").arg(path);
    }

//点击发送图片按钮的处理函数
void ChatWindow::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    imgPathToHtml(fileName);
    ui->textBrowser_2->insertHtml(fileName);
}

//点击抖动按钮处理的函数
void ChatWindow::on_pushButton_4_clicked()
{
    ShakeAnimation();
}

//窗口抖动实现
void ChatWindow::ShakeAnimation()
{
    QPoint pos = this->pos();
//动画还没有结束就先立马停止，防止用户不停的点击
    if(m_animation->state() == QPropertyAnimation::Running)
    {
        m_animation->stop();
    }
    m_animation->setDuration(500);
    m_animation->setStartValue(pos);
    m_animation->setKeyValueAt(0.1,pos + QPoint(-5,-5));
    m_animation->setKeyValueAt(0.2,pos + QPoint(0,-5));
    m_animation->setKeyValueAt(0.3,pos + QPoint(5,0));
    m_animation->setKeyValueAt(0.4,pos + QPoint(6,1));
    m_animation->setKeyValueAt(0.5,pos + QPoint(7,-7));
    m_animation->setKeyValueAt(0.6,pos + QPoint(-6,6));
    m_animation->setKeyValueAt(0.7,pos + QPoint(-8,0));
    m_animation->setKeyValueAt(0.8,pos + QPoint(0,6));
    m_animation->setKeyValueAt(0.9,pos + QPoint(4,2));
    m_animation->setKeyValueAt(1.0,pos + QPoint(-5,-5));
    m_animation->setKeyValueAt(1.1,pos + QPoint(0,-5));
    m_animation->setKeyValueAt(1.2,pos + QPoint(5,0));
    m_animation->setKeyValueAt(1.3,pos + QPoint(6,1));
    m_animation->setKeyValueAt(1.4,pos + QPoint(7,-7));
    m_animation->setKeyValueAt(1.5,pos + QPoint(-6,6));
    m_animation->setKeyValueAt(1.6,pos + QPoint(-8,0));
    m_animation->setKeyValueAt(1.7,pos + QPoint(0,6));
    m_animation->setKeyValueAt(1.8,pos + QPoint(4,2));
    m_animation->setEndValue(pos);
    m_animation->start();
}
