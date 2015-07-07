#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMouseEvent>
#include <QPoint>


namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);

    ~LoginDialog();

private:
    Ui::LoginDialog *ui;
    QNetworkAccessManager *nam;
    QPoint dragPosition;
    QString account,password;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void replyFinished(QNetworkReply *);

};

#endif // LOGINDIALOG_H
