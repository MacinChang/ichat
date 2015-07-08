#ifndef ADDFINISHEDWINDOW_H
#define ADDFINISHEDWINDOW_H

#include <QDialog>
#include "QMouseEvent"

namespace Ui {
class AddFinishedWindow;
}

class AddFinishedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddFinishedWindow(QWidget *parent = 0);
    ~AddFinishedWindow();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    QPoint dragPosition;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddFinishedWindow *ui;
};

#endif // ADDFINISHEDWINDOW_H
