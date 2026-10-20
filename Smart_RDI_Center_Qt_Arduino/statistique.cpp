#include "statistique.h"

statistique::statistique()
{

}

QChart* statistique::barchart()
{
    QBarSeries *series = new QBarSeries();

   QBarSet *set = new QBarSet("Dates");


    //QSplineSeries *series = new QSplineSeries;


    QSqlQuery query("select to_date(to_char(date_debut,'dd/mm/yyyy'),'dd/mm/yyyy'),sum(nb_invites) from events group by  to_date(to_char(date_debut,'dd/mm/yyyy'),'dd/mm/yyyy') order by to_date(to_char(date_debut,'dd/mm/yyyy'),'dd/mm/yyyy')");
QStringList categories;
    while(query.next())
    {
         categories.append(query.value(0).toDate().toString("dd/MM/yyyy"));
        *set<<query.value(1).toInt();


    }
    series->append(set);


    QChart *chart = new QChart();
    chart->addSeries(series);

    chart->setTitle("Nombre d'invites");
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->axisX()->setLabelsAngle(90);
chart->axisX()->setTitleText("Dates");
chart->axisY()->setTitleText("Nb_invites");
chart->legend()->setVisible(false);
    chart->setAcceptHoverEvents(true);

    return chart;


}


QChart* statistique::piechart()
{

    QChart *chart = new QChart();
    QPieSeries *series = new QPieSeries(chart);
    QPieSlice *slice;
    chart->setTitle("Theme des evenements");
    QSqlQuery query("select theme,sum(nb_invites)*100/(select sum(nb_invites) from events) from events group by theme order by sum(nb_invites) desc");

    int n=0;
    while(query.next())
{
    n++;
    slice=series->append(query.value(0).toString(),query.value(1).toReal());
    slice->setLabelVisible();

}


   qreal pieSize = 1.0 /n;

    series->setHorizontalPosition(0.5);
            series->setPieSize(pieSize);
    series->setVerticalPosition(0.7);
    chart->addSeries(series);


    return chart;
}
