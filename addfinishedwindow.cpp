#include "addfinishedwindow.h"
#include "ui_addfinishedwindow.h"

AddFinishedWindow::AddFinishedWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFinishedWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

AddFinishedWindow::~AddFinishedWindow()
{
    delete ui;
}

void AddFinishedWindow::on_pushButton_clicked()
{
    this->close();
}
