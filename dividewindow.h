#ifndef DIVIDEWINDOW_H
#define DIVIDEWINDOW_H
#include "addfinishedwindow.h"
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "QMouseEvent"
#include "QVector"
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
    QVector<QString> class_id;
public:
    explicit DivideWindow(QString myAccount, QString  VerifyInfo, QString data,QWidget *parent = 0);
    ~DivideWindow();
    QString re;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    QPoint dragPosition;
private:
    Ui::DivideWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void replyFinished(QNetworkReply *);
    void infoReplyFinished(QNetworkReply *);
    void on_closeBtn_clicked();
signals:
    void addContactFinished();
};

#endif // DIVIDEWINDOW_H
