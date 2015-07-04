#ifndef MYLISTWIDGETITEM_H
#define MYLISTWIDGETITEM_H

#include <QListWidgetItem>


class MyListWidgetItem : public QListWidgetItem
{

public:
    explicit MyListWidgetItem(QWidget * parent = 0);

public:
    QString account;
};

#endif // MYLISTWIDGETITEM_H
