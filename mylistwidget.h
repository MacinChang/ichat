#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>
#include "QMouseEvent"
#include "QMenu"
#include "QAction"
#include "mylistwidgetitem.h"


class MyListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = 0);
    void contextMenuEvent(QContextMenuEvent *event);
    MyListWidget *conList;

private:
    QMenu *popMenu;
    QAction *scanAction;
    QAction *chatAction;
    QAction *deleteAction;
    QAction *modifyAction;
signals:
    //void itemClicked( MyListWidgetItem *item );

public slots:
    void on_chatAction_triggered();
    void on_scanAction_triggered();
    void on_deleteAction_triggered();
    void on_modifyAction_triggered();



public:
    //void mousePressEvent(QMouseEvent *e);
};

#endif // MYLISTWIDGET_H
