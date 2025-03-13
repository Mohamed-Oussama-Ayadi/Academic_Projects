/********************************************************************************
** Form generated from reading UI file 'dumessangerconnectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUMESSANGERCONNECTIONDIALOG_H
#define UI_DUMESSANGERCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DuMessangerConnectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *hostname;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *port;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *accepter;
    QPushButton *annuler;

    void setupUi(QDialog *DuMessangerConnectionDialog)
    {
        if (DuMessangerConnectionDialog->objectName().isEmpty())
            DuMessangerConnectionDialog->setObjectName(QStringLiteral("DuMessangerConnectionDialog"));
        DuMessangerConnectionDialog->resize(461, 188);
        verticalLayout = new QVBoxLayout(DuMessangerConnectionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DuMessangerConnectionDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        hostname = new QLineEdit(DuMessangerConnectionDialog);
        hostname->setObjectName(QStringLiteral("hostname"));

        horizontalLayout->addWidget(hostname);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(DuMessangerConnectionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        port = new QSpinBox(DuMessangerConnectionDialog);
        port->setObjectName(QStringLiteral("port"));
        port->setStyleSheet(QLatin1String("\n"
"    border: 2px solid gray;\n"
"\n"
"    border-radius: 10px;\n"
"\n"
"    padding: 0 8px;\n"
"\n"
"    background: white;\n"
"\n"
"    selection-background-color: darkgray;\n"
""));
        port->setMaximum(999999999);

        formLayout->setWidget(0, QFormLayout::FieldRole, port);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        accepter = new QPushButton(DuMessangerConnectionDialog);
        accepter->setObjectName(QStringLiteral("accepter"));

        horizontalLayout_2->addWidget(accepter);

        annuler = new QPushButton(DuMessangerConnectionDialog);
        annuler->setObjectName(QStringLiteral("annuler"));

        horizontalLayout_2->addWidget(annuler);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DuMessangerConnectionDialog);

        QMetaObject::connectSlotsByName(DuMessangerConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DuMessangerConnectionDialog)
    {
        DuMessangerConnectionDialog->setWindowTitle(QApplication::translate("DuMessangerConnectionDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DuMessangerConnectionDialog", "Hostname", Q_NULLPTR));
        label_2->setText(QApplication::translate("DuMessangerConnectionDialog", "Port", Q_NULLPTR));
        accepter->setText(QApplication::translate("DuMessangerConnectionDialog", "Accepter", Q_NULLPTR));
        annuler->setText(QApplication::translate("DuMessangerConnectionDialog", "Annuler", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DuMessangerConnectionDialog: public Ui_DuMessangerConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUMESSANGERCONNECTIONDIALOG_H
