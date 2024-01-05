/****************************************************************************
** Meta object code from reading C++ file 'observerfiledialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/common/observerfiledialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observerfiledialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSObserverFileDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSObserverFileDialogENDCLASS = QtMocHelpers::stringData(
    "ObserverFileDialog",
    "signalAccepted",
    "",
    "std::string",
    "file_path",
    "signalRejected",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSObserverFileDialogENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[19];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[10];
    char stringdata5[15];
    char stringdata6[23];
    char stringdata7[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSObserverFileDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSObserverFileDialogENDCLASS_t qt_meta_stringdata_CLASSObserverFileDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "ObserverFileDialog"
        QT_MOC_LITERAL(19, 14),  // "signalAccepted"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 11),  // "std::string"
        QT_MOC_LITERAL(47, 9),  // "file_path"
        QT_MOC_LITERAL(57, 14),  // "signalRejected"
        QT_MOC_LITERAL(72, 22),  // "slotEmitSignalAccepted"
        QT_MOC_LITERAL(95, 22)   // "slotEmitSignalRejected"
    },
    "ObserverFileDialog",
    "signalAccepted",
    "",
    "std::string",
    "file_path",
    "signalRejected",
    "slotEmitSignalAccepted",
    "slotEmitSignalRejected"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSObserverFileDialogENDCLASS[] = {

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
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    0,   41,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ObserverFileDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QFileDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSObserverFileDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSObserverFileDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSObserverFileDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ObserverFileDialog, std::true_type>,
        // method 'signalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::string &, std::false_type>,
        // method 'signalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalAccepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalRejected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ObserverFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ObserverFileDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalAccepted((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 1: _t->signalRejected(); break;
        case 2: _t->slotEmitSignalAccepted(); break;
        case 3: _t->slotEmitSignalRejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ObserverFileDialog::*)(const std::string & );
            if (_t _q_method = &ObserverFileDialog::signalAccepted; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ObserverFileDialog::*)();
            if (_t _q_method = &ObserverFileDialog::signalRejected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ObserverFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObserverFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSObserverFileDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QFileDialog::qt_metacast(_clname);
}

int ObserverFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFileDialog::qt_metacall(_c, _id, _a);
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
void ObserverFileDialog::signalAccepted(const std::string & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ObserverFileDialog::signalRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
