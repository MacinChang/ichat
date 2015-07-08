#include "useritem.h"
#include "ui_useritem.h"
#include "QIcon"

UserItem::UserItem(QString acc, QWidget *parent) :
    QWidget(parent),myAccount(acc),
    ui(new Ui::UserItem)
{
    ui->setupUi(this);




    //设置comboBox
    QIcon onlineIcon(":/images/image/online.png");
    ui->comboBox->addItem(onlineIcon,"online");
    QIcon leaveIcon(":/images/image/leave.png");
    ui->comboBox->addItem(leaveIcon,"leave");
    ui->comboBox->setIconSize(QSize(15,15));

    connect(ui->comboBox,SIGNAL(currentIndexChanged(const QString)),this,SLOT(on_comboBox_changed(const QString)));

}

UserItem::~UserItem()
{
    delete ui;
}
void UserItem::setAccount(QString myAccount){
   this->myAccount = myAccount;
}

void UserItem::setName(QString name)
{
    ui->nameLabel->setText(name);
}

void UserItem::setSignature(QString sign)
{
    ui->signLabel->setText(sign);
}

void UserItem::setHead(QIcon head)
{
    ui->headBtn->setIcon(head);
}

//单击头像打开个人资料修改界面
void UserItem::on_headBtn_clicked()
{
    //打开修改个人资料界面
    self = new UserInfo(myAccount);
    connect(self,SIGNAL(userInfoChanged()),this,SLOT(on_userInfoChanged()));
    self->show();

}

void UserItem::on_comboBox_changed(const QString &text)
{
    emit comboBoxCurrentIndexChanged(text);
}

void UserItem::on_userInfoChanged()
{
    emit userInfoChangedToPanel();
}
