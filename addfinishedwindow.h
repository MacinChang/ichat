#ifndef ADDFINISHEDWINDOW_H
#define ADDFINISHEDWINDOW_H

#include <QDialog>

namespace Ui {
class AddFinishedWindow;
}

class AddFinishedWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddFinishedWindow(QWidget *parent = 0);
    ~AddFinishedWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddFinishedWindow *ui;
};

#endif // ADDFINISHEDWINDOW_H
