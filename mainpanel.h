#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QFrame>
#include "addwindow.h"
#include "useritem.h"
#include "mylistwidget.h"
#include "grouplistwidget.h"
namespace Ui {
class MainPanel;
}

class MainPanel : public QFrame
{
    Q_OBJECT

public:
    explicit MainPanel(QString account,QWidget *parent = 0);
    ~MainPanel();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:
    void on_btnAddContacts_clicked();

    void on_btnContact_clicked();

    void on_btnGroup_clicked();

public slots:

    void on_contactDoubleClicked(const QModelIndex &index);
    void on_groupDoubleClicked(const QModelIndex &index);
    void on_item_rightClicked(const QPoint &point);

private:
    Ui::MainPanel *ui;
    AddWindow *addDlg;
    UserItem *myself;
    MyListWidget *contactsListWidget;
    GroupListWidget *groupListWidget;
    QPoint dragPosition;
public:
    QString myAccount;

};

#endif // MAINPANEL_H
