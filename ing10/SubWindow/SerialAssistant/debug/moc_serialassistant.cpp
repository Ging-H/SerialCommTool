/****************************************************************************
** Meta object code from reading C++ file 'serialassistant.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serialassistant.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialassistant.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialAssistant_t {
    QByteArrayData data[16];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialAssistant_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialAssistant_t qt_meta_stringdata_SerialAssistant = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SerialAssistant"
QT_MOC_LITERAL(1, 16, 22), // "slots_serialRxCallback"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 22), // "on_btnOpenPort_clicked"
QT_MOC_LITERAL(4, 63, 21), // "on_btnRefresh_clicked"
QT_MOC_LITERAL(5, 85, 25), // "on_chkFlowCtrlDTR_toggled"
QT_MOC_LITERAL(6, 111, 7), // "checked"
QT_MOC_LITERAL(7, 119, 25), // "on_chkFlowCtrlRTS_toggled"
QT_MOC_LITERAL(8, 145, 22), // "on_btnSaveFile_clicked"
QT_MOC_LITERAL(9, 168, 22), // "on_btnLoadFile_clicked"
QT_MOC_LITERAL(10, 191, 25), // "on_textBrower_textChanged"
QT_MOC_LITERAL(11, 217, 21), // "on_checkBox_5_toggled"
QT_MOC_LITERAL(12, 239, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(13, 258, 24), // "on_txtSingle_textChanged"
QT_MOC_LITERAL(14, 283, 25), // "on_toolBox_currentChanged"
QT_MOC_LITERAL(15, 309, 5) // "index"

    },
    "SerialAssistant\0slots_serialRxCallback\0"
    "\0on_btnOpenPort_clicked\0on_btnRefresh_clicked\0"
    "on_chkFlowCtrlDTR_toggled\0checked\0"
    "on_chkFlowCtrlRTS_toggled\0"
    "on_btnSaveFile_clicked\0on_btnLoadFile_clicked\0"
    "on_textBrower_textChanged\0"
    "on_checkBox_5_toggled\0on_btnSend_clicked\0"
    "on_txtSingle_textChanged\0"
    "on_toolBox_currentChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialAssistant[] = {

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
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    1,   77,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void SerialAssistant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialAssistant *_t = static_cast<SerialAssistant *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slots_serialRxCallback(); break;
        case 1: _t->on_btnOpenPort_clicked(); break;
        case 2: _t->on_btnRefresh_clicked(); break;
        case 3: _t->on_chkFlowCtrlDTR_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_chkFlowCtrlRTS_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_btnSaveFile_clicked(); break;
        case 6: _t->on_btnLoadFile_clicked(); break;
        case 7: _t->on_textBrower_textChanged(); break;
        case 8: _t->on_checkBox_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_btnSend_clicked(); break;
        case 10: _t->on_txtSingle_textChanged(); break;
        case 11: _t->on_toolBox_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SerialAssistant::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SerialAssistant.data,
      qt_meta_data_SerialAssistant,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialAssistant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialAssistant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialAssistant.stringdata0))
        return static_cast<void*>(const_cast< SerialAssistant*>(this));
    return QWidget::qt_metacast(_clname);
}

int SerialAssistant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
