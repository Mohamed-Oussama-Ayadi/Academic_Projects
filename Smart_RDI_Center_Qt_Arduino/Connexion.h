#ifndef CONNEXION_H
#define CONNEXION_H
#include<QSqlDatabase>

class connexion
{   QSqlDatabase db;
public:
    connexion();

    bool createconexion();
    void closeconnexion();
     int Authentification(int loginn,QString nom);
};
#endif // CONNEXION_H
