/****************************************************************************
** Meta object code from reading C++ file 'MainWindow_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../smart_rdi/MainWindow_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_p_t {
    QByteArrayData data[19];
    char stringdata0[321];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_p_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_p_t qt_meta_stringdata_MainWindow_p = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MainWindow_p"
QT_MOC_LITERAL(1, 13, 20), // "on_ajouter_4_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(4, 59, 22), // "on_supprimer_2_clicked"
QT_MOC_LITERAL(5, 82, 22), // "on_supprimer_3_clicked"
QT_MOC_LITERAL(6, 105, 22), // "on_supprimer_4_clicked"
QT_MOC_LITERAL(7, 128, 21), // "on_rechercher_clicked"
QT_MOC_LITERAL(8, 150, 14), // "on_tri_clicked"
QT_MOC_LITERAL(9, 165, 35), // "on_comboBoxTrie_currentIndexC..."
QT_MOC_LITERAL(10, 201, 5), // "index"
QT_MOC_LITERAL(11, 207, 5), // "trier"
QT_MOC_LITERAL(12, 213, 4), // "item"
QT_MOC_LITERAL(13, 218, 5), // "ordre"
QT_MOC_LITERAL(14, 224, 15), // "on_stat_clicked"
QT_MOC_LITERAL(15, 240, 18), // "on_notepad_clicked"
QT_MOC_LITERAL(16, 259, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(17, 281, 24), // "on_pushButton_19_clicked"
QT_MOC_LITERAL(18, 306, 14) // "on_pdf_clicked"

    },
    "MainWindow_p\0on_ajouter_4_clicked\0\0"
    "on_pushButton_7_clicked\0on_supprimer_2_clicked\0"
    "on_supprimer_3_clicked\0on_supprimer_4_clicked\0"
    "on_rechercher_clicked\0on_tri_clicked\0"
    "on_comboBoxTrie_currentIndexChanged\0"
    "index\0trier\0item\0ordre\0on_stat_clicked\0"
    "on_notepad_clicked\0on_pushButton_clicked\0"
    "on_pushButton_19_clicked\0on_pdf_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow_p[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      11,    2,   94,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow_p::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow_p *_t = static_cast<MainWindow_p *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouter_4_clicked(); break;
        case 1: _t->on_pushButton_7_clicked(); break;
        case 2: _t->on_supprimer_2_clicked(); break;
        case 3: _t->on_supprimer_3_clicked(); break;
        case 4: _t->on_supprimer_4_clicked(); break;
        case 5: _t->on_rechercher_clicked(); break;
        case 6: _t->on_tri_clicked(); break;
        case 7: _t->on_comboBoxTrie_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->trier((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->on_stat_clicked(); break;
        case 10: _t->on_notepad_clicked(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_pushButton_19_clicked(); break;
        case 13: _t->on_pdf_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow_p::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow_p.data,
      qt_meta_data_MainWindow_p,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow_p::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow_p::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow_p.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow_p::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
