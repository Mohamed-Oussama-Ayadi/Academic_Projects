/********************************************************************************
** Form generated from reading UI file 'activatoncodeclass.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVATONCODECLASS_H
#define UI_ACTIVATONCODECLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ActivatonCodeClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *le_code;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ActivatonCodeClass)
    {
        if (ActivatonCodeClass->objectName().isEmpty())
            ActivatonCodeClass->setObjectName(QStringLiteral("ActivatonCodeClass"));
        ActivatonCodeClass->resize(400, 134);
        verticalLayout_2 = new QVBoxLayout(ActivatonCodeClass);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ActivatonCodeClass);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        le_code = new QLineEdit(ActivatonCodeClass);
        le_code->setObjectName(QStringLiteral("le_code"));

        verticalLayout->addWidget(le_code);

        pushButton = new QPushButton(ActivatonCodeClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalSpacer = new QSpacerItem(379, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);


        retranslateUi(ActivatonCodeClass);

        QMetaObject::connectSlotsByName(ActivatonCodeClass);
    } // setupUi

    void retranslateUi(QDialog *ActivatonCodeClass)
    {
        ActivatonCodeClass->setWindowTitle(QApplication::translate("ActivatonCodeClass", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ActivatonCodeClass", "Enter The Activation Code : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ActivatonCodeClass", "SUBMIT", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ActivatonCodeClass: public Ui_ActivatonCodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVATONCODECLASS_H
