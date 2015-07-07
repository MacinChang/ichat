#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include <QMouseEvent>
#include <QFrame>
#include "QPushButton"
#include "QPropertyAnimation"
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QAudioInput>
#include <QTimer>
#include <QAudioOutput>
#include "QTcpSocket"
namespace Ui {
class ChatWindow;
}

class ChatWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();
    QPropertyAnimation *m_animation;
    void imgPathToHtml(QString &path);
    void ShakeAnimation();
    QPushButton *custButton(QString str);
    QString picbath;
    QString myHead;     //用于存放自己的头像
    QString friHead;    //用于存放好友的头像
private:
    Ui::ChatWindow *ui;
    QFile outputFile;
    QAudioInput *audio;
    QFile inputFile;
    QAudioOutput *audio2;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void finishedPlaying(QAudio::State);
    void startTransfer();
    void updateClientProgress(qint64); //发送数据，更新进度条
    void displayError(QAbstractSocket::SocketError); //显示错误
private:
    QTcpSocket *tcpClient;
    QFile *localFile;
    qint64 totalBytes;  //数据总大小
    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小
    QString fileName;  //保存文件路径
    QByteArray outBlock;
    QString friIp;      //存放好友ip
    int friPort;        //存放端口

};

#endif // CHATWINDOW_H
