/****************************************************************************
** Meta object code from reading C++ file 'qmythread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../jiancexitong/qmythread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmythread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QThreadDAQ_t {
    QByteArrayData data[4];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QThreadDAQ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QThreadDAQ_t qt_meta_stringdata_QThreadDAQ = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QThreadDAQ"
QT_MOC_LITERAL(1, 11, 9), // "connectOK"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8) // "gameover"

    },
    "QThreadDAQ\0connectOK\0\0gameover"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QThreadDAQ[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QThreadDAQ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QThreadDAQ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectOK(); break;
        case 1: _t->gameover(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QThreadDAQ::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QThreadDAQ::connectOK)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QThreadDAQ::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QThreadDAQ::gameover)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QThreadDAQ::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_QThreadDAQ.data,
    qt_meta_data_QThreadDAQ,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QThreadDAQ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QThreadDAQ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QThreadDAQ.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QThreadDAQ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QThreadDAQ::connectOK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QThreadDAQ::gameover()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_QThreadShow_t {
    QByteArrayData data[6];
    char stringdata0[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QThreadShow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QThreadShow_t qt_meta_stringdata_QThreadShow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QThreadShow"
QT_MOC_LITERAL(1, 12, 8), // "newValue"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "int*"
QT_MOC_LITERAL(4, 27, 4), // "data"
QT_MOC_LITERAL(5, 32, 5) // "count"

    },
    "QThreadShow\0newValue\0\0int*\0data\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QThreadShow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

       0        // eod
};

void QThreadShow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QThreadShow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newValue((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QThreadShow::*)(int * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QThreadShow::newValue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QThreadShow::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_QThreadShow.data,
    qt_meta_data_QThreadShow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QThreadShow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QThreadShow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QThreadShow.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QThreadShow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QThreadShow::newValue(int * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
