#include "mainwindow_event.h"
#include "ui_mainwindow_event.h"
#include "event.h"
#include "arduino.h"
#include "menu.h"
MainWindow_event::MainWindow_event(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_event)
{
    ui->setupUi(this);
    Event E;
    QSqlQueryModel *model=E.afficher();

    ui->tableView->setModel(model);
    ui->dateTimeEdit_debut->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_fin->setDateTime(QDateTime::currentDateTime());
    QString e;
    employes.append("");
    QSqlQuery query("select id_employe,nom,prenom from employes");


    while(query.next())
    {

      e=query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString();
      employes.append(e);

    }


    ui->comboBox_organisateur->addItems(employes);
    ui->spinBox_nb->setRange(0,1000);
    themes<<"" << "Conference" << "Atelier";
    ui->comboBox_theme->addItems(themes);
    lieu<<""<<"Tunis"<<"Sousse"<<"Bizerte";
    ui->comboBox_lieu->addItems(lieu);

    QCursor cursor;
    cursor.setShape(Qt::PointingHandCursor);
    ui->tableView->setCursor(cursor);
    ui->tableView->resizeColumnsToContents();


    connect(ui->calendar_pb,&QAbstractButton::clicked,&c,[&](){
        c.setGridVisible(true);


        c.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);


        c.setHorizontalHeaderFormat(QCalendarWidget::LongDayNames);



            b->setText("calendar");
            b1->setText("Prochain evenement");
        c.setWindowTitle("Calendrier");

            layout=c.layout();
            layout->setAlignment(Qt::AlignCenter);
            layout->addWidget(b1);
            layout->addWidget(b);

            label->setFont(QFont("Calibri",24));
            label->setAlignment(Qt::AlignLeft);
            label->setText(QDate::currentDate().toString());
            //label->setGeometry(500,500,100,100);



            layout->addWidget(label);
            //layout->setGeometry(QRect(500,500,40,10));
            c.setLayout(layout);
            //QObject::connect(b,SIGNAL(clicked()),this,SLOT(show_date()));
            QTextCharFormat  format;
            format.setUnderlineStyle(QTextCharFormat::DashUnderline);
            format.setFont(QFont("Calibri",24));
        c.setDateTextFormat(QDate::currentDate(),format);

        QObject::connect(&c,&QCalendarWidget::clicked,&c,[&](){
                    c.connect_to_db(c.selectedDate());


            });

        widget->setStyleSheet("background-color: rgb(178, 225, 229);");
        label_event->setStyleSheet("background-color: rgb(58, 195, 197);");
        QObject::connect(&c,&QCalendarWidget::selectionChanged,&c,[&](){label->setText(c.selectedDate().toString());});




        c1.setCurrentPage(QDate::currentDate().year(),1);c1.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c2.setCurrentPage(QDate::currentDate().year(),2);c2.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c3.setCurrentPage(QDate::currentDate().year(),3);c3.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c4.setCurrentPage(QDate::currentDate().year(),4);c4.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c5.setCurrentPage(QDate::currentDate().year(),5);c5.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c6.setCurrentPage(QDate::currentDate().year(),6);c6.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c7.setCurrentPage(QDate::currentDate().year(),7);c7.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c8.setCurrentPage(QDate::currentDate().year(),8);c8.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c9.setCurrentPage(QDate::currentDate().year(),9);c9.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c10.setCurrentPage(QDate::currentDate().year(),10);c10.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c11.setCurrentPage(QDate::currentDate().year(),11);c11.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        c12.setCurrentPage(QDate::currentDate().year(),12);c12.setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        c1.setDateRange(QDate(QDate::currentDate().year(),1,1),QDate(QDate::currentDate().year(),1,31));
        c2.setDateRange(QDate(QDate::currentDate().year(),2,1),QDate(QDate::currentDate().year(),1,31));
        c3.setDateRange(QDate(QDate::currentDate().year(),3,1),QDate(QDate::currentDate().year(),1,28));
        c4.setDateRange(QDate(QDate::currentDate().year(),4,1),QDate(QDate::currentDate().year(),1,30));
        c5.setDateRange(QDate(QDate::currentDate().year(),5,1),QDate(QDate::currentDate().year(),1,31));
        c6.setDateRange(QDate(QDate::currentDate().year(),6,1),QDate(QDate::currentDate().year(),1,30));
        c7.setDateRange(QDate(QDate::currentDate().year(),7,1),QDate(QDate::currentDate().year(),1,31));
        c8.setDateRange(QDate(QDate::currentDate().year(),8,1),QDate(QDate::currentDate().year(),1,31));
        c9.setDateRange(QDate(QDate::currentDate().year(),9,1),QDate(QDate::currentDate().year(),1,30));
        c10.setDateRange(QDate(QDate::currentDate().year(),10,1),QDate(QDate::currentDate().year(),1,31));
        c11.setDateRange(QDate(QDate::currentDate().year(),11,1),QDate(QDate::currentDate().year(),1,30));
        c12.setDateRange(QDate(QDate::currentDate().year(),12,1),QDate(QDate::currentDate().year(),1,31));
        QLabel *l1=new QLabel;
                QLabel *l2=new QLabel;
                QLabel *l3=new QLabel;
                QLabel *l4=new QLabel;
                QLabel *l5=new QLabel;
                QLabel *l6=new QLabel;
                QLabel *l7=new QLabel;
                QLabel *l8=new QLabel;
                QLabel *l9=new QLabel;
                QLabel *l10=new QLabel;
                QLabel *l11=new QLabel;
                QLabel *l12=new QLabel;
                QVBoxLayout *vl1=new QVBoxLayout;
                        QVBoxLayout *vl2=new QVBoxLayout;
                        QVBoxLayout *vl3=new QVBoxLayout;
                        QVBoxLayout *vl4=new QVBoxLayout;
                        QVBoxLayout *vl5=new QVBoxLayout;
                        QVBoxLayout *vl6=new QVBoxLayout;
                        QVBoxLayout *vl7=new QVBoxLayout;
                        QVBoxLayout *vl8=new QVBoxLayout;
                        QVBoxLayout *vl9=new QVBoxLayout;
                        QVBoxLayout *vl10=new QVBoxLayout;
                        QVBoxLayout *vl11=new QVBoxLayout;
                        QVBoxLayout *vl12=new QVBoxLayout;

                QVBoxLayout *vl=new QVBoxLayout;
                        QHBoxLayout *hl=new QHBoxLayout;
                        QHBoxLayout *hl1=new QHBoxLayout;
                        QHBoxLayout *hl2=new QHBoxLayout;
        l1->setText("Janvier");
        l2->setText("Fevrier");
        l3->setText("Mars");
        l4->setText("Avril");
        l5->setText("Mai");
        l6->setText("Juin");
        l7->setText("Juillet");
        l8->setText("Aout");
        l9->setText("Septembre");
        l10->setText("Octobre");
        l11->setText("Novembre");
        l12->setText("Décembre");
        l1->setFont(QFont("Calibri",12));
        l2->setFont(QFont("Calibri",12));
        l3->setFont(QFont("Calibri",12));
        l4->setFont(QFont("Calibri",12));
        l5->setFont(QFont("Calibri",12));
        l6->setFont(QFont("Calibri",12));
        l7->setFont(QFont("Calibri",12));
        l8->setFont(QFont("Calibri",12));
        l9->setFont(QFont("Calibri",12));
        l10->setFont(QFont("Calibri",12));
        l11->setFont(QFont("Calibri",12));
        l12->setFont(QFont("Calibri",12));
        QTableView * c_widget1=c1.findChild<QTableView *>();
        QTableView * c_widget2=c2.findChild<QTableView *>();
        QTableView * c_widget3=c3.findChild<QTableView *>();
        QTableView * c_widget4=c4.findChild<QTableView *>();
        QTableView * c_widget5=c5.findChild<QTableView *>();
        QTableView * c_widget6=c6.findChild<QTableView *>();
        QTableView * c_widget7=c7.findChild<QTableView *>();
        QTableView * c_widget8=c8.findChild<QTableView *>();
        QTableView * c_widget9=c9.findChild<QTableView *>();
        QTableView * c_widget10=c10.findChild<QTableView *>();
        QTableView * c_widget11=c11.findChild<QTableView *>();
        QTableView * c_widget12=c12.findChild<QTableView *>();

        c_widget1->setStyleSheet("background-color:white;");
        c_widget2->setStyleSheet("background-color:white;");
        c_widget3->setStyleSheet("background-color:white;");
        c_widget4->setStyleSheet("background-color:white;");
        c_widget5->setStyleSheet("background-color:white;");
        c_widget6->setStyleSheet("background-color:white;");
        c_widget7->setStyleSheet("background-color:white;");
        c_widget8->setStyleSheet("background-color:white;");
        c_widget9->setStyleSheet("background-color:white;");
        c_widget10->setStyleSheet("background-color:white;");
        c_widget11->setStyleSheet("background-color:white;");
        c_widget12->setStyleSheet("background-color:white;");

        vl1->addWidget(l1);
        vl1->addWidget(c_widget1);
        vl2->addWidget(l2);
        vl2->addWidget(c_widget2);
        vl3->addWidget(l3);
        vl3->addWidget(c_widget3);
        vl4->addWidget(l4);
        vl4->addWidget(c_widget4);
        vl5->addWidget(l5);
        vl5->addWidget(c_widget5);
        vl6->addWidget(l6);
        vl6->addWidget(c_widget6);
        vl7->addWidget(l7);
        vl7->addWidget(c_widget7);
        vl8->addWidget(l8);
        vl8->addWidget(c_widget8);
        vl9->addWidget(l9);
        vl9->addWidget(c_widget9);
        vl10->addWidget(l10);
        vl10->addWidget(c_widget10);
        vl11->addWidget(l11);
        vl11->addWidget(c_widget11);
        vl12->addWidget(l12);
        vl12->addWidget(c_widget12);

        vl1->setMargin(5);
        vl2->setMargin(5);
        vl3->setMargin(5);
        vl4->setMargin(5);
        vl5->setMargin(5);
        vl6->setMargin(5);
        vl7->setMargin(5);
        vl8->setMargin(5);
        vl9->setMargin(5);
        vl10->setMargin(5);
        vl11->setMargin(5);
        vl12->setMargin(5);




        //hl->setMargin(50);


        hl->addLayout(vl1);
        hl->addLayout(vl2);
        hl->addLayout(vl3);
        hl->addLayout(vl4);

        hl1->addLayout(vl5);
        hl1->addLayout(vl6);
        hl1->addLayout(vl7);
        hl1->addLayout(vl8);

        hl2->addLayout(vl9);
        hl2->addLayout(vl10);
        hl2->addLayout(vl11);
        hl2->addLayout(vl12);

        hl->setContentsMargins(10,10,10,10);
        hl1->setContentsMargins(10,10,10,10);
        hl2->setContentsMargins(10,10,10,10);

        vl->addLayout(hl);
        vl->addLayout(hl1);
        vl->addLayout(hl2);
        vl->setMargin(30);


        widget->setLayout(vl);



        QObject::connect(b,&QAbstractButton::clicked,[&](){
        widget->resize(1500,900);
            widget->show();});


        QObject::connect(b1,&QAbstractButton::clicked,[&](){
        label_event->setFont(QFont("Calibri",14));
        QSqlQuery query1;

        query1.prepare("select * from events where date_debut = (select min(date_debut) from events where date_debut>sysdate)");
        query1.exec();
        while(query1.next())
        {

            QDateTime d1=QDateTime::currentDateTime();
            QDateTime d2=query1.value(1).toDateTime();
            int diff=d1.daysTo(d2);

            label_event->setText("Prochain evenement dans "+QString::number(diff)+ " jours\nDate debut: "
                                 +d2.toString()
                                 +"    Date fin: "+query1.value(2).toDateTime().toString()
                                 +"    Lieu: "+query1.value(3).toString()
                                 +"\nTheme: "+query1.value(4).toString()
                                 +"    Organisateur: "+query1.value(5).toString()
                                 +"    Nombre d'invites: "+query1.value(6).toString()
                                 +"    Sponsor: "+query1.value(7).toString());

        }
        label_event->show();
        });
        c.resize(1250,700);
        c.setStyleSheet( "QCalendarWidget QWidget { alternate-background-color: rgb(58,195,197);font: 16pt 'Calibri';}"
                        "QCalendarWidget QToolButton{ height: 60px;  	width: 150px;  	color: white;	font-size: 35px; background-color:rgb(75,141,157); icon-size: 35px, 35px;}"
                         "QCalendarWidget QToolButton:hover{background-color: white;color:black;}"
                         "QCalendarWidget QWidget#qt_calendar_navigationbar{ background-color: rgb(75,141,157);}"
                         "QCalendarWidget QSpinBox {width: 100px; font-size:35px; color: black; background-color: white; selection-background-color: white;selection-color:black; }"
                           "QCalendarWidget QSpinBox::up-button { subcontrol-origin: border;  subcontrol-position: top right;  width:30px; }"
                           "QCalendarWidget QSpinBox::down-button {subcontrol-origin: border; subcontrol-position: bottom right;  width:30px;}"
                           "QCalendarWidget QSpinBox::up-arrow { width:20px;  height:20px; }"
                           "QCalendarWidget QSpinBox::down-arrow { width:20px;  height:20px; }"
                         "QCalendarWidget QMenu {	width: 150px;  	left: 20px;  	color: black;  	font-size: 22px;  }"
                         "QToolButton::menu-indicator {height:20px;width:20px;color:rgb(58,195,197);}");
        c.show();});

}

