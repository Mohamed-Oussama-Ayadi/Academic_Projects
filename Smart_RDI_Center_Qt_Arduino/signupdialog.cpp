#include "signupdialog.h"
#include "ui_signupdialog.h"
#include <stdlib.h>
#include <ctime>
#include <QSqlQuery>
#include <QDebug>
SignUpDialog::SignUpDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SignUpDialog)
{
  setFixedSize(260,130);
  act = nullptr;
  smtp = nullptr;
  ui->setupUi(this);
  mydb=QSqlDatabase::addDatabase("QODCB");
  //distination of ur db.
  mydb.setDatabaseName("source_projet2A");

  if(mydb.open()){
      qDebug()<<"Dialog Connected";
    }

}

SignUpDialog::~SignUpDialog()
{
  delete ui;
}

void SignUpDialog::on_pushButton_clicked()
{
  QSqlQuery sql;
  if(sql.exec("select * from EMPLOYES where EMAIL ='" + ui->email_le->text()+ "'")){
      qDebug()<<"DONE DONE DONE";

      qDebug() << sql.lastError().text();

      int count{0};
      if(sql.next()){
          count++;

        }
      if(count ==1){
          QMessageBox::warning(this,"System Message !", "Email Already Exist!",QMessageBox::Ok);

          return;
        }
    }if(sql.exec("select * from EMPLOYES where NOM ='" + ui->uname->text()+ "'")){
      qDebug()<<"MOGA";
      int count=0;
      if(sql.next()){
          count++;
        }
      if(count==1){

          QMessageBox::warning(this,"System Message!","UserName is Already Exist please Enter Another Username !",QMessageBox::Ok);
          return;
        }



    }
  sendMail();
  ui->pushButton->setEnabled(false);


}
unsigned int SignUpDialog::getRan() const
{
  return ran;
}


void SignUpDialog::sendMail()
{
    //your email ,your password , smtp server ,port
  smtp = new Smtp("nawel.kaabi@esprit.tn" , "vyuzogohebegjfox", "smtp.gmail.com",465);
  connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  ran=std::rand();
  msg ="Welcome To Launcher Application please copy this number and place it : "+QString::number(ran);
  // qDebug()<<msg;
  //your email
  smtp->sendMail("nawel.kaabi@esprit.tn", ui->email_le->text() , "Launcher Application code : "+QString::number(ran),msg);

}

void SignUpDialog::mailSent(QString status)
{
  //  if(smtp == nullptr) return;
  if(status == "Message sent"){
      //      disconnect(SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
      //      if(smtp != nullptr){
      //          smtp->deleteLater();
      //          smtp = nullptr;
      //        }
      if(!(ui->uname->text()==""||ui->pass->text()=="")){

          //          if(act == nullptr){
        //  act= new ActivatonCodeClass(this);
          /*  connect(act,&ActivatonCodeClass::accepted,this,[](){

                  qDebug()<<"Acccepted!";


                });*/

          act->setCode(ran);

          act->setUname(ui->uname->text());
          act->setPass(ui->pass->text());

          //              if(!act->exec()){
          //                  if(act->result() == QDialog::Accepted)
          //                    qDebug() << "acepted .......";
          //                }
          act->setEmail(ui->email_le->text());
          act->raise();
          act->activateWindow();
          act->show();

          this->hide();

        }
    }else{
      ui->pushButton->setEnabled(true);

    }

}

//}
//}


