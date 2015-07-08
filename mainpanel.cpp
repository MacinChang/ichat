#include "mainpanel.h"
#include "useritem.h"
#include "addwindow.h"
#include "ui_mainpanel.h"
#include <QDesktopWidget>
#include "QListWidget"
#include "QMenu"
#include "renamedialog.h"
#include "deleteconfirmdialog.h"
#include "QDebug"
#include "newgroupdialog.h"


QVector<FriendInfo*> MainPanel::fis;
QPixmap convertToGray(QImage image){

    int w,h;
    w = image.width();
    h = image.height();
    QImage iGray(w,h,QImage::Format_RGB32);
    for(int i=0; i<w; i++){
        for(int j=0;j<h; j++){
            QRgb pixel = image.pixel(i,j);
            int gray = qGray(pixel);
            QRgb grayPixel = qRgb(gray,gray,gray);
            iGray.setPixel(i,j,grayPixel);
        }
    }
    QPixmap a = QPixmap::fromImage(iGray);
    return a;
}

MainPanel::MainPanel(QString account, QWidget *parent) :
    QFrame(parent),myAccount(account),
    ui(new Ui::MainPanel)
{
    ui->setupUi(this);

    dragPosition = QPoint(-1,-1);
    this->setFixedSize(this->size());
    receiveUdpSocket = new QUdpSocket(this);
    connect(receiveUdpSocket, SIGNAL(readyRead()),this, SLOT(receiveData()));
    QByteArray self = myAccount.toLocal8Bit();
    QByteArray data("{\"user_id\":" + self + ",\"u\":\"receive\"}");
    receiveUdpSocket->writeDatagram(data.data(), data.size(), QHostAddress("182.92.69.19"), 10008);
    //主窗口相关设置
    QRect deskRect = QApplication::desktop()->availableGeometry();
    this->move(deskRect.right()-350,30);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QIcon winIcon(":/images/image/ichat.png");
    this->setWindowIcon(winIcon);
    this->setWindowTitle("iChat");

    //添加self
    myself = new UserItem(this);
    myself->setGeometry(33,54,240,70);
    myself->show();
    myState = "online";
    connect(myself,SIGNAL(comboBoxCurrentIndexChanged(const QString)),this,SLOT(on_comboBox_changed(const QString)));

    //添加好友窗口初始化
    addDlg = new AddWindow(myAccount);
    //修改分组窗口初始化
    changeDlg = new ChangeGroupDialog(this);
    changeDlg->hide();
    connect(changeDlg,SIGNAL(changeBtn_clicked(QString)),this,SLOT(on_group_changed(QString)));



    //联系人TreeView
    contactTreeView = new QTreeView(this);
    contactTreeView->setGeometry(1,152,297,395);
    contactTreeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    contactTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    contactTreeView->setHeaderHidden(true);
    contactTreeView->setEditTriggers(0);
    //联系人model
    contactModel = new QStandardItemModel(contactTreeView);
    contactTreeView->setModel(contactModel);
    //关联右键点击槽
    connect(contactTreeView,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(on_contact_rightClicked(const QPoint)));
    //关联双击槽
    connect(contactTreeView,SIGNAL(doubleClicked(const QModelIndex)),this,SLOT(on_contact_doubleClicked(const QModelIndex)));

    contactTreeView->show();



    //群TreeView
    groupTreeView = new QTreeView(this);
    groupTreeView->hide();
    groupTreeView->setGeometry(1,152,297,395);
    groupTreeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    groupTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    groupTreeView->setHeaderHidden(true);
    groupTreeView->setEditTriggers(0);
    //群model
    groupModel = new QStandardItemModel(groupTreeView);
    groupTreeView->setModel(groupModel);
    //关联右键点击槽
    connect(groupTreeView,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(on_group_rightClicked(const QPoint)));
    //关联双击槽
    connect(groupTreeView,SIGNAL(doubleClicked(const QModelIndex)),this,SLOT(on_group_doubleClicked(const QModelIndex)));

    groupTreeView->hide();


    //请求数据
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    QNetworkReply* reply = manager->post(QNetworkRequest(url), append);
}

MainPanel::~MainPanel()
{
    delete ui;
}

//以下三个函数实现窗口拖动
void MainPanel::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = e->globalPos()-frameGeometry().topLeft();
        QPoint p = e->pos();
        e->accept();
    }
    else dragPosition = QPoint(-1,-1);
}

