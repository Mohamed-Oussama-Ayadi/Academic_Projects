
#include "sponsor.h"
#include "MainWindow_spon.h"
#include <QSqlError>
//#include <QSqlQuery>

Sponsor::Sponsor(int id_sponsor,  QString nom,QString type, int budget,QString statut , QDateTime date_statut,int id_employe,QString image)
 { this->id_sponsor=id_sponsor;
   this->nom=nom;
   this->type=type;
   this->budget=budget;
   this->statut=statut;
   this->date_statut = date_statut;
   this->id_employe=id_employe;
    this->image=image;
}


bool Sponsor::verifierStatut(QString statut)
{  QString statutMin = statut.toLower(); // Convertir en minuscules
 return (statut == "accepter" || statut == "refuser");
}

bool Sponsor::ajouter()
{ statut = statut.toLower();
 if (statut != "accepter" && statut != "refuser") {
        qDebug() << "Erreur: statut invalide";
        return false;
    }
 QSqlQuery query;
QString res = QString::number(id_sponsor);
QString ress = QString::number(id_employe);
 query.prepare("insert into SPONSORS (ID_SPONSOR, NOM, TYPE, BUDGET, STATUT, DATE_STATUT,ID_EMPLOYE,IMAGE) values (:id_sponsor, :nom, :type, :budget,:statut, :date_statut,:id_employe, :image)");
 query.bindValue(":id_sponsor", res);
 query.bindValue(":nom", nom);
 query.bindValue(":type", type);
 query.bindValue(":budget", budget);
 query.bindValue(":statut", statut);
 query.bindValue(":date_statut", date_statut);
  query.bindValue(":id_employe", ress);
  query.bindValue(":image", image);
  qDebug() << "reached end of query";

 return query.exec();


}

QSqlQueryModel * Sponsor::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from SPONSORS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SPONSOR"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("BUDGET"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("STATUT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_STATUT"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("IMAGE"));



return model;

}
bool Sponsor::supprimer(int id_sponsor)
{     QString res=QString::number(id_sponsor);
 QSqlQuery query1;
   query1.prepare("select  * from SPONSORS where ID_SPONSOR = :id_sponsor ");
   query1.bindValue(":id_sponsor", res);
   query1.exec();
     if(query1.next())
       {
           QSqlQuery query;

     query.prepare("delete from SPONSORS where ID_SPONSOR = :id_sponsor ");
     query.bindValue(":id_sponsor", res);

     return query.exec();
}
     return false;
}
bool Sponsor::modifier()
{
 QSqlQuery query;
 QString res = QString::number(id_sponsor);
 QString ress = QString::number(id_employe);

 query.prepare("update SPONSORS set NOM=:nom, TYPE=:type, BUDGET=:budget, STATUT=:statut, DATE_STATUT=:date_statut, ID_EMPLOYE=:id_employe"
               ",IMAGE=:image where ID_SPONSOR=:id_sponsor");
 query.bindValue(":id_sponsor", res);
 query.bindValue(":nom", nom);
 query.bindValue(":type", type);
 query.bindValue(":budget", budget);
 query.bindValue(":statut", statut);
 query.bindValue(":date_statut", date_statut);
 query.bindValue(":id_employe", ress);
  query.bindValue(":image", image);
 return query.exec();
}
QSqlQueryModel * Sponsor::chercher(QString nom)
{
 QSqlQueryModel * model=new QSqlQueryModel();
 QSqlQuery query;
     query.prepare("SELECT * FROM SPONSORS WHERE LOWER(NOM) LIKE ?");
     query.addBindValue("%" + nom.toLower() + "%");
     query.exec();
     model->setQuery(query);

 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_SPONSOR"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("BUDGET"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("STATUT"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_STATUT"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
  model->setHeaderData(7,Qt::Horizontal,QObject::tr("IMAGE"));
  if (model->rowCount() == 0) {
         QMessageBox::information(nullptr, "Pas de résultat", "Le nom est introuvable.");
     }
 return model;
}
QSqlQuery Sponsor::rechercher(int id)
{
    QSqlQuery query;

        query.prepare(
            "SELECT NOM,TYPE,BUDGET,STATUT,DATE_STATUT,ID_EMPLYE,IMAGE FROM SPONSORS where ID_SPONSOR=:id");
        query.bindValue(":id",id);
        query.exec();
      return query;
}
QSqlQueryModel * Sponsor::tri(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;
    if(test==2)
    {
        query.prepare("SELECT * FROM SPONSORS ORDER BY ID_SPONSOR ASC") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT * FROM SPONSORS ORDER BY NOM ASC") ;
    }
    else if(test==4)
    {
        query.prepare("SELECT * FROM SPONSORS ORDER BY BUDGET DESC ") ;

    }
    if (query.lastError().isValid()) {
        qDebug() << query.lastError();
    }

    if (query.exec())
    {
        model->setQuery(query) ;
    }
    return model;
}



