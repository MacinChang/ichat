#ifndef MAINPANEL_H
#define MAINPANEL_H
#include "addwindow.h"
#include <QFrame>

namespace Ui {
class MainPanel;
}

class MainPanel : public QFrame
{
    Q_OBJECT

public:
    explicit MainPanel(QString acc,QWidget *parent = 0);
    ~MainPanel();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::MainPanel *ui;
    QString myAccount;
    AddWindow* aw;

};

#endif // MAINPANEL_H
