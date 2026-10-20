#ifndef MainWindow_p_H
#define MainWindow_p_H
#include <QMessageBox>
#include <QMainWindow>
#include<QTableView>
#include <QMessageBox>
#include"project.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_p; }
QT_END_NAMESPACE

class MainWindow_p : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_p(QWidget *parent = nullptr);

    ~MainWindow_p();

private slots:
    void on_ajouter_4_clicked();


    void on_pushButton_7_clicked();

    void on_supprimer_2_clicked();

    void on_supprimer_3_clicked();



    void on_supprimer_4_clicked();

    void on_rechercher_clicked();




    void on_tri_clicked();

    /*void on_comboBoxTrie_activated(const QString &arg1);*/

    void on_comboBoxTrie_currentIndexChanged(int index);
    void trier(QString item,QString ordre);

    void on_stat_clicked();

    void on_notepad_clicked();

    void on_pushButton_clicked();

    void on_pushButton_19_clicked();



    void on_pdf_clicked();

private:
    Ui::MainWindow_p *ui;
    Project P;
    QString item,ordre;
    QString file_path ;

};
#endif // MainWindow_p_H
