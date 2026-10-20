#include "MainWindow_em.h"
#include "ui_employes.h"
#include <Employes.h>
#include <QPixmap>
#include <QImage>
#include <QStackedWidget>
#include <QSqlError>
#include <QTableView>
#include <QSqlQuery>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include<QtCharts>
#include <QComboBox>
//#include"ui_menu.h"
#include <QPdfWriter>
#include "menu.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     //connect(ui->chat, SIGNAL(clicked()), this, SLOT(on_chat_clicked()));

       ui->tableView->setModel(E.afficher());
    QPixmap pix(":/Icones/Icones/background.png");
      ui->label->setPixmap(pix.scaled(1200,1100,Qt::KeepAspectRatio));

      ui->lineEdit_id->setValidator( new QIntValidator(11,99, this));
      ui->lineEdit_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
      ui->lineEdit_type->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
      ui->lineEdit_statut->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
     // ui->lineEdit_budget->setValidator( new QIntValidator(11111111,99999999, this));
     // ui->dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
      //ui->dateTimeEdit->setMaximumDateTime(QDateTime::currentDateTime().addMonths(4));

      QStringList labos;
      QString l;

      QSqlQuery query("select ID_LABO from LABORATOIRE");

          while(query.next())
          {

            l=query.value(0).toString();
            labos.append(l);

          }
          ui->comboBox_Emp->addItems(labos);
qDebug()<<labos;

  }

