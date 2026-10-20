#include "project.h"
#include "MainWindow_p.h"
#include<QSqlError>
#include <QMediaPlayer>


Project::Project(int id_projet,QString nom,QString utilisateur,QString description,QDate date_deb,QDate date_fin,int id_employe)
{
   this->id_projet=id_projet;
   this->nom=nom;
   this->utilisateur=utilisateur;
   this->description=description;
   this->date_deb=date_deb;
   this->date_fin=date_fin;
   this->id_employe=id_employe;
}
bool Project::ajouter()

    {
       QSqlQuery query;
       QString res = QString::number(id_projet);
       QString ress = QString::number(id_employe);
       query.prepare("INSERT INTO PROJETS (ID_PROJET, NOM, UTILISATEUR, DESCRIPTION, DATE_DEBUT, DATE_FIN, ID_EMPLOYE) VALUES (:id_projet, :nom, :utilisateur, :description, :date_deb, :date_fin, :id_employe)");
       query.bindValue(":id_projet", res);
       query.bindValue(":nom", nom);
       query.bindValue(":utilisateur", utilisateur);
       query.bindValue(":description", description);
       query.bindValue(":date_deb", date_deb);
       query.bindValue(":date_fin", date_fin);
       query.bindValue(":id_employe", ress);
       qDebug() << "Reached end of query";

       if (!query.exec()) {
           qDebug() << "Error executing query: " << query.lastError().text();
           return false;
       }

       return true;
    }

QSqlQueryModel * Project::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from PROJETS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PROJET"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("UTILISATEUR"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DESCRIPTION"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_FIN"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
    return model;

}
bool    Project::supprimer(int id_projet)
{
    QString res=QString::number(id_projet);
    QSqlQuery query1;
    query1.prepare("select * from PROJETS where ID_PROJET = :id_projet ");
    query1.bindValue(":id_projet",res);
    query1.exec();
    if(query1.next())
    {
        QSqlQuery query;

        query.prepare("delete from PROJETS where ID_PROJET = :id_projet ");
        query.bindValue(":id_projet",res);

        return query.exec();
    }
    return false;
}
bool Project::modifier()
{
    QSqlQuery query;
    QString res = QString::number(id_projet);
    QString ress = QString::number(id_employe);

    query.prepare("update  PROJETS set NOM=:nom, UTILISATEUR=:utilisateur, DESCRIPTION=:description, DATE_DEBUT=:date_deb, DATE_FIN=:date_fin, ID_EMPLOYE=:id_employe where ID_PROJET=:id_projet");
    query.bindValue(":id_projet", res);
    query.bindValue(":nom", nom);
    query.bindValue(":utilisateur", utilisateur);
    query.bindValue(":description", description);
    query.bindValue(":date_deb", date_deb);
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":id_employe", ress);
    return query.exec();
}

QSqlQueryModel* Project ::rechercherID(QString NOM)
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT * FROM PROJETS where NOM LIKE '"+NOM+"%' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("UTILISATEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_FIN"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));

    return model;

}


/*
QSqlQueryModel * Project::chercher(QString nom)
{
 QSqlQueryModel * model=new QSqlQueryModel();
 QSqlQuery query;
     query.prepare("SELECT * FROM PROJECTS WHERE LOWER(NOM) LIKE ?");
     query.addBindValue("%" + nom.toLower() + "%");
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("UTILISATEUR"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_FIN"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
  if (model->rowCount() == 0) {
         QMessageBox::information(nullptr, "Pas de résultat", "Le nom est introuvable.");
     }
 return model;
}*/
QSqlQueryModel* Project::chercher (QString champ, QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString query = "SELECT * FROM PROJETS WHERE " + champ + " LIKE '" + recherche + "%'";
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROJET"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("UTILISATEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DEBUT"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATE_FIN"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("ID_EMPLOYE"));
    return model;
}

QSqlQueryModel * Project::tri(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;
    if(test==1)
    {
        query.prepare("SELECT * FROM PROJETS ORDER BY NOM ASC") ;
    }
    /*else if(test==3)
    {
        query.prepare("SELECT * FROM PROJETS ORDER ID_PROJET  ASC") ;
    }
    else if(test==4)
    {
        query.prepare("SELECT * FROM PROJETS ORDER BY ID_PROJET  DESC ") ;

    }*/
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
    }

    if (query.exec())
    {
        model->setQuery(query) ;
    }
    return model;
}
