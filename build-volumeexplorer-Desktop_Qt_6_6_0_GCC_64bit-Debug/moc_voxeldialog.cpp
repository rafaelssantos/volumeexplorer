/****************************************************************************
** Meta object code from reading C++ file 'voxeldialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/rendering/voxeldialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'voxeldialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSVoxelDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVoxelDialogENDCLASS = QtMocHelpers::stringData(
    "VoxelDialog",
    "signalAccepted",
    "",
    "x",
    "y",
    "z",
    "signalRejected",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVoxelDialogENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[2];
    char stringdata5[2];
    char stringdata6[15];
    char stringdata7[23];
    char stringdata8[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVoxelDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVoxelDialogENDCLASS_t qt_meta_stringdata_CLASSVoxelDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "VoxelDialog"
        QT_MOC_LITERAL(12, 14),  // "signalAccepted"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 1),  // "x"
        QT_MOC_LITERAL(30, 1),  // "y"
        QT_MOC_LITERAL(32, 1),  // "z"
        QT_MOC_LITERAL(34, 14),  // "signalRejected"
        QT_MOC_LITERAL(49, 22),  // "slotEmitSignalAccepted"
        QT_MOC_LITERAL(72, 22)   // "slotEmitSignalRejected"
    },
    "VoxelDialog",
    "signalAccepted",
    "",
    "x",
    "y",
    "z",
    "signalRejected",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVoxelDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   38,    2, 0x06,    1 /* Public */,
       6,    0,   45,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   46,    2, 0x08,    6 /* Private */,
       8,    0,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject VoxelDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSVoxelDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVoxelDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVoxelDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VoxelDialog, std::true_type>,
        // method 'signalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'signalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void VoxelDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VoxelDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAccepted((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3]))); break;
        case 1: _t->signalRejected(); break;
        case 2: _t->slotEmitSignalAccepted(); break;
        case 3: _t->slotEmitSignalRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VoxelDialog::*)(float , float , float );
            if (_t _q_method = &VoxelDialog::signalAccepted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VoxelDialog::*)();
            if (_t _q_method = &VoxelDialog::signalRejected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *VoxelDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VoxelDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVoxelDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VoxelDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void VoxelDialog::signalAccepted(float _t1, float _t2, float _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VoxelDialog::signalRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
