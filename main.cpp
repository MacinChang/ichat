#include "logindialog.h"
#include "mainpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDlg;
    MainPanel mainDlg;
    /*if(loginDlg.exec() == QDialog::Accepted){
        mainDlg.show();
        return a.exec();
    }
    else{
        return 0;
    }*/
    mainDlg.show();
    return a.exec();

}
