#ifndef DIVIDEWINDOW_H
#define DIVIDEWINDOW_H
#include "addfinishedwindow.h"
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
namespace Ui {
class DivideWindow;
}

class DivideWindow : public QDialog
{
    Q_OBJECT
private:
    QNetworkAccessManager *nam;
    QString myAccount;
    QString verifyInfo;
    AddFinishedWindow *afw;
public:
    explicit DivideWindow(QString myAccount, QString  VerifyInfo, QString data,QWidget *parent = 0);
    ~DivideWindow();
    QString re;
private:
    Ui::DivideWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void replyFinished(QNetworkReply *);
};

#endif // DIVIDEWINDOW_H
