#include "mainpanel.h"
#include "userlistitem.h"
#include "addwindow.h"
#include "ui_mainpanel.h"
#include <QDesktopWidget>

MainPanel::MainPanel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainPanel)
{

    QRect deskRect = QApplication::desktop()->availableGeometry();
    this->move(deskRect.right()-280,30);

    ui->setupUi(this);
    ui->btnContact->setFlat(true);
    ui->btnGroup->setFlat(true);
    ui->btnAdd->setFlat(true);

    ui->listWidgetContact->setMouseTracking(true);
    ui->listWidgetContact->setAutoScroll(true);
    //UserListItem *myidtem = new UserListItem(ui->listWidgetContact);
    for(int i = 1; i <= 10; i++){
          UserListItem *myitem = new UserListItem(ui->listWidgetContact);
          myitem->move(0, myitem->rect().height() * (i - 1));
//        myitem->show();
//        QListWidgetItem *item = new QListWidgetItem();
//        //ui->listWidgetContact->addItem("hello");
//        item->setSizeHint(myitem->sizeHint());
//       // ui->listWidgetContact->setItemWidget(item, myitem);

    }
    //this->setShown(true);

}

MainPanel::~MainPanel()
{
    delete ui;
}

void MainPanel::on_btnAdd_clicked()
{
    AddWindow aw;
    aw.show();
}
