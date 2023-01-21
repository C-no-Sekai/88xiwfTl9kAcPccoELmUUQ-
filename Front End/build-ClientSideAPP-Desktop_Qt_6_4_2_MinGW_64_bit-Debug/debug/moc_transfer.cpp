/****************************************************************************
** Meta object code from reading C++ file 'transfer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ClientAppFinal/transfer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transfer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Transfer_t {
    uint offsetsAndSizes[20];
    char stringdata0[9];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[19];
    char stringdata5[8];
    char stringdata6[26];
    char stringdata7[22];
    char stringdata8[24];
    char stringdata9[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Transfer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Transfer_t qt_meta_stringdata_Transfer = {
    {
        QT_MOC_LITERAL(0, 8),  // "Transfer"
        QT_MOC_LITERAL(9, 18),  // "processTransaction"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 12),  // "std::string*"
        QT_MOC_LITERAL(42, 18),  // "transactionResults"
        QT_MOC_LITERAL(61, 7),  // "process"
        QT_MOC_LITERAL(69, 25),  // "displayTransactionResults"
        QT_MOC_LITERAL(95, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(117, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(141, 23)   // "on_pushButton_3_clicked"
    },
    "Transfer",
    "processTransaction",
    "",
    "std::string*",
    "transactionResults",
    "process",
    "displayTransactionResults",
    "on_pushButton_clicked",
    "on_pushButton_2_clicked",
    "on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Transfer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    1,   59,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   62,    2, 0x0a,    5 /* Public */,
       6,    1,   65,    2, 0x0a,    7 /* Public */,
       7,    0,   68,    2, 0x08,    9 /* Private */,
       8,    0,   69,    2, 0x08,   10 /* Private */,
       9,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Transfer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Transfer.offsetsAndSizes,
    qt_meta_data_Transfer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Transfer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Transfer, std::true_type>,
        // method 'processTransaction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string *, std::false_type>,
        // method 'transactionResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string *, std::false_type>,
        // method 'process'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string *, std::false_type>,
        // method 'displayTransactionResults'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string *, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Transfer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Transfer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->processTransaction((*reinterpret_cast< std::add_pointer_t<std::string*>>(_a[1]))); break;
        case 1: _t->transactionResults((*reinterpret_cast< std::add_pointer_t<std::string*>>(_a[1]))); break;
        case 2: _t->process((*reinterpret_cast< std::add_pointer_t<std::string*>>(_a[1]))); break;
        case 3: _t->displayTransactionResults((*reinterpret_cast< std::add_pointer_t<std::string*>>(_a[1]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Transfer::*)(std::string * );
            if (_t _q_method = &Transfer::processTransaction; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Transfer::*)(std::string * );
            if (_t _q_method = &Transfer::transactionResults; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *Transfer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transfer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Transfer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Transfer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Transfer::processTransaction(std::string * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Transfer::transactionResults(std::string * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
