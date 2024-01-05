/****************************************************************************
** Meta object code from reading C++ file 'clusteringuicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/clustering/clusteringuicontroller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clusteringuicontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS = QtMocHelpers::stringData(
    "ClusteringUIController",
    "signalClustered",
    "",
    "slotExecDialog",
    "sloDialogAccepted",
    "minPoints",
    "eps",
    "distFactor",
    "slotDialogRejected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[23];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[18];
    char stringdata5[10];
    char stringdata6[4];
    char stringdata7[11];
    char stringdata8[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS_t qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "ClusteringUIController"
        QT_MOC_LITERAL(23, 15),  // "signalClustered"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 14),  // "slotExecDialog"
        QT_MOC_LITERAL(55, 17),  // "sloDialogAccepted"
        QT_MOC_LITERAL(73, 9),  // "minPoints"
        QT_MOC_LITERAL(83, 3),  // "eps"
        QT_MOC_LITERAL(87, 10),  // "distFactor"
        QT_MOC_LITERAL(98, 18)   // "slotDialogRejected"
    },
    "ClusteringUIController",
    "signalClustered",
    "",
    "slotExecDialog",
    "sloDialogAccepted",
    "minPoints",
    "eps",
    "distFactor",
    "slotDialogRejected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSClusteringUIControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    3,   40,    2, 0x08,    3 /* Private */,
       8,    0,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int, QMetaType::Float, QMetaType::Float,    5,    6,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ClusteringUIController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSClusteringUIControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ClusteringUIController, std::true_type>,
        // method 'signalClustered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExecDialog'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sloDialogAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'slotDialogRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ClusteringUIController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClusteringUIController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalClustered(); break;
        case 1: { int _r = _t->slotExecDialog();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->sloDialogAccepted((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3]))); break;
        case 3: _t->slotDialogRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClusteringUIController::*)();
            if (_t _q_method = &ClusteringUIController::signalClustered; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ClusteringUIController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClusteringUIController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSClusteringUIControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClusteringUIController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ClusteringUIController::signalClustered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
