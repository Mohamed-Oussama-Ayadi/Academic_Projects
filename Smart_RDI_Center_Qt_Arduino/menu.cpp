#include <QPixmap>
#include <QGridLayout>
#include "menu.h"
#include "ui_menu.h"
#include"MainWindow_em.h"
#include"login.h"
#include"QDebug"
#include"QSqlQuery"
#include "Employes.h"
#include"QDialog"
#include"MainWindow_l.h"
#include"labo.h"
#include "MainWindow_spon.h"
#include "sponsor.h"
#include"MainWindow_p.h"
#include <QPushButton>
#include <QApplication>

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{

    ui->setupUi(this);

    /* QPushButton* quitButton = new QPushButton("Quit", this);
        quitButton->setGeometry(QRect(QPoint(10, 10), QSize(50, 30)));*/
        connect(ui->pushButton_19, SIGNAL(clicked()), qApp, SLOT(quit()));
   connect(ui->pushButton_37, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_37_toggled(bool)));

          /*  QString x = getnom();
            int y = getlog();
            qDebug()<< x;
            qDebug()<< y;*/

              on_pushButton_37_toggled(true);

              on_pushButton_50_toggled(false);
              on_pushButton_54_toggled(false);
              on_pushButton_42_toggled(false);
              on_pushButton_46_toggled(false);
              on_pushButton_58_toggled(false);
              on_pushButton_33_toggled(false);


                  //QPixmap pix(":/img/back.png");
                  //ui->label->setPixmap(pix.scaled(1500,900,Qt::KeepAspectRatio));
                  ui->sidebar->hide();
                  ui->widget_9->hide();
                  ui->widget_17->hide();
                  ui->widget_20->hide();
                  ui->widget_23->hide();
                  ui->widget_26->hide();
                  ui->widget_29->hide();


              }
void Menu::set_query(QString NOM, int ID_EMPLOYE)
{


              // Query the database for the user's information
              QSqlQuery query;
              query.prepare("SELECT FONCTION,PRENOM FROM EMPLOYES WHERE NOM= :NOM AND ID_EMPLOYE = :ID_EMPLOYE");
              query.bindValue(":NOM", NOM);
              query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
              query.exec();


              if (query.next()) {

                  QString FONCTION = query.value(0).toString();
                    ui->label_3->setText(NOM+' '+query.value(1).toString());
                  if(FONCTION =="ingenieur")
                  {
                      ui->pushButton_10->setEnabled(true);//employe
                      ui->pushButton_51->setEnabled(false);//materiels

                      ui->pushButton_55->setEnabled(false);//projets
                      ui->pushButton_43->setEnabled(false);//labo
                      ui->pushButton_47->setEnabled(false);//sponseur
                       ui->pushButton_59->setEnabled(false);//event
                  }
                  if(FONCTION =="Equipements")
                  {
                      ui->pushButton_10->setEnabled(false);//employe
                      ui->pushButton_51->setEnabled(true);//materiels

                      ui->pushButton_55->setEnabled(false);//projets
                      ui->pushButton_43->setEnabled(false);//labo
                      ui->pushButton_47->setEnabled(false);//sponseur
                       ui->pushButton_59->setEnabled(false);//event
                  }
                  if(FONCTION =="Projet")
                  {
                      ui->pushButton_10->setEnabled(false);//employe
                      ui->pushButton_51->setEnabled(false);//materiels

                      ui->pushButton_55->setEnabled(true);//projets
                      ui->pushButton_43->setEnabled(false);//labo
                      ui->pushButton_47->setEnabled(false);//sponseur
                       ui->pushButton_59->setEnabled(false);//event
                  }
                  if(FONCTION =="Laboratoire")
                  {
                      ui->pushButton_10->setEnabled(false);//employe
                      ui->pushButton_51->setEnabled(false);//materiels

                      ui->pushButton_55->setEnabled(false);//projets
                      ui->pushButton_43->setEnabled(true);//labo
                      ui->pushButton_47->setEnabled(false);//sponseur
                       ui->pushButton_59->setEnabled(false);//event
                  }
                       if(FONCTION=="Evenement")
                                     {
                                         ui->pushButton_10->setEnabled(true);
                                         ui->pushButton_51->setEnabled(true);
                                         ui->pushButton_55->setEnabled(true);
                                         ui->pushButton_43->setEnabled(true);
                                         ui->pushButton_47->setEnabled(true);
                                         ui->pushButton_59->setEnabled(true);

                                     }
                       if(FONCTION=="sponsor")
                                     {
                                         ui->pushButton_10->setEnabled(false);
                                         ui->pushButton_51->setEnabled(false);
                                         ui->pushButton_55->setEnabled(false);
                                         ui->pushButton_43->setEnabled(false);
                                         ui->pushButton_47->setEnabled(true);
                                         ui->pushButton_59->setEnabled(false);

                                     }
                       if(FONCTION=="admin")
                                     {
                                         ui->pushButton_10->setEnabled(true);
                                         ui->pushButton_51->setEnabled(true);
                                         ui->pushButton_55->setEnabled(true);
                                         ui->pushButton_43->setEnabled(true);
                                         ui->pushButton_47->setEnabled(true);
                                         ui->pushButton_59->setEnabled(true);

                                     }

}
}


