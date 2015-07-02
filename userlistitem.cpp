#include "userlistitem.h"
#include "chatwindow.h"
#include "ui_userlistitem.h"

UserListItem::UserListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserListItem)
{
    ui->setupUi(this);
    connect(this, SIGNAL(clicked()), this, SLOT(mousePressEventSlot()));
}

UserListItem::~UserListItem()
{
    delete ui;
}

void UserListItem::mousePressEvent(QMouseEvent *e){
    QRect rect = this->rect();
    int x = e->x();
    int y = e->y();
    if(x > rect.left() && x < rect.right() && y > rect.top() && y < rect.bottom()){
        emit clicked();
    }
}

void UserListItem::mousePressEventSlot(){
    ChatWindow cw;
    cw.show();
}
