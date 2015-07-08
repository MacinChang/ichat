#ifndef CHATMSGDLG_H
#define CHATMSGDLG_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class chatMsgDlg;
}

class chatMsgDlg : public QWidget
{
    Q_OBJECT

public:
    explicit chatMsgDlg(QString a,QString b,QWidget *parent = 0);
    ~chatMsgDlg();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::chatMsgDlg *ui;
    QString a;
    QString b;
    QPoint dragPosition;
};

#endif // CHATMSGDLG_H
