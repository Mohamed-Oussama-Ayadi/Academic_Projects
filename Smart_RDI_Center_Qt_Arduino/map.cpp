#include "map.h"
#include "ui_map.h"
#include <QDesktopServices>
#include <QUrl>

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}

Map::~Map()
{
    delete ui;
}

void Map::on_pushButton_clicked()
{

         ui->axWidget->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place//@36.9016729,10.1713215,3702m/data=!3m1!1e3");
        }

void Map::on_pushButton_2_clicked()
{

      ui->axWidget->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/Tunis+Clock+Tower/@36.8041141,10.1825236,1795m/data=!3m1!1e3");
}

void Map::on_pushButton_3_clicked()
{

    ui->axWidget->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/Tour+Eiffel/@48.8512115,2.2408212,24367m/data=!3m2!1e3");

}
