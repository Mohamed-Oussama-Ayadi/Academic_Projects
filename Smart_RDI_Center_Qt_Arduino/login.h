#ifndef LOGIN_H
#define LOGIN_H
#include "MainWindow_em.h"
#include <QDialog>
#include"Employes.h"
#include "menu.h"



namespace Ui {class login;}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


private slots:
    void on_pb_seconnecter_clicked();

    void on_pushButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
