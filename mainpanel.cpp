#include "mainpanel.h"
#include "useritem.h"
#include "addwindow.h"
#include "ui_mainpanel.h"
#include <QDesktopWidget>
#include "mylistwidget.h"
#include "QListWidget"
#include "grouplistwidget.h"

MainPanel::MainPanel(QString account, QWidget *parent) :
    QFrame(parent),myAccount(account),
    ui(new Ui::MainPanel)
{
    ui->setupUi(this);

    //移动主窗口的位置
    QRect deskRect = QApplication::desktop()->availableGeometry();
    this->move(deskRect.right()-280,30);

    //取消标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    //添加好友窗口初始化
    addDlg = new AddWindow();

    //添加自己头像
    myself = new UserItem(this);

    /*
    //设置contactsListWidget 添加item
    contactsListWidget = new MyListWidget(this);
    contactsListWidget->setGeometry(1,110,241,329);
    contactsListWidget->setViewMode(QListView::ListMode);
    contactsListWidget->setIconSize(QSize(50,50));
    contactsListWidget->setMovement(QListView::Static);
    //contactsListWidget->setSpacing(36);
    for(int i = 20;i!=0;i--){
        //好友头像设置
        QIcon icon("E:/PracticalTraining/git/head.png");
        //好友账号
        QString account = "wendabei";
        //创建item
        QListWidgetItem *item = new QListWidgetItem(icon,account);
        //添加item到list
        contactsListWidget->addItem(item);
    }
    //设置groupListWidget 添加item   并设为隐藏
    groupListWidget = new GroupListWidget(this);
    groupListWidget->setGeometry(1,110,241,329);
    groupListWidget->setViewMode(QListView::ListMode);
    groupListWidget->setIconSize(QSize(50,50));
    groupListWidget->setMovement(QListView::Static);
    //groupListWidget->setSpacing(36);
    for(int i = 20;i!=0;i--){
        //群头像设置
        QIcon icon("E:/PracticalTraining/git/head.png");
        //群号
        QString account = QString("Group %1").arg(i);
        //创建item
        QListWidgetItem *item = new QListWidgetItem(icon,account);
        //添加item到list
        groupListWidget->addItem(item);
    }
    groupListWidget->setVisible(false);

    connect(contactsListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_contactDoubleClicked(QListWidgetItem*)));
    connect(groupListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(on_groupDoubleClicked(QListWidgetItem*)));
    */
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

    //groupListWidget->setVisible(false);
    //contactsListWidget->setVisible(true);
}

//显示群列表
void MainPanel::on_btnGroup_clicked()
{

    //groupListWidget->setVisible(true);
    //contactsListWidget->setVisible(false);
}

//双击联系人开始聊天
void MainPanel::on_contactDoubleClicked(const QModelIndex &index)
{

    //私聊窗口
}

//双击群开始群聊
void MainPanel::on_groupDoubleClicked(const QModelIndex &index)
{

    //群聊窗口
}

//弹出右键菜单
void MainPanel::on_item_rightClicked(const QPoint &point)
{

}


