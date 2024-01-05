/****************************************************************************
** Meta object code from reading C++ file 'tfsettingsuicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/settings/tfsettingsuicontroller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tfsettingsuicontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS = QtMocHelpers::stringData(
    "TFSettingsUiController",
    "slotExecDialog",
    "",
    "slotSettingsDialogAccepted",
    "minDiameter",
    "borderWidth",
    "zoomIncrement",
    "baseOpacity",
    "selectedOpacity",
    "unselectedOpacity",
    "pivotLabelEnabled",
    "slotSettingsDialogRejected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[23];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[12];
    char stringdata5[12];
    char stringdata6[14];
    char stringdata7[12];
    char stringdata8[16];
    char stringdata9[18];
    char stringdata10[18];
    char stringdata11[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS_t qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "TFSettingsUiController"
        QT_MOC_LITERAL(23, 14),  // "slotExecDialog"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 26),  // "slotSettingsDialogAccepted"
        QT_MOC_LITERAL(66, 11),  // "minDiameter"
        QT_MOC_LITERAL(78, 11),  // "borderWidth"
        QT_MOC_LITERAL(90, 13),  // "zoomIncrement"
        QT_MOC_LITERAL(104, 11),  // "baseOpacity"
        QT_MOC_LITERAL(116, 15),  // "selectedOpacity"
        QT_MOC_LITERAL(132, 17),  // "unselectedOpacity"
        QT_MOC_LITERAL(150, 17),  // "pivotLabelEnabled"
        QT_MOC_LITERAL(168, 26)   // "slotSettingsDialogRejected"
    },
    "TFSettingsUiController",
    "slotExecDialog",
    "",
    "slotSettingsDialogAccepted",
    "minDiameter",
    "borderWidth",
    "zoomIncrement",
    "baseOpacity",
    "selectedOpacity",
    "unselectedOpacity",
    "pivotLabelEnabled",
    "slotSettingsDialogRejected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTFSettingsUiControllerENDCLASS[] = {

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
       3,    7,   33,    2, 0x08,    2 /* Private */,
      11,    0,   48,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Bool,    4,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TFSettingsUiController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTFSettingsUiControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TFSettingsUiController, std::true_type>,
        // method 'slotExecDialog'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotSettingsDialogAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotSettingsDialogRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TFSettingsUiController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TFSettingsUiController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->slotExecDialog();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->slotSettingsDialogAccepted((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7]))); break;
        case 2: _t->slotSettingsDialogRejected(); break;
        default: ;
        }
    }
}

const QMetaObject *TFSettingsUiController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TFSettingsUiController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTFSettingsUiControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TFSettingsUiController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
