/****************************************************************************
** Meta object code from reading C++ file 'baseserialcomm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../baseserialcomm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'baseserialcomm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseSerialComm_t {
    QByteArrayData data[13];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseSerialComm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseSerialComm_t qt_meta_stringdata_BaseSerialComm = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BaseSerialComm"
QT_MOC_LITERAL(1, 15, 8), // "BaudRate"
QT_MOC_LITERAL(2, 24, 8), // "Baud1200"
QT_MOC_LITERAL(3, 33, 8), // "Baud2400"
QT_MOC_LITERAL(4, 42, 8), // "Baud4800"
QT_MOC_LITERAL(5, 51, 8), // "Baud9600"
QT_MOC_LITERAL(6, 60, 9), // "Baud19200"
QT_MOC_LITERAL(7, 70, 9), // "Baud38400"
QT_MOC_LITERAL(8, 80, 9), // "Baud57600"
QT_MOC_LITERAL(9, 90, 10), // "Baud115200"
QT_MOC_LITERAL(10, 101, 10), // "Baud128000"
QT_MOC_LITERAL(11, 112, 10), // "Baud256000"
QT_MOC_LITERAL(12, 123, 11) // "UnknownBaud"

    },
    "BaseSerialComm\0BaudRate\0Baud1200\0"
    "Baud2400\0Baud4800\0Baud9600\0Baud19200\0"
    "Baud38400\0Baud57600\0Baud115200\0"
    "Baud128000\0Baud256000\0UnknownBaud"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseSerialComm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,   11,   18,

 // enum data: key, value
       2, uint(BaseSerialComm::Baud1200),
       3, uint(BaseSerialComm::Baud2400),
       4, uint(BaseSerialComm::Baud4800),
       5, uint(BaseSerialComm::Baud9600),
       6, uint(BaseSerialComm::Baud19200),
       7, uint(BaseSerialComm::Baud38400),
       8, uint(BaseSerialComm::Baud57600),
       9, uint(BaseSerialComm::Baud115200),
      10, uint(BaseSerialComm::Baud128000),
      11, uint(BaseSerialComm::Baud256000),
      12, uint(BaseSerialComm::UnknownBaud),

       0        // eod
};

void BaseSerialComm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject BaseSerialComm::staticMetaObject = {
    { &QSerialPort::staticMetaObject, qt_meta_stringdata_BaseSerialComm.data,
      qt_meta_data_BaseSerialComm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BaseSerialComm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseSerialComm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseSerialComm.stringdata0))
        return static_cast<void*>(const_cast< BaseSerialComm*>(this));
    if (!strcmp(_clname, "QSerialPortInfo"))
        return static_cast< QSerialPortInfo*>(const_cast< BaseSerialComm*>(this));
    return QSerialPort::qt_metacast(_clname);
}

int BaseSerialComm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
