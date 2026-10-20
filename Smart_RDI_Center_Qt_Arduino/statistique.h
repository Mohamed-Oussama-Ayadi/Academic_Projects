#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
//chartview
#include <QChart>
#include <QtCharts/QChartView>
//lineseries
#include <QtCharts/QLineSeries>
#include<QSplineSeries>
//barchart
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include<QDateTimeAxis>
#include<QBarCategoryAxis>
//piechart
#include<QPieSeries>
#include<QPieSlice>
//others
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QDebug>
#include<QDateTime>
#include<QMap>
#include<QSqlQueryModel>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE


class statistique : public QMainWindow
{
public:
    statistique();
    QChart* barchart();
    QChart* piechart();
};

#endif // STATISTIQUE_H
