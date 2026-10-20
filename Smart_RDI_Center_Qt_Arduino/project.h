#ifndef PROJECT_H
#define PROJECT_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtDebug>



class Project
{
public:
    //constructeurs
    Project(){}
    Project(int,QString,QString,QString,QDate,QDate,int);
    //getters
    QString getNom(){return nom;}
    QString getUtulisateur(){return utilisateur;}
    QString getDescription(){return description;}
    QDate getDateDeb(){return date_deb;}
    QDate getDateFin(){return date_fin;}
    int getIDprojet(){return id_projet;}
    int getIDemploye(){return id_employe;}
    //setters
    void setNom(QString n){nom=n;}
    void setUtulisateur(QString u){utilisateur=u;}
    void setDescription(QString d){description=d;}
    void setDateDeb(QDate db){date_deb=db;}
    void setDateFin(QDate df){date_fin=df;}
    void setIDprojet(int idp){this->id_projet=idp;}
    void setIDemploye(int ide){this->id_employe=ide;}
    //fonctionalites de base relatives a l entite Project
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel*rechercherID(QString);
    QSqlQueryModel *tri(int test);
    //QSqlQueryModel * chercher(QString nom);

QSqlQueryModel*chercher (QString champ, QString recherche);
private:
    int id_projet,id_employe;
    QString nom,utilisateur,description;
    QDate date_deb,date_fin;


};

#endif // PROJECT_H
