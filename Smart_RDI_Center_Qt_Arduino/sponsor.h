#ifndef SPONSOR_H
#define SPONSOR_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QPixmap>
#include <QSqlQueryModel>
#include<QDebug>
#include <QMessageBox>
#include <QSqlQuery>

class Sponsor
{ private:

     int id_sponsor;
     QString nom;
     QString type;
  int budget;
   QString statut;
   QDateTime date_statut;
   int id_employe;
   QString image;



public:

   //Getters

    QString getnom(){return nom;}
     QString getype(){return type;}
    int getbudget(){return budget;}
     QString getstatut(){return statut;}
     QDateTime getdate_statut(){return date_statut;}
     int getid_sponsor(){return id_sponsor;}

     //int getid_employe(){return id_employe;}
     //Setters
    void setnom( QString n){ nom=n;}
      void  setype(QString ty){type=ty;}
      void setbudget(int bu){ budget=bu;}
    void setstatut(QString sta){ statut=sta;}
     void setdate_statut(QDateTime ds){date_statut=ds;}
     void setid_sponsor(int id){this->id_sponsor=id;}
     void setid_employe(int idemp){this->id_employe=idemp;}
     //constructeurs
      Sponsor(){}
      Sponsor(int id_sponsor,  QString nom,QString type, int budget,QString statut, QDateTime date_statut,int id_employe,QString image);

    bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int id_sponsor);
   bool modifier();
   QSqlQueryModel * chercher(QString nom);
   QSqlQuery  rechercher(int id);
    QSqlQueryModel * tri(int test);
   //cntrl saisie
   bool verifierStatut(QString statut);
};

#endif // SPONSOR_H
