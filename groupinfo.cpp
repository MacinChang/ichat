#include "groupinfo.h"
#include "ui_groupinfo.h"

GroupInfo::GroupInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupInfo)
{
    ui->setupUi(this);
}

GroupInfo::~GroupInfo()
{
    delete ui;
}
