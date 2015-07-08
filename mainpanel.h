#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QFrame>
#include "addwindow.h"
#include "useritem.h"
#include "chatwindow.h"
#include "friendinfo.h"
#include "msgnode.h"
#include <QStandardItemModel>
#include <QTreeView>
#include <QMouseEvent>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QVector>
#include <QUdpSocket>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include "changegroupdialog.h"
#include <QTcpSocket>
#include <QTcpServer>
#include <QNetworkInterface>
#include <QList>

namespace Ui {
class MainPanel;
}

class MainPanel : public QFrame
{
    Q_OBJECT

public:
    explicit MainPanel(QString account,QWidget *parent = 0);
    ~MainPanel();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void checkMessage(QString msg);
    void checkAudio(QString contact);
    void checkFile(QString contact);
    ChatWindow* checkChatWindow(QString contact);

private slots:
    void on_btnAddContacts_clicked();

    void on_btnContact_clicked();

    void on_btnGroup_clicked();

    void on_minBtn_clicked();

    void on_closeBtn_clicked();

public slots:
    void displayError(QAbstractSocket::SocketError);

    void replyFinished(QNetworkReply *reply);
    void delReplyFinished(QNetworkReply *reply);
    void remarkReplyFinished(QNetworkReply *reply);
    void stateReplyFinished(QNetworkReply *reply);
    void renGroupReplyFinished(QNetworkReply *reply);
    void delGroupReplyFinished(QNetworkReply *reply);
    void newGroupReplyFinished(QNetworkReply *reply);
    void changeGroupReplyFinished(QNetworkReply *reply);
    void closeStateReplyFinished(QNetworkReply *reply);

    void on_contact_doubleClicked(const QModelIndex &index);
    void on_group_doubleClicked(const QModelIndex &index);
    void on_contact_rightClicked(const QPoint &point);
    void on_group_rightClicked(const QPoint &point);

    void receiveGroupRename(QString name);
    void receiveContactRename(QString name);
    void receiveNewGroup(QString newGroup);

    void on_comboBox_changed(const QString & text);
    void on_group_changed(QString classid);

    void on_Action_newGroup();

    void on_fenzuAction_reName();
    void on_fenzuAction_delete();

    void on_cAction_chat();
    void on_cAction_scanInfo();
    void on_cAction_reName();
    void on_cAction_reGroup();
    void on_cAction_delete();

    void on_gAction_chat();
    void on_gAction_modify();
    void on_gAction_quit();

    void receiveData();
    void receiveFile();


private:
    Ui::MainPanel *ui;
    AddWindow *addDlg;
    ChangeGroupDialog *changeDlg;
    UserItem *myself;
    QPoint dragPosition;
    QStandardItemModel *contactModel,*groupModel;
    QTreeView *contactTreeView,*groupTreeView;
    QNetworkAccessManager *manager;
    QVector<QString> class_id;

    QVector <ChatWindow*> cws;
    QUdpSocket *receiveUdpSocket;
    FriendInfo *selfFI;

    QTcpSocket *fileClient;
    QByteArray fileReceive;

    QString myAccount;
    QIcon myHead;
    QString myName;
    QString mySignature;
    QString myState;
    int flag;
    int fileSize;
    int receiveSize;
    QString fileName;
    QFile *localFile;
    QString fileType;
    QString fileContact = "";

public:
    static QVector<FriendInfo*> fis;
};


#endif // MAINPANEL_H
