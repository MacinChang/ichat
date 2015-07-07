#include "renamedialog.h"
#include "ui_renamedialog.h"

RenameDialog::RenameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RenameDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("修改备注");
}

RenameDialog::~RenameDialog()
{
    delete ui;
}

void RenameDialog::on_yesBtn_clicked()
{
    emit sendData(ui->remarkNameEdit->text());
    accept();
}
