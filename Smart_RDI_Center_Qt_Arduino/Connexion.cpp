#include "Connexion.h"
#include "ui_login.h"
#include "Employes.h"


connexion::connexion(){}
bool connexion::createconexion()

    {bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet2A");
    db.setUserName("nour1");//inserer nom de l'utilisateur
    db.setPassword("nour1");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;
        return  test;
    }
int connexion::Authentification(int loginn,QString nom)
{
    QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        QString log=QString::number(loginn);
        query.prepare("SELECT * FROM EMPLOYES where ID_EMPLOYE=\'"+log+"\' AND NOM=\'"+nom+"\'");

        query.exec();
        if (query.next())
        {
             return 1;
        }

        else {
            return 0;
        }



}
