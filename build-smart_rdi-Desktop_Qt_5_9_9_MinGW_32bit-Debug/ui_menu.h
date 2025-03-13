/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *sidebar;
    QPushButton *pushButton_16;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_22;
    QPushButton *pushButton_27;
    QWidget *icons;
    QPushButton *pushButton_19;
    QPushButton *pushButton_17;
    QPushButton *pushButton_15;
    QPushButton *pushButton_18;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_21;
    QWidget *menu;
    QWidget *taches;
    QGridLayout *gridLayout;
    QWidget *card6;
    QWidget *widget_28;
    QPushButton *pushButton_56;
    QPushButton *pushButton_57;
    QPushButton *pushButton_58;
    QWidget *widget_29;
    QPushButton *pushButton_59;
    QTextEdit *textEdit_6;
    QWidget *card5;
    QWidget *widget_19;
    QPushButton *pushButton_44;
    QPushButton *pushButton_45;
    QPushButton *pushButton_46;
    QWidget *widget_20;
    QPushButton *pushButton_47;
    QTextEdit *textEdit_5;
    QWidget *card3;
    QWidget *widget_25;
    QPushButton *pushButton_52;
    QPushButton *pushButton_53;
    QPushButton *pushButton_54;
    QWidget *widget_26;
    QPushButton *pushButton_55;
    QTextEdit *textEdit_3;
    QWidget *card4;
    QWidget *widget_16;
    QPushButton *pushButton_40;
    QPushButton *pushButton_41;
    QPushButton *pushButton_42;
    QWidget *widget_17;
    QPushButton *pushButton_43;
    QTextEdit *textEdit_4;
    QWidget *card2;
    QWidget *widget_22;
    QPushButton *pushButton_48;
    QPushButton *pushButton_49;
    QPushButton *pushButton_50;
    QWidget *widget_23;
    QPushButton *pushButton_51;
    QTextEdit *textEdit_2;
    QWidget *card1;
    QWidget *widget_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_33;
    QWidget *widget_9;
    QPushButton *pushButton_10;
    QTextEdit *textEdit;
    QPushButton *pushButton_37;
    QLabel *label_2;
    QLabel *label;
    QWidget *widget_2;
    QWidget *widget_3;
    QPushButton *pushButton_28;
    QWidget *widget_4;
    QLabel *label_3;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(1500, 900);
        Menu->setStyleSheet(QStringLiteral("background-color: rgb(75, 141, 157);"));
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName(QStringLiteral("sidebar"));
        sidebar->setMaximumSize(QSize(221, 16777215));
        sidebar->setStyleSheet(QLatin1String("#sidebar\n"
"{\n"
"	\n"
"	background-color: rgb(178, 225, 229);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"border-bottom-left-radius:35px;\n"
"border-top-left-radius:35px;\n"
"background-color: rgb(75, 141, 157);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"\n"
"	background-color: rgb(255, 255, 255);\n"
"	font: 12pt \"Cambria\";\n"
"}\n"
"\n"
""));
        pushButton_16 = new QPushButton(sidebar);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(0, 80, 221, 71));
        pushButton_16->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/home.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_16->setIcon(icon);
        pushButton_16->setIconSize(QSize(30, 30));
        pushButton_23 = new QPushButton(sidebar);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(0, 290, 221, 71));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/notification.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_23->setIcon(icon1);
        pushButton_23->setIconSize(QSize(30, 30));
        pushButton_24 = new QPushButton(sidebar);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(0, 390, 221, 71));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/lecture.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_24->setIcon(icon2);
        pushButton_24->setIconSize(QSize(30, 30));
        pushButton_25 = new QPushButton(sidebar);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(0, 500, 221, 71));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/notepad.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_25->setIcon(icon3);
        pushButton_25->setIconSize(QSize(30, 30));
        pushButton_26 = new QPushButton(sidebar);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setGeometry(QRect(0, 610, 221, 71));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/chat.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_26->setIcon(icon4);
        pushButton_26->setIconSize(QSize(30, 30));
        pushButton_22 = new QPushButton(sidebar);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(0, 180, 221, 71));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/calendrier.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_22->setIcon(icon5);
        pushButton_22->setIconSize(QSize(30, 30));
        pushButton_27 = new QPushButton(sidebar);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(0, 720, 221, 71));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/togglapp.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_27->setIcon(icon6);
        pushButton_27->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(sidebar, 0, 1, 1, 1);

        icons = new QWidget(centralwidget);
        icons->setObjectName(QStringLiteral("icons"));
        icons->setMaximumSize(QSize(71, 16777215));
        icons->setStyleSheet(QLatin1String("#icons\n"
"{\n"
"background-color: rgb(178, 225, 229);\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"\n"
"}"));
        pushButton_19 = new QPushButton(icons);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 720, 71, 71));
        pushButton_19->setMinimumSize(QSize(71, 71));
        pushButton_19->setMaximumSize(QSize(71, 71));
        pushButton_19->setIcon(icon6);
        pushButton_19->setIconSize(QSize(60, 60));
        pushButton_17 = new QPushButton(icons);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(0, 504, 71, 61));
        pushButton_17->setMinimumSize(QSize(71, 61));
        pushButton_17->setMaximumSize(QSize(71, 61));
        pushButton_17->setIcon(icon3);
        pushButton_17->setIconSize(QSize(40, 40));
        pushButton_15 = new QPushButton(icons);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(0, 292, 71, 61));
        pushButton_15->setMinimumSize(QSize(71, 61));
        pushButton_15->setMaximumSize(QSize(71, 61));
        pushButton_15->setIcon(icon1);
        pushButton_15->setIconSize(QSize(40, 40));
        pushButton_18 = new QPushButton(icons);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(0, 398, 71, 61));
        pushButton_18->setMinimumSize(QSize(71, 61));
        pushButton_18->setMaximumSize(QSize(71, 61));
        pushButton_18->setIcon(icon2);
        pushButton_18->setIconSize(QSize(40, 40));
        pushButton_13 = new QPushButton(icons);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(0, 80, 71, 61));
        pushButton_13->setMinimumSize(QSize(71, 61));
        pushButton_13->setMaximumSize(QSize(71, 61));
        pushButton_13->setStyleSheet(QStringLiteral("background-color: rgb(110, 161, 254);"));
        pushButton_13->setIcon(icon);
        pushButton_13->setIconSize(QSize(40, 40));
        pushButton_14 = new QPushButton(icons);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(0, 186, 71, 61));
        pushButton_14->setMinimumSize(QSize(71, 61));
        pushButton_14->setMaximumSize(QSize(71, 61));
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(40, 40));
        pushButton_21 = new QPushButton(icons);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(0, 610, 71, 61));
        pushButton_21->setMinimumSize(QSize(71, 61));
        pushButton_21->setMaximumSize(QSize(71, 61));
        pushButton_21->setIcon(icon4);
        pushButton_21->setIconSize(QSize(40, 40));

        gridLayout_2->addWidget(icons, 0, 0, 1, 1);

        menu = new QWidget(centralwidget);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setMinimumSize(QSize(1121, 0));
        menu->setMaximumSize(QSize(22222, 16777215));
        menu->setStyleSheet(QStringLiteral(""));
        taches = new QWidget(menu);
        taches->setObjectName(QStringLiteral("taches"));
        taches->setGeometry(QRect(0, 180, 1270, 621));
        taches->setMaximumSize(QSize(144444, 16777215));
        taches->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(taches);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        card6 = new QWidget(taches);
        card6->setObjectName(QStringLiteral("card6"));
        widget_28 = new QWidget(card6);
        widget_28->setObjectName(QStringLiteral("widget_28"));
        widget_28->setGeometry(QRect(20, 20, 331, 130));
        widget_28->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"border-color:rgb(255, 176, 1);\n"
