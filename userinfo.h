#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = 0);
    ~UserInfo();

private slots:

    void on_SaveButton_clicked();

    void on_CloseButton_clicked();\

    void SaveChange();

    void on_EditButton_clicked();

    void on_FaceButton_clicked();

private:
    Ui::UserInfo *ui;
    QString preY,preM,preD;

};

#endif // USERINFO_H
