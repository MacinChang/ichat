#include "newgroupdialog.h"
#include "ui_newgroupdialog.h"

NewGroupDialog::NewGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGroupDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("新建分组");
}

NewGroupDialog::~NewGroupDialog()
{
    delete ui;
}


void NewGroupDialog::on_yesBtn_clicked()
{
    emit sendData(ui->newEdit->text());
    accept();
}
