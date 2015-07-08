#include "logindialog.h"
#include "mainpanel.h"
#include "userinfo.h"
#include "groupinfo.h"
#include "chatwindow.h"
#include "friendinfo.h"
#include "chatwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog loginDlg;
    loginDlg.show();
    //ChatWindow cw("66666", "12345", "zhangji");
    //cw.show();
    //MainPanel *mainDlg = new MainPanel("66666");
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
