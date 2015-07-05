#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QFrame>
#include "addwindow.h"
#include "useritem.h"
#include "QStandardItemModel"
#include "QTreeView"
#include "QMouseEvent"
#include "QNetworkRequest"
#include "QNetworkReply"

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

    void on_minBtn_clicked();

public slots:

    void replyFinished(QNetworkReply *reply);
    void on_contact_doubleClicked(const QModelIndex &index);
    void on_group_doubleClicked(const QModelIndex &index);
    void on_contact_rightClicked(const QPoint &point);
    void on_group_rightClicked(const QPoint &point);
    void receiveGroupRename(QString name);
    void receiveContactRename(QString name);
    void on_comboBox_changed(const QString & text);

    void on_fenzuAction_reName();
    void on_fenzuAction_delete();

    void on_cAction_chat();
    void on_cAction_scanInfo();
    void on_cAction_reName();
    void on_cAction_reGroup();
    void on_cAction_delete();

    void on_gAction_chat();
    void on_gAction_modify();
    void on_gAction_quit();

private:
    Ui::MainPanel *ui;
    AddWindow *addDlg;
    UserItem *myself;
    QPoint dragPosition;
    QStandardItemModel *contactModel,*groupModel;
    QTreeView *contactTreeView,*groupTreeView;
    QString myState;
    QNetworkAccessManager *manager;
public:
    QString myAccount;

};

#endif // MAINPANEL_H