Menu::~Menu()
{
    delete ui;
}
/*void Menu::setnom(QString x)
{
    nom = x;
}
void Menu::setlog(int x)
{
    log = x;
}

QString Menu::getnom()
{
    return nom;
}
int Menu::getlog()
{
    return log;
}
*/


void Menu::on_pushButton_37_toggled(bool checked)
{

    if(checked)
    {
            ui->taches->resize(1500,621);
            ui->label->move(1170,-40);
            ui->label_2->move(500,0);
    }
    else
    {
            ui->label->move(1020,-40);
            ui->taches->resize(1270,621);
            ui->label_2->move(360,0);
    }
}

void Menu::on_pushButton_33_toggled(bool checked)
{
    if(!checked)
    {
        QIcon *ico = new QIcon();
            ico->addPixmap(QPixmap(":/Icones/Icones/up.png"),QIcon::Normal,QIcon::Off);
            ico->addPixmap(QPixmap(":/Icones/Icones/fleche.png"),QIcon::Normal,QIcon::On);
            ui->pushButton_33->setIcon(*ico);
    }
}

void Menu::on_pushButton_50_toggled(bool checked)
{
    if(!checked)
    {
        QIcon *ico = new QIcon();
            ico->addPixmap(QPixmap(":/Icones/Icones/up.png"),QIcon::Normal,QIcon::Off);
            ico->addPixmap(QPixmap(":/Icones/Icones/fleche.png"),QIcon::Normal,QIcon::On);
            ui->pushButton_50->setIcon(*ico);
    }
}

void Menu::on_pushButton_54_toggled(bool checked)
{
    if(!checked)
    {
        QIcon *ico = new QIcon();
            ico->addPixmap(QPixmap(":/Icones/Icones/up.png"),QIcon::Normal,QIcon::Off);
            ico->addPixmap(QPixmap(":/Icones/Icones/fleche.png"),QIcon::Normal,QIcon::On);
            ui->pushButton_54->setIcon(*ico);
    }
}

void Menu::on_pushButton_42_toggled(bool checked)
{
    if(!checked)
    {
        QIcon *ico = new QIcon();
            ico->addPixmap(QPixmap(":/Icones/Icones/up.png"),QIcon::Normal,QIcon::Off);
            ico->addPixmap(QPixmap(":/Icones/Icones/fleche.png"),QIcon::Normal,QIcon::On);
            ui->pushButton_42->setIcon(*ico);
    }
}

void Menu::on_pushButton_46_toggled(bool checked)
{
    if(!checked)
    {
        QIcon *ico = new QIcon();
            ico->addPixmap(QPixmap(":/Icones/Icones/up.png"),QIcon::Normal,QIcon::Off);
            ico->addPixmap(QPixmap(":/Icones/Icones/fleche.png"),QIcon::Normal,QIcon::On);
            ui->pushButton_46->setIcon(*ico);
    }
}

void Menu::on_pushButton_58_toggled(bool checked)
{
    if(!checked)
    {
        QIcon *ico = new QIcon();
        ico->addPixmap(QPixmap(":/Icones/Icones/up.png"),QIcon::Normal,QIcon::Off);
        ico->addPixmap(QPixmap(":/Icones/Icones/fleche.png"),QIcon::Normal,QIcon::On);
            ui->pushButton_58->setIcon(*ico);
    }
}



void Menu::on_pushButton_10_clicked()
{
      m.show();
}

void Menu::on_pushButton_59_clicked()
{
    ev.show();
}
void Menu::on_pushButton_51_clicked()
{
    eq.show();
}

void Menu::on_pushButton_47_clicked()
{
    sp.show();
}



void Menu::on_pushButton_43_clicked()
{
    l.show();

}

void Menu::on_pushButton_55_clicked()
{
        p.show();
}

void Menu::on_pushButton_19_clicked()
{
    qApp->quit();
}
