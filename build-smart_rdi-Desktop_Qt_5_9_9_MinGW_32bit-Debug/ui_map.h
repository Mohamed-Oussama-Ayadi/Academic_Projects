/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QAxWidget *axWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QStringLiteral("Map"));
        Map->resize(1211, 651);
        axWidget = new QAxWidget(Map);
        axWidget->setControl(QStringLiteral("{8856f961-340a-11d0-a96b-00c04fd705a2}"));
        axWidget->setObjectName(QStringLiteral("axWidget"));
        axWidget->setProperty("geometry", QVariant(QRect(0, 50, 1211, 601)));
        layoutWidget = new QWidget(Map);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 1211, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QDialog *Map)
    {
        Map->setWindowTitle(QApplication::translate("Map", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Map", "Locate1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Map", "Locate2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Map", "Locate3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
