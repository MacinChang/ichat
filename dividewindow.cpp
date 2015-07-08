#include "dividewindow.h"
#include "ui_dividewindow.h"
#include "QtScript/QScriptValue"
#include "QtScript/QScriptEngine"
#include "QtScript/QScriptValueIterator"
DivideWindow::DivideWindow(QString myAccount, QString verifyInfo, QString data,QWidget *parent) :
    QDialog(parent),re(data), myAccount(myAccount), verifyInfo(verifyInfo),
    ui(new Ui::DivideWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(this->width(), this->height());
    QScriptValue sc;
    QScriptEngine engine;
    sc=engine.evaluate("value="+re);
    QScriptValueIterator it(sc);
    it.next();
    it.next();
    QString account=it.value().toString();
    ui->label_2->setText(account);
    it.next();
    QString nickname=it.value().toString();
    ui->label_8->setText(nickname);
    it.next();
    //设置头像
    QByteArray head,face;
            QString str(it.value().toString());
            int j = str.indexOf('-');
            while(j!=-1){
                str[j] = '+';
                j = str.indexOf('-');
            }
            head = QByteArray::fromBase64(str.toLatin1());
            face = qUncompress(head);
            QImage img;
            img.loadFromData(face);
            ui->faceButton->setIcon(QPixmap::fromImage(img));

    it.next();
    it.next();it.next();
    QString sex=it.value().toString();
    ui->label_5->setText("性别  "+sex);
    it.next();
    QString age=it.value().toString();
    ui->label_7->setText("年龄  "+age);
    it.next();it.next();it.next();
    QString location=it.value().toString();
    ui->label_6->setText("所在地  "+location);
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    dragPosition = QPoint(-1,-1);
    //获取分组信息
    QNetworkAccessManager *infoManager = new QNetworkAccessManager(this);
    QObject::connect(infoManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(infoReplyFinished(QNetworkReply*)));
    QUrl url("http://182.92.69.19/ichat-server/public/user/load-panel");
    QByteArray usr = myAccount.toLocal8Bit();
    QByteArray append("account="+usr);
    infoManager->post(QNetworkRequest(url), append);
}

DivideWindow::~DivideWindow()
{
    delete ui;
}

void DivideWindow::on_pushButton_2_clicked()
{
    this->close();
}

void DivideWindow::on_pushButton_clicked()
{
    int index = ui->groupBox->currentIndex();
    QByteArray from  = myAccount.toLocal8Bit();
    QByteArray to = ui->label_2->text().toLocal8Bit();
    QByteArray remark = ui->lineEdit->text().toLocal8Bit();
    QByteArray id = class_id.at(index).toLocal8Bit();
    QUrl url("http://182.92.69.19/ichat-server/public/user/add-contact");
    if(remark == ""){
        remark = "null";
    }
    QByteArray append("from=" + from + "&to=" + to + "&remark=" + remark + "&class_id=" + id);
    nam->post(QNetworkRequest(url), append);

}
void DivideWindow::replyFinished(QNetworkReply *reply){
    QVariant vRes = reply->readAll();
    QString  res = vRes.toString();
    if(res == "true"){

        emit addContactFinished();
        this->close();
        afw = new AddFinishedWindow();
        afw->show();
    }
}

void DivideWindow::infoReplyFinished(QNetworkReply *reply)
{
    //获取分组名  classid
    QVariant vRes = reply->readAll();
    QString  res = vRes.toString();
    int leftIndex,rightIndex;
    leftIndex = res.indexOf("classname");
    res = res.mid(leftIndex);
    while(res.indexOf("classname") != -1){
        leftIndex = res.indexOf("classname")+12;
        rightIndex = res.indexOf("class_id")-4;
        QString groupName = res.mid(leftIndex,rightIndex-leftIndex+1);
        leftIndex = res.indexOf("class_id")+11;
        rightIndex = res.indexOf("contact")-4;
        class_id.append(res.mid(leftIndex,rightIndex-leftIndex+1));
        ui->groupBox->addItem(groupName);
        leftIndex = res.indexOf("classname",10);
        if(leftIndex == -1){
            break;
        }
        else{
            res = res.mid(leftIndex);
        }
    }
}

void DivideWindow::on_closeBtn_clicked()
{
    this->hide();
}

void DivideWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = e->globalPos()-frameGeometry().topLeft();
        QPoint p = e->pos();
        e->accept();
    }
    else dragPosition = QPoint(-1,-1);
}

void DivideWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(dragPosition != QPoint(-1,-1)){
        move(e->globalPos()-dragPosition);
    }
    e->accept();

}
void DivideWindow::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        dragPosition = QPoint(-1,-1);
        e->accept();
    }
}
