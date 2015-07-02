#ifndef USERLISTITEM_H
#define USERLISTITEM_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class UserListItem;
}

class UserListItem : public QWidget
{
    Q_OBJECT

public:
    explicit UserListItem(QWidget *parent = 0);
    ~UserListItem();
signals:
    void clicked();
public slots:
    virtual void mousePressEventSlot();
protected:
    void mousePressEvent(QMouseEvent *);
private:
    Ui::UserListItem *ui;
};

#endif // USERLISTITEM_H
