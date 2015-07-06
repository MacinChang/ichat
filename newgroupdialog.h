#ifndef NEWGROUPDIALOG_H
#define NEWGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class NewGroupDialog;
}

class NewGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGroupDialog(QWidget *parent = 0);
    ~NewGroupDialog();

private:
    Ui::NewGroupDialog *ui;
signals:
    void sendData(QString);

public slots:
    void on_yesBtn_clicked();
};

#endif // NEWGROUPDIALOG_H