void MainPanel::mouseMoveEvent(QMouseEvent *e)
{
    if(dragPosition != QPoint(-1,-1)){
        move(e->globalPos()-dragPosition);
    }
    e->accept();

}
void MainPanel::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = QPoint(-1,-1);
        e->accept();
    }
}
void MainPanel::receiveData(){
    QByteArray data;
    //while(receiveUdp)
    while(receiveUdpSocket->hasPendingDatagrams()){
            data.resize(receiveUdpSocket->pendingDatagramSize());
            QHostAddress addr;
            quint16 port;
            receiveUdpSocket->readDatagram(data.data(), data.size(), &addr, &port);
        }
    //QString str = data.data();
    checkMessage(data.data());
    //ui->textBrowser_2->setText(str);
    QByteArray self = myAccount.toLocal8Bit();
    QByteArray datas("{\"user_id\":" + self + ",\"u\":\"receive\"}");
    receiveUdpSocket->writeDatagram(datas.data(), datas .size(), QHostAddress("182.92.69.19"), 10008);

}
void MainPanel::checkMessage(QString msg){
    QVector<MsgNode> messages;
    QString x = "Nine pineapples";
    QString y = x.mid(5, 4);            // y == "pine"
    QString z = x.mid(5);               // z == "pineapples"
    int p = msg.indexOf("{", 0);
    while(p != -1){
        int q = msg.indexOf("}", p + 1);
        QString t = msg.mid(p, q - p + 1);
        QJsonParseError error;
        QJsonDocument document = QJsonDocument::fromJson(t.toUtf8(), &error);
        if(error.error == QJsonParseError::NoError){
            QVariantMap map = document.toVariant().toMap();
            MsgNode temp;
            temp.contact = map["user_id"].toString();
            temp.time = map["time"].toString();
            temp.content = map["content"].toString();
            messages.push_back(temp);
        }
        p = msg.indexOf("{", q);
    }
    QVector<MsgNode> temp;
    temp.push_back(messages[0]);
    for(int i = 1; i < messages.size(); i++){
        if(messages[i].contact != temp[0].contact){
            bool flag = false;
            for(int j = 0; j < cws.size(); j++){
                if(cws[j]->getContactAccount() == temp[0].contact){
                    cws[j]->receiveMessage(temp);
                    flag = true;
                    break;
                }
            }
            if(!flag){
             cws.push_back(new ChatWindow(myAccount, temp[0].contact,myName));
             cws[cws.size() - 1]->show();
            }
            temp.clear();
            temp.push_back(messages[i]);
        }else{
            temp.push_back(messages[i]);
        }
    }
    if(!temp.empty()){
        bool flag = false;
        for(int j = 0; j < cws.size(); j++){
            if(cws[j]->getContactAccount() == temp[0].contact){
                cws[j]->receiveMessage(temp);
                flag = true;
                break;
            }
        }
        if(!flag){
         cws.push_back(new ChatWindow(myAccount, temp[0].contact,myName));
         cws[cws.size() - 1]->receiveMessage(temp);
         cws[cws.size() - 1]->show();
        }
    }

}


//按下添加好友按钮
void MainPanel::on_btnAddContacts_clicked()
{
    addDlg->show();
}

//显示联系人列表
void MainPanel::on_btnContact_clicked()
{
    contactTreeView->show();
    groupTreeView->hide();
}

//显示群列表
void MainPanel::on_btnGroup_clicked()
{

    groupTreeView->show();
    contactTreeView->hide();
}

