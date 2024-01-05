/****************************************************************************
** Meta object code from reading C++ file 'renderingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/rendering/renderingwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderingwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRenderingWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRenderingWindowENDCLASS = QtMocHelpers::stringData(
    "RenderingWindow",
    "signalReset",
    "",
    "signalUpdate",
    "signalOpenDataset",
    "signalHighQuality",
    "signalSettings",
    "signalTFDesigner",
    "signalScreenshot",
    "slotZoomIn",
    "slotZoomOut",
    "slotRotateXCounterclockwise",
    "slotRotateXClockwise",
    "slotRotateYCounterclockwise",
    "slotRotateYClockwise",
    "slotRotateZCounterclockwise",
    "slotRotateZClockwise",
    "slotEmitSignalOpenDataset",
    "slotEmitSignalSettings",
    "slotEmitSignalTFDesigner",
    "slotEmitSignalReset",
    "slotEmitSignalUpdate",
    "slotEmitSignalScreenshot",
    "slotEmitSignalHighQuality",
    "stateChanged",
    "slotDisplayAbout"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRenderingWindowENDCLASS_t {
    uint offsetsAndSizes[52];
    char stringdata0[16];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[18];
    char stringdata5[18];
    char stringdata6[15];
    char stringdata7[17];
    char stringdata8[17];
    char stringdata9[11];
    char stringdata10[12];
    char stringdata11[28];
    char stringdata12[21];
    char stringdata13[28];
    char stringdata14[21];
    char stringdata15[28];
    char stringdata16[21];
    char stringdata17[26];
    char stringdata18[23];
    char stringdata19[25];
    char stringdata20[20];
    char stringdata21[21];
    char stringdata22[25];
    char stringdata23[26];
    char stringdata24[13];
    char stringdata25[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRenderingWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRenderingWindowENDCLASS_t qt_meta_stringdata_CLASSRenderingWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "RenderingWindow"
        QT_MOC_LITERAL(16, 11),  // "signalReset"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 12),  // "signalUpdate"
        QT_MOC_LITERAL(42, 17),  // "signalOpenDataset"
        QT_MOC_LITERAL(60, 17),  // "signalHighQuality"
        QT_MOC_LITERAL(78, 14),  // "signalSettings"
        QT_MOC_LITERAL(93, 16),  // "signalTFDesigner"
        QT_MOC_LITERAL(110, 16),  // "signalScreenshot"
        QT_MOC_LITERAL(127, 10),  // "slotZoomIn"
        QT_MOC_LITERAL(138, 11),  // "slotZoomOut"
        QT_MOC_LITERAL(150, 27),  // "slotRotateXCounterclockwise"
        QT_MOC_LITERAL(178, 20),  // "slotRotateXClockwise"
        QT_MOC_LITERAL(199, 27),  // "slotRotateYCounterclockwise"
        QT_MOC_LITERAL(227, 20),  // "slotRotateYClockwise"
        QT_MOC_LITERAL(248, 27),  // "slotRotateZCounterclockwise"
        QT_MOC_LITERAL(276, 20),  // "slotRotateZClockwise"
        QT_MOC_LITERAL(297, 25),  // "slotEmitSignalOpenDataset"
        QT_MOC_LITERAL(323, 22),  // "slotEmitSignalSettings"
        QT_MOC_LITERAL(346, 24),  // "slotEmitSignalTFDesigner"
        QT_MOC_LITERAL(371, 19),  // "slotEmitSignalReset"
        QT_MOC_LITERAL(391, 20),  // "slotEmitSignalUpdate"
        QT_MOC_LITERAL(412, 24),  // "slotEmitSignalScreenshot"
        QT_MOC_LITERAL(437, 25),  // "slotEmitSignalHighQuality"
        QT_MOC_LITERAL(463, 12),  // "stateChanged"
        QT_MOC_LITERAL(476, 16)   // "slotDisplayAbout"
    },
    "RenderingWindow",
    "signalReset",
    "",
    "signalUpdate",
    "signalOpenDataset",
    "signalHighQuality",
    "signalSettings",
    "signalTFDesigner",
    "signalScreenshot",
    "slotZoomIn",
    "slotZoomOut",
    "slotRotateXCounterclockwise",
    "slotRotateXClockwise",
    "slotRotateYCounterclockwise",
    "slotRotateYClockwise",
    "slotRotateZCounterclockwise",
    "slotRotateZClockwise",
    "slotEmitSignalOpenDataset",
    "slotEmitSignalSettings",
    "slotEmitSignalTFDesigner",
    "slotEmitSignalReset",
    "slotEmitSignalUpdate",
    "slotEmitSignalScreenshot",
    "slotEmitSignalHighQuality",
    "stateChanged",
    "slotDisplayAbout"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRenderingWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x06,    1 /* Public */,
       3,    0,  153,    2, 0x06,    2 /* Public */,
       4,    0,  154,    2, 0x06,    3 /* Public */,
       5,    1,  155,    2, 0x06,    4 /* Public */,
       6,    0,  158,    2, 0x06,    6 /* Public */,
       7,    1,  159,    2, 0x06,    7 /* Public */,
       8,    0,  162,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,  163,    2, 0x08,   10 /* Private */,
      10,    0,  164,    2, 0x08,   11 /* Private */,
      11,    0,  165,    2, 0x08,   12 /* Private */,
      12,    0,  166,    2, 0x08,   13 /* Private */,
      13,    0,  167,    2, 0x08,   14 /* Private */,
      14,    0,  168,    2, 0x08,   15 /* Private */,
      15,    0,  169,    2, 0x08,   16 /* Private */,
      16,    0,  170,    2, 0x08,   17 /* Private */,
      17,    0,  171,    2, 0x08,   18 /* Private */,
      18,    0,  172,    2, 0x08,   19 /* Private */,
      19,    0,  173,    2, 0x08,   20 /* Private */,
      20,    0,  174,    2, 0x08,   21 /* Private */,
      21,    0,  175,    2, 0x08,   22 /* Private */,
      22,    0,  176,    2, 0x08,   23 /* Private */,
      23,    1,  177,    2, 0x08,   24 /* Private */,
      25,    0,  180,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject RenderingWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSRenderingWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRenderingWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRenderingWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RenderingWindow, std::true_type>,
        // method 'signalReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalOpenDataset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalHighQuality'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signalSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalTFDesigner'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotZoomIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotZoomOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRotateXCounterclockwise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRotateXClockwise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRotateYCounterclockwise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRotateYClockwise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRotateZCounterclockwise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRotateZClockwise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalOpenDataset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalTFDesigner'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalReset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalHighQuality'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotDisplayAbout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void RenderingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderingWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalReset(); break;
        case 1: _t->signalUpdate(); break;
        case 2: _t->signalOpenDataset(); break;
        case 3: _t->signalHighQuality((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->signalSettings(); break;
        case 5: _t->signalTFDesigner((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->signalScreenshot(); break;
        case 7: _t->slotZoomIn(); break;
        case 8: _t->slotZoomOut(); break;
        case 9: _t->slotRotateXCounterclockwise(); break;
        case 10: _t->slotRotateXClockwise(); break;
        case 11: _t->slotRotateYCounterclockwise(); break;
        case 12: _t->slotRotateYClockwise(); break;
        case 13: _t->slotRotateZCounterclockwise(); break;
        case 14: _t->slotRotateZClockwise(); break;
        case 15: _t->slotEmitSignalOpenDataset(); break;
        case 16: _t->slotEmitSignalSettings(); break;
        case 17: _t->slotEmitSignalTFDesigner(); break;
        case 18: _t->slotEmitSignalReset(); break;
        case 19: _t->slotEmitSignalUpdate(); break;
        case 20: _t->slotEmitSignalScreenshot(); break;
        case 21: _t->slotEmitSignalHighQuality((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->slotDisplayAbout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RenderingWindow::*)();
            if (_t _q_method = &RenderingWindow::signalReset; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RenderingWindow::*)();
            if (_t _q_method = &RenderingWindow::signalUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RenderingWindow::*)();
            if (_t _q_method = &RenderingWindow::signalOpenDataset; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RenderingWindow::*)(int );
            if (_t _q_method = &RenderingWindow::signalHighQuality; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RenderingWindow::*)();
            if (_t _q_method = &RenderingWindow::signalSettings; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (RenderingWindow::*)(bool );
            if (_t _q_method = &RenderingWindow::signalTFDesigner; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (RenderingWindow::*)();
            if (_t _q_method = &RenderingWindow::signalScreenshot; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *RenderingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRenderingWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RenderingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void RenderingWindow::signalReset()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RenderingWindow::signalUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RenderingWindow::signalOpenDataset()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void RenderingWindow::signalHighQuality(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RenderingWindow::signalSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void RenderingWindow::signalTFDesigner(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void RenderingWindow::signalScreenshot()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
