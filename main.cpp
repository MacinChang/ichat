#include "logindialog.h"
#include "mainpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ld;
    ld.show();
    /*if (ld.exec() == QDialog::Accepted)
        {
           w = new MainPanel(account1);
           w->show();
           return a.exec();
        }
    else return 0;*/
    return a.exec();
}