//接收数据，处理数据
void MainPanel::replyFinished(QNetworkReply *reply)
{
    changeDlg->boxClear();
    class_id.clear();
    contactModel->clear();
    groupModel->clear();
    contactModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("account")<<QStringLiteral("name")<<QStringLiteral("signature"));
    groupModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("group number")<<QStringLiteral("group name"));
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();

    //解析字符串
    int leftIndex,rightIndex;
    QString selfInfo = res.left(res.indexOf("contact"));
    res = res.mid(res.indexOf("classname"));
    //解析self
     //name
    leftIndex = selfInfo.indexOf("nickname")+11;
    rightIndex = selfInfo.indexOf("head")-4;
    myName = selfInfo.mid(leftIndex,rightIndex-leftIndex+1);
     //signature
    leftIndex = selfInfo.indexOf("signature")+12;
    rightIndex = selfInfo.indexOf("state")-4;
    mySignature = selfInfo.mid(leftIndex,rightIndex-leftIndex+1);
    //state
    leftIndex = selfInfo.indexOf("state")+8;
    rightIndex = selfInfo.indexOf("}")-2;
    QString sTest = selfInfo.mid(leftIndex,rightIndex-leftIndex+1);

     //head
    leftIndex = selfInfo.indexOf("head")+7;
    rightIndex = selfInfo.indexOf("level")-4;
    QString base64 = selfInfo.mid(leftIndex,rightIndex-leftIndex+1);
    int j = base64.indexOf('-');
    while(j!=-1){
        base64[j] = '+';
        j = base64.indexOf('-');
    }
    QByteArray pressedData = QByteArray::fromBase64(base64.toLatin1());
    QByteArray unPressedData = qUncompress(pressedData);
    QImage head;
    head.loadFromData(unPressedData);
    if(sTest == "1"){
        //彩色头像
        myHead = QIcon(QPixmap::fromImage(head));
    }
    else{
        //灰色头像
        myHead = QIcon(QPixmap(convertToGray(head)));
    }
   // myHead = QIcon(head);

    //修改个人信息
    myself->setAccount(myAccount);
    myself->setName(myName);
    myself->setSignature(mySignature);
    myself->setHead(myHead);


    //解析添加分组、联系人
    while(res.indexOf("classname") != -1){
        //i用来记录分组中好友个数
        int i = 0;
        //解析分组
        leftIndex = res.indexOf("classname")+12;
        rightIndex = res.indexOf("class_id")-4;
        QString className =  res.mid(leftIndex,rightIndex-leftIndex+1);
        //添加分组信息
        QStandardItem *group = new QStandardItem(className);
        contactModel->appendRow(group);
        changeDlg->addItem(className);
        //记录分组id
        leftIndex = res.indexOf("class_id")+11;
        rightIndex = res.indexOf("contact")-4;
        QString idTest = res.mid(leftIndex,rightIndex-leftIndex+1);
        class_id.append(idTest);
        //解析联系人
        leftIndex = res.indexOf("contact");
        rightIndex = res.indexOf("classname",20);

        //如果是最后一个分组
        QString contactsInfo;
        if(rightIndex == -1){
            contactsInfo = res.mid(leftIndex);
        }
        //不是最后一个分组
        else{
            contactsInfo = res.mid(leftIndex,rightIndex-leftIndex);
        }
        //分组中还有联系人
        while(contactsInfo.indexOf("account") != -1){
            //account
            leftIndex = contactsInfo.indexOf("account")+10;
            rightIndex = contactsInfo.indexOf("nickname")-4;
            QString contactAcc = contactsInfo.mid(leftIndex,rightIndex-leftIndex+1);
            //nickname
            leftIndex = contactsInfo.indexOf("nickname")+11;
            rightIndex = contactsInfo.indexOf("head")-4;
            QString contactNick = contactsInfo.mid(leftIndex,rightIndex-leftIndex+1);
            //signature
            leftIndex = contactsInfo.indexOf("signature")+12;
            rightIndex = contactsInfo.indexOf("state")-4;
            QString contactSign = contactsInfo.mid(leftIndex,rightIndex-leftIndex+1);
            //remaik
            leftIndex = contactsInfo.indexOf("remark")+9;
            rightIndex = contactsInfo.indexOf("\"",leftIndex)-1;
            QString contactRemark = contactsInfo.mid(leftIndex,rightIndex-leftIndex+1);
            //state
            leftIndex = contactsInfo.indexOf("state")+8;
            QString test = contactsInfo.mid(leftIndex,1);
            if(test == "1"){
                QString contactState = "online";
            }
            else{
                QString contactState = "leave";
            }
            //head**************根据state设置彩色灰色
            //head
            leftIndex = contactsInfo.indexOf("head")+7;
            rightIndex = contactsInfo.indexOf("level")-4;
            QString base = contactsInfo.mid(leftIndex,rightIndex-leftIndex+1);
            int j = base.indexOf('-');
            while(j!=-1){
                base[j] = '+';
                j = base.indexOf('-');
            }
            QByteArray pressedData1 = QByteArray::fromBase64(base.toLatin1());
            QByteArray unPressedData1 = qUncompress(pressedData1);
            QImage head1;
            head1.loadFromData(unPressedData1);
            QIcon contactHead;
            if(sTest == "1"){
                if(test == "1"){
                    //彩色头像
                    contactHead = QIcon(QPixmap::fromImage(head1));
                }
                else{
                    //灰色头像
                    contactHead = QIcon(QPixmap(convertToGray(head1)));
                }
            }
            else{
                contactHead = QIcon(QPixmap(convertToGray(head1)));
            }
            
            //添加联系人
            group->appendRow(new QStandardItem(contactHead,contactAcc));
            if(contactRemark == "null"){
                group->setChild(i,1,new QStandardItem(contactNick));
            }
            else{
                group->setChild(i,1,new QStandardItem(contactRemark));
            }
            group->setChild(i,2,new QStandardItem(contactSign));

            leftIndex = contactsInfo.indexOf("remark")+5;
            contactsInfo = contactsInfo.mid(leftIndex);
            i++;
        }
        leftIndex = res.indexOf("classname",20);
        if(leftIndex == -1){
            break;
        }
        else{
            res = res.mid(leftIndex);
        }
    }
    //群***********
}

