/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../jiancexitong/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "startConnect"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "CloseConnect"
QT_MOC_LITERAL(4, 38, 11), // "sendsqlname"
QT_MOC_LITERAL(5, 50, 12), // "sendsqlname2"
QT_MOC_LITERAL(6, 63, 10), // "getcheckid"
QT_MOC_LITERAL(7, 74, 2), // "id"
QT_MOC_LITERAL(8, 77, 20), // "on_TotalRbtn_clicked"
QT_MOC_LITERAL(9, 98, 20), // "on_LocalRbtn_clicked"
QT_MOC_LITERAL(10, 119, 18), // "on_AccRbtn_clicked"
QT_MOC_LITERAL(11, 138, 27), // "on_toolBox_2_currentChanged"
QT_MOC_LITERAL(12, 166, 5), // "index"
QT_MOC_LITERAL(13, 172, 25), // "on_btnStartThread_clicked"
QT_MOC_LITERAL(14, 198, 31), // "on_listWidget_currentRowChanged"
QT_MOC_LITERAL(15, 230, 10), // "currentRow"
QT_MOC_LITERAL(16, 241, 24), // "on_connectServer_clicked"
QT_MOC_LITERAL(17, 266, 27), // "on_disconnectServer_clicked"
QT_MOC_LITERAL(18, 294, 19) // "on_conectDB_clicked"

    },
    "MainWindow\0startConnect\0\0CloseConnect\0"
    "sendsqlname\0sendsqlname2\0getcheckid\0"
    "id\0on_TotalRbtn_clicked\0on_LocalRbtn_clicked\0"
    "on_AccRbtn_clicked\0on_toolBox_2_currentChanged\0"
    "index\0on_btnStartThread_clicked\0"
    "on_listWidget_currentRowChanged\0"
    "currentRow\0on_connectServer_clicked\0"
    "on_disconnectServer_clicked\0"
    "on_conectDB_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       3,    0,   89,    2, 0x06 /* Public */,
       4,    2,   90,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   98,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    1,  104,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    1,  108,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startConnect((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->CloseConnect(); break;
        case 2: _t->sendsqlname((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sendsqlname2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->getcheckid((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_TotalRbtn_clicked(); break;
        case 6: _t->on_LocalRbtn_clicked(); break;
        case 7: _t->on_AccRbtn_clicked(); break;
        case 8: _t->on_toolBox_2_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_btnStartThread_clicked(); break;
        case 10: _t->on_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_connectServer_clicked(); break;
        case 12: _t->on_disconnectServer_clicked(); break;
        case 13: _t->on_conectDB_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(unsigned short , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startConnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::CloseConnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendsqlname)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendsqlname2)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void MainWindow::startConnect(unsigned short _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::CloseConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sendsqlname(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendsqlname2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
