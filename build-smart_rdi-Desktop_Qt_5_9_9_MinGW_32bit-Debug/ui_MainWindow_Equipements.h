/********************************************************************************
** Form generated from reading UI file 'MainWindow_Equipements.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_EQUIPEMENTS_H
#define UI_MAINWINDOW_EQUIPEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_MainWindow_Equipements
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *nom_gestion;
    QGroupBox *afficher;
    QLabel *afficher_label;
    QLineEdit *lineEdit_rechercher;
    QPushButton *rechercher;
    QPushButton *pb_trier;
    QPushButton *pushButtonPDF;
    QPushButton *pushButton_stat;
    QComboBox *comboBoxTrie;
    QTableView *tableView_2;
    QTableView *tableView;
    QPushButton *showMessagePushButton;
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
    QLabel *id_label;
    QLabel *nom_label;
    QLineEdit *le_nam;
    QLabel *organization_label;
    QLineEdit *le_Type;
    QLabel *budget_label;
    QLineEdit *le_prix;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_supprimer;
    QPushButton *pb_modifier;
    QLabel *id_label_2;
    QLineEdit *le_quantite;
    QLineEdit *le_id;
    QLineEdit *le_find;
    QLabel *date_label_3;
    QLineEdit *le_IDS;
    QLabel *date_label_4;
    QLabel *label_2;
    QPushButton *qr_code;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_Equipements)
    {
        if (MainWindow_Equipements->objectName().isEmpty())
            MainWindow_Equipements->setObjectName(QStringLiteral("MainWindow_Equipements"));
        MainWindow_Equipements->resize(1236, 872);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(9);
        MainWindow_Equipements->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/myappico.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow_Equipements->setWindowIcon(icon);
        MainWindow_Equipements->setStyleSheet(QLatin1String("QGroupBox {\n"
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
        centralwidget = new QWidget(MainWindow_Equipements);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 1211, 831));
        nom_gestion = new QLabel(groupBox);
        nom_gestion->setObjectName(QStringLiteral("nom_gestion"));
        nom_gestion->setGeometry(QRect(440, 10, 451, 61));
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
        afficher->setGeometry(QRect(580, 120, 621, 661));
        afficher->setStyleSheet(QStringLiteral(""));
        afficher_label = new QLabel(afficher);
        afficher_label->setObjectName(QStringLiteral("afficher_label"));
        afficher_label->setGeometry(QRect(130, 20, 311, 41));
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
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icones/Icones/rechercher.png"), QSize(), QIcon::Normal, QIcon::Off);
        rechercher->setIcon(icon1);
        rechercher->setIconSize(QSize(20, 20));
        pb_trier = new QPushButton(afficher);
        pb_trier->setObjectName(QStringLiteral("pb_trier"));
        pb_trier->setGeometry(QRect(360, 90, 93, 28));
        pb_trier->setMaximumSize(QSize(93, 28));
        pushButtonPDF = new QPushButton(afficher);
        pushButtonPDF->setObjectName(QStringLiteral("pushButtonPDF"));
        pushButtonPDF->setGeometry(QRect(10, 620, 93, 31));
        pushButtonPDF->setFont(font);
        pushButtonPDF->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icones/Icones/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPDF->setIcon(icon2);
        pushButtonPDF->setIconSize(QSize(30, 40));
        pushButton_stat = new QPushButton(afficher);
        pushButton_stat->setObjectName(QStringLiteral("pushButton_stat"));
        pushButton_stat->setGeometry(QRect(120, 620, 101, 28));
        pushButton_stat->setMaximumSize(QSize(121, 28));
        pushButton_stat->setFont(font);
        pushButton_stat->setStyleSheet(QStringLiteral(""));
        comboBoxTrie = new QComboBox(afficher);
        comboBoxTrie->setObjectName(QStringLiteral("comboBoxTrie"));
        comboBoxTrie->setGeometry(QRect(460, 90, 141, 31));
        tableView_2 = new QTableView(afficher);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(20, 130, 561, 211));
        tableView_2->setStyleSheet(QStringLiteral(""));
        tableView = new QTableView(afficher);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 350, 561, 211));
        tableView->setStyleSheet(QStringLiteral(""));
        showMessagePushButton = new QPushButton(afficher);
        showMessagePushButton->setObjectName(QStringLiteral("showMessagePushButton"));
        showMessagePushButton->setGeometry(QRect(470, 30, 93, 28));
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
        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 430, 71, 71));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/notepad.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_17->setIcon(icon6);
        pushButton_17->setIconSize(QSize(40, 40));
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
        groupBox_2->setGeometry(QRect(100, 120, 461, 681));
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
        id_label->setGeometry(QRect(10, 100, 121, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Cambria"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        id_label->setFont(font3);
        nom_label = new QLabel(groupBox_2);
        nom_label->setObjectName(QStringLiteral("nom_label"));
        nom_label->setGeometry(QRect(10, 150, 121, 21));
        nom_label->setFont(font3);
        le_nam = new QLineEdit(groupBox_2);
        le_nam->setObjectName(QStringLiteral("le_nam"));
        le_nam->setGeometry(QRect(180, 150, 221, 31));
        le_nam->setFont(font);
        organization_label = new QLabel(groupBox_2);
        organization_label->setObjectName(QStringLiteral("organization_label"));
        organization_label->setGeometry(QRect(10, 200, 131, 31));
        organization_label->setFont(font3);
        le_Type = new QLineEdit(groupBox_2);
        le_Type->setObjectName(QStringLiteral("le_Type"));
        le_Type->setGeometry(QRect(180, 200, 221, 31));
        le_Type->setFont(font);
        budget_label = new QLabel(groupBox_2);
        budget_label->setObjectName(QStringLiteral("budget_label"));
        budget_label->setGeometry(QRect(10, 260, 71, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Cambria"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        budget_label->setFont(font4);
        le_prix = new QLineEdit(groupBox_2);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(180, 260, 221, 31));
        le_prix->setFont(font);
        pushButton_ajouter = new QPushButton(groupBox_2);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(350, 360, 101, 31));
        pushButton_ajouter->setMaximumSize(QSize(101, 31));
        pushButton_ajouter->setFont(font);
        pushButton_ajouter->setStyleSheet(QStringLiteral(""));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Icones/Icones/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ajouter->setIcon(icon11);
        pushButton_ajouter->setIconSize(QSize(20, 20));
        pushButton_supprimer = new QPushButton(groupBox_2);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(60, 450, 101, 31));
        pushButton_supprimer->setMaximumSize(QSize(101, 31));
        pushButton_supprimer->setFont(font);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Icones/Icones/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_supprimer->setIcon(icon12);
        pushButton_supprimer->setIconSize(QSize(20, 20));
        pb_modifier = new QPushButton(groupBox_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(50, 400, 101, 31));
        pb_modifier->setMaximumSize(QSize(101, 31));
        pb_modifier->setFont(font);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Icones/Icones/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_modifier->setIcon(icon13);
        pb_modifier->setIconSize(QSize(20, 20));
        id_label_2 = new QLabel(groupBox_2);
        id_label_2->setObjectName(QStringLiteral("id_label_2"));
        id_label_2->setGeometry(QRect(10, 330, 121, 31));
        id_label_2->setFont(font3);
        le_quantite = new QLineEdit(groupBox_2);
        le_quantite->setObjectName(QStringLiteral("le_quantite"));
        le_quantite->setGeometry(QRect(180, 330, 221, 31));
        le_quantite->setFont(font);
        le_id = new QLineEdit(groupBox_2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(180, 90, 221, 31));
        le_id->setFont(font);
        le_find = new QLineEdit(groupBox_2);
        le_find->setObjectName(QStringLiteral("le_find"));
        le_find->setGeometry(QRect(180, 400, 221, 31));
        date_label_3 = new QLabel(groupBox_2);
        date_label_3->setObjectName(QStringLiteral("date_label_3"));
        date_label_3->setGeometry(QRect(10, 400, 31, 31));
        date_label_3->setFont(font3);
        le_IDS = new QLineEdit(groupBox_2);
        le_IDS->setObjectName(QStringLiteral("le_IDS"));
        le_IDS->setGeometry(QRect(180, 450, 221, 31));
        date_label_4 = new QLabel(groupBox_2);
        date_label_4->setObjectName(QStringLiteral("date_label_4"));
        date_label_4->setGeometry(QRect(0, 450, 41, 31));
        date_label_4->setFont(font3);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 490, 321, 181));
        qr_code = new QPushButton(groupBox_2);
        qr_code->setObjectName(QStringLiteral("qr_code"));
        qr_code->setGeometry(QRect(10, 580, 93, 31));
        qr_code->setStyleSheet(QStringLiteral(""));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Icones/Icones/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        qr_code->setIcon(icon14);
        qr_code->setIconSize(QSize(30, 40));
        label->raise();
        afficher->raise();
        nom_gestion->raise();
        pushButton_20->raise();
        widget->raise();
        groupBox_2->raise();
        MainWindow_Equipements->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_Equipements);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1236, 26));
        MainWindow_Equipements->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_Equipements);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_Equipements->setStatusBar(statusbar);

        retranslateUi(MainWindow_Equipements);

        QMetaObject::connectSlotsByName(MainWindow_Equipements);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_Equipements)
    {
        MainWindow_Equipements->setWindowTitle(QApplication::translate("MainWindow_Equipements", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow_Equipements", "Gestion Equipements", Q_NULLPTR));
        nom_gestion->setText(QApplication::translate("MainWindow_Equipements", "Gestion Equipements", Q_NULLPTR));
        afficher->setTitle(QString());
        afficher_label->setText(QApplication::translate("MainWindow_Equipements", "Liste Equipements", Q_NULLPTR));
        rechercher->setText(QApplication::translate("MainWindow_Equipements", "Rechercher", Q_NULLPTR));
        pb_trier->setText(QApplication::translate("MainWindow_Equipements", "Lancer Tri", Q_NULLPTR));
        pushButtonPDF->setText(QApplication::translate("MainWindow_Equipements", "PDF", Q_NULLPTR));
        pushButton_stat->setText(QApplication::translate("MainWindow_Equipements", "Statistiques", Q_NULLPTR));
        comboBoxTrie->clear();
        comboBoxTrie->insertItems(0, QStringList()
         << QApplication::translate("MainWindow_Equipements", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow_Equipements", "Type", Q_NULLPTR)
        );
        showMessagePushButton->setText(QApplication::translate("MainWindow_Equipements", "notification", Q_NULLPTR));
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
        Ajouter->setText(QApplication::translate("MainWindow_Equipements", "Equipement", Q_NULLPTR));
        id_label->setText(QApplication::translate("MainWindow_Equipements", "Identifiant", Q_NULLPTR));
        nom_label->setText(QApplication::translate("MainWindow_Equipements", "Nom", Q_NULLPTR));
        organization_label->setText(QApplication::translate("MainWindow_Equipements", "Type", Q_NULLPTR));
        budget_label->setText(QApplication::translate("MainWindow_Equipements", "prix", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("MainWindow_Equipements", "Ajouter", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("MainWindow_Equipements", "Supprimer", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow_Equipements", "Modifier", Q_NULLPTR));
        id_label_2->setText(QApplication::translate("MainWindow_Equipements", "quantite", Q_NULLPTR));
        date_label_3->setText(QApplication::translate("MainWindow_Equipements", "id ", Q_NULLPTR));
        date_label_4->setText(QApplication::translate("MainWindow_Equipements", "id ", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow_Equipements", "Qr code", Q_NULLPTR));
        qr_code->setText(QApplication::translate("MainWindow_Equipements", "Qr_code", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Equipements: public Ui_MainWindow_Equipements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_EQUIPEMENTS_H
