#include "grouplistwidget.h"


GroupListWidget::GroupListWidget(QWidget *parent) : QListWidget(parent)
{
    popMenu = new QMenu(this);
    chatAction = new QAction("Start group-chating",this);
    modifyAction = new QAction("Group information",this);
    quitAction = new QAction("Quit group",this);
    popMenu->addAction(chatAction);
    popMenu->addAction(modifyAction);
    popMenu->addAction(quitAction);
    connect(chatAction,SIGNAL(triggered()),this,SLOT(on_chatAction_triggered()));
    connect(modifyAction,SIGNAL(triggered()),this,SLOT(on_modifyAction_triggered()));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(on_quitAction_triggered()));
}

void GroupListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QPoint p = mapFromGlobal(QCursor::pos());
    if(this->itemAt(p) != NULL){
        popMenu->exec(QCursor::pos());
    }
}

void GroupListWidget::on_chatAction_triggered()
{

}

void GroupListWidget::on_modifyAction_triggered()
{

}

void GroupListWidget::on_quitAction_triggered()
{

}

