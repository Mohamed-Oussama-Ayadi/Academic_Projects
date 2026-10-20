#ifndef EMPLOYES_H
#define EMPLOYES_H
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
//#include"ui_menu.h"

class Employes
{ private:

     int ID_EMPLOYE;
     QString NOM;
     QString PRENOM;
  QString EMAIL;
   QString SEXE;
   QString FONCTION;
    QString SPECIALITE;
   int ID_LABO;




public:

   //Getters

    QString getnom(){return NOM;}
     QString getprenom(){return PRENOM;}
     QString getemail(){return EMAIL;}
    QString getsexe(){return SEXE;}
    QString getfonction(){return FONCTION;}
    QString getspecialite(){return SPECIALITE;}
     int getid_employes(){return ID_EMPLOYE;}

     //int getid_labo(){return ID_LABO;}
     //Setters
    void setnom( QString n){ NOM=n;}
      void  setprenom(QString pe){PRENOM=pe;}
      void setemail(int e){ EMAIL=e;}
    void setsexe(QString se){ SEXE=se;}
    void setfonction(QString fun){ FONCTION=fun;}
    void setspecialite(QString sta){ SPECIALITE=sta;}

     void setid_employes(int id){this->ID_EMPLOYE=id;}
     void setid_labo(int idl){this->ID_LABO=idl;}
     //constructeurs
      Employes(){}
      Employes(int ID_EMPLOYES,  QString NOM,QString PRENOM, QString EMAIL, QString SEXE,QString FONCTION,QString SPECIALITE ,int ID_LABO);
      bool verifierSexe(QString sexe);

    bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(QString NOM);
   bool modifier();
   QSqlQueryModel * chercher(QString NOM);
    QSqlQueryModel * tri(int test);
    bool setModal;
   //cntrl saisie
  // bool verifierStatut(QString statut);
};

#endif // EMPLOYES_H
