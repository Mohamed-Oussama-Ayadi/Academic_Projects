QT       += core gui multimediawidgets multimedia serialport
QT += sql
QT += charts
QT +=  core network
        QT += network
QT       += core  gui axcontainer


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

QT += axcontainer
#QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Connexion.cpp \
    DuMessangerConnectionDialog.cpp \
    Employes.cpp \
    Equipements.cpp \
    MainWindow_Equipements.cpp \
    MainWindow_em.cpp \
    MainWindow_l.cpp \
    MainWindow_p.cpp \
    MainWindow_spon.cpp \
    QrCode.cpp \
    activatoncodeclass.cpp \
    arduino.cpp \
    arduinoP.cpp \
    arduino_l.cpp \
    calendrier.cpp \
    event.cpp \
    labo.cpp \
    login.cpp \
    main.cpp \
    mainwindow_event.cpp \
    map.cpp \
    menu.cpp \
    notepad.cpp \
    project.cpp \
    signupdialog.cpp \
    smtp.cpp \
    sponsor.cpp \
    statistique.cpp \
    video.cpp \
    widget.cpp

HEADERS += \
    Connexion.h \
    Employes.h \
    Equipements.h \
    MainWindow_Equipements.h \
    MainWindow_em.h \
    MainWindow_l.h \
    MainWindow_p.h \
    MainWindow_spon.h \
    QrCode.h \
    activatoncodeclass.h \
    arduino.h \
    arduinoP.h \
    arduino_l.h \
    calendrier.h \
    dumessangerconnectiondialog.h \
    event.h \
    labo.h \
    login.h \
    mainwindow_event.h \
    map.h \
    menu.h \
    notepad.h \
    project.h \
    signupdialog.h \
    smtp.h \
    sponsor.h \
    statistique.h \
    video.h \
    widget.h

FORMS += \
    MainWindow_Equipements.ui \
    MainWindow_l.ui \
    MainWindow_spon.ui \
    activatoncodeclass.ui \
    arduino.ui \
    dumessangerconnectiondialog.ui \
    employes.ui \
    login.ui \
    mainwindow_event.ui \
    map.ui \
    menu.ui \
    notepad.ui \
    parking.ui \
    projet.ui \
    signupdialog.ui \
    video.ui \
    widget.ui
  RC_ICONS = myappico.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    menu/back.png \
    menu/back2.png \
    menu/calendrier.png \
    menu/chat.png \
    menu/employe.png \
    menu/events.png \
    menu/home.png \
    menu/info.png \
    menu/lecture.png \
    menu/logo.png \
    menu/materiels.png \
    menu/menu.png \
    menu/microscope.png \
    menu/notepad.png \
    menu/notification.png \
    menu/project.png \
    menu/projects.png \
    menu/sponsor.png \
    menu/togglapp.png \
    menu/user.png \
    myappico.ico \
    myappico.png
