#ifndef MAINWINDOW_EVENT_H
#define MAINWINDOW_EVENT_H

#include"statistique.h"
#include"video.h"
#include <QMainWindow>
#include <QString>
#include<iostream>
#include<QMessageBox>
#include <QDateTime>
#include<QPdfWriter>
#include<QPainter>
#include<QDate>
#include<QDesktopServices>
#include<QPushButton>
#include<QUrl>
#include"calendrier.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_event; }
QT_END_NAMESPACE

class MainWindow_event : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_event(QWidget *parent = nullptr);
    ~MainWindow_event();
    void reset();
    bool verif();

private slots:
    void on_ajouter_pb_clicked();

    void on_supprimer_pb_clicked();

    void on_modifier_pb_clicked();

    void on_chercher_clicked();

    void on_annuler_pb_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_comboBox_tri_currentIndexChanged(int index);

    void on_stat_pb_clicked();

    void on_video_pb_clicked();

    void on_pdf_pb_clicked();

    void trier(QString item,QString ordre);

    void on_pushButton_tri_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_19_clicked();

private:
    Ui::MainWindow_event *ui;
    QDateTime dd,df;
    QString l,th,g;
    int n,s;
    QStringList employes,themes,lieu;
    QString item,ordre;
        Calendrier c;
        Calendrier c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12;
         QLayout *layout;
        QPushButton *b=new QPushButton;
                    QPushButton *b1=new QPushButton;
        QLabel *label=new QLabel;



                //QHBoxLayout *hl3=new QHBoxLayout;

                QWidget *widget=new QWidget;
                QLabel *label_event=new QLabel;



};
#endif // MAINWINDOW_EVENT_H
