#include "useritem.h"
#include "ui_useritem.h"
#include "QIcon"

UserItem::UserItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserItem)
{
    ui->setupUi(this);
    QPixmap image("E:/PracticalTraining/git/head.png");
    ui->headBtn->setIcon(QIcon(image));
    ui->nameLabel->setText("MyName");
    ui->signLabel->setText("MySignature");

    //设置comboBox
    QIcon onlineIcon("E:/PracticalTraining/git/image/online.png");
    ui->comboBox->addItem(onlineIcon,"online");
    QIcon leaveIcon("E:/PracticalTraining/git/image/leave.png");
    ui->comboBox->addItem(leaveIcon,"leave");
    ui->comboBox->setIconSize(QSize(15,15));

    connect(ui->comboBox,SIGNAL(currentIndexChanged(const QString)),this,SLOT(on_comboBox_changed(const QString)));
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

void UserItem::on_comboBox_changed(const QString &text)
{
    emit comboBoxCurrentIndexChanged(text);
}
