#include "video.h"
#include "ui_video.h"

Video::Video(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Video)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::MaximizeUsingFullscreenGeometryHint);
    connect(ui->horizontalSlider, &QAbstractSlider::sliderMoved,[&] (qint64 pos)  {mplayer->setPosition(pos);});
    connect(ui->horizontalSlider_2, &QAbstractSlider::sliderMoved,[&] (qint64 pos)  {mplayer->setVolume(pos);});


    connect(mplayer, &QMediaPlayer::positionChanged,  [&] (qint64 pos) {ui->horizontalSlider->setValue(pos);});
    connect(mplayer, &QMediaPlayer::durationChanged,[&] (qint64 duration) {ui->horizontalSlider->setRange(0,duration);});
    connect(mplayer, &QMediaPlayer::durationChanged,this,&Video::set_time);
    connect(mplayer, &QMediaPlayer::stateChanged,this,&Video::set_time);

    connect(ui->pushButton,&QAbstractButton::clicked,this, &Video::set_timer);
    connect(timer, SIGNAL(timeout()), this, SLOT(set_time()));
    videoItem->setSize(QSizeF(866,546));


    QRectF rect=scene->itemsBoundingRect();
    scene->setSceneRect(rect);
    ui->graphicsView->setScene(scene);
    scene->addItem(videoItem);


    mplayer->setVideoOutput(videoItem);
    ui->horizontalSlider->setRange(0,0);
    ui->horizontalSlider_2->setRange(0,100);
    ui->horizontalSlider->setValue(mplayer->position());
    ui->horizontalSlider_2->setValue(100);
    mplayer->setVolume(100);
index=0;
ui->label->setScaledContents(true);

ui->pushButton_5->setIcon(style()->standardIcon(QStyle::SP_DirIcon));
ui->pushButton_5->setIconSize(QSize(25,25));

start=1;
}

Video::~Video()
{
    delete ui;
}


void Video::on_pushButton_clicked()
{
    mplayer->play();
    timer->start();
}

void Video::on_pushButton_3_clicked()
{
    mplayer->pause();
    timer->stop();
}

void Video::on_pushButton_2_clicked()
{
    mplayer->stop();
    timer->stop();
    mplayer->pause();
}


void Video::on_pushButton_5_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "C:/Users/gasso/OneDrive/Bureau", tr("Image Files (*.mp3 *.mp4 *.asf)"));
    if(!fileName.isEmpty())
        playlist->addMedia(QUrl::fromLocalFile(fileName));
    playlist->setCurrentIndex(index);
    mplayer->setPlaylist(playlist);
mplayer->setMedia(playlist->media(index));
  //  QString file = playlist->media(index).canonicalUrl().fileName();
    ui->listWidget->addItem(fileName);
    index++;
}

void Video::on_listWidget_itemClicked(QListWidgetItem *item)
{
    mplayer->setMedia(QUrl::fromLocalFile(item->text()));
}

void Video::on_pushButton_4_toggled(bool checked)
{
    if(checked)
    {

        mplayer->setMuted(true);
        ui->horizontalSlider_2->setValue(0);
         ui->pushButton_4->setIcon(QIcon(":/Icones/Icones/sound-off.png"));
         ui->pushButton_4->setIconSize(QSize(25,25));
    }
    else
    {
        ui->horizontalSlider_2->setValue(100);
        mplayer->setMuted(false);
      ui->pushButton_4->setIcon(QIcon(":/Icones/Icones/son.png"));
      ui->pushButton_4->setIconSize(QSize(25,25));


    }
}

void Video::on_horizontalSlider_2_sliderMoved(int position)
{
    mplayer->setVolume(position);
    if(position==0)
    {
        ui->pushButton_4->setIcon(QIcon(":/Icones/Icones/sound-off.png"));
    }
    else
        ui->pushButton_4->setIcon(QIcon(":/Icones/Icones/son.png"));
}



void Video::set_time()
{
    int hour, min , sec , msec, d;


           if((QMediaPlayer::MediaStatus::LoadingMedia) | (QMediaPlayer::StoppedState))
            {
                d=mplayer->duration();
                hour=d/3600000;
                min=(d%3600000)/60000;
                sec=((d%3600000)%60000)/1000;
                msec=((d%3600000)%60000)%1000;
                QString stime=QString::number(hour)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(msec);
                time=time.fromString(stime,"h:m:s.z");
                s=time.toString("hh:mm:ss");

            }
            if(QMediaPlayer::MediaStatus::BufferedMedia)
           {
            d=mplayer->duration()-mplayer->position();
            //qDebug()<<"pos"<<d;
            hour=d/3600000;
            min=(d%3600000)/60000;
            sec=((d%3600000)%60000)/1000;
            msec=((d%3600000)%60000)%1000;
            QString stime2=QString::number(hour)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(msec);
            time=time.fromString(stime2,"h:m:s.z");
            }


    if(time.hour()==0 && time.minute()==0 && time.second()==0)
        timer->stop();

    QString text = time.toString("hh:mm:ss")+" / "+s;
    text[2] = ':';
    text[5] = ':';
    ui->label->setText(text);
    time=time.addSecs(-1);


}


QTimer* Video::set_timer()
{

timer->start(1000);
return timer;
}


void Video::resizeEvent(QResizeEvent*event)
{
if(start==0)
{QRectF rect=scene->itemsBoundingRect();
scene->setSceneRect(rect);
    ui->graphicsView->fitInView(rect,Qt::AspectRatioMode::KeepAspectRatio);

    QWidget::resizeEvent(event);
}
    start=0;

}
