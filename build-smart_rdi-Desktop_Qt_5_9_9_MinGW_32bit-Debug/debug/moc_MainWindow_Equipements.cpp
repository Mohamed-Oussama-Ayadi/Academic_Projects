/****************************************************************************
** Meta object code from reading C++ file 'MainWindow_Equipements.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smart_rdi/MainWindow_Equipements.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow_Equipements.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_Equipements_t {
    QByteArrayData data[15];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_Equipements_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_Equipements_t qt_meta_stringdata_MainWindow_Equipements = {
    {
QT_MOC_LITERAL(0, 0, 22), // "MainWindow_Equipements"
QT_MOC_LITERAL(1, 23, 29), // "on_pushButton_ajouter_clicked"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 31), // "on_pushButton_supprimer_clicked"
QT_MOC_LITERAL(4, 86, 22), // "on_pb_modifier_clicked"
QT_MOC_LITERAL(5, 109, 21), // "on_rechercher_clicked"
QT_MOC_LITERAL(6, 131, 26), // "on_pushButton_stat_clicked"
QT_MOC_LITERAL(7, 158, 19), // "on_pb_trier_clicked"
QT_MOC_LITERAL(8, 178, 18), // "on_qr_code_clicked"
QT_MOC_LITERAL(9, 197, 32), // "on_showMessagePushButton_clicked"
QT_MOC_LITERAL(10, 230, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(11, 255, 24), // "on_pushButton_19_clicked"
QT_MOC_LITERAL(12, 280, 24), // "on_pushButtonPDF_clicked"
QT_MOC_LITERAL(13, 305, 24), // "on_tableView_2_activated"
QT_MOC_LITERAL(14, 330, 5) // "index"

    },
    "MainWindow_Equipements\0"
    "on_pushButton_ajouter_clicked\0\0"
    "on_pushButton_supprimer_clicked\0"
    "on_pb_modifier_clicked\0on_rechercher_clicked\0"
    "on_pushButton_stat_clicked\0"
    "on_pb_trier_clicked\0on_qr_code_clicked\0"
    "on_showMessagePushButton_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_pushButton_19_clicked\0"
    "on_pushButtonPDF_clicked\0"
    "on_tableView_2_activated\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow_Equipements[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   14,

       0        // eod
};

void MainWindow_Equipements::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow_Equipements *_t = static_cast<MainWindow_Equipements *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_ajouter_clicked(); break;
        case 1: _t->on_pushButton_supprimer_clicked(); break;
        case 2: _t->on_pb_modifier_clicked(); break;
        case 3: _t->on_rechercher_clicked(); break;
        case 4: _t->on_pushButton_stat_clicked(); break;
        case 5: _t->on_pb_trier_clicked(); break;
        case 6: _t->on_qr_code_clicked(); break;
        case 7: _t->on_showMessagePushButton_clicked(); break;
        case 8: _t->on_pushButton_13_clicked(); break;
        case 9: _t->on_pushButton_19_clicked(); break;
        case 10: _t->on_pushButtonPDF_clicked(); break;
        case 11: _t->on_tableView_2_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow_Equipements::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow_Equipements.data,
      qt_meta_data_MainWindow_Equipements,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow_Equipements::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow_Equipements::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow_Equipements.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow_Equipements::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
