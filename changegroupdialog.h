#ifndef CHANGEGROUPDIALOG_H
#define CHANGEGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class ChangeGroupDialog;
}

class ChangeGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeGroupDialog(QWidget *parent = 0);
    ~ChangeGroupDialog();
    void boxClear();
    void addItem(QString groupName);

private slots:
    void on_yesBtn_clicked();

private:
    Ui::ChangeGroupDialog *ui;
signals:
    void changeBtn_clicked(QString class_id);
};

#endif // CHANGEGROUPDIALOG_H
