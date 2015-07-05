#ifndef DIVIDEWINDOW_H
#define DIVIDEWINDOW_H

#include <QDialog>

namespace Ui {
class DivideWindow;
}

class DivideWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DivideWindow(QString data,QWidget *parent = 0);
    ~DivideWindow();
    QString re;
private:
    Ui::DivideWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIVIDEWINDOW_H