MainWindow_event::~MainWindow_event()
{
    delete ui;
}


bool MainWindow_event::verif()
{
    int nb_invites,sponsor;
    QDateTime date_debut,date_fin;
    QString lieu,theme,organisateur;
    organisateur=ui->comboBox_organisateur->currentText();
    nb_invites=ui->spinBox_nb->text().toUInt();
    date_debut=ui->dateTimeEdit_debut->dateTime();
    date_fin=ui->dateTimeEdit_fin->dateTime();
    lieu=ui->comboBox_lieu->currentText();
    theme=ui->comboBox_theme->currentText();
    sponsor=ui->lineEdit_id_sponsor->text().toUInt();

    QSqlQuery query;
    query.prepare("select id_sponsor from sponsors where id_sponsor=:sponsor");
    query.bindValue(":sponsor",sponsor);
    query.exec();
    int erreur=0;
    QDateTime d1=ui->dateTimeEdit_debut->dateTime();
    QDateTime d2=ui->dateTimeEdit_fin->dateTime();
    if(date_debut!=dd || date_fin!=df || lieu!=l || theme!=th || organisateur!=g || nb_invites!=n || sponsor!=s)
    {
    if(d1>d2 )
    {
        QMessageBox::critical(nullptr, QObject::tr("la date de début doit être inferieur a la date de fin"),
                              QObject::tr("la date de début doit être inferieur a la date de fin.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        erreur=1;
    }
      else

                if(lieu==""){
                    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                          QObject::tr("Lieu est vide!.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                    erreur=1;

                }
                else

                        if(theme==""){
                            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                                  QObject::tr("Theme est vide!.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);
                            erreur=1;

                        }

    else

            if(organisateur==""){
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                      QObject::tr("Organisateur est vide!.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
                erreur=1;

            }

    else
        if(nb_invites==0)
        {
            QMessageBox::critical(nullptr, QObject::tr("Nombre d'invites non valide!"),
                        QObject::tr("Nombre d'invites non valide!.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            erreur=1;
    }
    else
            if(query.first()==0)
            {
                QMessageBox::critical(nullptr, QObject::tr("Nombre d'invites non valide!"),
                            QObject::tr("Sponsor inexistant.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                erreur=1;
        }

    }else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("Cette ligne existe déjà.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        erreur=1;
    }
        return erreur;
}

void MainWindow_event::on_ajouter_pb_clicked()
{
    int nb_invites,sponsor;
    QDateTime date_debut,date_fin;
    QString lieu,theme,organisateur;
    organisateur=ui->comboBox_organisateur->currentText();
    nb_invites=ui->spinBox_nb->text().toUInt();
    date_debut=ui->dateTimeEdit_debut->dateTime();
    date_fin=ui->dateTimeEdit_fin->dateTime();
    lieu=ui->comboBox_lieu->currentText();
    theme=ui->comboBox_theme->currentText();
    sponsor=ui->lineEdit_id_sponsor->text().toUInt();



    if(verif()==0)
    {


    Event E(date_debut,date_fin, lieu,theme,organisateur, nb_invites,sponsor);
    bool test=E.ajouter();
    if(test)
    {
        QMessageBox::StandardButton reply;
               reply = QMessageBox::question(this, "Confirmation",
                       "Êtes-vous sûr de vouloir ajouter cet événement ?",
                       QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
        QMessageBox::information(nullptr, QObject::tr("Ajouté"),
                    QObject::tr("Ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        cout<< "added";
       reset();

        Event E;
        ui->tableView->setModel(E.afficher());
}
    }
    else
    {
        cout<<"not added";
        QMessageBox::critical(nullptr, QObject::tr("erreur ajout"),
                    QObject::tr("Erreur! Non ajouté!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }


}
/*
void MainWindow_event::on_afficher_pb_clicked()
{
    Event E;
    ui->tableView->setModel(E.afficher());
}
*/
void MainWindow_event::on_supprimer_pb_clicked()
{
    //int id=ui->lineEdit_id->text().toInt();
    Event E;
    int row=ui->tableView->currentIndex().row();
    QSqlQueryModel *model=E.afficher();
    int id = model->data(model->index(row,0)).toInt();

    QSqlQuery query=E.chercher(id,"");

    QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this, "Confirmation",
                   "Êtes-vous sûr de vouloir supprimer cet événement ?",
                   QMessageBox::Yes|QMessageBox::No);
 if (reply == QMessageBox::Yes) {
        bool test=E.supprimer(id);

        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("Supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            cout<<"deleted";
            Event E;
            ui->tableView->setModel(E.afficher());
            reset();
        }
        else
        {
            cout<<"not deleted";
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("Erreur!.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
 }
 else {
     reset();
 }

}



/*
void MainWindow_event::on_rechercher_pb_clicked()
{
    Event E;
    QSqlQuery query=E.rechercher(ui->lineEdit_id->text().toUInt());
    if (!query.first()) {
        cout<<"erreur pas de resultat";
    }

    QDateTime date_debut = query.value(0).toDateTime();
    QDateTime date_fin = query.value(1).toDateTime();
    QString lieu = query.value(2).toString();
    QString theme = query.value(3).toString();
    QString organisateur = query.value(4).toString();
    int nb_invites = query.value(5).toInt();



    ui->dateTimeEdit_fin->setDateTime(date_debut);
    ui->dateTimeEdit_debut->setDateTime(date_fin);
    //ui->comboBox_lieu->setItemText(0,lieu);
    //ui->comboBox_theme->setItemText(0,theme);
    ui->lineEdit_id_organisateur->setText(organisateur);
    ui->spinBox_nb->setValue(nb_invites);

    int index = ui->comboBox_lieu->findText(lieu);
    if ( index != -1 )  // -1 for not found
       ui->comboBox_lieu->setCurrentIndex(index);

    int index1 = ui->comboBox_theme->findText(theme);
    if ( index1 != -1 )  // -1 for not found
       ui->comboBox_theme->setCurrentIndex(index1);

}
*/
void MainWindow_event::on_modifier_pb_clicked()
{
    Event E;
    int nb_invites,sponsor,row,id;
    QDateTime date_debut,date_fin;
    QString lieu,theme,organisateur;
    //organisateur=ui->lineEdit_id_organisateur->text();
    nb_invites=ui->spinBox_nb->text().toUInt();
    date_debut=ui->dateTimeEdit_debut->dateTime();
    date_fin=ui->dateTimeEdit_fin->dateTime();
    organisateur=ui->comboBox_organisateur->currentText();
    lieu=ui->comboBox_lieu->currentText();
    theme=ui->comboBox_theme->currentText();
    nb_invites=ui->spinBox_nb->value();
    sponsor=ui->lineEdit_id_sponsor->text().toUInt();
    row=ui->tableView->currentIndex().row();
    QSqlQueryModel *model=E.afficher();
    id = model->data(model->index(row,0)).toInt();

    if(date_debut!=dd || date_fin!=df || lieu!=l || theme!=th || organisateur!=g || nb_invites!=n || sponsor!=s)
    {

    if(verif()==0)
    {
    bool test=E.modifier(date_debut,date_fin,id,lieu,theme,organisateur,nb_invites,sponsor);

    if(test)
    {

        QMessageBox::StandardButton reply;
               reply = QMessageBox::question(this, "Confirmation",
                       "Êtes-vous sûr de vouloir modifier cet événement ?",
                       QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("Modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        cout<<"deleted";
        Event E;
        ui->tableView->setModel(E.afficher());
        reset();
     }
    }
    else
    {
        cout<<"not deleted";
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Erreur!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("Aucune modification n'a été effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void MainWindow_event::on_chercher_clicked()
{
    Event E;
    int id=ui->lineEdit_rechercher->text().toUInt();
    QString id1=ui->lineEdit_rechercher->text().toLower();
    QSqlQueryModel* model=new QSqlQueryModel;
    model->setQuery(E.chercher(id,id1));

    ui->tableView->setModel(model);

}

void MainWindow_event::on_annuler_pb_clicked()
{
    reset();
}

void MainWindow_event::on_tableView_clicked(const QModelIndex &index)
{
    Event E;
    int row=index.row();
    int id = E.afficher()->data(E.afficher()->index(row,0)).toInt();
    QSqlQuery query=E.chercher(id,"");
    ui->tableView->selectRow(row);

while(query.next())
{
    dd=query.value(1).toDateTime();
    df=query.value(2).toDateTime();
    l=query.value(3).toString();
    th=query.value(4).toString();
    g=query.value(5).toString();
    n=query.value(6).toInt();
    s=query.value(7).toUInt();

}
    ui->dateTimeEdit_debut->setDateTime(dd);
    ui->dateTimeEdit_fin->setDateTime(df);
    int i = ui->comboBox_lieu->findText(l);
    if ( i != -1 )  // -1 for not found
       ui->comboBox_lieu->setCurrentIndex(i);
    int i1 = ui->comboBox_theme->findText(th);
    if ( i1 != -1 )  // -1 for not found
       ui->comboBox_theme->setCurrentIndex(i1);
    ui->spinBox_nb->setValue(n);
    int i2 = ui->comboBox_organisateur->findText(g);
    if ( i2 != -1 )  // -1 for not found
    ui->comboBox_organisateur->setCurrentIndex(i2);
    ui->lineEdit_id_sponsor->setText(QString::number(s));



}

void MainWindow_event::reset()
{
    ui->dateTimeEdit_debut->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_fin->setDateTime(QDateTime::currentDateTime());
    ui->comboBox_lieu->setCurrentIndex(0);
    ui->comboBox_theme->setCurrentIndex(0);
    ui->comboBox_organisateur->setCurrentIndex(0);
    ui->spinBox_nb->clear();
    ui->lineEdit_id_sponsor->clear();
    Event E;
    ui->tableView->setModel(E.afficher());
}




void MainWindow_event::on_comboBox_tri_currentIndexChanged(int index)
{

    ordre="ASC";
    if(index==1)
        item="date_debut";
    else
        if(index==2)
            item="theme";
    else
            if(index==3)
                item="nb_invites";
    else
                if(index==5)
                    ordre="ASC";
    else
                            if(index==6)
                                ordre="DESC";

}


void MainWindow_event::trier(QString item,QString ordre)
{
    QString select;
    select="select * from events order by ";
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

void MainWindow_event::on_pushButton_tri_clicked()
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



void MainWindow_event::on_stat_pb_clicked()
{

       statistique stat;
       QWidget *widget=new QWidget;
       QHBoxLayout* layout=new QHBoxLayout;

       QChartView *barchartView = new QChartView(stat.barchart());

    QChartView *piechartView = new QChartView(stat.piechart());

    piechartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(barchartView);
    layout->addWidget(piechartView);


    widget->setLayout(layout);
    widget->setGeometry(400,400,900,500);
widget->show();

}



void MainWindow_event::on_video_pb_clicked()
{
    Video v;
    v.setWindowTitle("lecteur video");
    v.exec();
}






void MainWindow_event::on_pdf_pb_clicked()
{
    QPdfWriter pdf("C:/pdf/list.pdf");
    pdf.setPageSize(QPagedPaintDevice::A4);

   QPainter painter(&pdf);
   int i = 4100;
   const QImage image(":/img/img/logo.png");
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

          painter.drawText(3000,2700,"Liste des Evenements");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          //painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 10));

                        painter.drawText(200,3600,"ID");
                      painter.drawText(700,3600,"DATE DEBUT");
                      painter.drawText(2000,3600,"DATE FIN");
                      painter.drawText(3050,3600,"LIEU");
                       painter.drawText(3850,3600,"THEME");
                        painter.drawText(4900,3600,"ORGANISATEUR");
                        painter.drawText(6400,3600,"NB_INVITES");
                        painter.drawText(7500,3600,"SPONSOR");
                        painter.drawText(8500,3600,"ID EMPLOYE");


          painter.setFont(QFont("Montserrat", 10));
          painter.drawRect(100,3300,9400,9000);

          QSqlQuery query;
          query.prepare("select * from events");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=550;
                  painter.drawText(200,i,query.value(0).toString());
                  painter.drawText(700,i-60,query.value(1).toDate().toString("dd/MM/yyyy"));
                  painter.drawText(700,i+140,query.value(1).toTime().toString());

                  painter.drawText(2000,i-60,query.value(2).toDate().toString("dd/MM/yyyy"));
                  painter.drawText(2000,i+140,query.value(2).toTime().toString());

                  painter.drawText(3050,i,query.value(3).toString());
                  painter.drawText(3850,i,query.value(4).toString());
                  painter.drawText(4900,i,query.value(5).toString());
                  painter.drawText(6400,i,query.value(6).toString());
                  painter.drawText(7500,i,query.value(7).toString());
                  painter.drawText(8500,i,query.value(8).toString());

             i = i + 550;
             if(y>12000){
                 pdf.newPage();
                 y=1000;
                 i=1300;
                 painter.drawRect(100,1000,9400,9000);


             }

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


void MainWindow_event::on_pushButton_2_clicked()
{
    Arduino A;
    A.exec();
}

void MainWindow_event::on_pushButton_13_clicked()
{
    Menu * j= new Menu;
        j->show();
}

void MainWindow_event::on_pushButton_19_clicked()
{
    this->hide();
}
