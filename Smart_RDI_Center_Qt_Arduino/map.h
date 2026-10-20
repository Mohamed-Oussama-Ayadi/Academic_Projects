#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QPixmap>
#include <QSqlQuery>
#include <QtSql>
#include<QMessageBox>
#include <QAxWidget>

namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Map *ui;
};

#endif // MAP_H
