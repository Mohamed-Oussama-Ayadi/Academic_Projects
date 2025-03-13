/********************************************************************************
** Form generated from reading UI file 'parking.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARKING_H
#define UI_PARKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_arduinoP
{
public:
    QPushButton *pushButton;
    QTableView *table_events;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_nb;
    QLabel *label_3;
    QTableView *update_label;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *arduinoP)
    {
        if (arduinoP->objectName().isEmpty())
            arduinoP->setObjectName(QStringLiteral("arduinoP"));
        arduinoP->resize(1355, 847);
        pushButton = new QPushButton(arduinoP);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(780, 690, 151, 31));
        table_events = new QTableView(arduinoP);
        table_events->setObjectName(QStringLiteral("table_events"));
        table_events->setGeometry(QRect(250, 270, 721, 401));
        label = new QLabel(arduinoP);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(580, 30, 561, 91));
        label_2 = new QLabel(arduinoP);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 690, 138, 66));
        lineEdit_nb = new QLineEdit(arduinoP);
        lineEdit_nb->setObjectName(QStringLiteral("lineEdit_nb"));
        lineEdit_nb->setGeometry(QRect(610, 690, 137, 22));
        label_3 = new QLabel(arduinoP);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-160, 10, 1501, 761));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Icones/Icones/par.jpg")));
        update_label = new QTableView(arduinoP);
        update_label->setObjectName(QStringLiteral("update_label"));
        update_label->setGeometry(QRect(1080, 280, 211, 371));
        label_4 = new QLabel(arduinoP);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1090, 220, 291, 31));
        label_5 = new QLabel(arduinoP);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 220, 291, 41));
        label_3->raise();
        pushButton->raise();
        table_events->raise();
        label->raise();
        label_2->raise();
        lineEdit_nb->raise();
        update_label->raise();
        label_4->raise();
        label_5->raise();

        retranslateUi(arduinoP);

        QMetaObject::connectSlotsByName(arduinoP);
    } // setupUi

    void retranslateUi(QDialog *arduinoP)
    {
        arduinoP->setWindowTitle(QApplication::translate("arduinoP", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("arduinoP", "Envoyer", Q_NULLPTR));
        label->setText(QApplication::translate("arduinoP", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; color:#9f9f9f;\">Parking smart RDI</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("arduinoP", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600; color:#000000;\">Nombre invit\303\251s</span></p><p><br/></p></body></html>", Q_NULLPTR));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("arduinoP", "<html><head/><body><p><span style=\" font-size:14pt;\">Liste  voitures entr\303\251es</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("arduinoP", "<html><head/><body><p><span style=\" font-size:18pt;\">Liste \303\251v\303\251n\303\251ments</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class arduinoP: public Ui_arduinoP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARKING_H
