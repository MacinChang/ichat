#include "renamedialog.h"
#include "ui_renamedialog.h"

RenameDialog::RenameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RenameDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("New Name");
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->label->setText("New Name:");
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
