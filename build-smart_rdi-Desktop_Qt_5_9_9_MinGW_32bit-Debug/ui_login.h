/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *pb_seconnecter;
    QLineEdit *nom;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(639, 515);
        pb_seconnecter = new QPushButton(login);
        pb_seconnecter->setObjectName(QStringLiteral("pb_seconnecter"));
        pb_seconnecter->setGeometry(QRect(240, 290, 93, 28));
        nom = new QLineEdit(login);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(230, 140, 113, 22));
        password = new QLineEdit(login);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(230, 230, 113, 22));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 140, 81, 16));
        label->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 230, 91, 16));
        label_2->setStyleSheet(QLatin1String("QLabel {\n"
"   color:#ffb001;\n"
"}"));
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 340, 93, 28));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, -5, 651, 541));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/login.png")));
        label_3->setScaledContents(true);
        label_3->raise();
        pb_seconnecter->raise();
        nom->raise();
        password->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        pb_seconnecter->setText(QApplication::translate("login", "se connecter", Q_NULLPTR));
        label->setText(QApplication::translate("login", "Nom", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "Mot de passe", Q_NULLPTR));
        pushButton->setText(QApplication::translate("login", "signup", Q_NULLPTR));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