"border-width: 0 4px 8px 12px;\n"
"background-color: rgb(58, 195, 197);\n"
""));
        pushButton_56 = new QPushButton(widget_28);
        pushButton_56->setObjectName(QStringLiteral("pushButton_56"));
        pushButton_56->setGeometry(QRect(20, 10, 291, 31));
        pushButton_56->setStyleSheet(QLatin1String("font: 75 18pt \"Cambria\";\n"
"color: rgb(255, 176, 1);"));
        pushButton_57 = new QPushButton(widget_28);
        pushButton_57->setObjectName(QStringLiteral("pushButton_57"));
        pushButton_57->setGeometry(QRect(110, 40, 93, 61));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/events.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_57->setIcon(icon7);
        pushButton_57->setIconSize(QSize(70, 70));
        pushButton_58 = new QPushButton(widget_28);
        pushButton_58->setObjectName(QStringLiteral("pushButton_58"));
        pushButton_58->setGeometry(QRect(250, 70, 93, 28));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Icones/Icones/fleche.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_58->setIcon(icon8);
        pushButton_58->setIconSize(QSize(16, 16));
        pushButton_58->setCheckable(true);
        pushButton_58->setChecked(true);
        widget_29 = new QWidget(card6);
        widget_29->setObjectName(QStringLiteral("widget_29"));
        widget_29->setGeometry(QRect(20, 130, 331, 151));
        widget_29->setStyleSheet(QLatin1String("background-color: rgb(58, 195, 197);\n"
"\n"
"border-bottom-right-radius:15px;\n"
"\n"
"border-bottom-left-radius:15px;"));
        pushButton_59 = new QPushButton(widget_29);
        pushButton_59->setObjectName(QStringLiteral("pushButton_59"));
        pushButton_59->setGeometry(QRect(170, 90, 121, 31));
        pushButton_59->setStyleSheet(QLatin1String("\n"
"#pushButton_59\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 176, 1);\n"
"}\n"
"\n"
"#pushButton_59:hover\n"
"{\n"
"background-color: rgb(255, 176, 1);\n"
"color:rgb(255, 255, 255)\n"
"}\n"
"\n"
""));
        textEdit_6 = new QTextEdit(widget_29);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setGeometry(QRect(30, 30, 271, 60));
        QFont font;
        font.setFamily(QStringLiteral("Cambria"));
        font.setPointSize(30);
        font.setItalic(false);
        textEdit_6->setFont(font);

        gridLayout->addWidget(card6, 1, 2, 1, 1);

        card5 = new QWidget(taches);
        card5->setObjectName(QStringLiteral("card5"));
        widget_19 = new QWidget(card5);
        widget_19->setObjectName(QStringLiteral("widget_19"));
        widget_19->setGeometry(QRect(20, 20, 331, 130));
        widget_19->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"border-color:rgb(255, 176, 1);\n"
