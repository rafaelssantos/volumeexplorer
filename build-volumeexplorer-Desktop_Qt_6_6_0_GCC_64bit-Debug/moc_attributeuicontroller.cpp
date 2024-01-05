/****************************************************************************
** Meta object code from reading C++ file 'attributeuicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/attribute/attributeuicontroller.h"
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
#error "The header file 'attributeuicontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS = QtMocHelpers::stringData(
    "AttributeUIController",
    "slotExecAttributeDialog",
    "",
    "slotExecCSVFileDialog",
    "slotDialogAccepted",
    "std::set<attribute::AttributeType>&",
    "types",
    "mask",
    "std::string",
    "filePath"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[22];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[19];
    char stringdata5[36];
    char stringdata6[6];
    char stringdata7[5];
    char stringdata8[12];
    char stringdata9[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS_t qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "AttributeUIController"
        QT_MOC_LITERAL(22, 23),  // "slotExecAttributeDialog"
        QT_MOC_LITERAL(46, 0),  // ""
        QT_MOC_LITERAL(47, 21),  // "slotExecCSVFileDialog"
        QT_MOC_LITERAL(69, 18),  // "slotDialogAccepted"
        QT_MOC_LITERAL(88, 35),  // "std::set<attribute::Attribute..."
        QT_MOC_LITERAL(124, 5),  // "types"
        QT_MOC_LITERAL(130, 4),  // "mask"
        QT_MOC_LITERAL(135, 11),  // "std::string"
        QT_MOC_LITERAL(147, 8)   // "filePath"
    },
    "AttributeUIController",
    "slotExecAttributeDialog",
    "",
    "slotExecCSVFileDialog",
    "slotDialogAccepted",
    "std::set<attribute::AttributeType>&",
    "types",
    "mask",
    "std::string",
    "filePath"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAttributeUIControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x0a,    1 /* Public */,
       3,    0,   33,    2, 0x0a,    2 /* Public */,
       4,    3,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int, 0x80000000 | 8,    6,    7,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject AttributeUIController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAttributeUIControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AttributeUIController, std::true_type>,
        // method 'slotExecAttributeDialog'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotExecCSVFileDialog'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotDialogAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::set<attribute::AttributeType> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>
    >,
    nullptr
} };

void AttributeUIController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AttributeUIController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->slotExecAttributeDialog();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->slotExecCSVFileDialog();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->slotDialogAccepted((*reinterpret_cast< std::add_pointer_t<std::set<attribute::AttributeType>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject *AttributeUIController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttributeUIController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAttributeUIControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AttributeUIController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
