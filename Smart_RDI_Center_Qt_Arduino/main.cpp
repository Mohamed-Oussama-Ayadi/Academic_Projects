#include "MainWindow_em.h"
#include "Connexion.h"
#include <QApplication>
#include <QMessageBox>
#include <QUrl>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPainter>
#include <QSqlQuery>
#include <QDate>
#include "login.h"

#include"MainWindow_l.h"
#include "MainWindow_spon.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
   connexion connexion;


    bool success = connexion.createconexion();
     login w;
    if (success) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
            QObject::tr("Connection to database was successful. Click cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
            QObject::tr("Connection to database failed. Click cancel to exit."), QMessageBox::Cancel);
    }

    return app.exec();
}




