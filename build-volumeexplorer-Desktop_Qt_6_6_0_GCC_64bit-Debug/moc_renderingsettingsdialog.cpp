/****************************************************************************
** Meta object code from reading C++ file 'renderingsettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/rendering/settings/renderingsettingsdialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderingsettingsdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS = QtMocHelpers::stringData(
    "RenderingSettingsDialog",
    "signalAccepted",
    "",
    "dim3",
    "blockDim",
    "devSyncronize",
    "zoomIncrement",
    "rotationDegree",
    "maxOpacity",
    "step",
    "maxNumberOfSteps",
    "transfer_function::Interpolation",
    "filterType",
    "illuminationEnabled",
    "ambient",
    "diffuse",
    "specular",
    "power",
    "signalRejected",
    "slotSetFields",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected",
    "slotIlluminationEnabled",
    "enabled"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS_t {
    uint offsetsAndSizes[48];
    char stringdata0[24];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[9];
    char stringdata5[14];
    char stringdata6[14];
    char stringdata7[15];
    char stringdata8[11];
    char stringdata9[5];
    char stringdata10[17];
    char stringdata11[33];
    char stringdata12[11];
    char stringdata13[20];
    char stringdata14[8];
    char stringdata15[8];
    char stringdata16[9];
    char stringdata17[6];
    char stringdata18[15];
    char stringdata19[14];
    char stringdata20[23];
    char stringdata21[23];
    char stringdata22[24];
    char stringdata23[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS_t qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "RenderingSettingsDialog"
        QT_MOC_LITERAL(24, 14),  // "signalAccepted"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 4),  // "dim3"
        QT_MOC_LITERAL(45, 8),  // "blockDim"
        QT_MOC_LITERAL(54, 13),  // "devSyncronize"
        QT_MOC_LITERAL(68, 13),  // "zoomIncrement"
        QT_MOC_LITERAL(82, 14),  // "rotationDegree"
        QT_MOC_LITERAL(97, 10),  // "maxOpacity"
        QT_MOC_LITERAL(108, 4),  // "step"
        QT_MOC_LITERAL(113, 16),  // "maxNumberOfSteps"
        QT_MOC_LITERAL(130, 32),  // "transfer_function::Interpolation"
        QT_MOC_LITERAL(163, 10),  // "filterType"
        QT_MOC_LITERAL(174, 19),  // "illuminationEnabled"
        QT_MOC_LITERAL(194, 7),  // "ambient"
        QT_MOC_LITERAL(202, 7),  // "diffuse"
        QT_MOC_LITERAL(210, 8),  // "specular"
        QT_MOC_LITERAL(219, 5),  // "power"
        QT_MOC_LITERAL(225, 14),  // "signalRejected"
        QT_MOC_LITERAL(240, 13),  // "slotSetFields"
        QT_MOC_LITERAL(254, 22),  // "slotEmitSignalAccepted"
        QT_MOC_LITERAL(277, 22),  // "slotEmitSignalRejected"
        QT_MOC_LITERAL(300, 23),  // "slotIlluminationEnabled"
        QT_MOC_LITERAL(324, 7)   // "enabled"
    },
    "RenderingSettingsDialog",
    "signalAccepted",
    "",
    "dim3",
    "blockDim",
    "devSyncronize",
    "zoomIncrement",
    "rotationDegree",
    "maxOpacity",
    "step",
    "maxNumberOfSteps",
    "transfer_function::Interpolation",
    "filterType",
    "illuminationEnabled",
    "ambient",
    "diffuse",
    "specular",
    "power",
    "signalRejected",
    "slotSetFields",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected",
    "slotIlluminationEnabled",
    "enabled"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRenderingSettingsDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,   13,   50,    2, 0x06,    1 /* Public */,
      18,    0,   77,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      19,   13,   78,    2, 0x0a,   16 /* Public */,
      20,    0,  105,    2, 0x08,   30 /* Private */,
      21,    0,  106,    2, 0x08,   31 /* Private */,
      22,    1,  107,    2, 0x08,   32 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::UInt, 0x80000000 | 11, QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,    4,    5,    6,    7,    8,    9,   10,   12,   13,   14,   15,   16,   17,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::UInt, 0x80000000 | 11, QMetaType::Bool, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int,    4,    5,    6,    7,    8,    9,   10,   12,   13,   14,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   23,

       0        // eod
};

Q_CONSTINIT const QMetaObject RenderingSettingsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRenderingSettingsDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RenderingSettingsDialog, std::true_type>,
        // method 'signalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<dim3, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned , std::false_type>,
        QtPrivate::TypeAndForceComplete<transfer_function::Interpolation, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetFields'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<dim3, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<unsigned , std::false_type>,
        QtPrivate::TypeAndForceComplete<transfer_function::Interpolation, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotEmitSignalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotIlluminationEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void RenderingSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderingSettingsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAccepted((*reinterpret_cast< std::add_pointer_t<dim3>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<transfer_function::Interpolation>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[13]))); break;
        case 1: _t->signalRejected(); break;
        case 2: _t->slotSetFields((*reinterpret_cast< std::add_pointer_t<dim3>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<transfer_function::Interpolation>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[11])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[12])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[13]))); break;
        case 3: _t->slotEmitSignalAccepted(); break;
        case 4: _t->slotEmitSignalRejected(); break;
        case 5: _t->slotIlluminationEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RenderingSettingsDialog::*)(dim3 , bool , float , float , float , float , unsigned  , transfer_function::Interpolation , bool , float , float , float , int );
            if (_t _q_method = &RenderingSettingsDialog::signalAccepted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RenderingSettingsDialog::*)();
            if (_t _q_method = &RenderingSettingsDialog::signalRejected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *RenderingSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderingSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRenderingSettingsDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RenderingSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RenderingSettingsDialog::signalAccepted(dim3 _t1, bool _t2, float _t3, float _t4, float _t5, float _t6, unsigned  _t7, transfer_function::Interpolation _t8, bool _t9, float _t10, float _t11, float _t12, int _t13)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t12))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t13))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RenderingSettingsDialog::signalRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
