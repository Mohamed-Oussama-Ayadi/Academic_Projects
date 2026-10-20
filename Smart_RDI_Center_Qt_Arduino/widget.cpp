#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include "dumessangerconnectiondialog.h"
#include <QTextStream>
namespace  Duratecorporation {


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket=new QTcpSocket(this);
connect(mSocket,&QTcpSocket::readyRead , [&](){
    QTextStream T(mSocket);
    auto text = T.readAll();
    ui->textEdit->append(text);
        });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_envoyer_clicked()
{
QTextStream T(mSocket);
T <<ui->username->text() <<":"<< ui->message->text();
mSocket->flush();
ui->message->clear();
}

void Widget::on_connecter_clicked()
{
DuMessangerConnectionDialog D(this);
if(D.exec()==QDialog::Rejected){
    return;
}
 mSocket->connectToHost(D.Hostname(),D.Port());
}
}
