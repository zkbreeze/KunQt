/****************************************************************************
** Meta object code from reading C++ file 'kunscreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "kunscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kunscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_kun__kunScreen_t {
    QByteArrayData data[10];
    char stringdata[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_kun__kunScreen_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_kun__kunScreen_t qt_meta_stringdata_kun__kunScreen = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 21),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 3),
QT_MOC_LITERAL(4, 42, 23),
QT_MOC_LITERAL(5, 66, 5),
QT_MOC_LITERAL(6, 72, 22),
QT_MOC_LITERAL(7, 95, 4),
QT_MOC_LITERAL(8, 100, 13),
QT_MOC_LITERAL(9, 114, 21)
    },
    "kun::kunScreen\0setBackgroundColorRed\0"
    "\0red\0setBackgroundColorGreen\0green\0"
    "setBackgroundColorBlue\0blue\0openKVSMLFile\0"
    "chooseBackgroundColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_kun__kunScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       8,    0,   48,    2, 0x0a /* Public */,
       9,    0,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void kun::kunScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        kunScreen *_t = static_cast<kunScreen *>(_o);
        switch (_id) {
        case 0: _t->setBackgroundColorRed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setBackgroundColorGreen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setBackgroundColorBlue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->openKVSMLFile(); break;
        case 4: _t->chooseBackgroundColor(); break;
        default: ;
        }
    }
}

const QMetaObject kun::kunScreen::staticMetaObject = {
    { &kvs::qt::Screen::staticMetaObject, qt_meta_stringdata_kun__kunScreen.data,
      qt_meta_data_kun__kunScreen,  qt_static_metacall, 0, 0}
};


const QMetaObject *kun::kunScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *kun::kunScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_kun__kunScreen.stringdata))
        return static_cast<void*>(const_cast< kunScreen*>(this));
    return kvs::qt::Screen::qt_metacast(_clname);
}

int kun::kunScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = kvs::qt::Screen::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
