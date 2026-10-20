#ifndef MAINWINDOW_EM_H
#define MAINWINDOW_EM_H
#include <QMessageBox>
#include <QMainWindow>
#include <Employes.h>
#include <QSqlQueryModel>
#include <QUrl>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_ajouter_4_clicked();

    void on_pushButton_afficher_clicked();

    void on_supprimer_2_clicked();

    void on_modifier_3_clicked();

    bool verif();

    void on_rechercher_clicked();

    void on_pdf_clicked();

    void on_tableView_activated(const QModelIndex &index);


    void on_tri_clicked();

   void on_pushButton_statistique_clicked();

   void on_pushButton_13_clicked();

   void on_pushButton_19_clicked();

private:
    Ui::MainWindow *ui;

    Employes E;
};

#endif // MAINWINDOW_EM_H
