#ifndef FRIENDINFO_H
#define FRIENDINFO_H

#include <QDialog>

namespace Ui {
class FriendInfo;
}

class FriendInfo : public QDialog
{
    Q_OBJECT

public:
    explicit FriendInfo(QWidget *parent = 0);
    ~FriendInfo();

private slots:

    void on_ConfirmButton_clicked();

private:
    Ui::FriendInfo *ui;
};

#endif // FRIENDINFO_H
