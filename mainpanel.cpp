#include "mainpanel.h"
#include "useritem.h"
#include "addwindow.h"
#include "ui_mainpanel.h"
#include <QDesktopWidget>
#include "mylistwidget.h"
#include "QListWidget"
#include "mylistwidgetitem.h"
#include "grouplistwidget.h"

MainPanel::MainPanel(QWidget *parent) :
    QFrame(parent),
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

    //设置contactsListWidget 添加item
    contactsListWidget = new MyListWidget(this);
    contactsListWidget->setGeometry(1,110,241,329);
    contactsListWidget->setViewMode(QListView::IconMode);
    contactsListWidget->setIconSize(QSize(50,50));
    contactsListWidget->setMovement(QListView::Static);
    contactsListWidget->setSpacing(36);
    for(int i = 20;i!=0;i--){
        //好友头像设置
        QIcon icon("E:/PracticalTraining/git/head.png");
        //好友昵称
        QString name = "wendabei";
        //创建item
        MyListWidgetItem *item = new MyListWidgetItem(contactsListWidget);
        item->setIcon(icon);
        item->setText(name);
        //添加item到list
        contactsListWidget->addItem(item);
    }
    //设置groupListWidget 添加item   并设为隐藏
    groupListWidget = new GroupListWidget(this);
    groupListWidget->setGeometry(1,110,241,329);
    groupListWidget->setViewMode(QListView::IconMode);
    groupListWidget->setIconSize(QSize(50,50));
    groupListWidget->setMovement(QListView::Static);
    groupListWidget->setSpacing(36);
    for(int i = 20;i!=0;i--){
        //好友头像设置
        QIcon icon("E:/PracticalTraining/git/head.png");
        //好友昵称
        QString name = QString("Group %1").arg(i);
        //创建item
        MyListWidgetItem *item = new MyListWidgetItem(groupListWidget);
        item->setIcon(icon);
        item->setText(name);
        //添加item到list
        groupListWidget->addItem(item);
    }
    groupListWidget->setVisible(false);

    connect(contactsListWidget,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(on_itemClicked(QListWidgetItem*)));
}

MainPanel::~MainPanel()
{
    delete ui;
}

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



void MainPanel::on_btnAddContacts_clicked()
{
    addDlg->show();
}

void MainPanel::on_btnContact_clicked()
{
    /*contactsListWidget->clear();
    //显示联系人************
    for(int i = 20;i!=0;i--){
        //好友头像设置
        QIcon icon("E:/PracticalTraining/git/head.png");
        //好友昵称
        QString name = "wendabei";
        //创建item
        MyListWidgetItem *item = new MyListWidgetItem(this);//(icon,name);
        item->setIcon(icon);
        item->setText(name);
        //添加item到list
        contactsListWidget->addItem(item);
    }*/
    groupListWidget->setVisible(false);
    contactsListWidget->setVisible(true);
}

void MainPanel::on_btnGroup_clicked()
{
    /*contactsListWidget->clear();
    //显示群***********
    for(int i = 20;i!=0;i--){
        //好友头像设置
        QIcon icon("E:/PracticalTraining/git/head.png");
        //好友昵称
        QString name = QString("Group %1").arg(i);
        //创建item
        MyListWidgetItem *item = new MyListWidgetItem(this);//(icon,name);
        item->setIcon(icon);
        item->setText(name);
        //添加item到list
        groupListWidget->addItem(item);
    }*/
    groupListWidget->setVisible(true);
    contactsListWidget->setVisible(false);
}


void MainPanel::on_itemClicked(QListWidgetItem *item)
{

}


