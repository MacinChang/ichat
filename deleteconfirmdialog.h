#ifndef DELETECONFIRMDIALOG_H
#define DELETECONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteConfirmDialog;
}

class DeleteConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConfirmDialog(QWidget *parent = 0);
    ~DeleteConfirmDialog();

private:
    Ui::DeleteConfirmDialog *ui;
};

#endif // DELETECONFIRMDIALOG_H
