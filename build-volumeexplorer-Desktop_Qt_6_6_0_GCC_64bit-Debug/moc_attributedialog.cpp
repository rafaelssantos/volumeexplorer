/****************************************************************************
** Meta object code from reading C++ file 'attributedialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/attribute/attributedialog.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attributedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAttributeDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAttributeDialogENDCLASS = QtMocHelpers::stringData(
    "AttributeDialog",
    "signalAccepted",
    "",
    "std::set<attribute::AttributeType>&",
    "types",
    "mask",
    "std::string",
    "filePath",
    "signalOpenCSVFile",
    "signalRejected",
    "slotSetAvailableTypes",
    "std::set<attribute::AttributeType>",
    "availableTypes",
    "slotSetCSVFilePath",
    "slotSelectAll",
    "slotEmitSignalAccepted",
    "slotEmitSignalOpenCVSFile",
    "slotEmitSignalRejected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAttributeDialogENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[16];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[36];
    char stringdata4[6];
    char stringdata5[5];
    char stringdata6[12];
    char stringdata7[9];
    char stringdata8[18];
    char stringdata9[15];
    char stringdata10[22];
    char stringdata11[35];
    char stringdata12[15];
    char stringdata13[19];
    char stringdata14[14];
    char stringdata15[23];
    char stringdata16[26];
    char stringdata17[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAttributeDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAttributeDialogENDCLASS_t qt_meta_stringdata_CLASSAttributeDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "AttributeDialog"
        QT_MOC_LITERAL(16, 14),  // "signalAccepted"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 35),  // "std::set<attribute::Attribute..."
        QT_MOC_LITERAL(68, 5),  // "types"
        QT_MOC_LITERAL(74, 4),  // "mask"
        QT_MOC_LITERAL(79, 11),  // "std::string"
        QT_MOC_LITERAL(91, 8),  // "filePath"
        QT_MOC_LITERAL(100, 17),  // "signalOpenCSVFile"
        QT_MOC_LITERAL(118, 14),  // "signalRejected"
        QT_MOC_LITERAL(133, 21),  // "slotSetAvailableTypes"
        QT_MOC_LITERAL(155, 34),  // "std::set<attribute::Attribute..."
        QT_MOC_LITERAL(190, 14),  // "availableTypes"
        QT_MOC_LITERAL(205, 18),  // "slotSetCSVFilePath"
        QT_MOC_LITERAL(224, 13),  // "slotSelectAll"
        QT_MOC_LITERAL(238, 22),  // "slotEmitSignalAccepted"
        QT_MOC_LITERAL(261, 25),  // "slotEmitSignalOpenCVSFile"
        QT_MOC_LITERAL(287, 22)   // "slotEmitSignalRejected"
    },
    "AttributeDialog",
    "signalAccepted",
    "",
    "std::set<attribute::AttributeType>&",
    "types",
    "mask",
    "std::string",
    "filePath",
    "signalOpenCSVFile",
    "signalRejected",
    "slotSetAvailableTypes",
    "std::set<attribute::AttributeType>",
    "availableTypes",
    "slotSetCSVFilePath",
    "slotSelectAll",
    "slotEmitSignalAccepted",
    "slotEmitSignalOpenCVSFile",
    "slotEmitSignalRejected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAttributeDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   68,    2, 0x06,    1 /* Public */,
       8,    0,   75,    2, 0x06,    5 /* Public */,
       9,    0,   76,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   77,    2, 0x0a,    7 /* Public */,
      13,    1,   80,    2, 0x0a,    9 /* Public */,
      14,    0,   83,    2, 0x0a,   11 /* Public */,
      15,    0,   84,    2, 0x08,   12 /* Private */,
      16,    0,   85,    2, 0x08,   13 /* Private */,
      17,    0,   86,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AttributeDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSAttributeDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAttributeDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAttributeDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AttributeDialog, std::true_type>,
        // method 'signalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::set<attribute::AttributeType> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'signalOpenCSVFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetAvailableTypes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::set<attribute::AttributeType> &, std::false_type>,
        // method 'slotSetCSVFilePath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotSelectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalOpenCVSFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AttributeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AttributeDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAccepted((*reinterpret_cast< std::add_pointer_t<std::set<attribute::AttributeType>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3]))); break;
        case 1: _t->signalOpenCSVFile(); break;
        case 2: _t->signalRejected(); break;
        case 3: _t->slotSetAvailableTypes((*reinterpret_cast< std::add_pointer_t<std::set<attribute::AttributeType>>>(_a[1]))); break;
        case 4: _t->slotSetCSVFilePath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->slotSelectAll(); break;
        case 6: _t->slotEmitSignalAccepted(); break;
        case 7: _t->slotEmitSignalOpenCVSFile(); break;
        case 8: _t->slotEmitSignalRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AttributeDialog::*)(std::set<attribute::AttributeType> & , int , std::string );
            if (_t _q_method = &AttributeDialog::signalAccepted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AttributeDialog::*)();
            if (_t _q_method = &AttributeDialog::signalOpenCSVFile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AttributeDialog::*)();
            if (_t _q_method = &AttributeDialog::signalRejected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *AttributeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttributeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAttributeDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AttributeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void AttributeDialog::signalAccepted(std::set<attribute::AttributeType> & _t1, int _t2, std::string _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AttributeDialog::signalOpenCSVFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AttributeDialog::signalRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
