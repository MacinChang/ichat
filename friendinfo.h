#ifndef FRIENDINFO_H
#define FRIENDINFO_H

#include <QDialog>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class FriendInfo;
}

class FriendInfo : public QDialog
{
    Q_OBJECT

public:
    explicit FriendInfo(QString account,QWidget *parent = 0);
    ~FriendInfo();
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);

private slots:
    void finishedSlot(QNetworkReply*);

    void on_ConfirmButton_clicked();

    void on_smallButton_clicked();

private:
    Ui::FriendInfo *ui;
    QNetworkAccessManager *manager1;
    QStringList hp,hc1,hc2,ha1,ha2,ha3,ha4,lp,lc1,lc2,la1,la2,la3,la4;
    QString friendaccount;
    QPoint dragPosition;
};


#endif // FRIENDINFO_H
