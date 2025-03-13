/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notepad
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionRedo;
    QAction *actionUndo;
    QAction *actionAbout_NotePad;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menufile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *notepad)
    {
        if (notepad->objectName().isEmpty())
            notepad->setObjectName(QStringLiteral("notepad"));
        notepad->resize(731, 470);
        actionNew = new QAction(notepad);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/add-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(notepad);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/folder2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(notepad);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/diskette2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(notepad);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/save-as2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon3);
        actionCut = new QAction(notepad);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/cut2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon4);
        actionCopy = new QAction(notepad);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/files2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(notepad);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/paste2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionRedo = new QAction(notepad);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/redo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon7);
        actionUndo = new QAction(notepad);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/undo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionAbout_NotePad = new QAction(notepad);
        actionAbout_NotePad->setObjectName(QStringLiteral("actionAbout_NotePad"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/information2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_NotePad->setIcon(icon9);
        centralwidget = new QWidget(notepad);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(notepad);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 731, 26));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QStringLiteral("menufile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(notepad);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        notepad->setStatusBar(statusbar);
        toolBar = new QToolBar(notepad);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        notepad->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menufile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menufile->addAction(actionNew);
        menufile->addAction(actionOpen);
        menufile->addSeparator();
        menufile->addAction(actionSave);
        menufile->addAction(actionSave_As);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionUndo);
        menuAbout->addAction(actionAbout_NotePad);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_As);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionCut);
        toolBar->addSeparator();
        toolBar->addAction(actionRedo);
        toolBar->addAction(actionUndo);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout_NotePad);

        retranslateUi(notepad);

        QMetaObject::connectSlotsByName(notepad);
    } // setupUi

    void retranslateUi(QMainWindow *notepad)
    {
        notepad->setWindowTitle(QApplication::translate("notepad", "MainWindow", Q_NULLPTR));
        actionNew->setText(QApplication::translate("notepad", "New", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("notepad", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("notepad", "Save", Q_NULLPTR));
        actionSave_As->setText(QApplication::translate("notepad", "Save As", Q_NULLPTR));
        actionCut->setText(QApplication::translate("notepad", "Cut", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("notepad", "Copy", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("notepad", "Paste", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("notepad", "Redo", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("notepad", "Undo", Q_NULLPTR));
        actionAbout_NotePad->setText(QApplication::translate("notepad", "About NotePad", Q_NULLPTR));
        menufile->setTitle(QApplication::translate("notepad", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("notepad", "Edit", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("notepad", "About", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("notepad", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class notepad: public Ui_notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
