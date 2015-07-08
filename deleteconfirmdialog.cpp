#include "deleteconfirmdialog.h"
#include "ui_deleteconfirmdialog.h"

DeleteConfirmDialog::DeleteConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("确认窗口");
    this->setWindowFlags(Qt::FramelessWindowHint);
}

DeleteConfirmDialog::~DeleteConfirmDialog()
{
    delete ui;
}
