/********************************************************************************
** Form generated from reading UI file 'MainWindow_l.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_L_H
#define UI_MAINWINDOW_L_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_l
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *nom_gestion;
    QGroupBox *afficher;
    QLabel *afficher_label;
    QTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_pausa_2;
    QPushButton *btn_iniciar_2;
    QPushButton *btn_stop_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLCDNumber *minutos_2;
    QLCDNumber *segundos_2;
    QWidget *cam;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_rechercher_2;
    QPushButton *supprimer_4;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_4;
    QPushButton *tri;
    QComboBox *comboBo_tri;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_rechercher_4;
    QLineEdit *lineEdit_rechercher_11;
    QLineEdit *lineEdit_rechercher_10;
    QLineEdit *lineEdit_rechercher_9;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_rechercher_5;
    QLineEdit *lineEdit_rechercher_6;
    QLineEdit *lineEdit_rechercher_7;
    QLineEdit *lineEdit_rechercher_8;
    QPushButton *tri_2;
    QPushButton *tri_3;
    QPushButton *tri_4;
    QPushButton *tri_5;
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
    QGroupBox *groupBox_2;
    QLabel *Ajouter;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout;
    QLabel *id_label;
    QLineEdit *lineEdit_id;
    QLabel *organization_label;
    QComboBox *comboBox;
    QLabel *statut_label;
    QLineEdit *lineEdit_rules;
    QLabel *date_label;
    QDateTimeEdit *dateTimeEdit_2;
    QLabel *date_label_2;
    QDateTimeEdit *dateTimeEdit_3;
    QLabel *date_label_3;
    QLineEdit *lineEdit_rechercher;
    QLabel *date_label_4;
    QLineEdit *lineEdit_rechercher_3;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_2;
    QPushButton *ajouter_4;
    QPushButton *supprimer_3;
    QPushButton *supprimer_2;
    QPushButton *pushButton_7;
    QPushButton *pdf;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QPlainTextEdit *plainTextEdit;
    QLCDNumber *lcdNumber;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_l)
    {
        if (MainWindow_l->objectName().isEmpty())
            MainWindow_l->setObjectName(QStringLiteral("MainWindow_l"));
        MainWindow_l->resize(1252, 872);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(9);
        MainWindow_l->setFont(font);
        MainWindow_l->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow_l);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 1211, 831));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"    font: 12px;\n"
" background-color:transparent;\n"
"}\n"
"QComboBox {\n"
"    border: 2px solid gray;\n"
"     border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"QLineEdit {\n"
"    border: 2px solid gray;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
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
"QLabel {\n"
"    font-weight: bold;\n"
"    padding: 1px;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(255, 176, 1);	\n"
"}\n"
"\n"
"\n"
""));
        nom_gestion = new QLabel(groupBox);
        nom_gestion->setObjectName(QStringLiteral("nom_gestion"));
        nom_gestion->setGeometry(QRect(440, 10, 351, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Cambria"));
        font1.setPointSize(28);
        font1.setBold(true);
        font1.setWeight(75);
        nom_gestion->setFont(font1);
        nom_gestion->setStyleSheet(QLatin1String("\n"
"QLabel {\n"
"   color:#ffb001;\n"
"}\n"
""));
        afficher = new QGroupBox(groupBox);
        afficher->setObjectName(QStringLiteral("afficher"));
        afficher->setGeometry(QRect(560, 70, 621, 751));
        afficher->setStyleSheet(QStringLiteral(""));
        afficher_label = new QLabel(afficher);
        afficher_label->setObjectName(QStringLiteral("afficher_label"));
        afficher_label->setGeometry(QRect(190, 10, 281, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        afficher_label->setFont(font2);
        afficher_label->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        tableView = new QTableView(afficher);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 150, 271, 241));
        layoutWidget = new QWidget(afficher);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 410, 271, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_pausa_2 = new QPushButton(layoutWidget);
        btn_pausa_2->setObjectName(QStringLiteral("btn_pausa_2"));

        horizontalLayout_3->addWidget(btn_pausa_2);

        btn_iniciar_2 = new QPushButton(layoutWidget);
        btn_iniciar_2->setObjectName(QStringLiteral("btn_iniciar_2"));

        horizontalLayout_3->addWidget(btn_iniciar_2);

        btn_stop_2 = new QPushButton(layoutWidget);
        btn_stop_2->setObjectName(QStringLiteral("btn_stop_2"));

        horizontalLayout_3->addWidget(btn_stop_2);

        layoutWidget_2 = new QWidget(afficher);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 450, 271, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        minutos_2 = new QLCDNumber(layoutWidget_2);
        minutos_2->setObjectName(QStringLiteral("minutos_2"));
        minutos_2->setDigitCount(2);

        horizontalLayout_4->addWidget(minutos_2);

        segundos_2 = new QLCDNumber(layoutWidget_2);
        segundos_2->setObjectName(QStringLiteral("segundos_2"));
        segundos_2->setDigitCount(2);

        horizontalLayout_4->addWidget(segundos_2);

        cam = new QWidget(afficher);
        cam->setObjectName(QStringLiteral("cam"));
        cam->setGeometry(QRect(39, 510, 541, 221));
        layoutWidget1 = new QWidget(afficher);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 80, 231, 61));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_rechercher_2 = new QLineEdit(layoutWidget1);
        lineEdit_rechercher_2->setObjectName(QStringLiteral("lineEdit_rechercher_2"));

        gridLayout_3->addWidget(lineEdit_rechercher_2, 0, 0, 1, 1);

        supprimer_4 = new QPushButton(layoutWidget1);
        supprimer_4->setObjectName(QStringLiteral("supprimer_4"));
        supprimer_4->setMaximumSize(QSize(101, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icones/Icones/rechercher.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_4->setIcon(icon);
        supprimer_4->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(supprimer_4, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(afficher);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(380, 80, 231, 61));
        gridLayout_4 = new QGridLayout(layoutWidget2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        tri = new QPushButton(layoutWidget2);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setMaximumSize(QSize(93, 28));

        gridLayout_4->addWidget(tri, 0, 0, 1, 1);

        comboBo_tri = new QComboBox(layoutWidget2);
        comboBo_tri->setObjectName(QStringLiteral("comboBo_tri"));

        gridLayout_4->addWidget(comboBo_tri, 0, 1, 1, 1);

        layoutWidget3 = new QWidget(afficher);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(340, 150, 238, 190));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_rechercher_4 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_4->setObjectName(QStringLiteral("lineEdit_rechercher_4"));

        verticalLayout->addWidget(lineEdit_rechercher_4);

        lineEdit_rechercher_11 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_11->setObjectName(QStringLiteral("lineEdit_rechercher_11"));

        verticalLayout->addWidget(lineEdit_rechercher_11);

        lineEdit_rechercher_10 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_10->setObjectName(QStringLiteral("lineEdit_rechercher_10"));

        verticalLayout->addWidget(lineEdit_rechercher_10);

        lineEdit_rechercher_9 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_9->setObjectName(QStringLiteral("lineEdit_rechercher_9"));

        verticalLayout->addWidget(lineEdit_rechercher_9);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_rechercher_5 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_5->setObjectName(QStringLiteral("lineEdit_rechercher_5"));

        verticalLayout_2->addWidget(lineEdit_rechercher_5);

        lineEdit_rechercher_6 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_6->setObjectName(QStringLiteral("lineEdit_rechercher_6"));

        verticalLayout_2->addWidget(lineEdit_rechercher_6);

        lineEdit_rechercher_7 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_7->setObjectName(QStringLiteral("lineEdit_rechercher_7"));

        verticalLayout_2->addWidget(lineEdit_rechercher_7);

        lineEdit_rechercher_8 = new QLineEdit(layoutWidget3);
        lineEdit_rechercher_8->setObjectName(QStringLiteral("lineEdit_rechercher_8"));

        verticalLayout_2->addWidget(lineEdit_rechercher_8);


        horizontalLayout->addLayout(verticalLayout_2);

        tri_2 = new QPushButton(afficher);
        tri_2->setObjectName(QStringLiteral("tri_2"));
        tri_2->setGeometry(QRect(350, 420, 93, 28));
        tri_2->setMaximumSize(QSize(93, 28));
        tri_3 = new QPushButton(afficher);
        tri_3->setObjectName(QStringLiteral("tri_3"));
        tri_3->setGeometry(QRect(480, 420, 93, 28));
        tri_3->setMaximumSize(QSize(93, 28));
        tri_4 = new QPushButton(afficher);
        tri_4->setObjectName(QStringLiteral("tri_4"));
        tri_4->setGeometry(QRect(350, 460, 93, 28));
        tri_4->setMaximumSize(QSize(93, 28));
        tri_5 = new QPushButton(afficher);
        tri_5->setObjectName(QStringLiteral("tri_5"));
        tri_5->setGeometry(QRect(480, 460, 93, 28));
        tri_5->setMaximumSize(QSize(93, 28));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 1211, 801));
        label->setStyleSheet(QLatin1String("background-image: url(:/Icones/Icones/background.png);\n"
""));
        pushButton_20 = new QPushButton(groupBox);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 50, 61, 51));
        pushButton_20->setStyleSheet(QStringLiteral("background-color: rgb(97, 208, 255);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/menu.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_20->setIcon(icon1);
        pushButton_20->setIconSize(QSize(40, 40));
        pushButton_20->setCheckable(true);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 110, 71, 701));
        widget->setStyleSheet(QStringLiteral("	background-color: rgb(178, 225, 229);"));
        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(0, 30, 71, 61));
        pushButton_13->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/home.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_13->setIcon(icon2);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(0, 120, 71, 61));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/calendrier.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_14->setIcon(icon3);
        pushButton_14->setIconSize(QSize(40, 40));
        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 430, 71, 71));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/notepad.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_17->setIcon(icon4);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(0, 210, 71, 61));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/notification.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_15->setIcon(icon5);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(0, 310, 71, 71));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/lecture.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_18->setIcon(icon6);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(widget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(0, 540, 71, 61));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/chat.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_21->setIcon(icon7);
        pushButton_21->setIconSize(QSize(40, 40));
        pushButton_19 = new QPushButton(widget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 640, 71, 61));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/togglapp.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_19->setIcon(icon8);
        pushButton_19->setIconSize(QSize(60, 60));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(90, 70, 461, 741));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        Ajouter = new QLabel(groupBox_2);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(60, 20, 211, 41));
        Ajouter->setFont(font2);
        Ajouter->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 80, 451, 411));
        gridLayout = new QGridLayout(layoutWidget4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        id_label = new QLabel(layoutWidget4);
        id_label->setObjectName(QStringLiteral("id_label"));
        QFont font3;
        font3.setFamily(QStringLiteral("Cambria"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        id_label->setFont(font3);

        gridLayout->addWidget(id_label, 0, 0, 1, 1);

        lineEdit_id = new QLineEdit(layoutWidget4);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));

        gridLayout->addWidget(lineEdit_id, 0, 1, 1, 2);

        organization_label = new QLabel(layoutWidget4);
        organization_label->setObjectName(QStringLiteral("organization_label"));
        organization_label->setFont(font3);

        gridLayout->addWidget(organization_label, 1, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget4);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 2);

        statut_label = new QLabel(layoutWidget4);
        statut_label->setObjectName(QStringLiteral("statut_label"));
        statut_label->setFont(font3);

        gridLayout->addWidget(statut_label, 2, 0, 1, 2);

        lineEdit_rules = new QLineEdit(layoutWidget4);
        lineEdit_rules->setObjectName(QStringLiteral("lineEdit_rules"));

        gridLayout->addWidget(lineEdit_rules, 2, 2, 1, 1);

        date_label = new QLabel(layoutWidget4);
        date_label->setObjectName(QStringLiteral("date_label"));
        date_label->setFont(font3);

        gridLayout->addWidget(date_label, 3, 0, 1, 1);

        dateTimeEdit_2 = new QDateTimeEdit(layoutWidget4);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        QFont font4;
        font4.setPointSize(10);
        dateTimeEdit_2->setFont(font4);

        gridLayout->addWidget(dateTimeEdit_2, 3, 2, 1, 1);

        date_label_2 = new QLabel(layoutWidget4);
        date_label_2->setObjectName(QStringLiteral("date_label_2"));
        date_label_2->setFont(font3);

        gridLayout->addWidget(date_label_2, 4, 0, 1, 1);

        dateTimeEdit_3 = new QDateTimeEdit(layoutWidget4);
        dateTimeEdit_3->setObjectName(QStringLiteral("dateTimeEdit_3"));
        dateTimeEdit_3->setFont(font4);

        gridLayout->addWidget(dateTimeEdit_3, 4, 2, 1, 1);

        date_label_3 = new QLabel(layoutWidget4);
        date_label_3->setObjectName(QStringLiteral("date_label_3"));
        date_label_3->setFont(font3);

        gridLayout->addWidget(date_label_3, 5, 0, 1, 1);

        lineEdit_rechercher = new QLineEdit(layoutWidget4);
        lineEdit_rechercher->setObjectName(QStringLiteral("lineEdit_rechercher"));

        gridLayout->addWidget(lineEdit_rechercher, 5, 1, 1, 2);

        date_label_4 = new QLabel(layoutWidget4);
        date_label_4->setObjectName(QStringLiteral("date_label_4"));
        date_label_4->setFont(font3);

        gridLayout->addWidget(date_label_4, 6, 0, 1, 1);

        lineEdit_rechercher_3 = new QLineEdit(layoutWidget4);
        lineEdit_rechercher_3->setObjectName(QStringLiteral("lineEdit_rechercher_3"));

        gridLayout->addWidget(lineEdit_rechercher_3, 6, 1, 1, 2);

        layoutWidget5 = new QWidget(groupBox_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 500, 411, 88));
        gridLayout_2 = new QGridLayout(layoutWidget5);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ajouter_4 = new QPushButton(layoutWidget5);
        ajouter_4->setObjectName(QStringLiteral("ajouter_4"));
        ajouter_4->setMaximumSize(QSize(101, 31));
        ajouter_4->setFont(font);
        ajouter_4->setStyleSheet(QStringLiteral(""));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Icones/Icones/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter_4->setIcon(icon9);
        ajouter_4->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(ajouter_4, 0, 0, 1, 1);

        supprimer_3 = new QPushButton(layoutWidget5);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setMaximumSize(QSize(101, 31));
        supprimer_3->setFont(font);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Icones/Icones/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_3->setIcon(icon10);
        supprimer_3->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(supprimer_3, 0, 1, 1, 1);

        supprimer_2 = new QPushButton(layoutWidget5);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setMaximumSize(QSize(101, 31));
        supprimer_2->setFont(font);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Icones/Icones/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_2->setIcon(icon11);
        supprimer_2->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(supprimer_2, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget5);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(121, 28));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0)"));

        gridLayout_2->addWidget(pushButton_7, 0, 3, 1, 1);

        pdf = new QPushButton(layoutWidget5);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setFont(font);
        pdf->setStyleSheet(QStringLiteral(""));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Icones/Icones/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon12);
        pdf->setIconSize(QSize(30, 40));

        gridLayout_2->addWidget(pdf, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(121, 28));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(pushButton_8, 1, 1, 1, 1);

        pushButton_10 = new QPushButton(layoutWidget5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMaximumSize(QSize(121, 28));
        pushButton_10->setFont(font);
        pushButton_10->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(pushButton_10, 1, 2, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMaximumSize(QSize(121, 28));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QStringLiteral(""));

        gridLayout_2->addWidget(pushButton_9, 1, 3, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 580, 421, 151));
        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(770, 30, 441, 31));
        lcdNumber->setStyleSheet(QLatin1String("QLCDNumber\n"
"{\n"
"	background-color:black;\n"
"	color:red;\n"
"}"));
        lcdNumber->setDigitCount(20);
        label->raise();
        afficher->raise();
        nom_gestion->raise();
        pushButton_20->raise();
        widget->raise();
        groupBox_2->raise();
        lcdNumber->raise();
        MainWindow_l->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_l);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1252, 26));
        MainWindow_l->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_l);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_l->setStatusBar(statusbar);

        retranslateUi(MainWindow_l);

        QMetaObject::connectSlotsByName(MainWindow_l);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_l)
    {
        MainWindow_l->setWindowTitle(QApplication::translate("MainWindow_l", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow_l", "Gestion Sponsors", Q_NULLPTR));
        nom_gestion->setText(QApplication::translate("MainWindow_l", "Gestion Labo", Q_NULLPTR));
        afficher->setTitle(QString());
        afficher_label->setText(QApplication::translate("MainWindow_l", "Liste Labo", Q_NULLPTR));
        btn_pausa_2->setText(QApplication::translate("MainWindow_l", "pausar", Q_NULLPTR));
        btn_iniciar_2->setText(QApplication::translate("MainWindow_l", "iniciar", Q_NULLPTR));
        btn_stop_2->setText(QApplication::translate("MainWindow_l", "stop", Q_NULLPTR));
        supprimer_4->setText(QApplication::translate("MainWindow_l", "Rechercher", Q_NULLPTR));
        tri->setText(QApplication::translate("MainWindow_l", "Lancer Tri", Q_NULLPTR));
        comboBo_tri->clear();
        comboBo_tri->insertItems(0, QStringList()
         << QApplication::translate("MainWindow_l", "id_labo-acd", Q_NULLPTR)
         << QApplication::translate("MainWindow_l", "id_labo-des", Q_NULLPTR)
         << QApplication::translate("MainWindow_l", "id_projet_acd", Q_NULLPTR)
         << QApplication::translate("MainWindow_l", "id_projet_desc", Q_NULLPTR)
         << QApplication::translate("MainWindow_l", "date_debut_acd", Q_NULLPTR)
         << QApplication::translate("MainWindow_l", "date_debut_dec", Q_NULLPTR)
        );
        tri_2->setText(QApplication::translate("MainWindow_l", "ON", Q_NULLPTR));
        tri_3->setText(QApplication::translate("MainWindow_l", "OFF", Q_NULLPTR));
        tri_4->setText(QApplication::translate("MainWindow_l", "GREENLED", Q_NULLPTR));
        tri_5->setText(QApplication::translate("MainWindow_l", "REDLED", Q_NULLPTR));
        label->setText(QString());
        pushButton_20->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_17->setText(QString());
        pushButton_15->setText(QString());
        pushButton_18->setText(QString());
        pushButton_21->setText(QString());
        pushButton_19->setText(QString());
        groupBox_2->setTitle(QString());
        Ajouter->setText(QApplication::translate("MainWindow_l", "Labo", Q_NULLPTR));
        id_label->setText(QApplication::translate("MainWindow_l", "labo", Q_NULLPTR));
        organization_label->setText(QApplication::translate("MainWindow_l", "projet", Q_NULLPTR));
        statut_label->setText(QApplication::translate("MainWindow_l", "Rules(accepter/refuser)", Q_NULLPTR));
        date_label->setText(QApplication::translate("MainWindow_l", "Date debut", Q_NULLPTR));
        date_label_2->setText(QApplication::translate("MainWindow_l", "Date fin", Q_NULLPTR));
        date_label_3->setText(QApplication::translate("MainWindow_l", "ID a supprimer", Q_NULLPTR));
        date_label_4->setText(QApplication::translate("MainWindow_l", "ID a modifier", Q_NULLPTR));
        ajouter_4->setText(QApplication::translate("MainWindow_l", "Ajouter", Q_NULLPTR));
        supprimer_3->setText(QApplication::translate("MainWindow_l", "Modifier", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("MainWindow_l", "Supprimer", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow_l", "Afficher", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow_l", "PDF", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow_l", "Statistiques", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow_l", "camera", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow_l", "map", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow_l", "RULES\n"
"\n"
"Les r\303\250gles de navigation et d'interface: Celles-ci incluent comment naviguer dans l'application, comment acc\303\251der aux diff\303\251rentes fonctionnalit\303\251s et comment utiliser l'interface utilisateur.\n"
"Les r\303\250gles d'entr\303\251e: Celles-ci incluent des lignes directrices sur la mani\303\250re de saisir des donn\303\251es dans l'application, telles que les types de caract\303\250res autoris\303\251s, la quantit\303\251 de texte pouvant \303\252tre saisie et le format dans lequel les donn\303\251es doivent \303\252tre saisies.\n"
"Les r\303\250gles de sortie: Celles-ci incluent des directives sur la mani\303\250re dont l'application pr\303\251sente des informations \303\240 l'utilisateur, telles que la fa\303\247on dont les donn\303\251es sont affich\303\251es, les types de graphiques ou de diagrammes utilis\303\251s et la fa\303\247on dont les rapports sont g\303\251n\303\251r\303\251s.\n"
"Les r\303\250gles de s\303\251curit\303\251: Celles-ci incluent des directives s"
                        "ur la mani\303\250re dont l'application g\303\250re l'authentification des utilisateurs, le contr\303\264le d'acc\303\250s et le chiffrement des donn\303\251es.\n"
"Les r\303\250gles de performance: Celles-ci incluent des directives sur la mani\303\250re dont l'application g\303\250re les ressources syst\303\250me telles que la m\303\251moire, le processeur et l'espace disque, afin de garantir qu'elle fonctionne de mani\303\250re fluide et efficace.\n"
"Les r\303\250gles de gestion des erreurs: Celles-ci incluent des directives sur la mani\303\250re dont l'application doit g\303\251rer les erreurs, telles que l'affichage des messages d'erreur, la journalisation des erreurs et la r\303\251cup\303\251ration des erreurs.\n"
"Les r\303\250gles d'accessibilit\303\251: Celles-ci incluent des directives sur la mani\303\250re dont l'application doit \303\252tre con\303\247ue pour \303\252tre accessible aux utilisateurs handicap\303\251s, telles que la fourniture de texte alternatif pour les images, les raccourcis clav"
                        "ier et les lecteurs d'\303\251cran.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_l: public Ui_MainWindow_l {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_L_H