//删除好友reply
void MainPanel::delReplyFinished(QNetworkReply *reply)
{
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();

    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    manager->post(QNetworkRequest(url), append);
}

//修改备注reply
void MainPanel::remarkReplyFinished(QNetworkReply *reply)
{

}

//修改状态reply
void MainPanel::stateReplyFinished(QNetworkReply *reply)
{
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();

    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    manager->post(QNetworkRequest(url), append);
}

//修改分组名reply
void MainPanel::renGroupReplyFinished(QNetworkReply *reply)
{
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();
}

//删除分组reply
void MainPanel::delGroupReplyFinished(QNetworkReply *reply)
{
    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    manager->post(QNetworkRequest(url), append);
}

//新建分组reply
void MainPanel::newGroupReplyFinished(QNetworkReply *reply)
{
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();

    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    manager->post(QNetworkRequest(url), append);
}

//修改分组reply
void MainPanel::changeGroupReplyFinished(QNetworkReply *reply)
{
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();

    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    manager->post(QNetworkRequest(url), append);
}

void MainPanel::closeStateReplyFinished(QNetworkReply *reply)
{
    close();
}

//双击联系人开始聊天
void MainPanel::on_contact_doubleClicked(const QModelIndex &index)
{
    QString contactAcc = contactModel->data(index).toString();
    //私聊窗口***********
}

//双击群开始群聊
void MainPanel::on_group_doubleClicked(const QModelIndex &index)
{
    QString groupNum = groupModel->data(index).toString();
    //群聊窗口**********
}

//联系人列表弹出右键菜单
void MainPanel::on_contact_rightClicked(const QPoint &point)
{
    QMenu *popMenu = new QMenu();
    //QModelIndex index = contactTreeView->currentIndex();
    QModelIndex index = contactTreeView->indexAt(point);
    if(!index.isValid()){
        popMenu->addAction(QString("New group"), this, SLOT(on_Action_newGroup()));
    }
    else{
        QString test = index.sibling(index.row(),1).data().toString();
        //右键点击分组
        if(test == ""){
            //默认分组不能删除
            if(index.row() == 0){
                popMenu->addAction(QString("Rename group"), this, SLOT(on_fenzuAction_reName()));
            }
            else{
                popMenu->addAction(QString("Rename group"), this, SLOT(on_fenzuAction_reName()));
                popMenu->addAction(QString("Delete group"), this, SLOT(on_fenzuAction_delete()));
            }
        }
        //右键点击联系人
        else{
            QString account = contactModel->data(index).toString();
            popMenu->addAction(QString("Chat"), this, SLOT(on_cAction_chat()));
            popMenu->addAction(QString("Scan information"), this, SLOT(on_cAction_scanInfo()));
            popMenu->addAction(QString("Modify name"), this, SLOT(on_cAction_reName()));
            popMenu->addAction(QString("Change group"), this, SLOT(on_cAction_reGroup()));
            popMenu->addAction(QString("Delete"), this, SLOT(on_cAction_delete()));
        }
    }
    popMenu->exec(QCursor::pos());

}

