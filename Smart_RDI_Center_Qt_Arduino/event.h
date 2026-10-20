#ifndef EVENT_H
#define EVENT_H
#include<string>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDateTime>


using namespace std;
class Event
{
    int id,nb_invites,sponsor;
    QDateTime date_debut,date_fin;
    QString lieu,theme, organisateur;

public:
    Event();
    Event(QDateTime date_debut,QDateTime date_fin, QString lieu,QString theme,QString organisateur, int nb_invites, int sponsor);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int id);
    QSqlQuery rechercher(int id);
    QSqlQuery chercher(int id,QString id1);
    bool modifier(QDateTime date_debut,QDateTime date_fin, int id, QString lieu, QString theme, QString organisateur, int nb_invites,int sponsor);

};

#endif // EVENT_H
