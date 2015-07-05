#ifndef ADDWINDOW_H
#define ADDWINDOW_H
#include "QtNetwork/QNetworkReply"
#include "QtNetwork/QNetworkRequest"
#include <QFrame>
#include <QMouseEvent>
#include "additems.h"
#include "confirmwindow.h"
namespace Ui {
class AddWindow;
}

class AddWindow : public QFrame
{
    Q_OBJECT
private:
    QString myAccount;
public:
    explicit AddWindow(QString acc, QWidget *parent = 0);
    ~AddWindow();
    void imgPathToHtml(QString &path);
    QString str;
protected:
    void mousePressEvent(QMouseEvent *);
private:
    Ui::AddWindow *ui;
    confirmWindow *cw;
    QNetworkAccessManager *manager;
private slots:
    void on_pushButton_clicked();
    void replyFinished(QNetworkReply *);
    virtual void headPressEventSlot();
    void on_pushButton_2_clicked();
signals:
    void clicked();
};

#endif // ADDWINDOW_H