//群列表右键菜单
void MainPanel::on_group_rightClicked(const QPoint &point)
{
    QMenu *popMenu = new QMenu();
    QModelIndex index = contactTreeView->currentIndex();
    popMenu->addAction(QString("Chat"), this, SLOT(on_gAction_chat()));
    popMenu->addAction(QString("Modify information"), this, SLOT(on_gAction_modify()));
    popMenu->addAction(QString("Quit"), this, SLOT(on_gAction_quit()));
    popMenu->exec(QCursor::pos());
}

//具体修改分组名
void MainPanel::receiveGroupRename(QString name)
{
    QModelIndex index = contactTreeView->currentIndex();
    contactModel->setData(index,name);
    //上传到服务器
    QNetworkAccessManager *renGroupManager = new QNetworkAccessManager(this);
    QObject::connect(renGroupManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(renGroupReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/set-classname");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray id = class_id.at(index.row()).toLocal8Bit();
    QByteArray rem = name.toLocal8Bit();
    QByteArray append("account="+usr+"&class_id="+id+"&classname="+rem);
    renGroupManager->post(QNetworkRequest(url), append);

}
//具体修改备注名
void MainPanel::receiveContactRename(QString name)
{
    QModelIndex index = contactTreeView->currentIndex();
    QModelIndex contactIndex = index.parent().child(index.row(),1);
    contactModel->setData(contactIndex,name);

    QNetworkAccessManager *renameManager = new QNetworkAccessManager(this);
    QObject::connect(renameManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(remarkReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/set-remark");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray con = index.data().toString().toLocal8Bit();
    QByteArray rem = name.toLocal8Bit();
    QByteArray append("user_id="+usr+"&contact_id="+con+"&remark="+rem);
    renameManager->post(QNetworkRequest(url), append);

}

//具体新建分组*****************
void MainPanel::receiveNewGroup(QString newGroup)
{
    QNetworkAccessManager *newGroupManager = new QNetworkAccessManager(this);
    QObject::connect(newGroupManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(newGroupReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/new-class");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray className = newGroup.toLocal8Bit();
    QByteArray append("account="+usr+"&classname="+className);
    newGroupManager->post(QNetworkRequest(url), append);
}

//在线状态改变
void MainPanel::on_comboBox_changed(const QString &text)
{
    myState = text;
    //上传到服务器******************
    QNetworkAccessManager *stateManager = new QNetworkAccessManager(this);
    QObject::connect(stateManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(stateReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/set-state");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray sta;
    if(text == "online"){
        sta = "1";
    }
    else{
        sta = "0";
    }
    QByteArray append("account="+usr+"&state="+sta);
    stateManager->post(QNetworkRequest(url), append);
}

//具体修改分组
void MainPanel::on_group_changed(QString classid)
{
    QModelIndex index = contactTreeView->currentIndex();
    //上传到服务器
    QNetworkAccessManager *changeGroupManager = new QNetworkAccessManager(this);
    QObject::connect(changeGroupManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(changeGroupReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/set-class");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray con = index.data().toString().toLocal8Bit();
    QByteArray cid = class_id.at(classid.toInt()).toLocal8Bit();
    QByteArray append("user_id="+usr+"&contact_id="+con+"&class_id="+cid);
    changeGroupManager->post(QNetworkRequest(url), append);
}

//新建分组
void MainPanel::on_Action_newGroup()
{
    NewGroupDialog *nDlg = new NewGroupDialog;
    connect(nDlg,SIGNAL(sendData(QString)),this,SLOT(receiveNewGroup(QString)));
    nDlg->exec();
}


//弹出修改分组名窗口
void MainPanel::on_fenzuAction_reName()
{
    RenameDialog *rDlg = new RenameDialog;
    connect(rDlg,SIGNAL(sendData(QString)),this,SLOT(receiveGroupRename(QString)));
    rDlg->exec();

}
//弹出确定删除分组对话框
void MainPanel::on_fenzuAction_delete()
{
    QModelIndex index = contactTreeView->currentIndex();
    DeleteConfirmDialog *dDlg = new DeleteConfirmDialog;
    if(dDlg->exec() == QDialog::Accepted){
        QModelIndex deleteGroup = contactTreeView->currentIndex();
        //上传到服务器***********************
        QNetworkAccessManager *delGroupManager = new QNetworkAccessManager(this);
        QObject::connect(delGroupManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(delGroupReplyFinished(QNetworkReply*)));
        QUrl url("http://182.92.69.19/ichat-server/public/user/del-class");
        QByteArray usr = myAccount.toLocal8Bit();
        QByteArray classid = class_id.at(index.row()).toLocal8Bit();
        QByteArray append("account="+usr+"&class_id="+classid);
        delGroupManager->post(QNetworkRequest(url), append);
    }
}
//私聊
void MainPanel::on_cAction_chat()
{
    QModelIndex index = contactTreeView->currentIndex();
    QString contactAccount = contactModel->data(index).toString();
    //打开私聊窗口******************
    bool flag = false;
    //判断是否已经打开
    for(int i = 0; i < cws.size(); i++){
        if(cws[i]->getContactAccount() == contactAccount){
            cws[i]->setAttribute(Qt::WA_KeyboardFocusChange);
            flag = true;
        }
    }
    if(!flag){
        cws.push_back(new ChatWindow(myAccount, contactAccount,myName));
        cws[cws.size() - 1]->show();
    }

}
//查看资料
void MainPanel::on_cAction_scanInfo()
{
    QModelIndex index = contactTreeView->currentIndex();
    QString account = contactModel->data(index).toString();
    //打开查看资料窗口*******************
    bool flag = false;
    int size = fis.size();
    for(int i = 0; i < size; i++){
        if(fis[i]->getAccount() == "-1"){
            fis.remove(i);
            size--;
            continue;
        }
        if(fis[i]->getAccount() == account){
            fis[i]->setAttribute(Qt::WA_KeyboardFocusChange);
            flag = true;
            break;
        }
    }
    if(!flag){
        fis.push_back(new FriendInfo(account));
        fis[fis.size() - 1]->show();
    }

}
//弹出修改备注名窗口
void MainPanel::on_cAction_reName()
{
    RenameDialog *rDlg = new RenameDialog;
    connect(rDlg,SIGNAL(sendData(QString)),this,SLOT(receiveContactRename(QString)));
    rDlg->exec();
}
//修改分组窗口
void MainPanel::on_cAction_reGroup()
{
    QModelIndex index = contactTreeView->currentIndex();
    changeDlg->exec();
}
//删除好友
void MainPanel::on_cAction_delete()
{
    DeleteConfirmDialog dDlg;
    if(dDlg.exec() == QDialog::Accepted){
        QModelIndex index = contactTreeView->currentIndex();
        QString account = contactModel->data(index).toString();
        QStandardItem *parent = contactModel->item(index.parent().row());
        parent->removeRow(index.row());
        //上传到服务器
        QNetworkAccessManager *delManager = new QNetworkAccessManager(this);
        QObject::connect(delManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(delReplyFinished(QNetworkReply*)));
        QUrl url("http://182.92.69.19/ichat-server/public/user/del-contact");
        QByteArray con = account.toLocal8Bit();
        QByteArray usr = myAccount.toLocal8Bit();
        QByteArray append("user_id="+usr+"&contact_id="+con);
        delManager->post(QNetworkRequest(url), append);

    }

}
//群聊
void MainPanel::on_gAction_chat()
{
    QModelIndex index = groupTreeView->currentIndex();
    QString account = groupModel->data(index).toString();
    //打开群聊窗口***********************
}
//修改群资料
void MainPanel::on_gAction_modify()
{
    QModelIndex index = groupTreeView->currentIndex();
    QString account = groupModel->data(index).toString();
    //打开修改群资料窗口********************
}
//退出群
void MainPanel::on_gAction_quit()
{
    DeleteConfirmDialog dDlg;
    if(dDlg.exec() == QDialog::Accepted){
        QModelIndex index = groupTreeView->currentIndex();
        QString account = groupModel->data(index).toString();
        groupModel->removeRow(index.row());
        //上传到服务器************************
    }

}


//最小化
void MainPanel::on_minBtn_clicked()
{
    this->showMinimized();
}


//关闭
void MainPanel::on_closeBtn_clicked()
{
    QNetworkAccessManager *closeStateManager = new QNetworkAccessManager(this);
    QObject::connect(closeStateManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(closeStateReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/set-state");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray sta("0");
    QByteArray append("account="+usr+"&state="+sta);
    closeStateManager->post(QNetworkRequest(url), append);
}