"border-width: 0 4px 8px 12px;\n"
"background-color: rgb(58, 195, 197);\n"
""));
        pushButton_44 = new QPushButton(widget_19);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        pushButton_44->setGeometry(QRect(50, 10, 221, 31));
        pushButton_44->setStyleSheet(QLatin1String("font: 75 18pt \"Cambria\";\n"
"color: rgb(255, 176, 1);"));
        pushButton_45 = new QPushButton(widget_19);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        pushButton_45->setGeometry(QRect(110, 40, 101, 61));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/sponsor.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_45->setIcon(icon9);
        pushButton_45->setIconSize(QSize(70, 70));
        pushButton_46 = new QPushButton(widget_19);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        pushButton_46->setGeometry(QRect(250, 70, 93, 28));
        pushButton_46->setIcon(icon8);
        pushButton_46->setIconSize(QSize(16, 16));
        pushButton_46->setCheckable(true);
        pushButton_46->setChecked(true);
        widget_20 = new QWidget(card5);
        widget_20->setObjectName(QStringLiteral("widget_20"));
        widget_20->setGeometry(QRect(20, 130, 331, 151));
        widget_20->setStyleSheet(QLatin1String("background-color: rgb(58, 195, 197);\n"
"\n"
"border-bottom-right-radius:15px;\n"
"\n"
"border-bottom-left-radius:15px;"));
        pushButton_47 = new QPushButton(widget_20);
        pushButton_47->setObjectName(QStringLiteral("pushButton_47"));
        pushButton_47->setGeometry(QRect(170, 90, 121, 31));
        pushButton_47->setStyleSheet(QLatin1String("\n"
"#pushButton_47\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 176, 1);\n"
"}\n"
"\n"
"#pushButton_47:hover\n"
"{\n"
"background-color: rgb(255, 176, 1);\n"
"color:rgb(255, 255, 255)\n"
"}\n"
""));
        textEdit_5 = new QTextEdit(widget_20);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setGeometry(QRect(30, 30, 271, 60));
        textEdit_5->setFont(font);

        gridLayout->addWidget(card5, 1, 1, 1, 1);

        card3 = new QWidget(taches);
        card3->setObjectName(QStringLiteral("card3"));
        widget_25 = new QWidget(card3);
        widget_25->setObjectName(QStringLiteral("widget_25"));
        widget_25->setGeometry(QRect(20, 20, 331, 130));
        widget_25->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"border-color:rgb(255, 176, 1);\n"
