#include "logindialog.h"
#include "mainpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    LoginDialog ld;
    MainPanel mp;
    if(ld.exec() == QDialog::Accepted){
        mp.show();
        return a.exec();
    }else{
        return 0;
    }
    //return a.exec();
}
