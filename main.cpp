#include "logindialog.h"
#include "mainpanel.h"
#include "userinfo.h"
#include "groupinfo.h"
#include "friendinfo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ld;
    MainPanel mp;
    UserInfo usrInfo;
    GroupInfo groInfo;
    FriendInfo frInfo;
 if(ld.exec() == QDialog::Accepted){
   frInfo.show();
        return a.exec();
    }else{
        return 0;
    }
}
