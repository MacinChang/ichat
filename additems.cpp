#include "additems.h"
#include "ui_additems.h"

AddItems::AddItems(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddItems)
{
    ui->setupUi(this);
    connect(this, SIGNAL(clicked()), this, SLOT(headPressEventSlot()));
}

AddItems::~AddItems()
{
    delete ui;
}

void AddItems::on_pushButton_clicked()
{

}

void AddItems::mousePressEvent(QMouseEvent *e)
{
    QRect rect = ui->label_3->rect();
    int x = e->x();
    int y = e->y();
    if(x > rect.left() && x < rect.right() && y > rect.top() && y < rect.bottom()){
        emit clicked();
    }
}

void AddItems::headPressEventSlot()
{
    //点击头像查看用户信息
}

