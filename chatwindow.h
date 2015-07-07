#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMouseEvent>
#include <QFrame>
#include "QPropertyAnimation"
#include "msgnode.h"
#include <QUdpSocket>
namespace Ui {
class ChatWindow;
}

class ChatWindow : public QFrame
{
    Q_OBJECT
private:
     QUdpSocket *sendUdpSocket;
     QString selfAccount;
     QString contactAccount;
    //QTcpServer *tcpServer;
public:
    QString getContactAccount();
    explicit ChatWindow(QString selfAccount, QString contactAccount, QWidget *parent = 0);
    ~ChatWindow();
    QPropertyAnimation *m_animation;
    void imgPathToHtml(QString &path);
    void ShakeAnimation();
private:
    Ui::ChatWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    //void readBackData();
private slots:
    void readBackData();
public:
    void sendTextMessage(QString content);
    void receiveMessage(QVector<MsgNode> messages);

 };

#endif // CHATWINDOW_H
