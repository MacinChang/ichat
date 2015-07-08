#ifndef USERITEM_H
#define USERITEM_H
#include "userinfo.h"
#include <QWidget>

namespace Ui {
class UserItem;
}

class UserItem : public QWidget
{
    Q_OBJECT

public:
    explicit UserItem(QString acc,QWidget *parent = 0);
    ~UserItem();
    void setName(QString name);
    void setSignature(QString sign);
    void setHead(QIcon head);
    void setAccount(QString myAccount);


private slots:
    void on_headBtn_clicked();
    void on_comboBox_changed(const QString & text);
    void on_userInfoChanged();

signals:
    void comboBoxCurrentIndexChanged(const QString & text);
    void userInfoChangedToPanel();

private:
    Ui::UserItem *ui;
    QString myAccount;
    UserInfo *self;
};

#endif // USERITEM_H
