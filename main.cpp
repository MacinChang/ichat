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
    LoginDialog *loginDlg =new LoginDialog;
    //loginDlg.show();
    if(loginDlg->exec() == QDialog::Accepted){
        return 0;
    }


    return a.exec();

}
