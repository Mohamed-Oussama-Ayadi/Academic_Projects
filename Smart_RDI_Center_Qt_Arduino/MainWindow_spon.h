#ifndef MAINWINDOW_SPON_H
#define MAINWINDOW_SPON_H
#include <QMessageBox>
#include <QMainWindow>
#include "sponsor.h"
#include <QSqlQueryModel>
#include <QUrl>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_spon; }
QT_END_NAMESPACE
namespace  Duratecorporation {
class MainWindow_spon : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_spon(QWidget *parent = nullptr);

    ~MainWindow_spon();

private slots:
    void on_ajouter_4_clicked();

    void on_pushButton_afficher_clicked();

    void on_supprimer_2_clicked();

    void on_modifier_3_clicked();

    bool verif();

    void on_rechercher_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tri_clicked();

   void on_pushButton_statistique_clicked();

   void on_pushButton_importer_clicked();


   void on_chat_clicked();

   void on_pushButton_parking_clicked();

   void on_pushButton_acceuil_clicked();

   void on_pushButton_exit_clicked();

   void on_pdf_clicked();

private:
    Ui::MainWindow_spon*ui;

    Sponsor Etmp, S;
};
}
#endif // MAINWINDOW_SPON_H
