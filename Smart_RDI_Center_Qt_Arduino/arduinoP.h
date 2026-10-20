#ifndef ARDUINO_H
#define ARDUINO_H
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include<QSqlQuery>
#include<QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui {
class arduinoP;
}
QT_END_NAMESPACE
class arduinoP : public QDialog
{
    Q_OBJECT

public:
    explicit arduinoP(QWidget *parent = nullptr);
    QSqlQueryModel * afficherP();
    ~arduinoP();
    int connect_arduino(); // permet de connecter le PC à arduino
    int close_arduino(); // permet de femer la connexion
    int write_to_arduino( QByteArray ); // envoyer des données vers arduino
    QByteArray read_from_arduino();  //recevoir des données de la carte arduino
    QSerialPort* getserial();   // accesseur
    QString getarduino_port_name();
private:

QSerialPort * serial; //Cet objet rassemble des informations (vitesse, bits de données, etc.)
//et des fonctions (envoi, lecture de réception,…) sur ce qu’est une voie série pour arduino.
static const quint16 arduino_uno_vendor_id=9025;
static const quint16 arduino_uno_producy_id=67;
QString arduino_port_name;
bool arduino_is_available;

QByteArray data;  // contenant les données lues à partir d'arduino

QByteArray str;
Ui::arduinoP *ui;



private slots:

   void update_label();
    void on_pushButton_clicked();
     void on_table_events_activated(const QModelIndex &index);


};

#endif // arduino_H
