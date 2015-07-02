#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QFrame>

namespace Ui {
class MainPanel;
}

class MainPanel : public QFrame
{
    Q_OBJECT

public:
    explicit MainPanel(QWidget *parent = 0);
    ~MainPanel();

private slots:
    void on_btnAdd_clicked();

private:
    Ui::MainPanel *ui;
};

#endif // MAINPANEL_H