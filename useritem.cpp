#include "useritem.h"
#include "ui_useritem.h"

UserItem::UserItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserItem)
{
    ui->setupUi(this);
    QPixmap image("E:/PracticalTraining/git/head.png");
    ui->headBtn->setIcon(QIcon(image));
    ui->nameLabel->setText("MyName");
    ui->signLabel->setText("MySignature");
}

UserItem::~UserItem()
{
    delete ui;
}

//单击头像打开个人资料修改界面
void UserItem::on_headBtn_clicked()
{
    //打开修改个人资料界面**************
}
