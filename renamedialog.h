#ifndef RENAMEDIALOG_H
#define RENAMEDIALOG_H

#include <QDialog>

namespace Ui {
class RenameDialog;
}

class RenameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RenameDialog(QWidget *parent = 0);
    ~RenameDialog();

private:
    Ui::RenameDialog *ui;

signals:
    void sendData(QString);

public slots:
    void on_yesBtn_clicked();
};

#endif // RENAMEDIALOG_H
