#include "MainWindow_spon.h"
#include "ui_MainWindow_spon.h"
#include <sponsor.h>
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
#include "ui_dumessangerconnectiondialog.h"
#include "ui_widget.h"
#include "widget.h"
#include "menu.h"
#include <QUrl>
#include <QPdfWriter>
//arduino
#include "arduinoP.h"


namespace  Duratecorporation {
MainWindow_spon::MainWindow_spon(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_spon)
{
    ui->setupUi(this);
     connect(ui->chat, SIGNAL(clicked()), this, SLOT(on_chat_clicked()));

       ui->tableView->setModel(Etmp.afficher());
    QPixmap pix(":/Icones/Icones/background.png");
      ui->label->setPixmap(pix.scaled(1200,1100,Qt::KeepAspectRatio));

      ui->lineEdit_id->setValidator( new QIntValidator(11,99, this));
      ui->lineEdit_nom->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
      ui->lineEdit_type->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
      ui->lineEdit_statut->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
      ui->lineEdit_budget->setValidator( new QIntValidator(11111111,99999999, this));
      ui->dateTimeEdit->setMinimumDateTime(QDateTime::currentDateTime());
      ui->dateTimeEdit->setMaximumDateTime(QDateTime::currentDateTime().addMonths(4));

      QStringList employes;
      QString e;

      QSqlQuery query("select ID_EMPLOYE, nom from EMPLOYES");

          while(query.next())
          {

            e=query.value(0).toString()+query.value(1).toString();
            employes.append(e);

          }
          ui->comboBox_Emp->addItems(employes);
qDebug()<<employes;

  }

void MainWindow_spon::on_ajouter_4_clicked()
{

    int id_sponsor = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();
    int budget = ui->lineEdit_budget->text().toInt();
    QString statut = ui->lineEdit_statut->text();
    QDateTime date_statut = ui->dateTimeEdit->dateTime();
    int id_employe=ui->comboBox_Emp->currentText().remove(1,20).toInt();
    QString image =ui->label_image->text();

   // Afficher une boîte de dialogue de confirmation
       QMessageBox::StandardButton reply;
       reply = QMessageBox::question(this, "Confirmation",
               "Êtes-vous sûr de vouloir ajouter ce sponsor ?",
               QMessageBox::Yes|QMessageBox::No);
       if (reply == QMessageBox::Yes) {
           Sponsor S(id_sponsor, nom, type, budget, statut, date_statut, id_employe, image);
           bool test = S.ajouter();
           if (verif()) {
               if (test) {
                   ui->tableView->setModel(S.afficher());
                   QMessageBox::information(nullptr, QObject::tr("OK"),
                                            QObject::tr("Ajout effectué\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
               } else {
                   QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                            QObject::tr("Existe déjà.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
               }
           }
       } else {
           // Si l'utilisateur clique sur "Non", vider le formulaire
           ui->lineEdit_id->clear();
           ui->lineEdit_nom->clear();
           ui->lineEdit_type->clear();
           ui->lineEdit_budget->clear();
           ui->lineEdit_statut->clear();
           ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
           ui->comboBox_Emp->clear();
           ui->label_image->clear();
       }
   }

bool MainWindow_spon::verif()
{
    if(ui->lineEdit_id->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ id_sponsor est obligatoire",QMessageBox::Cancel);
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
        QMessageBox::warning(nullptr,"Saisie","le champ type est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_type->setFocus();
        return false;
    }
    if(ui->lineEdit_budget->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ budget est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_budget->setFocus();
        return false;
    }
    if(ui->lineEdit_statut->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ statut est obligatoire ",QMessageBox::Cancel);
        ui->lineEdit_statut->setFocus();
        return false;
    }
    if(ui->dateTimeEdit->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ date est obligatoire ",QMessageBox::Cancel);
        ui->dateTimeEdit->setFocus();
        return false;
    }
   /* if(ui->comboBox_Emp->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ statut est obligatoire ",QMessageBox::Cancel);
        ui->comboBox_Emp->setFocus();
        return false;
    }*/
    if(ui->label_image->text()=="")
    {
        QMessageBox::warning(nullptr,"Saisie","le champ logo  est obligatoire ",QMessageBox::Cancel);
        ui->label_image->setFocus();
        return false;
    }
    return true;
}

MainWindow_spon::~MainWindow_spon()
{
    delete ui;
}

void MainWindow_spon::on_pushButton_afficher_clicked()
{

    ui->lineEdit_id->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_budget->clear();
    ui->lineEdit_statut->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->comboBox_Emp->clear();
    ui->label_image->clear();
    Sponsor S;
     ui->tableView->setModel(S.afficher());
}

void MainWindow_spon::on_supprimer_2_clicked()
{
    int id_Sponsor = ui->lineEdit_id->text().toInt();
    QSqlQuery query;
    query.prepare("select * from SPONSORS where ID_SPONSOR = :id_Sponsors");
    query.bindValue(":id_Sponsors", id_Sponsor);
    query.exec();
    bool test = Etmp.supprimer(id_Sponsor);
    // Afficher une boîte de dialogue de confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation",
                "Êtes-vous sûr de vouloir ajouter ce sponsor ?",
                QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes){
    if (test) {
        ui->tableView->setModel(S.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("ID_Sponsor n'existe pas\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
         } else {
    ui->lineEdit_id->clear();
           ui->lineEdit_nom->clear();
           ui->lineEdit_type->clear();
           ui->lineEdit_budget->clear();
           ui->lineEdit_statut->clear();
           ui->comboBox_Emp->clear();
        }
}


void MainWindow_spon::on_modifier_3_clicked()
{

        int id_sponsor = ui->lineEdit_id->text().toInt();
        QString nom = ui->lineEdit_nom->text();
        QString type = ui->lineEdit_type->text();
        float budget = ui->lineEdit_budget->text().toInt();
        QString statut = ui->lineEdit_statut->text();
        QDateTime date_statut = ui->dateTimeEdit->dateTime();
        int id_employe = ui->comboBox_Emp->currentText().toInt(); // si vous avez un champ pour l'ID de l'employé
       QString image =ui->label_image->text();

        Sponsor S(id_sponsor, nom, type, budget, statut, date_statut,id_employe,image);
        bool test = S.modifier();
        if(verif())
        {if(test)
        {
            ui->tableView->setModel(S.afficher());
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
               ui->comboBox_Emp->clear();
               ui->label_image->clear();


}

void MainWindow_spon::on_rechercher_clicked()
{  Sponsor S;
    QString nom = ui->lineEdit_rechercher->text();
        QSqlQueryModel * model = S.chercher(nom);
        ui->tableView->setModel(model);
}


void MainWindow_spon::on_tableView_activated(const QModelIndex &index)
{
      QString val=ui->tableView->model()->data(index).toString();
        QSqlQuery qry;
        qry.prepare("select * from SPONSORS where ID_SPONSOR='"+val+"'");
        if(qry.exec())
        {
            while (qry.next())
            {
             ui->lineEdit_id->setText(qry.value(0).toString());
               ui->lineEdit_nom->setText(qry.value(1).toString());
                 ui->lineEdit_type->setText(qry.value(2).toString());
                   ui->lineEdit_budget->setText(qry.value(3).toString());
                     ui->lineEdit_statut->setText(qry.value(4).toString());
                     QDateTime date = QDateTime::fromString(qry.value(5).toString(), "yyyy-MM-dd hh:mm:ss");
                     ui->dateTimeEdit->setDateTime(date);

                     int i = ui->comboBox_Emp->findText(qry.value(6).toString());
                         if ( i != -1 )  // -1 for not found

                             ui->comboBox_Emp->setCurrentIndex(i);
                        ui->label_image->setText(qry.value(7).toString());
                        // Afficher l'image dans une boîte de dialogue
                     QString image = qry.value(7).toString(); // récupérer le chemin de l'image
                        if (!image.isEmpty()) { // vérifier si le chemin n'est pas vide
                            QPixmap pixmap(image); // créer un QPixmap à partir du chemin de l'image
                            QMessageBox msgBox;
                            msgBox.setWindowTitle(tr("Image de sposor"));
                            msgBox.setIconPixmap(pixmap); // définir l'image dans la boîte de dialogue
                            msgBox.exec(); // afficher la boîte de dialogue
                        }

                        else {
                                qDebug() << "Invalid Image:" << image; // Afficher un message de débogage si l'image est invalide
                            }
                        }

                    }

                else
                {
                    QMessageBox::critical(this, tr("Erreur"), qry.lastError().text());
                }


        }



void MainWindow_spon::on_pushButton_statistique_clicked()
{
    qDebug() << "Showing Stats";
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("SELECT * FROM SPONSORS WHERE STATUT LIKE '%accepter%'");
           float dispo1=model->rowCount();
           model->setQuery("SELECT * FROM SPONSORS WHERE STATUT LIKE '%refuser%'");
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


}

void MainWindow_spon::on_tri_clicked()
{
    Sponsor *sponsor = new Sponsor();
    int triType = ui->comboBo_tri->currentIndex() + 1;
        QSqlQueryModel *model = sponsor->tri(triType);
        ui->tableView->setModel(model);
}


void MainWindow_spon::on_pushButton_importer_clicked()
{
    QString image = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "", tr("Images (*.png *.xpm *.jpg *.bmp)"));

        ui->label_image->setText(image);

}

void MainWindow_spon::on_chat_clicked()
{
    Widget * i= new Widget ;
    i->show();
}
void MainWindow_spon::on_pushButton_parking_clicked()
{
    arduinoP A;
    A.setModal(true);
    A.exec();
    /*arduino * i= new arduino ;
    i->show();*/
}
}//end name space



void Duratecorporation::MainWindow_spon::on_pushButton_acceuil_clicked()
{ Menu * j= new Menu;
    j->show();

}

void Duratecorporation::MainWindow_spon::on_pushButton_exit_clicked()
{
    this->hide();
}

void Duratecorporation::MainWindow_spon::on_pdf_clicked()
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

          painter.drawText(3000,2700,"Liste des Sponsors");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          //painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 10));

          painter.drawText(200,3600,"ID_SPONSORS");
                      painter.drawText(1500,3600,"NOM");
                      painter.drawText(2250,3600,"TYPE");
                      painter.drawText(3500,3600,"BUDGET");
                      painter.drawText(4500,3600,"STATUT");
                       painter.drawText(5500,3600,"DATE_STATUT");
                        painter.drawText(7000,3600,"ID_EMPLOYE");
                        painter.drawText(8200,3600,"IMAGE");


          painter.setFont(QFont("Montserrat", 10));
          painter.drawRect(100,3300,9400,9000);

          QSqlQuery query;
          query.prepare("select * from SPONSORS");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=500;
              painter.drawText(200,i,query.value(0).toString());
                  painter.drawText(1500,i,query.value(1).toString());
                  painter.drawText(2250,i,query.value(2).toString());
                  painter.drawText(3500,i,query.value(3).toString());
                  painter.drawText(4500,i,query.value(4).toString());
                  painter.drawText(5500,i,query.value(5).toString());
                  painter.drawText(7500,i,query.value(6).toString());
                  QPixmap image(query.value(7).toString());
                  if (!image.isNull()) {
                      // Dessiner l'image sur le widget
                      painter.drawPixmap(8200, i, image.scaled(300, 300, Qt::KeepAspectRatio));
                  }
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
