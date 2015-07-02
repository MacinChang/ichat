#include "logindialog.h"
#include "mainpanel.h"
#include "userinfo.h"
#include "groupinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ld;
    MainPanel mp;
    UserInfo usrInfo;
    GroupInfo groInfo;
 if(ld.exec() == QDialog::Accepted){
      groInfo.show();
        return a.exec();
    }else{
        return 0;
    }
}
