/********************************************************************************
** Form generated from reading UI file 'arduino.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARDUINO_H
#define UI_ARDUINO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Arduino
{
public:
    QLabel *label_7;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *pushButton_5;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_5;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_3;
    QLCDNumber *lcdNumber_3;
    QPushButton *pushButton_4;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Arduino)
    {
        if (Arduino->objectName().isEmpty())
            Arduino->setObjectName(QStringLiteral("Arduino"));
        Arduino->resize(764, 531);
        Arduino->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    color: white;\n"
"}\n"
"\n"
"\n"
""));
        label_7 = new QLabel(Arduino);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, -10, 761, 541));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/img/arduino.jpg")));
        label_7->setScaledContents(true);
        pushButton_3 = new QPushButton(Arduino);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 240, 93, 41));
        QFont font;
        pushButton_3->setFont(font);
        label = new QLabel(Arduino);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 161, 41));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        pushButton_5 = new QPushButton(Arduino);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 440, 111, 41));
        pushButton_5->setStyleSheet(QStringLiteral("color:black"));
        label_6 = new QLabel(Arduino);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 340, 111, 31));
        label_2 = new QLabel(Arduino);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 131, 41));
        label_2->setFont(font1);
        label_5 = new QLabel(Arduino);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(440, 250, 56, 16));
        lcdNumber = new QLCDNumber(Arduino);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(160, 20, 121, 51));
        pushButton = new QPushButton(Arduino);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 30, 93, 41));
        pushButton->setFont(font);
        label_4 = new QLabel(Arduino);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 130, 141, 41));
        label_3 = new QLabel(Arduino);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 30, 121, 31));
        lcdNumber_3 = new QLCDNumber(Arduino);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(280, 20, 121, 51));
        pushButton_4 = new QPushButton(Arduino);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(530, 340, 93, 41));
        pushButton_4->setFont(font);
        lcdNumber_2 = new QLCDNumber(Arduino);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(160, 90, 121, 51));
        pushButton_2 = new QPushButton(Arduino);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 140, 93, 41));
        pushButton_2->setFont(font);

        retranslateUi(Arduino);

        QMetaObject::connectSlotsByName(Arduino);
    } // setupUi

    void retranslateUi(QDialog *Arduino)
    {
        Arduino->setWindowTitle(QApplication::translate("Arduino", "Dialog", Q_NULLPTR));
        label_7->setText(QString());
        pushButton_3->setText(QString());
        label->setText(QApplication::translate("Arduino", "Temperature", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Arduino", "Ajouter", Q_NULLPTR));
        label_6->setText(QApplication::translate("Arduino", "VENTILATEUR", Q_NULLPTR));
        label_2->setText(QApplication::translate("Arduino", "Humidite", Q_NULLPTR));
        label_5->setText(QApplication::translate("Arduino", "BUZZER", Q_NULLPTR));
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("Arduino", "LED ORANGE", Q_NULLPTR));
        label_3->setText(QApplication::translate("Arduino", "LED VERTE", Q_NULLPTR));
        pushButton_4->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Arduino: public Ui_Arduino {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARDUINO_H
