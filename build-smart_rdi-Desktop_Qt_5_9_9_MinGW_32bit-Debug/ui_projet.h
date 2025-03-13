/********************************************************************************
** Form generated from reading UI file 'projet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJET_H
#define UI_PROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_p
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *nom_gestion;
    QGroupBox *afficher;
    QLabel *afficher_label;
    QLineEdit *lineEdit_rechercher;
    QPushButton *rechercher;
    QPushButton *chat;
    QPushButton *tri;
    QPushButton *pdf;
    QPushButton *stat;
    QComboBox *comboBoxTrie;
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_20;
    QWidget *widget;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *notepad;
    QPushButton *pushButton_15;
    QPushButton *pushButton_18;
    QPushButton *pushButton_21;
    QPushButton *pushButton_19;
    QGroupBox *groupBox_2;
    QLabel *Ajouter;
    QLabel *id_label;
    QLineEdit *lineEdit_id;
    QLabel *nom_label;
    QLineEdit *lineEdit_nom;
    QLabel *organization_label;
    QLineEdit *lineEdit_type;
    QLabel *budget_label;
    QLineEdit *lineEdit_budget;
    QLabel *statut_label;
    QLabel *date_label;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *ajouter_4;
    QPushButton *supprimer_2;
    QPushButton *supprimer_3;
    QLabel *date_label_2;
    QPushButton *pushButton_7;
    QDateTimeEdit *dateTimeEdit_2;
    QLabel *date_label_3;
    QLineEdit *lineEdit_budget_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_p)
    {
        if (MainWindow_p->objectName().isEmpty())
            MainWindow_p->setObjectName(QStringLiteral("MainWindow_p"));
        MainWindow_p->resize(1252, 872);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(9);
        MainWindow_p->setFont(font);
        centralwidget = new QWidget(MainWindow_p);
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
        afficher->setGeometry(QRect(560, 120, 621, 621));
        afficher->setStyleSheet(QStringLiteral(""));
        afficher_label = new QLabel(afficher);
        afficher_label->setObjectName(QStringLiteral("afficher_label"));
        afficher_label->setGeometry(QRect(180, 20, 281, 41));
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
        lineEdit_rechercher = new QLineEdit(afficher);
        lineEdit_rechercher->setObjectName(QStringLiteral("lineEdit_rechercher"));
        lineEdit_rechercher->setGeometry(QRect(10, 90, 221, 31));
        rechercher = new QPushButton(afficher);
        rechercher->setObjectName(QStringLiteral("rechercher"));
        rechercher->setGeometry(QRect(230, 90, 101, 31));
        rechercher->setMaximumSize(QSize(101, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icones/Icones/rechercher.png"), QSize(), QIcon::Normal, QIcon::Off);
        rechercher->setIcon(icon);
        rechercher->setIconSize(QSize(20, 20));
        chat = new QPushButton(afficher);
        chat->setObjectName(QStringLiteral("chat"));
        chat->setGeometry(QRect(120, 590, 93, 31));
        chat->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icones/Icones/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        chat->setIcon(icon1);
        chat->setIconSize(QSize(30, 40));
        tri = new QPushButton(afficher);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(360, 90, 93, 28));
        tri->setMaximumSize(QSize(93, 28));
        pdf = new QPushButton(afficher);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(10, 590, 93, 31));
        pdf->setFont(font);
        pdf->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icones/Icones/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon2);
        pdf->setIconSize(QSize(30, 40));
        stat = new QPushButton(afficher);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(220, 590, 101, 28));
        stat->setMaximumSize(QSize(121, 28));
        stat->setFont(font);
        stat->setStyleSheet(QStringLiteral(""));
        comboBoxTrie = new QComboBox(afficher);
        comboBoxTrie->setObjectName(QStringLiteral("comboBoxTrie"));
        comboBoxTrie->setGeometry(QRect(460, 90, 141, 31));
        tableView = new QTableView(afficher);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 170, 561, 311));
        pushButton = new QPushButton(afficher);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 580, 111, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 1211, 801));
        label->setStyleSheet(QLatin1String("background-image: url(:/Icones/Icones/background.png);\n"
""));
        pushButton_20 = new QPushButton(groupBox);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 50, 61, 51));
        pushButton_20->setStyleSheet(QStringLiteral("background-color: rgb(97, 208, 255);"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/menu.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_20->setIcon(icon3);
        pushButton_20->setIconSize(QSize(40, 40));
        pushButton_20->setCheckable(true);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 110, 71, 701));
        widget->setStyleSheet(QStringLiteral("	background-color: rgb(178, 225, 229);"));
        pushButton_13 = new QPushButton(widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(0, 30, 71, 61));
        pushButton_13->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/home.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(0, 120, 71, 61));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/calendrier.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(40, 40));
        notepad = new QPushButton(widget);
        notepad->setObjectName(QStringLiteral("notepad"));
        notepad->setGeometry(QRect(0, 430, 71, 71));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/notepad.png"), QSize(), QIcon::Normal, QIcon::On);
        notepad->setIcon(icon6);
        notepad->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(0, 210, 71, 61));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/notification.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_15->setIcon(icon7);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(0, 310, 71, 71));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/lecture.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_18->setIcon(icon8);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(widget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(0, 540, 71, 61));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/chat.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_21->setIcon(icon9);
        pushButton_21->setIconSize(QSize(40, 40));
        pushButton_19 = new QPushButton(widget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 640, 71, 61));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/togglapp.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_19->setIcon(icon10);
        pushButton_19->setIconSize(QSize(60, 60));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(90, 110, 461, 681));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        Ajouter = new QLabel(groupBox_2);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(120, 20, 211, 41));
        Ajouter->setFont(font2);
        Ajouter->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        id_label = new QLabel(groupBox_2);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(30, 110, 141, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Cambria"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        id_label->setFont(font3);
        lineEdit_id = new QLineEdit(groupBox_2);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(180, 100, 221, 41));
        nom_label = new QLabel(groupBox_2);
        nom_label->setObjectName(QStringLiteral("nom_label"));
        nom_label->setGeometry(QRect(60, 160, 121, 21));
        nom_label->setFont(font3);
        lineEdit_nom = new QLineEdit(groupBox_2);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(180, 160, 221, 31));
        organization_label = new QLabel(groupBox_2);
        organization_label->setObjectName(QStringLiteral("organization_label"));
        organization_label->setGeometry(QRect(50, 220, 131, 31));
        organization_label->setFont(font3);
        lineEdit_type = new QLineEdit(groupBox_2);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(180, 220, 221, 31));
        budget_label = new QLabel(groupBox_2);
        budget_label->setObjectName(QStringLiteral("budget_label"));
        budget_label->setGeometry(QRect(20, 470, 141, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Cambria"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        budget_label->setFont(font4);
        lineEdit_budget = new QLineEdit(groupBox_2);
        lineEdit_budget->setObjectName(QStringLiteral("lineEdit_budget"));
        lineEdit_budget->setGeometry(QRect(180, 280, 221, 31));
        QFont font5;
        font5.setFamily(QStringLiteral("Calibri"));
        font5.setPointSize(7);
        lineEdit_budget->setFont(font5);
        statut_label = new QLabel(groupBox_2);
        statut_label->setObjectName(QStringLiteral("statut_label"));
        statut_label->setGeometry(QRect(10, 350, 71, 16));
        statut_label->setFont(font3);
        date_label = new QLabel(groupBox_2);
        date_label->setObjectName(QStringLiteral("date_label"));
        date_label->setGeometry(QRect(80, 410, 121, 21));
        date_label->setFont(font3);
        dateTimeEdit = new QDateTimeEdit(groupBox_2);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(180, 410, 221, 21));
        QFont font6;
        font6.setPointSize(10);
        dateTimeEdit->setFont(font6);
        ajouter_4 = new QPushButton(groupBox_2);
        ajouter_4->setObjectName(QStringLiteral("ajouter_4"));
        ajouter_4->setGeometry(QRect(0, 650, 101, 31));
        ajouter_4->setMaximumSize(QSize(101, 31));
        ajouter_4->setFont(font);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Icones/Icones/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter_4->setIcon(icon11);
        ajouter_4->setIconSize(QSize(20, 20));
        supprimer_2 = new QPushButton(groupBox_2);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(220, 650, 101, 31));
        supprimer_2->setMaximumSize(QSize(101, 31));
        supprimer_2->setFont(font);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Icones/Icones/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_2->setIcon(icon12);
        supprimer_2->setIconSize(QSize(20, 20));
        supprimer_3 = new QPushButton(groupBox_2);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setGeometry(QRect(110, 650, 101, 31));
        supprimer_3->setMaximumSize(QSize(101, 31));
        supprimer_3->setFont(font);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Icones/Icones/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_3->setIcon(icon13);
        supprimer_3->setIconSize(QSize(20, 20));
        date_label_2 = new QLabel(groupBox_2);
        date_label_2->setObjectName(QStringLiteral("date_label_2"));
        date_label_2->setGeometry(QRect(50, 280, 161, 31));
        date_label_2->setFont(font3);
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(330, 650, 121, 28));
        pushButton_7->setMaximumSize(QSize(121, 28));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0)"));
        dateTimeEdit_2 = new QDateTimeEdit(groupBox_2);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));
        dateTimeEdit_2->setGeometry(QRect(170, 350, 221, 21));
        dateTimeEdit_2->setFont(font6);
        date_label_3 = new QLabel(groupBox_2);
        date_label_3->setObjectName(QStringLiteral("date_label_3"));
        date_label_3->setGeometry(QRect(50, 350, 121, 21));
        date_label_3->setFont(font3);
        lineEdit_budget_2 = new QLineEdit(groupBox_2);
        lineEdit_budget_2->setObjectName(QStringLiteral("lineEdit_budget_2"));
        lineEdit_budget_2->setGeometry(QRect(170, 470, 221, 31));
        lineEdit_budget_2->setFont(font5);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(330, 590, 101, 31));
        pushButton_3->setFont(font);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Icones/Icones/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon14);
        pushButton_3->setIconSize(QSize(20, 20));
        label->raise();
        afficher->raise();
        nom_gestion->raise();
        pushButton_20->raise();
        widget->raise();
        groupBox_2->raise();
        MainWindow_p->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_p);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1252, 26));
        MainWindow_p->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_p);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_p->setStatusBar(statusbar);

        retranslateUi(MainWindow_p);

        QMetaObject::connectSlotsByName(MainWindow_p);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_p)
    {
        MainWindow_p->setWindowTitle(QApplication::translate("MainWindow_p", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow_p", "Gestion Sponsors", Q_NULLPTR));
        nom_gestion->setText(QApplication::translate("MainWindow_p", "Gestion Projet", Q_NULLPTR));
        afficher->setTitle(QString());
        afficher_label->setText(QApplication::translate("MainWindow_p", "Liste Projet", Q_NULLPTR));
        rechercher->setText(QApplication::translate("MainWindow_p", "Rechercher", Q_NULLPTR));
        chat->setText(QApplication::translate("MainWindow_p", "Chat", Q_NULLPTR));
        tri->setText(QApplication::translate("MainWindow_p", "Lancer Tri", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow_p", "PDF", Q_NULLPTR));
        stat->setText(QApplication::translate("MainWindow_p", "Statistiques", Q_NULLPTR));
        comboBoxTrie->clear();
        comboBoxTrie->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow_p", "date debut", Q_NULLPTR)
         << QApplication::translate("MainWindow_p", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow_p", "id projet croissant", Q_NULLPTR)
         << QApplication::translate("MainWindow_p", "id projet decroissant", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("MainWindow_p", "excel", Q_NULLPTR));
        label->setText(QString());
        pushButton_20->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        notepad->setText(QString());
        pushButton_15->setText(QString());
        pushButton_18->setText(QString());
        pushButton_21->setText(QString());
        pushButton_19->setText(QString());
        groupBox_2->setTitle(QString());
        Ajouter->setText(QApplication::translate("MainWindow_p", "Projet", Q_NULLPTR));
        id_label->setText(QApplication::translate("MainWindow_p", "Identifiant Projet", Q_NULLPTR));
        nom_label->setText(QApplication::translate("MainWindow_p", "Nom", Q_NULLPTR));
        organization_label->setText(QApplication::translate("MainWindow_p", "Utilisateur", Q_NULLPTR));
        budget_label->setText(QApplication::translate("MainWindow_p", "Identifiant Employe", Q_NULLPTR));
        statut_label->setText(QString());
        date_label->setText(QApplication::translate("MainWindow_p", "Date Fin", Q_NULLPTR));
        ajouter_4->setText(QApplication::translate("MainWindow_p", "Ajouter", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("MainWindow_p", "Supprimer", Q_NULLPTR));
        supprimer_3->setText(QApplication::translate("MainWindow_p", "Modifier", Q_NULLPTR));
        date_label_2->setText(QApplication::translate("MainWindow_p", "Description", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow_p", "Afficher", Q_NULLPTR));
        date_label_3->setText(QApplication::translate("MainWindow_p", "Date Debut", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow_p", "Importer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_p: public Ui_MainWindow_p {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJET_H
