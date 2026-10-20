#include "MainWindow_p.h"
#include "ui_projet.h"
#include "project.h"
#include "notepad.h"
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include"QtDebug"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include<QtCharts>
#include <QtSql>
#include <QAxObject>
#include <QDebug>
#include <QSqlDatabase>

MainWindow_p::MainWindow_p(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_p)
{
    ui->setupUi(this);
          ui->tableView->setModel(P.afficher());
       QPixmap pix(":/Icones/Icones/background.png");
         ui->label->setPixmap(pix.scaled(1200,1100,Qt::KeepAspectRatio));

         ui->lineEdit_id->setValidator( new QIntValidator(11111,99999, this));
         ui->lineEdit_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
         ui->lineEdit_type->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
         ui->lineEdit_budget->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
         ui->lineEdit_budget_2->setValidator( new QIntValidator(11111,99999, this));
         ui->dateTimeEdit_2->setMinimumDate(QDate::currentDate());
         ui->dateTimeEdit->setMaximumDate(QDate::currentDate().addDays(30));


}

MainWindow_p::~MainWindow_p()
{
    delete ui;
}


void MainWindow_p::on_ajouter_4_clicked()
{
    int ID_PROJET = ui->lineEdit_id->text().toInt();
       QString NOM = ui->lineEdit_nom->text();
       QString UTILISATEUR = ui->lineEdit_type->text();
       QString DESCRIPTION = ui->lineEdit_budget->text();
       QDate DATE_DEBUT = ui->dateTimeEdit_2->date();
       QDate DATE_FIN = ui->dateTimeEdit->date();
       int ID_EMPLOYE = ui->lineEdit_budget_2->text().toInt(); // Ajout de la clé étrangère
       QString  ID_PROJET_STR= ui->lineEdit_id->text();
                   if (ID_PROJET_STR.isEmpty()) {
                       QMessageBox::critical(this, "Erreur", "Veuillez entrer UN IDENTIFIANT pour le PROJET.");
                       return;
                   }
                   // Vérification du champ Nom
                           if (NOM.isEmpty()) {
                               QMessageBox::critical(this, "Erreur", "Veuillez entrer un nom pour le projet.");
                               return;
                           }
                           QRegularExpression regexNom("^[A-Za-z0-9 ]+$"); // Expression régulière pour valider le nom
                           QRegularExpressionMatch matchNom = regexNom.match(NOM);

                           if (!matchNom.hasMatch()) {
                               QMessageBox::critical(this, "Erreur", "Nom invalide : Nom ne doit contenir que des lettres, des chiffres et des espaces!");
                               return;
                           }

                           if (UTILISATEUR.isEmpty()) {
                               QMessageBox::critical(this, "Erreur", "Veuillez entrer un utilisateur le projet.");
                               return;
                           }
                           if (DESCRIPTION.isEmpty()) {
                               QMessageBox::critical(this, "Erreur", "Veuillez entrer une description pour le projet.");
                               return;
                           }
                           QString  ID_EMPLOYE_STR= ui->lineEdit_budget_2->text();
                                       if (ID_EMPLOYE_STR.isEmpty()) {
                                           QMessageBox::critical(this, "Erreur", "Veuillez entrer L id d'emlpoye pour le PROJET.");
                                           return;
                                       }

                           // Vérifier que le nom est unique dans la base de données
                                       Project PROJ;
                                       if (PROJ.rechercherID(NOM)->rowCount() != 0) {
                                           QMessageBox::warning(this, "Erreur", "Le nom existe déjà dans la base de données.");


                                           return;
                                       }


       Project P(ID_PROJET, NOM, UTILISATEUR, DESCRIPTION, DATE_DEBUT, DATE_FIN, ID_EMPLOYE); // Mettre à jour la création de l'objet Sponsor

       bool test = P.ajouter();
       if(test)
       {
          // ui->tableView->setModel(P.afficher());
           QMessageBox::information(nullptr, QObject::tr("OK"),
                                    QObject::tr("Ajouter effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
           ui->lineEdit_id->clear();
           ui->lineEdit_nom->clear();
           ui->lineEdit_type->clear();
           ui->lineEdit_budget->clear();
           ui->lineEdit_budget_2->clear();
           ui->dateTimeEdit_2->clear();
           ui->dateTimeEdit->clear();
           ui->lineEdit_budget_2->clear();
       }
       else
       {
           QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                    QObject::tr("Ajout non effectué.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow_p::on_pushButton_7_clicked()
{
     ui->tableView->setModel(P.afficher());
}

void MainWindow_p::on_supprimer_2_clicked()
{
    int id_projet =ui->lineEdit_id->text().toInt();
           bool test=P.supprimer(id_projet);
           if(test)
           {    ui->tableView->setModel(P.afficher());
               QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("suppression effectuee\n"
                                                    "Click Cancel to exit."),QMessageBox::Cancel);
           }
           else
               QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("Supression non effectuee\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow_p::on_supprimer_3_clicked()
{


    int ID_PROJET = ui->lineEdit_id->text().toInt();
       QString NOM = ui->lineEdit_nom->text();
       QString UTILISATEUR = ui->lineEdit_type->text();
       QString DESCRIPTION = ui->lineEdit_budget->text();
       QDate DATE_DEBUT = ui->dateTimeEdit_2->date();
       QDate DATE_FIN = ui->dateTimeEdit->date();
       int ID_EMPLOYE = ui->lineEdit_budget_2->text().toInt();

            Project P(ID_PROJET, NOM, UTILISATEUR, DESCRIPTION, DATE_DEBUT, DATE_FIN, ID_EMPLOYE);
            bool test = P.modifier();
            if(test)
            {
                ui->tableView->setModel(P.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                                         QObject::tr("Modification effectuée\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
                ui->lineEdit_id->clear();
                ui->lineEdit_nom->clear();
                ui->lineEdit_type->clear();
                ui->lineEdit_budget->clear();
                ui->lineEdit_budget_2->clear();
                ui->dateTimeEdit_2->clear();
                ui->dateTimeEdit->clear();
                ui->lineEdit_budget_2->clear();
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                                         QObject::tr("Modification non effectuée.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
            }


    }





void MainWindow_p::on_supprimer_4_clicked()
{
    Project P;
        QString nom = ui->lineEdit_rechercher->text();
            QSqlQueryModel * model = P.chercher("NOM",nom);
            ui->tableView->setModel(model);
}




void MainWindow_p::on_rechercher_clicked()
{  Project E;
    QString NOM= ui->lineEdit_rechercher->text();
        QSqlQueryModel * model = E.rechercherID(NOM);
        ui->tableView->setModel(model);

}





/*void MainWindow_p::on_pushButton_8_clicked()
{
    qDebug() << "Showing Stats";
           QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM PROJECTS WHERE STATUT LIKE '%accepter%'");
               float dispo1=model->rowCount();
               model->setQuery("SELECT * FROM PROJECTS WHERE STATUT LIKE '%refuser%'");
               float dispo=model->rowCount();
               float total=dispo1+dispo;
                   QString a=QString("accepter. "+QString::number((dispo1*100)/total,'f',2)+"%" );
                   QString b=QString("refuser . "+QString::number((dispo*100)/total,'f',2)+"%" );
                   QPieSeries *series = new QPieSeries();
                   series->append(a,dispo1);
               series->append(b,dispo);
               if (dispo1!=0)
               {QPieSlice *slice = series->slices().at(0);
                   slice->setLabelVisible();
                   slice->setPen(QPen());}
               if ( dispo!=0)
               {
                   QPieSlice *slice1 = series->slices().at(1);
                   slice1->setLabelVisible();
               }
               QChart *chart = new QChart();
               chart->addSeries(series);
               chart->setTitle("Nombre de sponsors : "+ QString::number(total));
               chart->legend()->hide();


               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               qDebug() << "Showing Stats";
               chartView->show();

}*/










void MainWindow_p::trier(QString item,QString ordre)
{
    QString select;
    select="select * from PROJETS order by ";
    select+=item;
    select+=" ";
    select+=ordre;

    QSqlQuery query;
    query.prepare(select);
    query.exec();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery(query);



    ui->tableView->setModel(model);
}



void MainWindow_p::on_comboBoxTrie_currentIndexChanged(int index)
{
    ordre="ASC";
    if(index==1)
        item="DATE_DEBUT";
    else
        if(index==2)
            item="NOM";
    else
            if(index==3)
                item="ID_PROJET";
    else
                if(index==4)
                    ordre="DESC";

}

void MainWindow_p::on_tri_clicked()
{
    if(item=="")
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("Erreur!!.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        trier(item,ordre);
}



void MainWindow_p::on_stat_clicked()
{
    qDebug() << "Showing Stats";
           QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM PROJETS WHERE UTILISATEUR LIKE '%mohamed%'");
               float dispo1=model->rowCount();
               model->setQuery("SELECT * FROM PROJETS WHERE UTILISATEUR LIKE '%ali%'");
               float dispo=model->rowCount();
               float total=dispo1+dispo;
                   QString a=QString("mohamed. "+QString::number((dispo1*100)/total,'f',2)+"%" );
                   QString b=QString("ali . "+QString::number((dispo*100)/total,'f',2)+"%" );
                   QPieSeries *series = new QPieSeries();
                   series->append(a,dispo1);
               series->append(b,dispo);
               if (dispo1!=0)
               {QPieSlice *slice = series->slices().at(0);
                   slice->setLabelVisible();
                   slice->setPen(QPen());}
               if ( dispo!=0)
               {
                   QPieSlice *slice1 = series->slices().at(1);
                   slice1->setLabelVisible();
               }
               QChart *chart = new QChart();
               chart->addSeries(series);
               chart->setTitle("Nombre des utulisateurs : "+ QString::number(total));
               chart->legend()->hide();


               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               qDebug() << "Showing Stats";
               chartView->show();
}

void MainWindow_p::on_notepad_clicked()
{
    notepad * i= new notepad ;
     i->show();
}

void MainWindow_p::on_pushButton_clicked()
{





    QSqlQuery query;
        query.prepare("SELECT NOM,DESCRIPTION FROM PROJETS");
        if (!query.exec()) {
            qDebug() << "Erreur lors de l'extraction des données de la base de données";
            return;
        }

        // Exportation des données dans un fichier Excel
        QAxObject excel("Excel.Application");
        excel.setProperty("Visible", true); // affiche Excel
        QAxObject *workbooks = excel.querySubObject("Workbooks");
        QAxObject *workbook = workbooks->querySubObject("Add()");
        QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1); // première feuille de calcul
        worksheet->setProperty("Name", "Projets"); // renomme la feuille de calcul
        worksheet->querySubObject("Range(const QString&)", "A1")->setProperty("Value", "Nom");
        worksheet->querySubObject("Range(const QString&)", "B1")->setProperty("Value", "Description");

        int rowIndex = 2;
        while (query.next()) {
            QString nom = query.value(0).toString();
            QString description = query.value(1).toString();
            worksheet->querySubObject("Range(const QString&)", QString("A%1").arg(rowIndex))->setProperty("Value", QVariant(nom));
            worksheet->querySubObject("Range(const QString&)", QString("B%1").arg(rowIndex))->setProperty("Value", QVariant(description));
            rowIndex++;
        }
    }




void MainWindow_p::on_pushButton_19_clicked()
{
    this->hide();
}

void MainWindow_p::on_pdf_clicked()
{

      QPdfWriter pdf("C:/pdf/list.pdf");

     QPainter painter(&pdf);
     int i = 4100;
     const QImage image(":/img/logo.png");
                 const QPoint imageCoordinates(155,0);
                 int width1 = 1600;
                 int height1 = 600;
                 QImage img=image.scaled(width1,height1);
                 painter.drawImage(imageCoordinates, img );


            QColor dateColor(0x4a5bcf);
            painter.setPen(dateColor);

            painter.setFont(QFont("Montserrat SemiBold", 11));
            QDate cd = QDate::currentDate();
            painter.drawText(7700,250,cd.toString("Ariana, El Ghazela"));
            painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

            QColor titleColor(0x341763);
            painter.setPen(titleColor);
            painter.setFont(QFont("Montserrat SemiBold", 25));

            painter.drawText(3000,2700,"Liste des PROJETS");

            painter.setPen(Qt::black);
            painter.setFont(QFont("Time New Roman", 15));
            //painter.drawRect(100,100,9400,2500);
            painter.drawRect(100,3300,9400,500);

            painter.setFont(QFont("Montserrat SemiBold", 10));

            painter.drawText(500,3600,"ID_PROJET");
            painter.drawText(1500,3600,"Nom");
            painter.drawText(2500,3600,"UTILISATEUR");
            painter.drawText(4500,3600,"DESCRIPTION");
            painter.drawText(6500,3600,"DATE_FIN");
            painter.drawText(7500,3600,"ID_EMPLOYE");
            painter.setFont(QFont("Montserrat", 10));
            painter.drawRect(100,3300,9400,9000);

            QSqlQuery query;
            query.prepare("select * from PROJETS");
            query.exec();
            int y=4300;
            while (query.next())
            {
                painter.drawLine(100,y,9490,y);
                y+=500;
                painter.drawText(2500,i,query.value(2).toString());
                painter.drawText(500,i,query.value(0).toString());
                painter.drawText(1300,i,query.value(1).toString());
                painter.drawText(3200,i,query.value(3).toString());
                painter.drawText(5200,i,query.value(4).toString());
                painter.drawText(7200,i,query.value(5).toString());
                painter.drawText(8200,i,query.value(6).toString());
                painter.drawText(10200,i,query.value(7).toString());

               i = i + 500;
            }

            int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré.\nVous voulez l'affichez ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl( QUrl ::fromLocalFile("C:/pdf/list.pdf"));
                painter.end();
            }
            else
            {
                painter.end();
            }


  }
