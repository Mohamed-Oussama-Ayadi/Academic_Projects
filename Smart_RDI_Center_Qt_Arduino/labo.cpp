#include"MainWindow_l.h"
#include "labo.h"


labo::labo()
{ id_labo=0;
    id_projet=0;
    rules="_";
  }



labo::labo(int id_labo, int id_projet, QString rules,  QDateTime date_debut , QDateTime date_fin )
    { this->id_labo=id_labo;
      this->id_projet=id_projet;
           this->rules=rules;
      this->date_debut=date_debut;
      this->date_fin=date_fin;




}

bool labo::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_labo);
    QString ress = QString::number(id_projet);
      //query.exec("insert into ")
    query.prepare("insert into LABORATOIRES (ID_LABO, RULES, ID_PROJET, DATE_DEBUT, DATE_FIN)" "values (:id_labo,  :rules,:id_projet, :date_debut, :date_fin)");
    query.bindValue(":id_labo", res);
    query.bindValue(":rules", rules);
    if (rules != "accepter" && rules != "refuser") {
               qDebug() << "Erreur: statut invalide";
               return false;
           }
    query.bindValue(":id_projet", ress);
    query.bindValue(":date_debut", date_debut);
    query.bindValue(":date_fin", date_fin);
    qDebug() << "reached end of query";
    return query.exec();
}

bool labo::supprimer(int id_labo)
{
    QSqlQuery query;
    QString res=QString::number(id_labo);
    query.prepare("delete from LABORATOIRES where ID_LABO = :id_labo ");
    query.bindValue(":id_labo",res);

    return query.exec();
}

QSqlQueryModel * labo::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from LABORATOIRES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_LABO"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("RULES"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID_PROJET"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_FIN"));

return model;

}



bool labo :: modifier(QString recherche)
{
    QSqlQuery query;
        query.prepare("UPDATE LABORATOIRES SET ID_LABO = :id_labo, RULES = :rules, ID_PROJET = :id_projet, DATE_DEBUT = :date_debut, DATE_FIN = :date_fin WHERE ID_LABO LIKE '"+recherche+"%'");
        query.bindValue(":id_labo",id_labo);
        query.bindValue(":rules",rules);
        query.bindValue(":id_projet",id_projet);
        query.bindValue(":date_debut",date_debut);
        query.bindValue(":date_fin",date_fin);

        query.exec();
       return  query.exec();
}

QSqlQueryModel* labo ::rechercherID(QString recherche)
{
    QSqlQueryModel* model=new QSqlQueryModel();



    model->setQuery("SELECT * FROM LABORATOIRES where ID_LABO '"+recherche+"%' ");

    model->setQuery("select * from LABORATOIRES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_LABO"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("RULES"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID_PROJET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_FIN"));

    return model;
}

QSqlQueryModel * labo::tri(int test)
{
    QSqlQueryModel * model= new QSqlQueryModel();
      QString SortBy;
      switch(test)
      {
          case 1:
          {
              SortBy = "SELECT * FROM LABORATOIRES ORDER BY ID_LABO ASC";
              break;
          }
          case 2:
          {
              SortBy = "SELECT * FROM LABORATOIRES ORDER BY ID_LABO DESC";
              break;
          }
          case 3:
          {
              SortBy = "SELECT * FROM LABORATOIRES ORDER BY ID_PROJET ASC";
              break;
          }
          case 4:
          {
              SortBy = "SELECT * FROM LABORATOIRES ORDER BY ID_PROJET DESC";
              break;
          }
          case 5:
          {
              SortBy = "SELECT * FROM LABORATOIRES ORDER BY DATE_DEBUT ASC";
              break;
          }
          case 6:
          {
              SortBy = "SELECT * FROM LABORATOIRES ORDER BY DATE_DEBUT DESC";
              break;
          }
      }

      model->setQuery(SortBy);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID LABO"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("RULES"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID PROJET"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE DEBUT"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE FIN."));

      return model;
}

QSqlQueryModel * labo::chercher(QString rules)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM LABORATOIRES WHERE RULES LIKE '%"+rules+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_LABO"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("RULES"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID_PROJET"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_DEBUT"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_FIN"));
    return model;
}


QSqlQueryModel * labo::afficher1()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select * from EMPLOYES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("SEXE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("FONCTION"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("SPECIALITE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_LABO"));


return model;

}



