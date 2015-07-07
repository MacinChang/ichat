#ifndef GROUPINFO_H
#define GROUPINFO_H

#include <QDialog>

namespace Ui {
class GroupInfo;
}

class GroupInfo : public QDialog
{
    Q_OBJECT

public:
    explicit GroupInfo(QWidget *parent = 0);
    ~GroupInfo();

private slots:
    void on_SaveButton_clicked();

    void on_CloseButton_clicked();

    void SaveChange();
    void on_GroupFaceBtn_clicked();

    void on_EditButton_clicked();

private:
    Ui::GroupInfo *ui;
};

#endif // GROUPINFO_H
