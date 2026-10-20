#include "calendrier.h"


Calendrier::Calendrier()
{
    query.prepare("select date_debut,theme from events order by date_debut");

      query.exec();
          while(query.next())
          {
              v.push_back(query.value(0).toDateTime());
              v2.push_back(query.value(1).toString());


          }
}


void Calendrier::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{

    QRectF rr=rect;
QRect r1(rect.x()+50,rect.y(),rect.width()-40,rect.height());


QFont font1("Calibri",10);

QPen pen,pen1;
pen.setColor(QColor(200,154,80));
pen1.setColor(QColor(50,50,50));
painter->setPen(pen);
QDate d1,d2=QDate(0,0,0);
    for(int i=0;i<v.size();i++)
    {

     d1=v[i].date();
    if(date==v[i].date())
    {

painter->setPen(pen1);
painter->setFont(font1);




    if(d2!=d1)
    {
        painter->fillRect(rect,QColor(128,128,255,128));

    }
painter->drawText(r1,Qt::AlignLeft,v[i].time().toString().remove(5,3)+" "+v2[i],&rr);

    r1.setY(r1.y()+25);

        }
    d2=v[i].date();

    }
    painter->setPen(pen);
        painter->drawText(rect,Qt::AlignLeft,QString::number(date.day()));

    }



void Calendrier::connect_to_db(QDate date)
{
    QSqlQuery query;
    query.prepare("select date_debut,date_fin,theme,lieu from events where to_date(to_char(date_debut,'dd/mm/yyyy'),'dd/mm/yyyy')=to_date(to_char(:date,'dd/mm/yyyy'),'dd/mm/yyyy')");
    query.bindValue(":date",date);
    query.exec();
    QWidget *widget= new QWidget;



    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->resize(290,500);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        //scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        //scrollArea->setFixedSize(QSize(500,500));
        QVBoxLayout *vlayout=new QVBoxLayout;


    int set=0;
    while(query.next())
    {
       QLabel *label=new QLabel;
       label->setText("Evenement: \nHeure debut: "
                      +query.value(0).toTime().toString().remove(5,3)
                      +"\nHeure fin: "+query.value(1).toTime().toString().remove(5,3)
                      +"\nTheme: "+query.value(2).toString()
                      +"\nLieu: "+query.value(3).toString()
                      );
       label->setStyleSheet("background-color: rgb(58, 195, 197);");
       label->setFont(QFont("Calibri",18));
       //label->setFixedSize(QSize(500,500))

       vlayout->addWidget(label);
       vlayout->addStretch(1);
        set=1;

    }

if(set)
{
widget->setLayout(vlayout);
scrollArea->setWidget(widget);
scrollArea->show();
}

    widget->setWindowTitle("Events");

}
