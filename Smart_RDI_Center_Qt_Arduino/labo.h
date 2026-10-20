#ifndef LABO_H
#define LABO_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QPixmap>
#include <QSqlQuery>
#include <QtSql>
#include<QMessageBox>
class labo
{ private:
     int id_labo;
     int id_projet;
     QString rules;
   QDateTime date_debut;
    QDateTime date_fin;
public:
    labo();
    labo(int id_labo, int id_projet, QString rules,  QDateTime date_debut , QDateTime date_fin );
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher1();

    bool modifier(QString id_projet);
    QSqlQueryModel* rechercherID(QString );
    QSqlQueryModel* tri(int test);
    QSqlQueryModel* chercher(QString rules);




};

#endif // SPONSOR_H
