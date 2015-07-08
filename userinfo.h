#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include <qpoint.h>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class UserInfo;
}

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QString account,QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    ~UserInfo();

private slots:

    void on_SaveButton_clicked();

    void on_CloseButton_clicked();\

    void on_EditButton_clicked();

    void on_FaceButton_clicked();

    void finishedSlot(QNetworkReply*);

    void uploadfinishedSlot(QNetworkReply*);

    void faceuploadfinishedsolt(QNetworkReply*);

    void on_HomeP_activated();

    void on_HomeC_activated();

    void on_LocalP_activated();

    void on_LocalC_activated();

    void on_MonthCombo_activated();

    void on_pushButton_clicked();

private:
    Ui::UserInfo *ui;
    QString preY,preM,preD,preHP,preHC,preHL,preLP,preLC,preLL,preSex;
    QStringList hp,hc1,hc2,ha1,ha2,ha3,ha4,lp,lc1,lc2,la1,la2,la3,la4;
    QPoint dragPosition;
    QString myaccount;
    QNetworkAccessManager *manager1,*manager2,*manager3;

};

#endif // USERINFO_H
