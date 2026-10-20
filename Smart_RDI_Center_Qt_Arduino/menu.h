#ifndef Menu_H
#define Menu_H

#include<QMainWindow>
#include"QSqlQuery"
#include "Employes.h"
#include"MainWindow_em.h"
#include"mainwindow_event.h"
#include"MainWindow_Equipements.h"
#include"MainWindow_l.h"
#include"labo.h"
#include "sponsor.h"
#include "MainWindow_spon.h"
#include"MainWindow_p.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
   /* void setnom(QString);
    void setlog(int);
    QString getnom();
    int getlog();
private:
    QString nom;
    int log;
*/
    void set_query(QString NOM, int ID_EMPLOYE);
private slots:
    void on_pushButton_37_toggled(bool checked);

    void on_pushButton_33_toggled(bool checked);

    void on_pushButton_50_toggled(bool checked);

    void on_pushButton_54_toggled(bool checked);

    void on_pushButton_42_toggled(bool checked);

    void on_pushButton_46_toggled(bool checked);

    void on_pushButton_58_toggled(bool checked);



    void on_pushButton_10_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_47_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_55_clicked();

    void on_pushButton_19_clicked();




private:
    Ui::Menu *ui;
    MainWindow m;
    Employes E;
    MainWindow_event ev;
MainWindow_Equipements eq;
MainWindow_l l;
MainWindow_p p;
Duratecorporation::MainWindow_spon sp;
};



#endif // Menu_H
