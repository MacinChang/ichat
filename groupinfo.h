#ifndef GROUPINFO_H
#define GROUPINFO_H

#include <QDialog>
#include <qpoint.h>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "QMessageBox"
#include "QFileDialog"
#include <QMouseEvent>
#include <QJsonArray>
#include <QJsonObject>
#include <QScriptEngine>
#include <QScriptValueIterator>
#include <QtGui>
#include <QDrag>


namespace Ui {
class GroupInfo;
}

class GroupInfo : public QDialog
{
    Q_OBJECT

public:
    explicit GroupInfo(QString groupaccount, QWidget *parent = 0);
    ~GroupInfo();

private slots:
    void on_SaveButton_clicked();

    void on_CloseButton_clicked();

    void on_GroupFaceBtn_clicked();

    void on_EditButton_clicked();

    void finishedSlot(QNetworkReply*);

    void uploadfinishedSlot(QNetworkReply*);

private:
    Ui::GroupInfo *ui;
    QNetworkAccessManager *manager1,*manager2,*manager3;
    QString groupAccount;

};

#endif // GROUPINFO_H
