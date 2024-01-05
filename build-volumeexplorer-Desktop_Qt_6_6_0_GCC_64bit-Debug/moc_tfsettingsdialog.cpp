/****************************************************************************
** Meta object code from reading C++ file 'tfsettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/settings/tfsettingsdialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tfsettingsdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS = QtMocHelpers::stringData(
    "TFSettingsDialog",
    "signalAccepted",
    "",
    "size",
    "borderWidth",
    "zoomIncrement",
    "baseOpacity",
    "selectedOpacity",
    "unselectedOpacity",
    "pivotLabelEnabled",
    "signalRejected",
    "slotSetFields",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[17];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[12];
    char stringdata5[14];
    char stringdata6[12];
    char stringdata7[16];
    char stringdata8[18];
    char stringdata9[18];
    char stringdata10[15];
    char stringdata11[14];
    char stringdata12[23];
    char stringdata13[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS_t qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "TFSettingsDialog"
        QT_MOC_LITERAL(17, 14),  // "signalAccepted"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 4),  // "size"
        QT_MOC_LITERAL(38, 11),  // "borderWidth"
        QT_MOC_LITERAL(50, 13),  // "zoomIncrement"
        QT_MOC_LITERAL(64, 11),  // "baseOpacity"
        QT_MOC_LITERAL(76, 15),  // "selectedOpacity"
        QT_MOC_LITERAL(92, 17),  // "unselectedOpacity"
        QT_MOC_LITERAL(110, 17),  // "pivotLabelEnabled"
        QT_MOC_LITERAL(128, 14),  // "signalRejected"
        QT_MOC_LITERAL(143, 13),  // "slotSetFields"
        QT_MOC_LITERAL(157, 22),  // "slotEmitSignalAccepted"
        QT_MOC_LITERAL(180, 22)   // "slotEmitSignalRejected"
    },
    "TFSettingsDialog",
    "signalAccepted",
    "",
    "size",
    "borderWidth",
    "zoomIncrement",
    "baseOpacity",
    "selectedOpacity",
    "unselectedOpacity",
    "pivotLabelEnabled",
    "signalRejected",
    "slotSetFields",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTFSettingsDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    7,   44,    2, 0x06,    1 /* Public */,
      10,    0,   59,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    7,   60,    2, 0x0a,   10 /* Public */,
      12,    0,   75,    2, 0x08,   18 /* Private */,
      13,    0,   76,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Bool,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Bool,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TFSettingsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTFSettingsDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TFSettingsDialog, std::true_type>,
        // method 'signalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetFields'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotEmitSignalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TFSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TFSettingsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAccepted((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7]))); break;
        case 1: _t->signalRejected(); break;
        case 2: _t->slotSetFields((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7]))); break;
        case 3: _t->slotEmitSignalAccepted(); break;
        case 4: _t->slotEmitSignalRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TFSettingsDialog::*)(float , float , float , float , float , float , bool );
            if (_t _q_method = &TFSettingsDialog::signalAccepted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TFSettingsDialog::*)();
            if (_t _q_method = &TFSettingsDialog::signalRejected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *TFSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TFSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTFSettingsDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TFSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TFSettingsDialog::signalAccepted(float _t1, float _t2, float _t3, float _t4, float _t5, float _t6, bool _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TFSettingsDialog::signalRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
