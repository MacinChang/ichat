#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(430, 335);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::SubWindow);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