void MainWindow::on_ajouter_4_clicked()
{

    int ID_EMPLOYE = ui->lineEdit_id->text().toInt();
    QString NOM = ui->lineEdit_nom->text();
    QString PRENOM = ui->lineEdit_type->text();
    QString EMAIL = ui->lineEdit_budget->text();
    QString SEXE = ui->lineEdit_statut->text();
    QString FONCTION = ui->lineEdit_budget_2->text();
    QString SPECIALITE = ui->lineEdit_budget_3->text();
    int ID_LABO=ui->comboBox_Emp->currentText().toInt();


   // Afficher une boîte de dialogue de confirmation
       QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, "Confirmation",
               "Êtes-vous sûr de vouloir ajouter cet employe ?",
               QMessageBox::Yes|QMessageBox::No);
       if (reply == QMessageBox::Yes) {
          Employes E (ID_EMPLOYE, NOM, PRENOM, EMAIL, SEXE, FONCTION, SPECIALITE, ID_LABO);
           bool test = E.ajouter();
           if (verif()) {
               if (test) {
                   ui->tableView->setModel(E.afficher());
                   QMessageBox::information(nullptr, QObject::tr("OK"),
                                            QObject::tr("Ajout effectué\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
               } else {
                   QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                            QObject::tr("Existe déjà.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
               }
           }
           //***********************emeil
                       // Vérification du champ Email
                       if (EMAIL.isEmpty()) {
                           QMessageBox::critical(this, "Error", "Please enter an email address for the Employe.");
                           return;
                       }

                       QRegularExpression regexEmail("^\\S+@\\S+\\.\\S+$"); // Expression régulière pour valider l'email
                       QRegularExpressionMatch matchEmail = regexEmail.match(EMAIL);

                       if (!matchEmail.hasMatch()) {
                           QMessageBox::critical(this, "Error", "Invalid Email: Please enter a valid email address.");
                           return;
                       }

           //**********************fin email
       } else {
           // Si l'utilisateur clique sur "Non", vider le formulaire
           ui->lineEdit_id->clear();
           ui->lineEdit_nom->clear();
           ui->lineEdit_type->clear();
           ui->lineEdit_budget->clear();
           ui->lineEdit_statut->clear();
          ui->lineEdit_budget_2->clear();
          ui->lineEdit_budget_3->clear();
           //ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
           ui->comboBox_Emp->clear();
           //ui->label_image->clear();
       }
   }

bool MainWindow::verif()
{
    if(ui->lineEdit_id->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ id employé est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_id->setFocus();
        return false;
    }
    if(ui->lineEdit_nom->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ nom est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_nom->setFocus();
        return false;
    }
    if(ui->lineEdit_type->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ prénom est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_type->setFocus();
        return false;
    }
    if(ui->lineEdit_budget->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ Email est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_budget->setFocus();
        return false;
    }
    if(ui->lineEdit_statut->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ sexe est obligatoire ",QMessageBox::Cancel);
        ui->lineEdit_statut->setFocus();
        return false;
    }
    if(ui->lineEdit_budget_2->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ fonction est obligatoire ",QMessageBox::Cancel);
        ui->lineEdit_budget_2->setFocus();
        return false;
    }
    if(ui->lineEdit_budget_3->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ specialite est obligatoire ",QMessageBox::Cancel);
        ui->lineEdit_budget_3->setFocus();
        return false;
    }
    return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_afficher_clicked()
{

    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_budget->clear();
    ui->lineEdit_statut->clear();
   // ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->lineEdit_budget_2->clear();
    ui->lineEdit_budget_3->clear();
    ui->comboBox_Emp->clear();
   // ui->label_image->clear();
   Employes E;
     ui->tableView->setModel(E.afficher());
}

void MainWindow::on_supprimer_2_clicked()
{
    {
        // Obtenir le nom de l'élément à supprimer à partir de la ligne de texte de l'utilisateur
        QString NOM = ui->lineEdit_nom->text();


        // Demander une confirmation à l'utilisateur avant de supprimer l'élément
        QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirmation de suppression", "Êtes-vous sûr de supprimer cet élément ?", QMessageBox::Yes|QMessageBox::No);

        // Si l'utilisateur confirme la suppression, supprimer l'élément
        if (confirmation == QMessageBox::Yes)
        {
            bool suppressionReussie = E.supprimer(NOM);

            // Si la suppression a réussi, actualiser le tableau
            if (suppressionReussie)
            {
                ui->tableView->setModel(E.afficher());

                QMessageBox::information(this, "Suppression réussie", "L'élément a été supprimé avec succès !");
            }
            // Si la suppression a échoué, afficher un message d'erreur
            else
            {
                QMessageBox::critical(this, "Erreur de suppression", "La suppression a échoué.");
            }
        }

          else {
    ui->lineEdit_id->clear();
           ui->lineEdit_nom->clear();
           ui->lineEdit_type->clear();
           ui->lineEdit_budget->clear();
           ui->lineEdit_statut->clear();
           ui->lineEdit_budget_2->clear();
           ui->lineEdit_budget_3->clear();
           ui->comboBox_Emp->clear();
        }
}

}
void MainWindow::on_modifier_3_clicked()
{

        int ID_EMPLOYE = ui->lineEdit_id->text().toInt();
        QString NOM = ui->lineEdit_nom->text();
        QString PRENOM = ui->lineEdit_type->text();
        QString EMAIL = ui->lineEdit_budget->text();
        QString SEXE = ui->lineEdit_statut->text();
        QString  FONCTION= ui->lineEdit_budget_2->text();
        QString SPECILAITE = ui->lineEdit_budget_3->text();
        int ID_LABO = ui->comboBox_Emp->currentText().toInt(); // si vous avez un champ pour l'ID labo
       QString image =ui->label_image->text();

       Employes E (ID_EMPLOYE, NOM, PRENOM, EMAIL, SEXE, FONCTION, SPECILAITE, ID_LABO);
        bool test = E.modifier();
        if(verif())
        {if(test)
        {
            ui->tableView->setModel(E.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Modification effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                                     QObject::tr("Modification non effectuée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }}
         ui->lineEdit_id->clear();
               ui->lineEdit_nom->clear();
               ui->lineEdit_type->clear();
               ui->lineEdit_budget->clear();
               ui->lineEdit_statut->clear();
               ui->lineEdit_budget_2->clear();
               ui->lineEdit_budget_3->clear();
               ui->comboBox_Emp->clear();



}

void MainWindow::on_rechercher_clicked()
{  Employes E;
    QString NOM = ui->lineEdit_rechercher->text();
        QSqlQueryModel * model = E.chercher(NOM);
        ui->tableView->setModel(model);
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
      QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from EMPLOYES where ID_EMPLOYE='"+val+"'");
        if(qry.exec())
        {
            while (qry.next())
            {
             ui->lineEdit_id->setText(qry.value(0).toString());
               ui->lineEdit_nom->setText(qry.value(1).toString());
                 ui->lineEdit_type->setText(qry.value(2).toString());
                   ui->lineEdit_budget->setText(qry.value(3).toString());
                     ui->lineEdit_statut->setText(qry.value(4).toString());
                    ui->lineEdit_budget_2->setText(qry.value(5).toString());
                    ui->lineEdit_budget_3->setText(qry.value(5).toString());


                     int i = ui->comboBox_Emp->findText(qry.value(7).toString());
                         if ( i != -1 )  // -1 for not found

                             ui->comboBox_Emp->setCurrentIndex(i);
                        ui->label_image->setText(qry.value(7).toString());

                        }

                    }

                else
                {
                    QMessageBox::critical(this, tr("Erreur"), qry.lastError().text());
                }
            }


void MainWindow::on_pushButton_statistique_clicked()
{
    qDebug() << "Showing Stats";
               QSqlQueryModel * model= new QSqlQueryModel();
               model->setQuery("SELECT * FROM EMPLOYES WHERE SEXE LIKE '%homme%'");
                   float dispo1=model->rowCount();
                   model->setQuery("SELECT * FROM EMPLOYES WHERE SEXE LIKE '%femme%'");
                   float dispo=model->rowCount();
                   float total=dispo1+dispo;
                       QString a=QString("homme. "+QString::number((dispo1*100)/total,'f',2)+"%" );
                       QString b=QString("femme . "+QString::number((dispo*100)/total,'f',2)+"%" );
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
                   chart->setTitle("Nombre de sexe : "+ QString::number(total));
                   chart->legend()->hide();


                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);
                   chartView->resize(1000,500);
                   qDebug() << "Showing Stats";
                   chartView->show();


}

void MainWindow::on_tri_clicked()
{
   Employes *employes = new Employes();
    int triType = ui->comboBo_tri->currentIndex() + 1;
        QSqlQueryModel *model = employes->tri(triType);
        ui->tableView->setModel(model);
}




void MainWindow::MainWindow::on_pdf_clicked()
{
    QPdfWriter pdf("C:/pdf/list.pdf");

   QPainter painter(&pdf);
   int i = 4100;
   const QImage image(":/img/logo.png");
               const QPoint imageCoordinates(155,0);
               int width1 = 2000;
               int height1 = 2000;
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

          painter.drawText(3000,2700,"Liste des Employes");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          //painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 10));

          painter.drawText(200,3600,"ID_EMPLOYES");
                      painter.drawText(1400,3600,"NOM");
                      painter.drawText(2400,3600,"PRENOM");
                      painter.drawText(3900,3600,"EMAIL");
                      painter.drawText(5500,3600,"SEXE");
                       painter.drawText(6400,3600,"FONCTION");
                        painter.drawText(7500,3600,"SPECIALITE");
                        painter.drawText(8600,3600,"ID_LABO");
          painter.setFont(QFont("Montserrat", 10));
          painter.drawRect(100,3300,9400,9000);

          QSqlQuery query;
          query.prepare("select * from EMPLOYES");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=500;
              painter.drawText(200,i,query.value(0).toString());
                  painter.drawText(1400,i,query.value(1).toString());
                  painter.drawText(2400,i,query.value(2).toString());
                  painter.drawText(3900,i,query.value(3).toString());
                  painter.drawText(5500,i,query.value(4).toString());
                  painter.drawText(6400,i,query.value(5).toString());
                  painter.drawText(7500,i,query.value(6).toString());
                   painter.drawText(8600,i,query.value(7).toString());
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



void MainWindow::on_pushButton_13_clicked()
{
    Menu * j= new Menu;
        j->show();
}

void MainWindow::on_pushButton_19_clicked()
{
    this->hide();
}
