/********************************************************************************
** Form generated from reading UI file 'signupdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPDIALOG_H
#define UI_SIGNUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SignUpDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *uname;
    QLabel *label_2;
    QLineEdit *pass;
    QLabel *label_3;
    QLineEdit *email_le;
    QPushButton *pushButton;

    void setupUi(QDialog *SignUpDialog)
    {
        if (SignUpDialog->objectName().isEmpty())
            SignUpDialog->setObjectName(QStringLiteral("SignUpDialog"));
        SignUpDialog->resize(442, 138);
        SignUpDialog->setAutoFillBackground(false);
        SignUpDialog->setStyleSheet(QLatin1String("background-color: #d2ff2a\n"
""));
        verticalLayout_2 = new QVBoxLayout(SignUpDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(SignUpDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(23, 103, 211);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        uname = new QLineEdit(SignUpDialog);
        uname->setObjectName(QStringLiteral("uname"));

        formLayout->setWidget(0, QFormLayout::FieldRole, uname);

        label_2 = new QLabel(SignUpDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(23, 103, 211);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        pass = new QLineEdit(SignUpDialog);
        pass->setObjectName(QStringLiteral("pass"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pass);

        label_3 = new QLabel(SignUpDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(23, 103, 211);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        email_le = new QLineEdit(SignUpDialog);
        email_le->setObjectName(QStringLiteral("email_le"));

        formLayout->setWidget(2, QFormLayout::FieldRole, email_le);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(SignUpDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 168, 0);"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SignUpDialog);

        QMetaObject::connectSlotsByName(SignUpDialog);
    } // setupUi

    void retranslateUi(QDialog *SignUpDialog)
    {
        SignUpDialog->setWindowTitle(QApplication::translate("SignUpDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SignUpDialog", "Username", Q_NULLPTR));
        label_2->setText(QApplication::translate("SignUpDialog", "Password", Q_NULLPTR));
        label_3->setText(QApplication::translate("SignUpDialog", "Email:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SignUpDialog", "Create", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignUpDialog: public Ui_SignUpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPDIALOG_H
