 #include "Employes.h"
#include "MainWindow_em.h"
#include <QSqlError>
#include <QSqlQuery>


Employes::Employes (int ID_EMPLOYE,  QString NOM,QString PRENOM, QString EMAIL , QString SEXE,QString FONCTION ,QString SPECIALITE,int ID_LABO)
 {
this->ID_EMPLOYE=ID_EMPLOYE;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->EMAIL=EMAIL;
    this->SEXE=SEXE;
    this->FONCTION=FONCTION;
    this->SPECIALITE=SPECIALITE;
    this->ID_LABO=ID_LABO;
}


bool Employes::verifierSexe(QString sexe)
{  QString statutMin = sexe.toLower(); // Convertir en minuscules
 return (sexe == "homme" || sexe == "femme");
}


bool Employes::ajouter()
{ SEXE = SEXE.toLower();
    if (SEXE != "homme" && SEXE != "femme") {
           qDebug() << "Erreur: sexe invalide";
           return false;
       }
 QSqlQuery query;
QString res = QString::number(ID_EMPLOYE);
QString ress = QString::number(ID_LABO);
 query.prepare("insert into EMPLOYES (ID_EMPLOYE, NOM, PRENOM, EMAIL, SEXE, FONCTION,SPECIALITE,ID_LABO) values (:ID_EMPLOYE,  :NOM,:PRENOM, :EMAIL, :SEXE, :FONCTION, :SPECIALITE, :ID_LABO)");
 query.bindValue(":ID_EMPLOYE", res);
 query.bindValue(":NOM", NOM);
 query.bindValue(":PRENOM", PRENOM);
 query.bindValue(":EMAIL", EMAIL);
 query.bindValue(":SEXE", SEXE);
 query.bindValue(":FONCTION", FONCTION);
  query.bindValue(":SPECIALITE", SPECIALITE);
  query.bindValue(":ID_LABO", ress);
  qDebug() << "reached end of query";

 return query.exec();


}

QSqlQueryModel * Employes::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from EMPLOYES");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("SEXE"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("FONCTION"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("SPECIALITE"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("ID_LABO"));



return model;

}
bool Employes::supprimer(QString NOM)
{
    QSqlQuery query;
    query.prepare("delete from EMPLOYES where NOM = :NOM ");
    query.bindValue(":NOM", NOM);

    return query.exec();
}
bool Employes::modifier()
{
 QSqlQuery query;
 QString res = QString::number(ID_EMPLOYE);
 QString ress = QString::number(ID_LABO);

    query.prepare("update EMPLOYES set ID_EMPLOYE=:ID_EMPLOYE, NOM=:NOM, PRENOM=:PRENOM, EMAIL=:EMAIL, SEXE=:SEXE, FONCTION=:FONCTION, SPECIALITE=:SPECIALITE where ID_EMPLOYE=:ID_EMPLOYE ");
 query.bindValue(":ID_EMPLOYE", res);

   query.bindValue(":NOM", NOM);
   query.bindValue(":PRENOM", PRENOM);
   query.bindValue(":EMAIL", EMAIL);
   query.bindValue(":SEXE", SEXE);
   query.bindValue(":FONCTION", FONCTION);
   query.bindValue(":SPECIALITE", SPECIALITE);
   query.bindValue(":ID_LABO", ress);
 return query.exec();
}
QSqlQueryModel * Employes::chercher(QString NOM)
{
 QSqlQueryModel * model=new QSqlQueryModel();
 QSqlQuery query;
     query.prepare("SELECT * FROM EMPLOYES WHERE LOWER(NOM) LIKE ?");
     query.addBindValue("%" + NOM.toLower() + "%");
     query.exec();
     model->setQuery(query);

 model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMPLOYE"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("SEXE"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("FONCTION"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("SPECIALITE"));
  model->setHeaderData(7,Qt::Horizontal,QObject::tr("ID_LABO"));
  if (model->rowCount() == 0) {
         QMessageBox::information(nullptr, "Pas de résultat", "Le nom est introuvable.");
     }
 return model;
}

QSqlQueryModel * Employes::tri(int test)
{
    QSqlQueryModel *model=new QSqlQueryModel() ;
    QSqlQuery query ;
    if(test==2)
    {
        query.prepare("SELECT * FROM EMPLOYES  ORDER BY NOM ASC") ;
    }
    else if(test==3)
    {
        query.prepare("SELECT * FROM EMPLOYES ORDER BY FONCTION ASC") ;
    }
    else if(test==4)
    {
        query.prepare("SELECT * FROM EMPLOYES ORDER BY ID_EMPLOYE DESC ") ;

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



