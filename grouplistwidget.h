#ifndef GROUPLISTWIDGET_H
#define GROUPLISTWIDGET_H

#include <QListWidget>
#include "QMenu"
#include "QAction"

class GroupListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit GroupListWidget(QWidget *parent = 0);
    void contextMenuEvent(QContextMenuEvent *event);
private:
    QMenu *popMenu;
    QAction *modifyAction;
    QAction *chatAction;
    QAction *quitAction;

public slots:
    void on_chatAction_triggered();
    void on_modifyAction_triggered();
    void on_quitAction_triggered();
signals:

public slots:
};

#endif // GROUPLISTWIDGET_H
