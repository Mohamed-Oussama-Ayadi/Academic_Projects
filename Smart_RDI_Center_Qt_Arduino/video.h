#ifndef VIDEO_H
#define VIDEO_H

#include <QDialog>
#include<QFileDialog>

#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QVBoxLayout>
#include<QDockWidget>
#include<QListWidget>
#include<QTimer>
#include<QTime>
#include<QAbstractVideoSurface>
#include<QGraphicsVideoItem>
#include<QGraphicsScene>
#include<QGraphicsView>
namespace Ui {
class Video;
}

class Video : public QDialog
{
    Q_OBJECT

public:
    explicit Video(QWidget *parent = nullptr);
    ~Video();

private slots:

    void set_time();

   QTimer* set_timer();

   void resizeEvent(QResizeEvent *event) override;


   void on_pushButton_clicked();

   void on_pushButton_3_clicked();

   void on_pushButton_2_clicked();

   void on_pushButton_5_clicked();

   void on_listWidget_itemClicked(QListWidgetItem *item);

   void on_pushButton_4_toggled(bool checked);

   void on_horizontalSlider_2_sliderMoved(int position);

private:
    Ui::Video *ui;
    QMediaPlayer *mplayer=new QMediaPlayer(this);
    QMediaPlaylist *playlist=new QMediaPlaylist(this);
    int index;
    QTimer *timer = new QTimer(this);
     QTime time;
    QString s;
    QGraphicsVideoItem *videoItem=new QGraphicsVideoItem;
    QGraphicsScene *scene=new QGraphicsScene;
    int start;
};

#endif // VIDEO_H
