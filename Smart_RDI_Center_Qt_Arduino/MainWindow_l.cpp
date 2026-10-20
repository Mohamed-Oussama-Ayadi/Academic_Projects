
#include "ui_MainWindow_l.h"
#include "labo.h"
#include <QPixmap>
#include <QString>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QSslSocket>
#include <QNetworkReply>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include<QtCharts>
#include "map.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include"MainWindow_l.h"
#include "menu.h"




MainWindow_l::MainWindow_l(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_l)
{

    ui->setupUi(this);

    int retTT=AA.connect_arduino(); // lancer la connexion à arduino
                   switch(retTT){
                   case(0):qDebug()<< "arduino is available and connected to : "<< AA.getarduino_port_name();
                       break;
                   case(1):qDebug() << "arduino is available but not connected to :" <<AA.getarduino_port_name();
                      break;
                   case(-1):qDebug() << "arduino is not available";
                   }
                    QObject::connect(AA.getserial(),SIGNAL(readyRead()),this,SLOT(update()));
       //menu = new menu(this);





    DateTime = new QTimer() ;
    connect(DateTime, SIGNAL(timeout()), this, SLOT(Date_Time_Display_Slot()));
    DateTime->setInterval(1000);
    DateTime->start();



    segundos = 0;
    minutos = 0;
    pausado = false;
    connect(&reloj,SIGNAL(timeout()), this, SLOT(procesar()));



    QStringList projet;
    QString e;

    QSqlQuery query("select ID_PROJET from PROJETS");

        while(query.next())
        {

          e=query.value(0).toString()+" "+query.value(1).toString();/*+" "+query.value(2).toString();*/
          projet.append(e);

        }
        ui->comboBox->addItems(projet);


    QPixmap pix(":/Icones/Icones/background.png");
      ui->label->setPixmap(pix.scaled(1200,1100,Qt::KeepAspectRatio));




      ui->tableView->setModel(ltmp.afficher());




          ui->lineEdit_id->setValidator( new QIntValidator(11111111,99999999, this));
          ui->comboBox->setValidator( new QIntValidator(11111111,99999999, this));
          ui->lineEdit_rechercher->setValidator( new QIntValidator(11111,99999, this));
          ui->lineEdit_rechercher_3->setValidator( new QIntValidator(11111,99999, this));
           ui->lineEdit_rules->setValidator(new QRegExpValidator(  QRegExp("[A-z]*")  ));
           ui->dateTimeEdit_2->setMinimumDateTime(QDateTime::currentDateTime());
           ui->dateTimeEdit_2->setMaximumDateTime(QDateTime::currentDateTime().addDays(365));
           ui->dateTimeEdit_3->setMinimumDateTime(QDateTime::currentDateTime());
           ui->dateTimeEdit_3->setMaximumDateTime(QDateTime::currentDateTime().addDays(365));



             ui->tableView->setModel(ltmp.afficher());






}





MainWindow_l::~MainWindow_l()
{
    delete ui;
}