"border-width: 0 4px 8px 12px;\n"
"background-color: rgb(58, 195, 197);\n"
""));
        pushButton_52 = new QPushButton(widget_25);
        pushButton_52->setObjectName(QStringLiteral("pushButton_52"));
        pushButton_52->setGeometry(QRect(50, 10, 221, 31));
        pushButton_52->setStyleSheet(QLatin1String("font: 75 18pt \"Cambria\";\n"
"color: rgb(255, 176, 1);"));
        pushButton_53 = new QPushButton(widget_25);
        pushButton_53->setObjectName(QStringLiteral("pushButton_53"));
        pushButton_53->setGeometry(QRect(110, 40, 93, 61));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/projects.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_53->setIcon(icon10);
        pushButton_53->setIconSize(QSize(70, 70));
        pushButton_54 = new QPushButton(widget_25);
        pushButton_54->setObjectName(QStringLiteral("pushButton_54"));
        pushButton_54->setGeometry(QRect(250, 70, 93, 28));
        pushButton_54->setIcon(icon8);
        pushButton_54->setIconSize(QSize(16, 16));
        pushButton_54->setCheckable(true);
        pushButton_54->setChecked(true);
        widget_26 = new QWidget(card3);
        widget_26->setObjectName(QStringLiteral("widget_26"));
        widget_26->setGeometry(QRect(20, 130, 331, 151));
        widget_26->setStyleSheet(QLatin1String("background-color: rgb(58, 195, 197);\n"
"\n"
"border-bottom-right-radius:15px;\n"
"\n"
"border-bottom-left-radius:15px;"));
        pushButton_55 = new QPushButton(widget_26);
        pushButton_55->setObjectName(QStringLiteral("pushButton_55"));
        pushButton_55->setGeometry(QRect(170, 90, 121, 31));
        pushButton_55->setStyleSheet(QLatin1String("\n"
"#pushButton_55\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 176, 1);\n"
"}\n"
"\n"
"#pushButton_55:hover\n"
"{\n"
"background-color: rgb(255, 176, 1);\n"
"color:rgb(255, 255, 255)\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        textEdit_3 = new QTextEdit(widget_26);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(30, 30, 271, 60));
        textEdit_3->setFont(font);

        gridLayout->addWidget(card3, 0, 2, 1, 1);

        card4 = new QWidget(taches);
        card4->setObjectName(QStringLiteral("card4"));
        widget_16 = new QWidget(card4);
        widget_16->setObjectName(QStringLiteral("widget_16"));
        widget_16->setGeometry(QRect(20, 20, 331, 130));
        widget_16->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"border-color:rgb(255, 176, 1);\n"
"border-width: 0 4px 8px 12px;\n"
"background-color: rgb(58, 195, 197);\n"
""));
        pushButton_40 = new QPushButton(widget_16);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        pushButton_40->setGeometry(QRect(30, 10, 271, 31));
        pushButton_40->setStyleSheet(QLatin1String("font: 75 18pt \"Cambria\";\n"
"color: rgb(255, 176, 1);"));
        pushButton_41 = new QPushButton(widget_16);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        pushButton_41->setGeometry(QRect(110, 40, 93, 71));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/microscope.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_41->setIcon(icon11);
        pushButton_41->setIconSize(QSize(70, 70));
        pushButton_42 = new QPushButton(widget_16);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        pushButton_42->setGeometry(QRect(250, 70, 93, 28));
        pushButton_42->setIcon(icon8);
        pushButton_42->setIconSize(QSize(16, 16));
        pushButton_42->setCheckable(true);
        pushButton_42->setChecked(true);
        widget_17 = new QWidget(card4);
        widget_17->setObjectName(QStringLiteral("widget_17"));
        widget_17->setGeometry(QRect(20, 130, 331, 151));
        widget_17->setStyleSheet(QLatin1String("background-color: rgb(58, 195, 197);\n"
"\n"
"border-bottom-right-radius:15px;\n"
"\n"
"border-bottom-left-radius:15px;"));
        pushButton_43 = new QPushButton(widget_17);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        pushButton_43->setGeometry(QRect(170, 90, 121, 31));
        pushButton_43->setStyleSheet(QLatin1String("\n"
"#pushButton_43\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 176, 1);\n"
"}\n"
"\n"
"#pushButton_43:hover\n"
"{\n"
"background-color: rgb(255, 176, 1);\n"
"color:rgb(255, 255, 255)\n"
"}\n"
""));
        textEdit_4 = new QTextEdit(widget_17);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(30, 30, 271, 60));
        textEdit_4->setFont(font);

        gridLayout->addWidget(card4, 1, 0, 1, 1);

        card2 = new QWidget(taches);
        card2->setObjectName(QStringLiteral("card2"));
        widget_22 = new QWidget(card2);
        widget_22->setObjectName(QStringLiteral("widget_22"));
        widget_22->setGeometry(QRect(20, 20, 331, 130));
        widget_22->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"border-color:rgb(255, 176, 1);\n"
