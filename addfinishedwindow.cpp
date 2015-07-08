#include "addfinishedwindow.h"
#include "ui_addfinishedwindow.h"

AddFinishedWindow::AddFinishedWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFinishedWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    dragPosition = QPoint(-1,-1);
}

AddFinishedWindow::~AddFinishedWindow()
{
    delete ui;
}

void AddFinishedWindow::on_pushButton_clicked()
{
    this->close();
}

void AddFinishedWindow::on_pushButton_2_clicked()
{
    this->close();
}
void AddFinishedWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = e->globalPos()-frameGeometry().topLeft();
        QPoint p = e->pos();
        e->accept();
    }
    else dragPosition = QPoint(-1,-1);
}

void AddFinishedWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(dragPosition != QPoint(-1,-1)){
        move(e->globalPos()-dragPosition);
    }
    e->accept();

}
void AddFinishedWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = QPoint(-1,-1);
        e->accept();
    }
}
