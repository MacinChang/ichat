#include "mylistwidget.h"


MyListWidget::MyListWidget(QWidget *parent) : QListWidget(parent)
{
    popMenu = new QMenu(this);
    chatAction = new QAction("Start chating",this);
    scanAction = new QAction("Contact information",this);
    modifyAction = new QAction("Modify remark",this);
    deleteAction = new QAction("Delete contact",this);
    popMenu->addAction(chatAction);
    popMenu->addAction(scanAction);
    popMenu->addAction(modifyAction);
    popMenu->addAction(deleteAction);
    connect(chatAction,SIGNAL(triggered()),this,SLOT(on_chatAction_triggered()));
    connect(scanAction,SIGNAL(triggered()),this,SLOT(on_scanAction_triggered()));
    connect(deleteAction,SIGNAL(triggered()),this,SLOT(on_deleteAction_triggered()));
    connect(modifyAction,SIGNAL(triggered()),this,SLOT(on_modifyAction_triggered()));

}

void MyListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QPoint p = mapFromGlobal(QCursor::pos());
    if(this->itemAt(p) != NULL){
        popMenu->exec(QCursor::pos());
    }
}

void MyListWidget::on_chatAction_triggered()
{

}

void MyListWidget::on_scanAction_triggered()
{

}

void MyListWidget::on_deleteAction_triggered()
{

}

void MyListWidget::on_modifyAction_triggered()
{

}


