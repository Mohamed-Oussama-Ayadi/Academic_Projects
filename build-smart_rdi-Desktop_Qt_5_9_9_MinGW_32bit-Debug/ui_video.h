/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Video
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QLabel *label;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *graphicsView;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QSlider *horizontalSlider_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_6;

    void setupUi(QDialog *Video)
    {
        if (Video->objectName().isEmpty())
            Video->setObjectName(QStringLiteral("Video"));
        Video->resize(1192, 743);
        Video->setStyleSheet(QLatin1String("#Video\n"
"{\n"
"	background-color: rgb(58, 195, 197);\n"
"}"));
        gridLayout = new QGridLayout(Video);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSlider = new QSlider(Video);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #999999;\n"
"height: 12px;\n"
"	background-color: rgb(230, 230, 230);\n"
"border-radius: 9px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"width: 15px;\n"
"\n"
"	background-color: rgb(255, 176, 1);\n"
"}\n"
""));
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label = new QLabel(Video);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        graphicsView = new QGraphicsView(Video);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral(""));
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        graphicsView->setRubberBandSelectionMode(Qt::ContainsItemBoundingRect);

        horizontalLayout_4->addWidget(graphicsView);

        dockWidget = new QDockWidget(Video);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(218, 546));
        dockWidget->setMaximumSize(QSize(300, 524287));
        dockWidget->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(dockWidgetContents);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(190, 400));
        listWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(listWidget);

        dockWidget->setWidget(dockWidgetContents);

        horizontalLayout_4->addWidget(dockWidget);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        horizontalSpacer_9 = new QSpacerItem(200, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        horizontalSpacer_3 = new QSpacerItem(1400, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(Video);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icones/Icones/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(Video);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icones/Icones/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(Video);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icones/Icones/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_10 = new QSpacerItem(1000, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(Video);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icones/Icones/son.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(25, 25));
        pushButton_4->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_4);

        horizontalSlider_2 = new QSlider(Video);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimumSize(QSize(100, 0));
        horizontalSlider_2->setMaximumSize(QSize(100, 16777215));
        horizontalSlider_2->setStyleSheet(QLatin1String("\n"
"\n"
"QSlider::handle:horizontal {\n"
"width: 15px;\n"
"\n"
"	background-color: rgb(255, 176, 1);\n"
"}\n"
""));
        horizontalSlider_2->setPageStep(1);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::NoTicks);

        horizontalLayout_2->addWidget(horizontalSlider_2);

        horizontalSpacer_4 = new QSpacerItem(1100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        pushButton_5 = new QPushButton(Video);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(pushButton_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_6 = new QPushButton(Video);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setStyleSheet(QStringLiteral(""));
        pushButton_6->setCheckable(true);

        horizontalLayout_3->addWidget(pushButton_6);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(Video);
        QObject::connect(pushButton_6, SIGNAL(toggled(bool)), dockWidget, SLOT(setVisible(bool)));
        QObject::connect(pushButton_6, SIGNAL(toggled(bool)), dockWidget, SLOT(setHidden(bool)));

        QMetaObject::connectSlotsByName(Video);
    } // setupUi

    void retranslateUi(QDialog *Video)
    {
        Video->setWindowTitle(QApplication::translate("Video", "Dialog", Q_NULLPTR));
        label->setText(QString());
        dockWidget->setWindowTitle(QApplication::translate("Video", "playlist", Q_NULLPTR));
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QApplication::translate("Video", "playlist", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Video: public Ui_Video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
