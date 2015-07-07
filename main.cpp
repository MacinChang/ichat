#include "logindialog.h"
#include "mainpanel.h"
#include "userinfo.h"
#include "groupinfo.h"
#include "friendinfo.h"
#include "chatwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDlg;
    loginDlg.show();
    //MainPanel *mainDlg = new MainPanel("12345");
    /*if(loginDlg.exec() == QDialog::Accepted){
        mainDlg.show();
        return a.exec();
    }
    else{
        return 0;
    }*/
    //mainDlg->show();
    return a.exec();

}
