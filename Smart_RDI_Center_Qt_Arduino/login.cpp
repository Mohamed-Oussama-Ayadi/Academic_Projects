#include "login.h"
#include "ui_login.h"
#include "MainWindow_em.h"
#include "Connexion.h"
#include <QMessageBox>
#include <QDebug>
#include"menu.h"
#include<QDialog>
#include"signupdialog.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("LOGIN");
}

login::~login()
{
    delete ui;
}

void login::on_pb_seconnecter_clicked()
{
    connexion connexion;
    QString nom = ui->nom->text();
    int loginn = ui->password->text().toInt();

    int auth = connexion.Authentification(loginn, nom);
    if (auth == 1) {
        QMessageBox::information(this, "Connexion", "Login et mot de passe corrects");
        qDebug() << "Login et mot de passe corrects";
        this->hide();
        Menu *R = new Menu(this);
        qDebug() << nom;
        qDebug() << loginn;
        /*R->setnom(nom);
        R->setlog(loginn);*/
        R->set_query(nom,loginn);
        R->show();

    } else if (auth == 0) {
        QMessageBox::critical(this, "Connexion", "Login et mot de passe incorrects");
        qDebug() << "Login et mot de passe incorrects";
        this->hide();
    }
}

void login::on_pushButton_clicked()
{
    SignUpDialog *sign=new SignUpDialog(this);
      //if(!sign->exec());
    sign->exec();
}
