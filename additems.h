#ifndef ADDITEMS_H
#define ADDITEMS_H
#include "dividewindow.h"
#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class AddItems;
}

class AddItems : public QWidget
{
    Q_OBJECT

public:
    explicit AddItems(QWidget *parent = 0);
    ~AddItems();
protected:
    void mousePressEvent(QMouseEvent *);
private:
    Ui::AddItems *ui;
    DivideWindow *dw;
private slots:
    void on_pushButton_clicked();
    virtual void headPressEventSlot();
signals:
    void clicked();
};

#endif // ADDITEMS_H
