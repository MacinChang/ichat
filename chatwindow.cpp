#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "userlistitem.h"
#include <qdatetime.h>
#include "QFileDialog"
#include "QPixmap"
#include "QBitmap"
#include "QLabel"
#include "QDebug"
ChatWindow::ChatWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    m_animation = new QPropertyAnimation(this,"pos");
    //添加好友头像，昵称和个性签名
    UserListItem *myitem = new UserListItem(this);
    myitem->move(5, 5);
    //隐藏录音
    ui->textEdit->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    //自己的头像和好友头像
    myHead="F:/qiyi/banben2/resource/myHead.png";
    imgPathToHtml(myHead);
    //初始化传输文件相关数据
    ui->textEdit_2->hide();
    ui->label->hide();
    ui->progressBar->hide();
    loadSize = 4 * 1024;
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    tcpClient = new QTcpSocket(this);
    //当连接服务器成功时，发出connected()信号，我们开始传送文件
    connect(tcpClient,SIGNAL(connected()),this,SLOT(startTransfer()));
    //当有数据发送成功时，我们更新进度条
    connect(tcpClient,SIGNAL(bytesWritten(qint64)),this,
           SLOT(updateClientProgress(qint64)));
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,
           SLOT(displayError(QAbstractSocket::SocketError)));
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

//发送文件
void ChatWindow::on_pushButton_12_clicked()
{
    fileName = QFileDialog::getOpenFileName(this);
    bytesWritten = 0;
    //初始化已发送字节为0
     if(!fileName.isEmpty())
     {
         tcpClient->connectToHost(friIp, friPort);
     }

}

void ChatWindow::startTransfer()
{
    localFile = new QFile(fileName);
   if(!localFile->open(QFile::ReadOnly))
   {
      qDebug() << "open file error!";
      return;
   }

   //文件总大小
   totalBytes = localFile->size();

   QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
   sendOut.setVersion(QDataStream::Qt_5_4);
   QString currentFileName = fileName.right(fileName.size()
                                            - fileName.lastIndexOf('/') - 1);

   //依次写入总大小信息空间，文件名大小信息空间，文件名
   sendOut << qint64(0) << qint64(0) << currentFileName;

   //这里的总大小是文件名大小等信息和实际文件大小的总和
   totalBytes += outBlock.size();

   sendOut.device()->seek(0);
   //返回outBolock的开始，用实际的大小信息代替两个qint64(0)空间
   sendOut<<totalBytes<<qint64((outBlock.size() - sizeof(qint64)*2));

   //发送完头数据后剩余数据的大小
   bytesToWrite = totalBytes - tcpClient->write(outBlock);
   outBlock.resize(0);
}

void ChatWindow::displayError(QAbstractSocket::SocketError){
    qDebug() << tcpClient->errorString();
        tcpClient->close();
}

void ChatWindow::on_pushButton_clicked()
{
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
        //每条消息前查个头像
        ui->textBrowser->insertHtml(myHead);
        ui->textBrowser->append(c);
        ui->textBrowser->insertHtml(picbath);
        ui->textBrowser_2->clear();
    }
}

//发送数据，更新数据条
void ChatWindow::updateClientProgress(qint64 numBytes)
{
    ui->label->show();
    ui->progressBar->show();
    ui->textEdit_2->show();
    //已经发送数据的大小
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0) //如果已经发送了数据
    {
   //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
   //就发送剩余数据的大小
       outBlock = localFile->read(qMin(bytesToWrite,loadSize));

       //发送完一次数据后还剩余数据的大小
       bytesToWrite -= (int)tcpClient->write(outBlock);

       //清空发送缓冲区
       outBlock.resize(0);

    } else {
       localFile->close(); //如果没有发送任何数据，则关闭文件
    }

    //更新进度条
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesWritten);

    if(bytesWritten == totalBytes) //发送完毕
    {
       localFile->close();
       tcpClient->close();
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
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("选择本地图片"),
                                                    "",
                                                    tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    imgPathToHtml(fileName);
    ui->textBrowser_2->insertHtml(fileName);
    picbath=fileName;
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
    m_animation->setEndValue(pos);
    m_animation->start();
}

//准备录音了
void ChatWindow::on_pushButton_6_clicked()
{
    ui->textEdit->show();
    ui->pushButton_8->show();
    ui->pushButton_9->show();
    ui->pushButton_10->show();
    ui->pushButton_11->show();
    outputFile.setFileName("test.raw");
    outputFile.open(QIODevice::ReadWrite | QIODevice::Truncate);
    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if(!info.isFormatSupported(format))
    {
        qDebug()<<"format is not support try to use nearest";
        format=info.nearestFormat(format);
    }
    audio = new QAudioInput(format, this);
    audio->start(&outputFile);
    qDebug()<<"start recording";
}

//停止录音
void ChatWindow::on_pushButton_9_clicked()
{
    audio->stop();
    outputFile.close();
    delete audio;
    qDebug()<<"record end";
}

//播放录音
void ChatWindow::on_pushButton_8_clicked()
{
    inputFile.setFileName("test.raw");
    inputFile.open(QIODevice::ReadOnly);
    QAudioFormat format;
    format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    if(!info.isFormatSupported(format))
    {
        qDebug()<<"don't support and return";
        return;
    }
    audio2 = new QAudioOutput(format,this);
    connect(audio2,SIGNAL(stateChanged(QAudio::State)),this,SLOT(finishedPlaying(QAudio::State)));
    audio2->start(&inputFile);
    qDebug()<<"start play";
}

//发送录音
void ChatWindow::on_pushButton_10_clicked()
{

}

//取消录音
void ChatWindow::on_pushButton_11_clicked()
{
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->textEdit->hide();
    audio2->stop();
    inputFile.close();
    delete audio2;
}

void ChatWindow::finishedPlaying(QAudio::State state)
{
    if(state == QAudio::IdleState)
    {
        audio2->stop();
        inputFile.close();
        delete audio2;
        qDebug()<<"play finished";
    }
}

//自定义头像按钮
QPushButton *ChatWindow::custButton(QString str)
{
    QPushButton *pushButton= new QPushButton;

    //pushButton->setGeometry(10,10,200,200); //按钮的位置及大小
    pushButton->clearMask();
    pushButton->setBackgroundRole( QPalette::Base);

    QPixmap mypixmap;   mypixmap.load(str);
    pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    pushButton->setFixedSize( mypixmap.width(), mypixmap.height() );
    pushButton->setMask(mypixmap.createHeuristicMask());
    pushButton->setIcon(mypixmap);
    pushButton->setIconSize(QSize(mypixmap.width(),mypixmap.height()));
    return pushButton;
}


