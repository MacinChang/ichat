#include "mainpanel.h"
#include "useritem.h"
#include "addwindow.h"
#include "ui_mainpanel.h"
#include <QDesktopWidget>
#include "QListWidget"
#include "QMenu"
#include "renamedialog.h"
#include "deleteconfirmdialog.h"



MainPanel::MainPanel(QString account, QWidget *parent) :
    QFrame(parent),myAccount(account),
    ui(new Ui::MainPanel)
{
    ui->setupUi(this);
    dragPosition = QPoint(-1,-1);
    this->setFixedSize(this->size());

    //移动主窗口的位置
    QRect deskRect = QApplication::desktop()->availableGeometry();
    this->move(deskRect.right()-350,30);

    //取消标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    //添加好友窗口初始化
    addDlg = new AddWindow();

    //请求数据
    manager = new QNetworkAccessManager(this);
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    QNetworkReply* reply = manager->post(QNetworkRequest(url), append);

    //添加自己头像
    myself = new UserItem(this);
    myself->setGeometry(33,54,240,70);
    myState = "online";
    connect(myself,SIGNAL(comboBoxCurrentIndexChanged(const QString)),this,SLOT(on_comboBox_changed(const QString)));

    //联系人TreeView
    contactTreeView = new QTreeView(this);
    contactTreeView->setGeometry(1,152,297,395);
    contactTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    contactTreeView->setHeaderHidden(true);
    contactTreeView->setEditTriggers(0);
    //联系人model
    contactModel = new QStandardItemModel(contactTreeView);
    contactTreeView->setModel(contactModel);
    contactModel->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Number")<<QStringLiteral("Name")<<QStringLiteral("Signature")));

    //添加分组信息、联系人信息********
    QStandardItem *group1 = new QStandardItem("group1");
    contactModel->appendRow(group1);
    QStandardItem *group2 = new QStandardItem("group2");
    contactModel->appendRow(group2);

    QIcon icon("E:/PracticalTraining/git/head.png");
    QString acc = "123";
    QStandardItem *contactTestAcc1 = new QStandardItem(icon,acc);
    QStandardItem *contactTest1 = new QStandardItem("name");
    group1->appendRow(contactTestAcc1);
    group1->setChild(0,1,contactTest1);

    acc = "456";
    QStandardItem *contactTestAcc2 = new QStandardItem(icon,acc);
    QStandardItem *contactTest2 = new QStandardItem("name");
    group2->appendRow(contactTestAcc2);
    group2->setChild(0,1,contactTest2);


    //关联右键点击槽
    connect(contactTreeView,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(on_contact_rightClicked(const QPoint)));
    //关联双击槽
    connect(contactTreeView,SIGNAL(doubleClicked(const QModelIndex)),this,SLOT(on_contact_doubleClicked(const QModelIndex)));


    //群TreeView
    groupTreeView = new QTreeView(this);
    groupTreeView->hide();
    groupTreeView->setGeometry(1,152,297,395);
    groupTreeView->setContextMenuPolicy(Qt::CustomContextMenu);
    groupTreeView->setHeaderHidden(true);
    groupTreeView->setEditTriggers(0);
    //群model
    groupModel = new QStandardItemModel(groupTreeView);
    groupTreeView->setModel(groupModel);
    groupModel->setHorizontalHeaderLabels((QStringList()<<QStringLiteral("Number")<<QStringLiteral("GroupName")));

    //添加群信息**************
    //QIcon icon("E:/PracticalTraining/git/head.png");
    QString groupNum = "123";
    QStandardItem *groupTest = new QStandardItem(icon,groupNum);
    QStandardItem *groupName = new QStandardItem("name");
    groupModel->appendRow(groupTest);
    groupModel->setItem(0,1,groupName);

    //关联右键点击槽
    connect(groupTreeView,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(on_group_rightClicked(const QPoint)));
    //关联双击槽
    connect(groupTreeView,SIGNAL(doubleClicked(const QModelIndex)),this,SLOT(on_group_doubleClicked(const QModelIndex)));
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
    QVariant vRes = reply->readAll();
    QString res = vRes.toString();
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
    QModelIndex index = contactTreeView->currentIndex();
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
        popMenu->exec(QCursor::pos());

    }
    //右键点击联系人
    else{
        QString account = contactModel->data(index).toString();
        popMenu->addAction(QString("Chat"), this, SLOT(on_cAction_chat()));
        popMenu->addAction(QString("Scan information"), this, SLOT(on_cAction_scanInfo()));
        popMenu->addAction(QString("Modify name"), this, SLOT(on_cAction_reName()));
        popMenu->addAction(QString("Modify group"), this, SLOT(on_cAction_reGroup()));
        popMenu->addAction(QString("Delete"), this, SLOT(on_cAction_delete()));
        popMenu->exec(QCursor::pos());
    }

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
    //上传到服务器***************
}
//具体修改备注名
void MainPanel::receiveContactRename(QString name)
{
    QModelIndex index = contactTreeView->currentIndex();
    QModelIndex contactIndex = index.parent().child(index.row(),1);
    contactModel->setData(contactIndex,name);
    //上传到服务器***************
}

//在线状态改变
void MainPanel::on_comboBox_changed(const QString &text)
{
    myState = text;
    //上传到服务器******************
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
    DeleteConfirmDialog *dDlg = new DeleteConfirmDialog;
    if(dDlg->exec() == QDialog::Accepted){
        QModelIndex defaultGroup = contactModel->index(0,0);
        QModelIndex deleteGroup = contactTreeView->currentIndex();
        QModelIndex aChild = deleteGroup.child(0,0);
        /*
        while(aChild.isValid()){
            //aChild送给default，aChild = deleteGroup.child(0,0)******************
        }
        */
        contactModel->removeRow(deleteGroup.row());
    }
}
//私聊
void MainPanel::on_cAction_chat()
{
    QModelIndex index = contactTreeView->currentIndex();
    QString account = contactModel->data(index).toString();
    //打开私聊窗口******************
}
//查看资料
void MainPanel::on_cAction_scanInfo()
{
    QModelIndex index = contactTreeView->currentIndex();
    QString account = contactModel->data(index).toString();
    //打开查看资料窗口*******************
}
//弹出修改备注名窗口
void MainPanel::on_cAction_reName()
{
    RenameDialog *rDlg = new RenameDialog;
    connect(rDlg,SIGNAL(sendData(QString)),this,SLOT(receiveContactRename(QString)));
    rDlg->exec();
}
//修改分组****************
void MainPanel::on_cAction_reGroup()
{
    QModelIndex index = contactTreeView->currentIndex();
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
        //上传到服务器*********************
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



void MainPanel::on_minBtn_clicked()
{
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);
}
