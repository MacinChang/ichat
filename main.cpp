#include "logindialog.h"
#include "mainpanel.h"
#include "userinfo.h"
#include "groupinfo.h"
#include "chatwindow.h"
#include "friendinfo.h"
#include "chatwindow.h"
#include "connect.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    if (!createConnection())
           return 1;
    LoginDialog *loginDlg =new LoginDialog;
    if(loginDlg->exec() == QDialog::Accepted){
        return 0;
    }

    return a.exec();
}
