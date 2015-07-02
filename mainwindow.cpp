#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	this->setWindowTitle("iChat");
	ui->pushButton->setText(QStringLiteral("µÇÂ¼"));
	//ui->lineEdit;
}

MainWindow::~MainWindow()
{
    delete ui;
}
