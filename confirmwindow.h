#ifndef CONFIRMWINDOW_H
#define CONFIRMWINDOW_H
#include "dividewindow.h"
#include <QDialog>

namespace Ui {
class confirmWindow;
}

class confirmWindow : public QDialog
{
    Q_OBJECT

public:
    explicit confirmWindow(QString data,QWidget *parent = 0);
    ~confirmWindow();
    QString receivedData;
private:
    Ui::confirmWindow *ui;
    DivideWindow *dw;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // CONFIRMWINDOW_H
