#include "arduinoP.h"
#include "ui_parking.h"
#include <QMessageBox>
#include<QSqlQuery>
#include <QSqlError>
#include "QDebug"
#include <QDateTime>
#include <QStandardItemModel>
#include  <QSqlQuery>

arduinoP::arduinoP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arduinoP)
{
    ui->setupUi(this);
   QSqlQueryModel *model = afficherP();
      ui->table_events->setModel(model);
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
    int ret=connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

    }

arduinoP::~arduinoP()
{
    delete ui;
}


QString arduinoP::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduinoP::getserial()
{
   return serial;
}
int arduinoP::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                qDebug()<<"oui";
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
               // serial->setDataTerminalReady(true);
                return 0;
            }
            return 1;
        }
        return -1;
}

int arduinoP::close_arduino()
{
    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;
}


 QByteArray arduinoP::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
 }


int arduinoP::write_to_arduino( QByteArray d)
{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers arduino
        qDebug()<<"d="<<d;
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}




void arduinoP::update_label()
{
    data = read_from_arduino();
    qDebug() << data;
    if (data == "w") {  // w est la commande envoyée par l'Arduino lorsqu'une voiture est détectée
        QSqlQuery query;
        query.prepare("INSERT INTO PARKING (date_time) VALUES (:date_time)");
        query.bindValue(":date_time", QDateTime::currentDateTime());
        if(query.exec()) {
            qDebug() << "Nouvelle voiture ajoutée à la base de données.";
            query.exec("SELECT DATE_TIME FROM parking");
            QStandardItemModel *model = new QStandardItemModel();
            model->setHorizontalHeaderLabels(QStringList() << "Date et Heure");
                int row = 0;
                while(query.next()){
                    QStandardItem *item1 = new QStandardItem(query.value(0).toString());
                    model->setItem(row, 0, item1);

                    row++;
                }

                // Mettre à jour l'interface avec les données de la table parking
                ui->update_label->setModel(model);
                ui->update_label->show();
            }
        }
        else {
            qDebug() << "Erreur lors de l'ajout de la voiture à la base de données : " ;
        }
    }
QSqlQueryModel * arduinoP::afficherP()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from EVENTS");
return model;
}
void arduinoP::on_table_events_activated(const QModelIndex &index)
{
    QString val=ui->table_events->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select NB_INVITES from EVENTS where ID_EVENT='"+val+"'");
      if(qry.exec())
      {
          while (qry.next())
          {
           ui->lineEdit_nb->setText(qry.value(0).toString());
                  }
}
              else
              {
                  QMessageBox::critical(this, tr("Erreur"), qry.lastError().text());
              }
}
void arduinoP::on_pushButton_clicked()
{
    QString val = ui->lineEdit_nb->text(); // Récupérer la valeur du line edit
      write_to_arduino(val.toLatin1());
}




