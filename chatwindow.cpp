#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <qdatetime.h>
#include "QFileDialog"
#include "QPixmap"
#include "QBitmap"
#include "QLabel"
#include "QDebug"
#include "QScriptEngine"
#include "QScriptValue"
#include "QScriptValueIterator"
ChatWindow::ChatWindow(QString selfAccount, QString contactAccount,QString myName, QWidget *parent) :
    QFrame(parent), selfAccount(selfAccount), contactAccount(contactAccount),myName(myName),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    friIp = "127.0.0.1";
    friPort = 6666;
    dragPosition=QPoint(-1,-1);
    m_animation = new QPropertyAnimation(this,"pos");
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    this->setWindowFlags(Qt::FramelessWindowHint);
    //添加好友头像，昵称和个性签名
    manager1=new QNetworkAccessManager(this);
    QObject::connect(manager1, SIGNAL(finished(QNetworkReply*)),
                       this, SLOT(finishedSlot(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/get-info");
    QByteArray MyAccount = contactAccount.toLocal8Bit();
    QByteArray append("account="+MyAccount);
    QNetworkReply* reply = manager1->post(QNetworkRequest(url),append);
    //发送信息槽函数绑定
    sendUdpSocket = new QUdpSocket(this);
    connect(sendUdpSocket, SIGNAL(readyRead()), this, SLOT(readBackData()));

    //隐藏录音
    ui->textEdit->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->listenButton->hide();
    //自己的头像和好友头像
    myHead="head";
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
         friIp = "182.92.69.19";
         friPort = 6666;
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



   QString currentFileName = fileName.right(fileName.size()
                                            - fileName.lastIndexOf('/') - 1);

   //依次写入总大小信息空间，文件名大小信息空间，文件名


   //这里的总大小是文件名大小等信息和实际文件大小的总和
   totalBytes += outBlock.size();

    QByteArray  user_id  = selfAccount.toLocal8Bit();
    QByteArray contact_id = contactAccount.toLocal8Bit();
    outBlock = "{\"user_id\":" + user_id + ", \"filename\":\"" + currentFileName.toLocal8Bit().toBase64()
           + "\", \"contact_id\":" + contact_id + ", \"type\":\"audio\", \"u\":\"send\"}";

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
    QString current_date = current_date_time.toString(" hh:mm:ss");
    //显示时间和聊天记录........
    QString c=ui->textBrowser_2->toPlainText();
    if(c!=NULL)
    {
        //ui->textBrowser->setAlignment(Qt::AlignHCenter); //时间居中
        ui->textBrowser->append(myName+current_date);
        //ui->textBrowser->setAlignment(Qt::AlignRight); //发送的信息右对齐
        //每条消息前查个头像
        ui->textBrowser->append(c);
        //ui->textBrowser_2->clear();
        sendTextMessage(c);
    }
}

void ChatWindow::sendTextMessage(QString content){
    QDateTime current_date_time = QDateTime::currentDateTime();
    //current_date_time.to
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QByteArray time = current_date.toLocal8Bit();
    QByteArray from = selfAccount.toLocal8Bit();
    QByteArray to = contactAccount.toLocal8Bit();
    QByteArray textP = content.toLocal8Bit();
    QByteArray text = textP.toBase64(QByteArray::Base64UrlEncoding | QByteArray::OmitTrailingEquals);
    QByteArray data("{\"user_id\":" + from + ", \"contact_id\":" + to +", \"time\":\"" + time +"\", \"content\":\"" + text + "\", \"u\":\"send\"}");
    sendUdpSocket->writeDatagram(data.data(), data.size(), QHostAddress("182.92.69.19"), 10008);
}

void ChatWindow::readBackData(){
    QByteArray data;
    while(sendUdpSocket->hasPendingDatagrams()){
            data.resize(sendUdpSocket->pendingDatagramSize());
            QHostAddress addr;
            quint16 port;
            sendUdpSocket->readDatagram(data.data(), data.size(), &addr, &port);
            //processTheDatagram
            //processTheDatagram(data);
        }
    QString str = data.data();
    if(str == "true"){
        ui->textBrowser_2->clear();
    }
}

void ChatWindow::finishedSlot(QNetworkReply *reply)
{
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
        ui->faceButton->setIcon(QPixmap::fromImage(img));
        ui->nameLabel->setText(usrInfo[2]);
        friName=usrInfo[2];
        ui->signalLabel->setText(usrInfo[4]);
}

void ChatWindow::receiveAudio(QFile *file){
    ui->listenButton->show();
    audioReceive = file;
}

void ChatWindow::receiveFile(QFile *file)
{
//    ui->fileButton->show();
//    fileReceive = file;
}

void ChatWindow::receiveMessage(QVector<MsgNode> messages){
    for(int i = 0; i < messages.size(); i++){
        ui->textBrowser->append(messages[i].time);
        //ui->textBrowser->setAlignment(Qt::AlignRight); //发送的信息右对齐
        QByteArray content = QByteArray::fromBase64(messages[i].content.toLocal8Bit(), QByteArray::Base64UrlEncoding | QByteArray::OmitTrailingEquals);
        ui->textBrowser->append(content);
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

QString ChatWindow::getContactAccount(){
    return contactAccount;
}


//准备录音
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
    fileName = "test.raw";
    tcpClient->connectToHost(friIp, friPort);
}

//取消录音
void ChatWindow::on_pushButton_11_clicked()
{
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->textEdit->hide();
    audio->stop();
    outputFile.close();
    delete audio;
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

//点击好友头像，显示好友资料
void ChatWindow::on_faceButton_clicked()
{

}

void ChatWindow::on_minButton_clicked()
{
    this->showMinimized();
}

//关闭窗口按钮
void ChatWindow::on_closeButton_clicked()
{
    //

    this->close();
}


void ChatWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = e->globalPos()-frameGeometry().topLeft();
        QPoint p = e->pos();
        e->accept();
    }
    else dragPosition = QPoint(-1,-1);
}

void ChatWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(dragPosition != QPoint(-1,-1)){
        move(e->globalPos()-dragPosition);
    }
    e->accept();

}
void ChatWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = QPoint(-1,-1);
        e->accept();
    }
}


void ChatWindow::on_pushButton_2_clicked()
{
    this->close();
}

void ChatWindow::on_listenButton_clicked()
{
    //inputFile.setFileName("test.raw");  //test.raw录音文件名
    audioReceive->setFileName("test.raw");
    if(!audioReceive->open(QIODevice::ReadOnly)){
        qDebug() << "wrong";
    }
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
    audio2->start(audioReceive);
    qDebug()<<"start play";
}
