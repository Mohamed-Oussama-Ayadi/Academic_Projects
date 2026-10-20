#ifndef MAINWINDOW_L_H
#define MAINWINDOW_L_H
#include <QMessageBox>
#include <QMainWindow>
#include <QVariant>
#include <QNetworkReply>
#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QTime>
#include <QDebug>
#include<arduino_l.h>
#include"labo.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_l; }
QT_END_NAMESPACE

class MainWindow_l : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_l(QWidget *parent = nullptr);
    void on_pushButton_ajouter_clicked();
    ~MainWindow_l();

private slots:
    bool verif();

    void on_tableView_activated(const QModelIndex &index);

    void on_ajouter_4_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_7_clicked();

    void on_supprimer_3_clicked();

    void on_tri_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pdf_clicked();

    void on_supprimer_4_clicked();

    void procesar();



    void on_btn_stop_2_clicked();

    void on_btn_pausa_2_clicked();

    void on_btn_iniciar_2_clicked();


    void Date_Time_Display_Slot();

    void on_pushButton_10_clicked();
    void update();


    void on_tri_2_clicked();

    void on_tri_3_clicked();

    void on_tri_4_clicked();

    void on_tri_5_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow_l*ui;
    labo ltmp;
    short int minutos;
    short int segundos;
    bool pausado;
    QTimer reloj;
    QTimer* DateTime;
arduinoo AA;
};
#endif // MAINWINDOW_L_H
