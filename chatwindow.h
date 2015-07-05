#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include <QMouseEvent>
#include <QFrame>
#include "QPropertyAnimation"
namespace Ui {
class ChatWindow;
}

class ChatWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();
    QPropertyAnimation *m_animation;
    void imgPathToHtml(QString &path);
    void ShakeAnimation();
private:
    Ui::ChatWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
};

#endif // CHATWINDOW_H
