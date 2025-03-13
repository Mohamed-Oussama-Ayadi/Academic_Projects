/********************************************************************************
** Form generated from reading UI file 'employes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYES_H
#define UI_EMPLOYES_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *nom_gestion;
    QGroupBox *afficher;
    QLabel *afficher_label;
    QLineEdit *lineEdit_rechercher;
    QPushButton *rechercher;
    QPushButton *tri;
    QPushButton *pdf;
    QPushButton *pushButton_statistique;
    QComboBox *comboBo_tri;
    QTableView *tableView;
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
    QLineEdit *lineEdit_id;
    QLabel *nom_label;
    QLineEdit *lineEdit_nom;
    QLabel *organization_label;
    QLineEdit *lineEdit_type;
    QLabel *budget_label;
    QLineEdit *lineEdit_budget;
    QLabel *statut_label;
    QLabel *date_label;
    QPushButton *ajouter_4;
    QPushButton *supprimer_2;
    QPushButton *modifier_3;
    QPushButton *pushButton_afficher;
    QLineEdit *lineEdit_statut;
    QLabel *id_label_2;
    QLabel *label_image;
    QComboBox *comboBox_Emp;
    QLineEdit *lineEdit_budget_2;
    QLineEdit *lineEdit_budget_3;
    QLabel *date_label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1266, 888);
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QLatin1String("QGroupBox {\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 1211, 831));
        nom_gestion = new QLabel(groupBox);
        nom_gestion->setObjectName(QStringLiteral("nom_gestion"));
        nom_gestion->setGeometry(QRect(340, 40, 451, 61));
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
        afficher->setGeometry(QRect(560, 100, 621, 681));
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
        tri = new QPushButton(afficher);
        tri->setObjectName(QStringLiteral("tri"));
        tri->setGeometry(QRect(360, 90, 93, 28));
        tri->setMaximumSize(QSize(93, 28));
        pdf = new QPushButton(afficher);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(0, 650, 93, 31));
        pdf->setFont(font);
        pdf->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icones/Icones/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdf->setIcon(icon1);
        pdf->setIconSize(QSize(30, 40));
        pushButton_statistique = new QPushButton(afficher);
        pushButton_statistique->setObjectName(QStringLiteral("pushButton_statistique"));
        pushButton_statistique->setGeometry(QRect(100, 650, 101, 28));
        pushButton_statistique->setMaximumSize(QSize(121, 28));
        pushButton_statistique->setFont(font);
        pushButton_statistique->setStyleSheet(QStringLiteral(""));
        comboBo_tri = new QComboBox(afficher);
        comboBo_tri->setObjectName(QStringLiteral("comboBo_tri"));
        comboBo_tri->setGeometry(QRect(460, 90, 141, 31));
        tableView = new QTableView(afficher);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(30, 140, 571, 301));
        tableView->setStyleSheet(QStringLiteral(""));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 20, 1211, 801));
        label->setStyleSheet(QLatin1String("background-image: url(:/Icones/Icones/background.png);\n"
""));
        pushButton_20 = new QPushButton(groupBox);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 50, 61, 51));
        pushButton_20->setStyleSheet(QStringLiteral("background-color: rgb(97, 208, 255);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/menu.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_20->setIcon(icon2);
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
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/home.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_13->setIcon(icon3);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(0, 120, 71, 61));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/calendrier.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_14->setIcon(icon4);
        pushButton_14->setIconSize(QSize(40, 40));
        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 430, 71, 71));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/notepad.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_17->setIcon(icon5);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(0, 210, 71, 61));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/notification.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_15->setIcon(icon6);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(0, 310, 71, 71));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/lecture.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_18->setIcon(icon7);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(widget);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(0, 540, 71, 61));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/chat.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_21->setIcon(icon8);
        pushButton_21->setIconSize(QSize(40, 40));
        pushButton_19 = new QPushButton(widget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 640, 71, 61));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/togglapp.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_19->setIcon(icon9);
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
        id_label->setGeometry(QRect(10, 100, 121, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Cambria"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        id_label->setFont(font3);
        lineEdit_id = new QLineEdit(groupBox_2);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(180, 100, 221, 31));
        lineEdit_id->setFont(font);
        nom_label = new QLabel(groupBox_2);
        nom_label->setObjectName(QStringLiteral("nom_label"));
        nom_label->setGeometry(QRect(10, 150, 121, 21));
        nom_label->setFont(font3);
        lineEdit_nom = new QLineEdit(groupBox_2);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(180, 150, 221, 31));
        lineEdit_nom->setFont(font);
        organization_label = new QLabel(groupBox_2);
        organization_label->setObjectName(QStringLiteral("organization_label"));
        organization_label->setGeometry(QRect(10, 200, 131, 31));
        organization_label->setFont(font3);
        lineEdit_type = new QLineEdit(groupBox_2);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setGeometry(QRect(180, 200, 221, 31));
        lineEdit_type->setFont(font);
        budget_label = new QLabel(groupBox_2);
        budget_label->setObjectName(QStringLiteral("budget_label"));
        budget_label->setGeometry(QRect(10, 260, 71, 31));
        QFont font4;
        font4.setFamily(QStringLiteral("Cambria"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        budget_label->setFont(font4);
        lineEdit_budget = new QLineEdit(groupBox_2);
        lineEdit_budget->setObjectName(QStringLiteral("lineEdit_budget"));
        lineEdit_budget->setGeometry(QRect(180, 260, 221, 31));
        lineEdit_budget->setFont(font);
        statut_label = new QLabel(groupBox_2);
        statut_label->setObjectName(QStringLiteral("statut_label"));
        statut_label->setGeometry(QRect(20, 330, 91, 16));
        statut_label->setFont(font3);
        date_label = new QLabel(groupBox_2);
        date_label->setObjectName(QStringLiteral("date_label"));
        date_label->setGeometry(QRect(20, 400, 121, 21));
        date_label->setFont(font3);
        ajouter_4 = new QPushButton(groupBox_2);
        ajouter_4->setObjectName(QStringLiteral("ajouter_4"));
        ajouter_4->setGeometry(QRect(0, 650, 101, 31));
        ajouter_4->setMaximumSize(QSize(101, 31));
        ajouter_4->setFont(font);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Icones/Icones/ajouter.png"), QSize(), QIcon::Normal, QIcon::Off);
        ajouter_4->setIcon(icon10);
        ajouter_4->setIconSize(QSize(20, 20));
        supprimer_2 = new QPushButton(groupBox_2);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(230, 650, 101, 31));
        supprimer_2->setMaximumSize(QSize(101, 31));
        supprimer_2->setFont(font);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Icones/Icones/supprimer.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_2->setIcon(icon11);
        supprimer_2->setIconSize(QSize(20, 20));
        modifier_3 = new QPushButton(groupBox_2);
        modifier_3->setObjectName(QStringLiteral("modifier_3"));
        modifier_3->setGeometry(QRect(110, 650, 101, 31));
        modifier_3->setMaximumSize(QSize(101, 31));
        modifier_3->setFont(font);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Icones/Icones/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifier_3->setIcon(icon12);
        modifier_3->setIconSize(QSize(20, 20));
        pushButton_afficher = new QPushButton(groupBox_2);
        pushButton_afficher->setObjectName(QStringLiteral("pushButton_afficher"));
        pushButton_afficher->setGeometry(QRect(340, 650, 121, 28));
        pushButton_afficher->setMaximumSize(QSize(121, 28));
        pushButton_afficher->setFont(font);
        pushButton_afficher->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0)"));
        lineEdit_statut = new QLineEdit(groupBox_2);
        lineEdit_statut->setObjectName(QStringLiteral("lineEdit_statut"));
        lineEdit_statut->setGeometry(QRect(180, 320, 221, 31));
        lineEdit_statut->setFont(font);
        id_label_2 = new QLabel(groupBox_2);
        id_label_2->setObjectName(QStringLiteral("id_label_2"));
        id_label_2->setGeometry(QRect(30, 550, 121, 31));
        id_label_2->setFont(font3);
        label_image = new QLabel(groupBox_2);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(180, 520, 271, 31));
        comboBox_Emp = new QComboBox(groupBox_2);
        comboBox_Emp->setObjectName(QStringLiteral("comboBox_Emp"));
        comboBox_Emp->setGeometry(QRect(180, 550, 221, 31));
        lineEdit_budget_2 = new QLineEdit(groupBox_2);
        lineEdit_budget_2->setObjectName(QStringLiteral("lineEdit_budget_2"));
        lineEdit_budget_2->setGeometry(QRect(180, 390, 221, 31));
        lineEdit_budget_2->setFont(font);
        lineEdit_budget_3 = new QLineEdit(groupBox_2);
        lineEdit_budget_3->setObjectName(QStringLiteral("lineEdit_budget_3"));
        lineEdit_budget_3->setGeometry(QRect(180, 470, 221, 31));
        lineEdit_budget_3->setFont(font);
        date_label_2 = new QLabel(groupBox_2);
        date_label_2->setObjectName(QStringLiteral("date_label_2"));
        date_label_2->setGeometry(QRect(20, 470, 121, 21));
        date_label_2->setFont(font3);
        label->raise();
        afficher->raise();
        nom_gestion->raise();
        pushButton_20->raise();
        widget->raise();
        groupBox_2->raise();
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1266, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Gestion Sponsors", Q_NULLPTR));
        nom_gestion->setText(QApplication::translate("MainWindow", "GESTION EMPLOYES", Q_NULLPTR));
        afficher->setTitle(QString());
        afficher_label->setText(QApplication::translate("MainWindow", "LISTE EMPLOYES", Q_NULLPTR));
        rechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        tri->setText(QApplication::translate("MainWindow", "Lancer Tri", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButton_statistique->setText(QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        comboBo_tri->clear();
        comboBo_tri->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Fonction", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ID_EMPLOYE", Q_NULLPTR)
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
        groupBox_2->setTitle(QString());
        Ajouter->setText(QApplication::translate("MainWindow", "EMPLOYES", Q_NULLPTR));
        id_label->setText(QApplication::translate("MainWindow", "Id employe", Q_NULLPTR));
        nom_label->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        organization_label->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        budget_label->setText(QApplication::translate("MainWindow", "email", Q_NULLPTR));
        statut_label->setText(QApplication::translate("MainWindow", "sexe", Q_NULLPTR));
        date_label->setText(QApplication::translate("MainWindow", "fonction", Q_NULLPTR));
        ajouter_4->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        modifier_3->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_afficher->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        lineEdit_statut->setPlaceholderText(QApplication::translate("MainWindow", "Homme ou Femme", Q_NULLPTR));
        id_label_2->setText(QApplication::translate("MainWindow", "Labo", Q_NULLPTR));
        label_image->setText(QString());
        comboBox_Emp->clear();
        comboBox_Emp->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "11", Q_NULLPTR)
        );
        date_label_2->setText(QApplication::translate("MainWindow", "specialite", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYES_H
