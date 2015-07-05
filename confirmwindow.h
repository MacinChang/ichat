#ifndef CONFIRMWINDOW_H
#define CONFIRMWINDOW_H
#include "dividewindow.h"
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class confirmWindow;
}

class confirmWindow : public QDialog
{
    Q_OBJECT
private:
    QString myAccount;
public:
    explicit confirmWindow(QString data, QString myAccount, QWidget *parent = 0);
    ~confirmWindow();
    QString receivedData;
private:
    Ui::confirmWindow *ui;
    DivideWindow *dw;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};

#endif // CONFIRMWINDOW_H
