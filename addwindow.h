#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QFrame>

namespace Ui {
class AddWindow;
}

class AddWindow : public QFrame
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = 0);
    ~AddWindow();

private:
    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