"border-width: 0 4px 8px 12px;\n"
"background-color: rgb(58, 195, 197);\n"
""));
        pushButton_48 = new QPushButton(widget_22);
        pushButton_48->setObjectName(QStringLiteral("pushButton_48"));
        pushButton_48->setGeometry(QRect(20, 10, 281, 31));
        pushButton_48->setStyleSheet(QLatin1String("font: 75 18pt \"Cambria\";\n"
"color: rgb(255, 176, 1);"));
        pushButton_49 = new QPushButton(widget_22);
        pushButton_49->setObjectName(QStringLiteral("pushButton_49"));
        pushButton_49->setGeometry(QRect(110, 40, 93, 61));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/materiels.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_49->setIcon(icon12);
        pushButton_49->setIconSize(QSize(70, 70));
        pushButton_50 = new QPushButton(widget_22);
        pushButton_50->setObjectName(QStringLiteral("pushButton_50"));
        pushButton_50->setGeometry(QRect(250, 70, 93, 28));
        pushButton_50->setIcon(icon8);
        pushButton_50->setIconSize(QSize(16, 16));
        pushButton_50->setCheckable(true);
        pushButton_50->setChecked(true);
        widget_23 = new QWidget(card2);
        widget_23->setObjectName(QStringLiteral("widget_23"));
        widget_23->setGeometry(QRect(20, 130, 331, 151));
        widget_23->setStyleSheet(QLatin1String("background-color: rgb(58, 195, 197);\n"
"\n"
"border-bottom-right-radius:15px;\n"
"\n"
"border-bottom-left-radius:15px;"));
        pushButton_51 = new QPushButton(widget_23);
        pushButton_51->setObjectName(QStringLiteral("pushButton_51"));
        pushButton_51->setGeometry(QRect(170, 90, 121, 31));
        pushButton_51->setStyleSheet(QLatin1String("\n"
"#pushButton_51\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 176, 1);\n"
"}\n"
"\n"
"#pushButton_51:hover\n"
"{\n"
"background-color: rgb(255, 176, 1);\n"
"color:rgb(255, 255, 255)\n"
"}\n"
"\n"
""));
        textEdit_2 = new QTextEdit(widget_23);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(30, 30, 271, 60));
        textEdit_2->setFont(font);

        gridLayout->addWidget(card2, 0, 1, 1, 1);

        card1 = new QWidget(taches);
        card1->setObjectName(QStringLiteral("card1"));
        widget_8 = new QWidget(card1);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(20, 20, 331, 130));
        widget_8->setStyleSheet(QLatin1String("border-radius:15px;\n"
"\n"
"border-color:rgb(255, 176, 1);\n"
"border-width: 0 4px 8px 12px;\n"
"background-color: rgb(58, 195, 197);\n"
""));
        pushButton_5 = new QPushButton(widget_8);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(50, 10, 221, 31));
        pushButton_5->setStyleSheet(QLatin1String("font: 75 18pt \"Cambria\";\n"
"color: rgb(255, 176, 1);"));
        pushButton_6 = new QPushButton(widget_8);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 40, 93, 61));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/img/employe.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_6->setIcon(icon13);
        pushButton_6->setIconSize(QSize(70, 70));
        pushButton_33 = new QPushButton(widget_8);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        pushButton_33->setGeometry(QRect(250, 70, 93, 28));
        pushButton_33->setIcon(icon8);
        pushButton_33->setIconSize(QSize(16, 16));
        pushButton_33->setCheckable(true);
        pushButton_33->setChecked(true);
        widget_9 = new QWidget(card1);
        widget_9->setObjectName(QStringLiteral("widget_9"));
        widget_9->setGeometry(QRect(20, 130, 331, 151));
        widget_9->setStyleSheet(QLatin1String("background-color: rgb(58, 195, 197);\n"
"\n"
"border-bottom-right-radius:15px;\n"
"\n"
"border-bottom-left-radius:15px;"));
        pushButton_10 = new QPushButton(widget_9);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(170, 90, 121, 31));
        pushButton_10->setStyleSheet(QLatin1String("\n"
"#pushButton_10\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:15px;\n"
"color: rgb(255, 176, 1);\n"
"}\n"
"\n"
"#pushButton_10:hover\n"
"{\n"
"background-color: rgb(255, 176, 1);\n"
"color:rgb(255, 255, 255)\n"
"}\n"
""));
        textEdit = new QTextEdit(widget_9);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 30, 271, 60));
        textEdit->setFont(font);

        gridLayout->addWidget(card1, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 400);
        gridLayout->setColumnStretch(1, 400);
        gridLayout->setColumnStretch(2, 400);
        pushButton_37 = new QPushButton(menu);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        pushButton_37->setGeometry(QRect(20, 20, 61, 51));
        pushButton_37->setStyleSheet(QStringLiteral("background-color: rgb(97, 208, 255);"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/img/menu.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_37->setIcon(icon14);
        pushButton_37->setIconSize(QSize(40, 40));
        pushButton_37->setCheckable(true);
        pushButton_37->setChecked(true);
        pushButton_37->setAutoExclusive(true);
        label_2 = new QLabel(menu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 0, 431, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(48);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("\n"
"font: 48pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 176, 1);\n"
"\n"
"\n"
"\n"
""));
        label = new QLabel(menu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1020, -40, 241, 171));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/logo.png")));
        label->setScaledContents(true);
        widget_2 = new QWidget(menu);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 80, 111, 80));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(10, 0, 91, 80));
        pushButton_28 = new QPushButton(widget_3);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(19, 19, 71, 61));
        pushButton_28->setStyleSheet(QLatin1String("background-color:white;\n"
"\n"
""));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/img/user.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_28->setIcon(icon15);
        pushButton_28->setIconSize(QSize(100, 100));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(110, 0, 120, 80));
        label_3 = new QLabel(menu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 80, 411, 91));
        QFont font2;
        font2.setFamily(QStringLiteral("Cambria"));
        font2.setPointSize(15);
        label_3->setFont(font2);

        gridLayout_2->addWidget(menu, 0, 2, 1, 1);

        Menu->setCentralWidget(centralwidget);

        retranslateUi(Menu);
        QObject::connect(pushButton_37, SIGNAL(toggled(bool)), icons, SLOT(setVisible(bool)));
        QObject::connect(pushButton_37, SIGNAL(toggled(bool)), sidebar, SLOT(setHidden(bool)));
        QObject::connect(pushButton_33, SIGNAL(toggled(bool)), widget_9, SLOT(setVisible(bool)));
        QObject::connect(pushButton_33, SIGNAL(toggled(bool)), widget_9, SLOT(setHidden(bool)));
        QObject::connect(pushButton_50, SIGNAL(toggled(bool)), widget_23, SLOT(setVisible(bool)));
        QObject::connect(pushButton_50, SIGNAL(toggled(bool)), widget_23, SLOT(setHidden(bool)));
        QObject::connect(pushButton_54, SIGNAL(toggled(bool)), widget_26, SLOT(setVisible(bool)));
        QObject::connect(pushButton_54, SIGNAL(toggled(bool)), widget_26, SLOT(setHidden(bool)));
        QObject::connect(pushButton_42, SIGNAL(toggled(bool)), widget_17, SLOT(setVisible(bool)));
        QObject::connect(pushButton_42, SIGNAL(toggled(bool)), widget_17, SLOT(setHidden(bool)));
        QObject::connect(pushButton_46, SIGNAL(toggled(bool)), widget_20, SLOT(setVisible(bool)));
        QObject::connect(pushButton_46, SIGNAL(toggled(bool)), widget_20, SLOT(setHidden(bool)));
        QObject::connect(pushButton_58, SIGNAL(toggled(bool)), widget_29, SLOT(setVisible(bool)));
        QObject::connect(pushButton_58, SIGNAL(toggled(bool)), widget_29, SLOT(setHidden(bool)));

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Menu", "Acceuil", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("Menu", "Notification", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("Menu", "Vid\303\251o", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("Menu", "Notepad", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("Menu", "Chat", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("Menu", "Calendrier", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("Menu", "Exit", Q_NULLPTR));
        pushButton_19->setText(QString());
        pushButton_17->setText(QString());
        pushButton_15->setText(QString());
        pushButton_18->setText(QString());
        pushButton_13->setText(QString());
        pushButton_14->setText(QString());
        pushButton_21->setText(QString());
        pushButton_56->setText(QApplication::translate("Menu", "Gestion Ev\303\250nements", Q_NULLPTR));
        pushButton_57->setText(QString());
        pushButton_58->setText(QString());
        pushButton_59->setText(QApplication::translate("Menu", "Entrer", Q_NULLPTR));
        textEdit_6->setHtml(QApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cambria'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">afficher, ajouter, modifier, supprimer un \303\251v\303\251nement</span></p></body></html>", Q_NULLPTR));
        pushButton_44->setText(QApplication::translate("Menu", "Gestion Sponsors", Q_NULLPTR));
        pushButton_45->setText(QString());
        pushButton_46->setText(QString());
        pushButton_47->setText(QApplication::translate("Menu", "Entrer", Q_NULLPTR));
        textEdit_5->setHtml(QApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cambria'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">afficher, ajouter, modifier, supprimer un sponsor</span></p></body></html>", Q_NULLPTR));
        pushButton_52->setText(QApplication::translate("Menu", "Gestion Projets", Q_NULLPTR));
        pushButton_53->setText(QString());
        pushButton_54->setText(QString());
        pushButton_55->setText(QApplication::translate("Menu", "Entrer", Q_NULLPTR));
        textEdit_3->setHtml(QApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cambria'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">afficher, ajouter, modifier, supprimer un projet</span></p></body></html>", Q_NULLPTR));
        pushButton_40->setText(QApplication::translate("Menu", "Gestion Laboratoires", Q_NULLPTR));
        pushButton_41->setText(QString());
        pushButton_42->setText(QString());
        pushButton_43->setText(QApplication::translate("Menu", "Entrer", Q_NULLPTR));
        textEdit_4->setHtml(QApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cambria'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">afficher, ajouter, modifier, supprimer un laboratoire</span></p></body></html>", Q_NULLPTR));
        pushButton_48->setText(QApplication::translate("Menu", "Gestion Equipements", Q_NULLPTR));
        pushButton_49->setText(QString());
        pushButton_50->setText(QString());
        pushButton_51->setText(QApplication::translate("Menu", "Entrer", Q_NULLPTR));
        textEdit_2->setHtml(QApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cambria'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">afficher, ajouter, modifier, supprimer un mat\303\251riel</span></p></body></html>", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Menu", "Gestion Employ\303\251s", Q_NULLPTR));
        pushButton_6->setText(QString());
        pushButton_33->setText(QString());
        pushButton_10->setText(QApplication::translate("Menu", "Entrer", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cambria'; font-size:30pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt;\">afficher, ajouter, modifier, supprimer un employ\303\251</span></p></body></html>", Q_NULLPTR));
        pushButton_37->setText(QString());
        label_2->setText(QApplication::translate("Menu", "Smart RDI", Q_NULLPTR));
        label->setText(QString());
        pushButton_28->setText(QString());
        label_3->setText(QApplication::translate("Menu", "User:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
