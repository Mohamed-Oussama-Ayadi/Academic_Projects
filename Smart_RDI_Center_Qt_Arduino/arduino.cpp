#include "arduino.h"
#include "ui_arduino.h"

Arduino::Arduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino)
{
    ui->setupUi(this);
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

     temp=0;
     hum=0;
     timer=new QTimer(this);
     timer->singleShot(1000,this,SLOT(update_max()));
}

Arduino::~Arduino()
{
    delete ui;
}


QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino()
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

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
 }


int Arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
        qDebug()<<"d="<<d;
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}


void Arduino::update_label()
{

    data=read_from_arduino().trimmed();
    str.append(data);
foreach(auto item, str.split(' '))
{
    qDebug()<<"item="<<item;
    if(item.startsWith('t') && item.length()>1 && item.length()<7)
    {
        item.remove(0,1);
        temp=item.toFloat();
        ui->lcdNumber->display(temp);
    }
    else
        if(item.startsWith('h') && item.length()>1 && item.length()<7)
        {
            item.remove(0,1);
            hum=item.toFloat();
            ui->lcdNumber_2->display(hum);
        }
    else
            if(item.startsWith('v') && item.length()>1 && item.length()<3)
            {
                item.remove(0,1);
                led_verte=item.toInt();
                if(led_verte==1)
                {
                    ui->pushButton->setText("ON");
                    ui->pushButton->setStyleSheet("background-color: green");
                }
                else
                {
                    ui->pushButton->setText("OFF");
                    ui->pushButton->setStyleSheet("background-color: red");

                }
            }
    else
                if(item.startsWith('r') && item.length()>1 && item.length()<3)
                {
                    item.remove(0,1);
                    led_orange=item.toUInt();
                    if(led_orange==1)
                    {
                        ui->pushButton_2->setText("ON");
                        ui->pushButton_4->setText("ON");
                        ui->pushButton_2->setStyleSheet("background-color: green");
                        ui->pushButton_4->setStyleSheet("background-color: green");

                    }
                    else
                    {
                        ui->pushButton_2->setText("OFF");
                        ui->pushButton_4->setText("OFF");
                        ui->pushButton_2->setStyleSheet("background-color: red");
                        ui->pushButton_4->setStyleSheet("background-color: red");


                    }

                }
    else
                    if(item.startsWith('.'))
                    {
                        str.clear();
                    }
    else
                        if(item.startsWith('b') && item.length()>1 && item.length()<3)
                        {
                            item.remove(0,1);
                            buzzer=item.toInt();
                            if(buzzer==1)
                            {
                                ui->pushButton_3->setText("ON");
                                ui->pushButton_3->setStyleSheet("background-color: green");
                            }
                            else
                            {
                                ui->pushButton_3->setText("OFF");
                                ui->pushButton_3->setStyleSheet("background-color: red");
                            }
                        }


}


}

void Arduino::update_max()
{
    write_to_arduino("i");
    QSqlQuery requete;
    requete.prepare("SELECT max(temperature) FROM LABORATOIRES");
    requete.exec();
    while (requete.next())
    {
        max_t.setNum(requete.value(0).toFloat());
    }

    ui->lcdNumber_3->display(max_t.toFloat());

    write_to_arduino(max_t);
    write_to_arduino("i");

}



void Arduino::on_pushButton_clicked()
{
    if(led_verte==1)
        write_to_arduino("v"); //envoyer 1 à arduino
    else
        if(led_verte==0)
            write_to_arduino("a");
}

void Arduino::on_pushButton_2_clicked()
{
    if(led_orange==1)
        write_to_arduino("o"); //envoyer 1 à arduino
    else
        if(led_orange==0)
            write_to_arduino("n");
}

void Arduino::on_pushButton_3_clicked()
{
    if(buzzer==1)
        write_to_arduino("b"); //envoyer 1 à arduino
    else
        if(buzzer==0)
            write_to_arduino("e");

}

void Arduino::on_pushButton_4_clicked()
{
    write_to_arduino("m"); //envoyer 1 à arduino
}

void Arduino::on_pushButton_5_clicked()
{
    QSqlQuery requete;
    requete.prepare("INSERT INTO LABORATOIRES(TEMPERATURE , HUMIDITE) "
                    "VALUES(:temp,:hum)");

    requete.bindValue(":temp", temp);
    requete.bindValue(":hum",hum);

  requete.exec();

  update_max();
}


