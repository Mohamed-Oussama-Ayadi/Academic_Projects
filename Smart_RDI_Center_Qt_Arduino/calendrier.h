#ifndef CALENDRIER_H
#define CALENDRIER_H


#include <QDialog>
#include <QMainWindow>
#include<QTableView>
#include <QDebug>
#include<QStandardItemModel>
#include <QItemDelegate>
#include<QPainter>
#include<QCalendarWidget>
#include<QAbstractItemView>
#include<QLayout>
#include<QPushButton>
#include<QLabel>
#include<QHBoxLayout>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include<QVector>
#include<QTextCharFormat>
#include<QLineEdit>
#include<QTimeEdit>
#include<QLabel>
#include<QAbstractItemView>
#include<QSpinBox>
#include<QScrollArea>
#include<QStackedWidget>
#include<QCheckBox>
#include<QObject>
#include<QWidget>
class Calendrier:public QCalendarWidget
{
public:
    Calendrier();
    //~Calendrier();
       void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const ;
           void connect_to_db(QDate date);


private:
    //Ui::Calendrier *ui;
    QSqlQuery query;
    QVector<QDateTime> v;
    QVector<QString> v2;

};

#endif // CALENDRIER_H
