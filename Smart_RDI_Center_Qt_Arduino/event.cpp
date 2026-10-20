#include "event.h"
#include "mainwindow_event.h"
#include <QDateEdit>

Event::Event()
{

}
Event::Event(QDateTime date_debut,QDateTime date_fin, QString lieu,QString theme,QString organisateur, int nb_invites,int sponsor)
{


    this->date_debut=date_debut;
    this->date_fin=date_fin;
    this->lieu=lieu;
    this->theme=theme;
    this->organisateur=organisateur;
    this->nb_invites=nb_invites;
    this->sponsor=sponsor;

}

bool Event::ajouter()
{


    QSqlQuery requete;
    requete.prepare("INSERT INTO EVENTS(date_debut,date_fin, lieu,theme,organisateur, nb_invites,sponsor)"
                    "VALUES (:date_debut,:date_fin, :lieu,:theme,:organisateur, :nb_invites, :sponsor)");


    requete.bindValue(":date_debut",date_debut);
    requete.bindValue(":date_fin",date_fin);
    requete.bindValue(":lieu",lieu);
    requete.bindValue(":theme",theme);
    requete.bindValue(":organisateur",organisateur);
    requete.bindValue(":nb_invites",nb_invites);
    requete.bindValue(":sponsor",sponsor);



    return requete.exec();


}


bool Event::supprimer(int id)
{
    QSqlQuery requete;
    requete.prepare("delete from events where id_event=:id");
    requete.bindValue(":id", id);
    return requete.exec();
}


QSqlQuery Event::rechercher(int id)
{
    QSqlQuery query;

        query.prepare(
            "SELECT date_debut,date_fin,lieu,theme,organisateur,nb_invites FROM events where id_event=:id");
        query.bindValue(":id",id);
        query.exec();
      return query;
}

bool Event::modifier(QDateTime date_debut,QDateTime date_fin, int id, QString lieu, QString theme, QString organisateur, int nb_invites,int sponsor)
{
    QSqlQuery requete;
    requete.prepare("update EVENTS set date_debut=:date_debut, date_fin=:date_fin,lieu=:lieu, theme=:theme,organisateur=:organisateur, nb_invites=:nb_invites, sponsor=:sponsor where id_event=:id");
    requete.bindValue(":date_debut",date_debut);
    requete.bindValue(":date_fin",date_fin);
    requete.bindValue(":lieu",lieu);
    requete.bindValue(":theme",theme);
    requete.bindValue(":organisateur",organisateur);
    requete.bindValue(":nb_invites",nb_invites);
    requete.bindValue(":id",id);
    requete.bindValue(":sponsor",sponsor);
     return requete.exec();


}

QSqlQuery Event::chercher(int id,QString id1)
{

    QSqlQuery query;
    query.prepare("SELECT * FROM events where id_event=:id or lower(theme)=:id1");
    query.bindValue(":id",id);
    query.bindValue(":id1",id1);
    query.exec();

return query;

}


QSqlQueryModel *Event::afficher()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query("select * from events");

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Date début"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date fin"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Lieu"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Theme"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Organisateur"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nb invités"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Sponsor"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Id employe"));
    return model;
}

