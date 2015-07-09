#include "changegroupdialog.h"
#include "ui_changegroupdialog.h"

ChangeGroupDialog::ChangeGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeGroupDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

ChangeGroupDialog::~ChangeGroupDialog()
{
    delete ui;
}

void ChangeGroupDialog::boxClear()
{
    ui->groupBox->clear();
}

void ChangeGroupDialog::addItem(QString groupName)
{
    ui->groupBox->addItem(groupName);
}


void ChangeGroupDialog::on_yesBtn_clicked()
{
    QString class_id = QString("%1").arg(ui->groupBox->currentIndex());
    emit changeBtn_clicked(class_id);
    accept();
}
