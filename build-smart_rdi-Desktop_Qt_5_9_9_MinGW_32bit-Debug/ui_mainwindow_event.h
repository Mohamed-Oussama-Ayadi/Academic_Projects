/********************************************************************************
** Form generated from reading UI file 'mainwindow_event.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_EVENT_H
#define UI_MAINWINDOW_EVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_event
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox;
    QGroupBox *ajouter;
    QLabel *Ajouter;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nom_label;
    QDateTimeEdit *dateTimeEdit_debut;
    QHBoxLayout *horizontalLayout_2;
    QLabel *nom_label_2;
    QDateTimeEdit *dateTimeEdit_fin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *organization_label;
    QComboBox *comboBox_lieu;
    QHBoxLayout *horizontalLayout_4;
    QLabel *budget_label;
    QComboBox *comboBox_theme;
    QHBoxLayout *horizontalLayout_5;
    QLabel *id_label;
    QComboBox *comboBox_organisateur;
    QHBoxLayout *horizontalLayout_6;
    QLabel *date_label;
    QSpinBox *spinBox_nb;
    QHBoxLayout *horizontalLayout_7;
    QLabel *id_label_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_id_sponsor;
    QPushButton *ajouter_pb;
    QPushButton *supprimer_pb;
    QPushButton *modifier_pb;
    QPushButton *annuler_pb;
    QPushButton *pushButton_2;
    QLabel *nom_gestion;
    QGroupBox *afficher;
    QLabel *afficher_label;
    QTableView *tableView;
    QPushButton *stat_pb;
    QPushButton *calendar_pb;
    QPushButton *video_pb;
    QPushButton *pdf_pb;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_rechercher;
    QPushButton *chercher;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_tri;
    QComboBox *comboBox_tri;
    QLabel *label;
    QPushButton *pushButton_20;
    QWidget *widget;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_17;
    QPushButton *pushButton_15;
    QPushButton *pushButton_18;
    QPushButton *pushButton_21;
    QPushButton *pushButton_19;

    void setupUi(QMainWindow *MainWindow_event)
    {
        if (MainWindow_event->objectName().isEmpty())
            MainWindow_event->setObjectName(QStringLiteral("MainWindow_event"));
        MainWindow_event->resize(1252, 872);
        MainWindow_event->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"    background-color: rgb(58, 195, 197);\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 176, 1);	\n"
"}\n"
"\n"
"QLineEdit:focus, QPushButton:focus {\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow_event);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        ajouter = new QGroupBox(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(90, 120, 461, 681));
        ajouter->setMaximumSize(QSize(500, 700));
        ajouter->setStyleSheet(QLatin1String("QGroupBox {\n"
"    font: 12px;\n"
" background-color:transparent;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QLabel {\n"
"    font-weight: bold;\n"
"    padding: 1px;\n"
"}\n"
"\n"
"QDateTimeEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QComboBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QSpinBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}"));
        Ajouter = new QLabel(ajouter);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(40, 10, 211, 31));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        Ajouter->setFont(font);
        Ajouter->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        layoutWidget_4 = new QWidget(ajouter);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 40, 361, 411));
        verticalLayout = new QVBoxLayout(layoutWidget_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nom_label = new QLabel(layoutWidget_4);
        nom_label->setObjectName(QStringLiteral("nom_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        nom_label->setFont(font1);

        horizontalLayout->addWidget(nom_label);

        dateTimeEdit_debut = new QDateTimeEdit(layoutWidget_4);
        dateTimeEdit_debut->setObjectName(QStringLiteral("dateTimeEdit_debut"));
        dateTimeEdit_debut->setMaximumSize(QSize(16777215, 35));

        horizontalLayout->addWidget(dateTimeEdit_debut);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        nom_label_2 = new QLabel(layoutWidget_4);
        nom_label_2->setObjectName(QStringLiteral("nom_label_2"));
        nom_label_2->setFont(font1);

        horizontalLayout_2->addWidget(nom_label_2);

        dateTimeEdit_fin = new QDateTimeEdit(layoutWidget_4);
        dateTimeEdit_fin->setObjectName(QStringLiteral("dateTimeEdit_fin"));
        dateTimeEdit_fin->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_2->addWidget(dateTimeEdit_fin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        organization_label = new QLabel(layoutWidget_4);
        organization_label->setObjectName(QStringLiteral("organization_label"));
        organization_label->setFont(font1);

        horizontalLayout_3->addWidget(organization_label);

        comboBox_lieu = new QComboBox(layoutWidget_4);
        comboBox_lieu->setObjectName(QStringLiteral("comboBox_lieu"));
        comboBox_lieu->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(comboBox_lieu);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        budget_label = new QLabel(layoutWidget_4);
        budget_label->setObjectName(QStringLiteral("budget_label"));
        budget_label->setFont(font1);

        horizontalLayout_4->addWidget(budget_label);

        comboBox_theme = new QComboBox(layoutWidget_4);
        comboBox_theme->setObjectName(QStringLiteral("comboBox_theme"));
        comboBox_theme->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_4->addWidget(comboBox_theme);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        id_label = new QLabel(layoutWidget_4);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setFont(font1);

        horizontalLayout_5->addWidget(id_label);

        comboBox_organisateur = new QComboBox(layoutWidget_4);
        comboBox_organisateur->setObjectName(QStringLiteral("comboBox_organisateur"));

        horizontalLayout_5->addWidget(comboBox_organisateur);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        date_label = new QLabel(layoutWidget_4);
        date_label->setObjectName(QStringLiteral("date_label"));
        date_label->setFont(font1);

        horizontalLayout_6->addWidget(date_label);

        spinBox_nb = new QSpinBox(layoutWidget_4);
        spinBox_nb->setObjectName(QStringLiteral("spinBox_nb"));
        spinBox_nb->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_6->addWidget(spinBox_nb);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        id_label_2 = new QLabel(layoutWidget_4);
        id_label_2->setObjectName(QStringLiteral("id_label_2"));
        id_label_2->setFont(font1);

        horizontalLayout_7->addWidget(id_label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        lineEdit_id_sponsor = new QLineEdit(layoutWidget_4);
        lineEdit_id_sponsor->setObjectName(QStringLiteral("lineEdit_id_sponsor"));
        lineEdit_id_sponsor->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_7->addWidget(lineEdit_id_sponsor);


        verticalLayout->addLayout(horizontalLayout_7);

        ajouter_pb = new QPushButton(ajouter);
        ajouter_pb->setObjectName(QStringLiteral("ajouter_pb"));
        ajouter_pb->setGeometry(QRect(10, 650, 99, 31));
        ajouter_pb->setMaximumSize(QSize(100, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icones/Icones/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter_pb->setIcon(icon);
        ajouter_pb->setIconSize(QSize(20, 20));
        supprimer_pb = new QPushButton(ajouter);
        supprimer_pb->setObjectName(QStringLiteral("supprimer_pb"));
        supprimer_pb->setGeometry(QRect(230, 650, 99, 31));
        supprimer_pb->setMaximumSize(QSize(101, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icones/Icones/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_pb->setIcon(icon1);
        supprimer_pb->setIconSize(QSize(20, 20));
        modifier_pb = new QPushButton(ajouter);
        modifier_pb->setObjectName(QStringLiteral("modifier_pb"));
        modifier_pb->setGeometry(QRect(120, 650, 99, 31));
        modifier_pb->setMaximumSize(QSize(100, 31));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icones/Icones/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifier_pb->setIcon(icon2);
        modifier_pb->setIconSize(QSize(20, 20));
        annuler_pb = new QPushButton(ajouter);
        annuler_pb->setObjectName(QStringLiteral("annuler_pb"));
        annuler_pb->setGeometry(QRect(340, 650, 99, 31));
        annuler_pb->setMaximumSize(QSize(100, 31));
        annuler_pb->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0)"));
        QIcon icon3;
        QString iconThemeName = QStringLiteral("s");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        annuler_pb->setIcon(icon3);
        annuler_pb->setIconSize(QSize(20, 20));
        pushButton_2 = new QPushButton(ajouter);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 520, 121, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icones/Icones/temp\303\251rature.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(30, 30));
        nom_gestion = new QLabel(groupBox);
        nom_gestion->setObjectName(QStringLiteral("nom_gestion"));
        nom_gestion->setGeometry(QRect(440, 10, 441, 61));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(28);
        font2.setBold(false);
        font2.setWeight(50);
        nom_gestion->setFont(font2);
        nom_gestion->setStyleSheet(QLatin1String("\n"
"QLabel {\n"
"   color:#ffb001;\n"
"}\n"
""));
        afficher = new QGroupBox(groupBox);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(560, 120, 631, 621));
        afficher->setStyleSheet(QLatin1String("QGroupBox {\n"
"    font: 12px;\n"
" background-color:transparent;\n"
"}\n"
"\n"
"\n"
"QLabel {\n"
"    font-weight: bold;\n"
"    padding: 1px;\n"
"}\n"
"\n"
"\n"
"QComboBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}"));
        afficher_label = new QLabel(afficher);
        afficher_label->setObjectName(QStringLiteral("afficher_label"));
        afficher_label->setGeometry(QRect(20, 10, 221, 31));
        afficher_label->setFont(font);
        afficher_label->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        tableView = new QTableView(afficher);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 160, 601, 281));
        stat_pb = new QPushButton(afficher);
        stat_pb->setObjectName(QStringLiteral("stat_pb"));
        stat_pb->setGeometry(QRect(340, 590, 93, 31));
        stat_pb->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"    background-color: rgb(58, 195, 197);\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus, QPushButton:focus {\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 176, 1);	\n"
"}\n"
"\n"
""));
        stat_pb->setIconSize(QSize(30, 40));
        calendar_pb = new QPushButton(afficher);
        calendar_pb->setObjectName(QStringLiteral("calendar_pb"));
        calendar_pb->setGeometry(QRect(120, 590, 93, 31));
        calendar_pb->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"    background-color: rgb(58, 195, 197);\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus, QPushButton:focus {\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 176, 1);	\n"
"}\n"
"\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icones/Icones/calendrier.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon5.addFile(QStringLiteral(":/Img/Icones/calendrier.png"), QSize(), QIcon::Normal, QIcon::On);
        calendar_pb->setIcon(icon5);
        calendar_pb->setIconSize(QSize(30, 40));
        calendar_pb->setCheckable(true);
        video_pb = new QPushButton(afficher);
        video_pb->setObjectName(QStringLiteral("video_pb"));
        video_pb->setGeometry(QRect(230, 590, 93, 31));
        video_pb->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"    background-color: rgb(58, 195, 197);\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLineEdit:focus, QPushButton:focus {\n"
"    border: 2px solid #4CAF50;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 176, 1);	\n"
"}\n"
"\n"
""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icones/Icones/video.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/Img/Icones/video.png"), QSize(), QIcon::Normal, QIcon::On);
        video_pb->setIcon(icon6);
        video_pb->setIconSize(QSize(30, 40));
        pdf_pb = new QPushButton(afficher);
        pdf_pb->setObjectName(QStringLiteral("pdf_pb"));
        pdf_pb->setGeometry(QRect(10, 590, 93, 31));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icones/Icones/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf_pb->setIcon(icon7);
        pdf_pb->setIconSize(QSize(30, 40));
        layoutWidget = new QWidget(afficher);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 611, 39));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        lineEdit_rechercher = new QLineEdit(layoutWidget);
        lineEdit_rechercher->setObjectName(QStringLiteral("lineEdit_rechercher"));
        lineEdit_rechercher->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_10->addWidget(lineEdit_rechercher);

        chercher = new QPushButton(layoutWidget);
        chercher->setObjectName(QStringLiteral("chercher"));
        chercher->setMaximumSize(QSize(101, 35));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Icones/Icones/rechercher.png"), QSize(), QIcon::Normal, QIcon::Off);
        chercher->setIcon(icon8);
        chercher->setIconSize(QSize(20, 20));

        horizontalLayout_10->addWidget(chercher);


        horizontalLayout_11->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_tri = new QPushButton(layoutWidget);
        pushButton_tri->setObjectName(QStringLiteral("pushButton_tri"));
        pushButton_tri->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_9->addWidget(pushButton_tri);

        comboBox_tri = new QComboBox(layoutWidget);
        comboBox_tri->setObjectName(QStringLiteral("comboBox_tri"));
        comboBox_tri->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_9->addWidget(comboBox_tri);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 1211, 801));
        label->setStyleSheet(QLatin1String("background-image: url(:/img/img/back.png);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/back.png")));
        label->setScaledContents(true);
        pushButton_20 = new QPushButton(groupBox);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 40, 61, 51));
        pushButton_20->setStyleSheet(QStringLiteral("background-color: rgb(97, 208, 255);"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/menu.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_20->setIcon(icon9);
        pushButton_20->setIconSize(QSize(40, 40));
        pushButton_20->setCheckable(true);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 100, 71, 701));
        widget->setStyleSheet(QStringLiteral("	background-color: rgb(178, 225, 229);"));
        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(0, 30, 71, 61));
        pushButton_13->setStyleSheet(QStringLiteral(""));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/home.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_13->setIcon(icon10);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(0, 120, 71, 61));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/calendrier.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_14->setIcon(icon11);
        pushButton_14->setIconSize(QSize(40, 40));
        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 430, 71, 71));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/notepad.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_17->setIcon(icon12);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(0, 210, 71, 61));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/img/notification.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_15->setIcon(icon13);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(0, 310, 71, 71));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/img/lecture.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_18->setIcon(icon14);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(widget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(0, 540, 71, 61));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/img/chat.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_21->setIcon(icon15);
        pushButton_21->setIconSize(QSize(40, 40));
        pushButton_19 = new QPushButton(widget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 640, 71, 61));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/img/togglapp.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_19->setIcon(icon16);
        pushButton_19->setIconSize(QSize(60, 60));
        label->raise();
        ajouter->raise();
        nom_gestion->raise();
        afficher->raise();
        pushButton_20->raise();
        widget->raise();

        horizontalLayout_8->addWidget(groupBox);

        MainWindow_event->setCentralWidget(centralwidget);

        retranslateUi(MainWindow_event);

        QMetaObject::connectSlotsByName(MainWindow_event);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_event)
    {
        MainWindow_event->setWindowTitle(QApplication::translate("MainWindow_event", "MainWindow_event", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow_event", "Gestion Evenements", Q_NULLPTR));
        ajouter->setTitle(QString());
        Ajouter->setText(QApplication::translate("MainWindow_event", "Formulaire", Q_NULLPTR));
        nom_label->setText(QApplication::translate("MainWindow_event", "Date d\303\251but", Q_NULLPTR));
        nom_label_2->setText(QApplication::translate("MainWindow_event", "Date fin", Q_NULLPTR));
        organization_label->setText(QApplication::translate("MainWindow_event", "Lieu", Q_NULLPTR));
        budget_label->setText(QApplication::translate("MainWindow_event", "Th\303\251me", Q_NULLPTR));
        id_label->setText(QApplication::translate("MainWindow_event", "Organisateur", Q_NULLPTR));
        date_label->setText(QApplication::translate("MainWindow_event", "Nombre d'invit\303\251s", Q_NULLPTR));
        id_label_2->setText(QApplication::translate("MainWindow_event", "Sponsor", Q_NULLPTR));
        ajouter_pb->setText(QApplication::translate("MainWindow_event", "Ajouter", Q_NULLPTR));
        supprimer_pb->setText(QApplication::translate("MainWindow_event", "Supprimer", Q_NULLPTR));
        modifier_pb->setText(QApplication::translate("MainWindow_event", "Modifier", Q_NULLPTR));
        annuler_pb->setText(QApplication::translate("MainWindow_event", "Annuler", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow_event", "Temperature", Q_NULLPTR));
        nom_gestion->setText(QApplication::translate("MainWindow_event", "Gestion Evenements", Q_NULLPTR));
        afficher->setTitle(QString());
        afficher_label->setText(QApplication::translate("MainWindow_event", "Liste Evenements", Q_NULLPTR));
        stat_pb->setText(QApplication::translate("MainWindow_event", "Statistiques", Q_NULLPTR));
        calendar_pb->setText(QApplication::translate("MainWindow_event", "Calendrier", Q_NULLPTR));
        video_pb->setText(QApplication::translate("MainWindow_event", "Vid\303\251o", Q_NULLPTR));
        pdf_pb->setText(QApplication::translate("MainWindow_event", "Pdf", Q_NULLPTR));
        chercher->setText(QApplication::translate("MainWindow_event", "Rechercher", Q_NULLPTR));
        pushButton_tri->setText(QApplication::translate("MainWindow_event", "Lancer tri", Q_NULLPTR));
        comboBox_tri->clear();
        comboBox_tri->insertItems(0, QStringList()
         << QApplication::translate("MainWindow_event", "trier", Q_NULLPTR)
         << QApplication::translate("MainWindow_event", "par date", Q_NULLPTR)
         << QApplication::translate("MainWindow_event", "par theme", Q_NULLPTR)
         << QApplication::translate("MainWindow_event", "par nombre d'invites", Q_NULLPTR)
         << QApplication::translate("MainWindow_event", "---------------------------------", Q_NULLPTR)
         << QApplication::translate("MainWindow_event", "ordre croissant", Q_NULLPTR)
         << QApplication::translate("MainWindow_event", "ordre decroissant", Q_NULLPTR)
        );
        label->setText(QString());
        pushButton_20->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_17->setText(QString());
        pushButton_15->setText(QString());
        pushButton_18->setText(QString());
        pushButton_21->setText(QString());
        pushButton_19->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow_event: public Ui_MainWindow_event {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_EVENT_H