void MainWindow_l::on_ajouter_4_clicked()
{
    int id_labo = ui->lineEdit_id->text().toInt();
    int id_projet = ui->comboBox->currentText().toInt();
    QString rules = ui->lineEdit_rules->text();


    QDateTime date_debut = ui->dateTimeEdit_2->dateTime();
    QDateTime date_fin = ui->dateTimeEdit_3->dateTime();

    // Afficher une boîte de dialogue de confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation",
                "Êtes-vous sûr de vouloir ajouter  ?",
                QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {


    labo l(id_labo, id_projet , rules,  date_debut ,date_fin );
    bool test = l.ajouter();
    if(verif())
    {
    if(test)
    {
        ui->tableView->setModel(l.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajouter effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                 QObject::tr("Ajout non effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

        } else {
                 // Si l'utilisateur clique sur "Non", vider le formulaire
                 ui->lineEdit_id->clear();

                 ui->lineEdit_rules->clear();
                 ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
                 ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());

             }
        ui->lineEdit_id->clear();

        ui->lineEdit_rules->clear();
        ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
        ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());
        ui->lineEdit_rechercher_3->clear();


}


void MainWindow_l::on_supprimer_2_clicked()
{
    int id_labo =ui->lineEdit_rechercher->text().toInt();
    bool test=ltmp.supprimer(id_labo);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectuee\n"
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Supression non effectuee\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


    ui->tableView->setModel(ltmp.afficher());
    ui->lineEdit_rechercher->clear();



}

void MainWindow_l::on_pushButton_7_clicked()
{
    ui->tableView->setModel(ltmp.afficher());

}

void MainWindow_l::on_supprimer_3_clicked()
{
    int id_labo = ui->lineEdit_id->text().toInt();
    int id_projet = ui->comboBox->currentText().toInt();
    QString rules = ui->lineEdit_rules->text();
    QDateTime date_debut = ui->dateTimeEdit_2->dateTime();
    QDateTime date_fin = ui->dateTimeEdit_3->dateTime();
    QString recherche = ui->lineEdit_rechercher_3->text();



    labo newlab(id_labo, id_projet , rules,  date_debut ,date_fin );


    if (newlab.rechercherID(recherche)->rowCount()!=0 and recherche.length()!=0)
    {
                bool test= newlab.modifier(recherche);
                               if(test){
                                   MainWindow_l w;
                               w.show();
                               QMessageBox::information(nullptr, QObject::tr("database is open"),
                                           QObject::tr("Modification effectué.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
                                  ui->tableView->setModel(newlab.afficher());
                           }
                           else
                               {
                               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                           QObject::tr("Modification non effectué.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
    }}
    else
    {QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                   QObject::tr("Modification non effectué !\n"
                     "Cliquer sur Cancel to exit."), QMessageBox::Cancel);}

    ui->lineEdit_id->clear();

    ui->lineEdit_rules->clear();
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());


    ui->tableView->setModel(newlab.afficher());
     }

void MainWindow_l::on_tri_clicked()
{
    labo *Labo = new labo();
        int triType = ui->comboBo_tri->currentIndex() + 1;
            QSqlQueryModel *model = Labo->tri(triType);
            ui->tableView->setModel(model);
}

void MainWindow_l::on_pushButton_8_clicked()
{


     qDebug() << "Showing Stats";
           QSqlQueryModel * model= new QSqlQueryModel();
           model->setQuery("SELECT * FROM LABORATOIRES WHERE RULES LIKE '%accepter%'");

               float dispo1=model->rowCount();
               model->setQuery("SELECT * FROM LABORATOIRES WHERE RULES LIKE '%refuser%'");

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
               chart->setTitle("Nombre de labo : "+ QString::number(total));
               chart->legend()->hide();


               QChartView *chartView = new QChartView(chart);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->resize(1000,500);
               qDebug() << "Showing Stats";
               chartView->show();





}

void MainWindow_l::on_pdf_clicked()
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

              painter.drawText(3000,2700,"Liste des labo");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              //painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(200,3600,"ID_labo");
              painter.drawText(2000,3600,"rules");
              painter.drawText(2800,3600,"ID_projet");
              painter.drawText(4500,3600,"date debut");
              painter.drawText(6500,3600,"date fin");
              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from LABORATOIRES");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(200,i,query.value(0).toString());
                      painter.drawText(2000,i,query.value(1).toString());
                      painter.drawText(3800,i,query.value(2).toString());
                      painter.drawText(4500,i,query.value(3).toString());
                      painter.drawText(6400,i,query.value(4).toString());

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

void MainWindow_l::on_supprimer_4_clicked()
{
    { labo l;
        QString rules = ui->lineEdit_rechercher_2->text();
            QSqlQueryModel * model = l.chercher(rules);
            ui->tableView->setModel(model);
    }
}


bool MainWindow_l::verif()
{
    if(ui->lineEdit_id->text()=="")
    {
        QMessageBox::warning(nullptr,"id_labo","le id_labo est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_id->setFocus();
        return false;
    }

    if(ui->comboBox->currentText()=="")
    {
        QMessageBox::warning(nullptr,"id_projet","le id_projet est obligatoire",QMessageBox::Cancel);
        ui->comboBox->setFocus();
        return false;
    }

    if(ui->lineEdit_rules->text()=="")
    {
        QMessageBox::warning(nullptr,"rules","les rules est obligatoire",QMessageBox::Cancel);
        ui->lineEdit_rules->setFocus();
        return false;
    }
return 1;

}


void MainWindow_l::on_tableView_activated(const QModelIndex &index)
{
    //int val=ui->tableView->model()->data(index).toInt();
            QString val=ui->tableView->model()->data(index).toString();
            QSqlQuery qry;
            qry.prepare("select * from LABORATOIRES where ID_LABO='"+val+"'");
            if(qry.exec())
            {
                while (qry.next())
                {
                 ui->lineEdit_id->setText(qry.value(0).toString());
                   ui->lineEdit_rules->setText(qry.value(1).toString());


                /* bool classea = qry.value(1).toBool();

                                     // Set the state of the radio button based on the value
                                     if (classea)
                                     {
                                         ui->radioButton_2->setChecked(true);
                                     }
                                     else
                                     {
                                         ui->radioButton->setChecked(true);
                                     }
                 ui->checkBox->setDown(qry.value(2).toBool());
                 ui->spinBox->setValue(qry.value(3).toInt());
                 ui->lineEdit_prix->setText(qry.value(4).toString() );*/
                }
            }
            else
            {
             QMessageBox::critical(this,tr("error::"),qry.lastError().text());
            }
    }



void MainWindow_l::procesar()
{
    segundos=segundos+1; // segundos++;
    if (segundos==60) {
        segundos=0;
        minutos=minutos+1;
    }
    else{
        ui->segundos_2->display(segundos);
        ui->minutos_2   ->display(minutos);
    }
}





void MainWindow_l::on_btn_stop_2_clicked()
{
    minutos=0;
    segundos=0;
    pausado=false;
    ui->minutos_2->display(minutos);
    ui->segundos_2->display(segundos);
    reloj.stop();
}

void MainWindow_l::on_btn_pausa_2_clicked()
{
    if (pausado==false) {
        reloj.stop();
        pausado=true;
        ui->btn_pausa_2->setText("reanudar");
    }
    else{
        pausado=false;
        reloj.start(1000);
        ui->btn_pausa_2->setText("pausar");
    }
}

void MainWindow_l::on_btn_iniciar_2_clicked()
{
    reloj.start(1000);
}

void MainWindow_l::Date_Time_Display_Slot()
{
    QString DateAndTime = QDateTime::currentDateTime().toString("dd:MM:yyyy  HH:mm:ss");
    ui->lcdNumber->display(DateAndTime);
}

void MainWindow_l::on_pushButton_9_clicked()
{
    Map *m = new Map();
    m->show();
}

void MainWindow_l::on_pushButton_10_clicked()
{
    QCamera *camera = new QCamera(this);
       QCameraViewfinder *viewfinder = new QCameraViewfinder(this);
       camera->setViewfinder(viewfinder);
       QVBoxLayout *layout = new QVBoxLayout;
       layout->addWidget(viewfinder);
       ui->cam->setLayout(layout);

       camera->start();

}


QString ch1="";
void MainWindow_l::update()
{

    QSqlQuery query;
     QByteArray data="";
     QString id="" ,nom="",prenom="",email="",sexe="",fonction="",specialite="",id_labo="";
        data=AA.read_from_arduino();
        qDebug() <<  " data is " <<data;
        ch1=ch1+data;
         qDebug() <<  " ch1 is " <<ch1;


    if(ch1!="" && ch1.length()>=11)
       {
           QString x = "SELECT* FROM EMPLOYES WHERE ARDUINO=" +ch1;
           qDebug() << x;
         query.prepare("SELECT* FROM EMPLOYES WHERE ARDUINO='"+ch1+"'  ");
         qDebug() << query.exec();
         while (query.next())
         {
         id =query.value(0).toString();
         nom=query.value(1).toString();
         prenom=query.value(2).toString();
         email=query.value(3).toString();
         sexe=query.value(4).toString();
         fonction=query.value(5).toString();
         specialite=query.value(6).toString();
         id_labo=query.value(7).toString();
         //grade=query.value(9).toString();
         }
         qDebug() << id;
         qDebug() << nom;
          qDebug() << prenom;
           qDebug() << email;
            qDebug() << sexe;
             qDebug() << fonction;
              qDebug() << specialite;
               qDebug() << id_labo;
         //qDebug() << grade;
         ui->lineEdit_rechercher_4->setText(id);
         ui->lineEdit_rechercher_11->setText(nom);
         ui->lineEdit_rechercher_10->setText(prenom);
         ui->lineEdit_rechercher_9->setText(email);
         ui->lineEdit_rechercher_5->setText(sexe);
         ui->lineEdit_rechercher_6->setText(fonction);
         ui->lineEdit_rechercher_7->setText(specialite);
         ui->lineEdit_rechercher_8->setText(id_labo);
         ui->tableView->setModel(ltmp.afficher1());

         //ui->l_grade_lg->setText(grade);
         if(nom!="")
         {
         QString message ="Bienvenue "+ nom;
         QByteArray br = message.toUtf8();
         AA.write_to_arduino(br);
         QMessageBox::information(nullptr, QObject::tr("arduino is open"),
          QObject::tr("Bienvenue %1 .\n" "click cancel to exit.")
                                  .arg(nom), QMessageBox::Cancel );

         }
         else {
             QString message ="acces denied";
             QByteArray br = message.toUtf8();
             AA.write_to_arduino(br);
             QMessageBox::information(nullptr, QObject::tr("arduino is open"),
              QObject::tr("acces denied.\n" "click cancel to exit."), QMessageBox::Cancel );
         }



    }

    if(ch1.length()>=11)
     {
     ch1="";
     }
}


void MainWindow_l::on_tri_2_clicked()
{
    AA.write_to_arduino("x");
    QMessageBox::information(nullptr, QObject::tr("arduino is open"),
    QObject::tr("HELLO.\n" "click cancel to exit."), QMessageBox::Cancel );
}

void MainWindow_l::on_tri_3_clicked()
{
    AA.write_to_arduino("y");
    QMessageBox::information(nullptr, QObject::tr("arduino is open"),
    QObject::tr("GOODBYE.\n" "click cancel to exit."), QMessageBox::Cancel );


}

void MainWindow_l::on_tri_4_clicked()
{
     AA.write_to_arduino("a");
     QMessageBox::information(nullptr, QObject::tr("arduino is open"),
     QObject::tr("GREENLED IS ON.\n" "click cancel to exit."), QMessageBox::Cancel );

}

void MainWindow_l::on_tri_5_clicked()
{
     AA.write_to_arduino("b");
     QMessageBox::information(nullptr, QObject::tr("arduino is open"),
     QObject::tr("REDLED IS ON.\n" "click cancel to exit."), QMessageBox::Cancel );

}

void MainWindow_l::on_pushButton_13_clicked()
{
    Menu * j= new Menu;
        j->show();
}

void MainWindow_l::on_pushButton_19_clicked()
{
    this->hide();
}
