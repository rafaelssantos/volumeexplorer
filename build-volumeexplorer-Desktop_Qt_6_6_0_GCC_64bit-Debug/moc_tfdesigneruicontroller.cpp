/****************************************************************************
** Meta object code from reading C++ file 'tfdesigneruicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/tfdesigneruicontroller.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tfdesigneruicontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS = QtMocHelpers::stringData(
    "TFDesignerUIController",
    "slotSetWindowVisible",
    "",
    "visible",
    "slotUpdate",
    "slotUnselectAll",
    "slotErasePlot",
    "slotPlot",
    "slotScreenshot",
    "path",
    "slotPivotScreenshot",
    "slotClusterScreenshot",
    "slotGroupScreenshot",
    "slotResetColor",
    "slotResetObserver",
    "slotSelectColor",
    "slotColorSelected",
    "color",
    "slotResize",
    "width",
    "height",
    "slotZoom",
    "graphics_utils::Zoom",
    "zoom",
    "slotSelect",
    "selected",
    "index",
    "slotSelectionMode",
    "transfer_function::SelectionMode",
    "selectionMode",
    "slotGroup",
    "slotUngroup",
    "slotExecScreenshotDialog",
    "slotExecScreenshotDialogForPivots",
    "slotExecScreenshotDialogForClusters",
    "slotExecScreenshotDialogForGroups",
    "slotNext",
    "slotPrevious",
    "slotSetLogWindowVisible"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS_t {
    uint offsetsAndSizes[78];
    char stringdata0[23];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[11];
    char stringdata5[16];
    char stringdata6[14];
    char stringdata7[9];
    char stringdata8[15];
    char stringdata9[5];
    char stringdata10[20];
    char stringdata11[22];
    char stringdata12[20];
    char stringdata13[15];
    char stringdata14[18];
    char stringdata15[16];
    char stringdata16[18];
    char stringdata17[6];
    char stringdata18[11];
    char stringdata19[6];
    char stringdata20[7];
    char stringdata21[9];
    char stringdata22[21];
    char stringdata23[5];
    char stringdata24[11];
    char stringdata25[9];
    char stringdata26[6];
    char stringdata27[18];
    char stringdata28[33];
    char stringdata29[14];
    char stringdata30[10];
    char stringdata31[12];
    char stringdata32[25];
    char stringdata33[34];
    char stringdata34[36];
    char stringdata35[34];
    char stringdata36[9];
    char stringdata37[13];
    char stringdata38[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS_t qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "TFDesignerUIController"
        QT_MOC_LITERAL(23, 20),  // "slotSetWindowVisible"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 7),  // "visible"
        QT_MOC_LITERAL(53, 10),  // "slotUpdate"
        QT_MOC_LITERAL(64, 15),  // "slotUnselectAll"
        QT_MOC_LITERAL(80, 13),  // "slotErasePlot"
        QT_MOC_LITERAL(94, 8),  // "slotPlot"
        QT_MOC_LITERAL(103, 14),  // "slotScreenshot"
        QT_MOC_LITERAL(118, 4),  // "path"
        QT_MOC_LITERAL(123, 19),  // "slotPivotScreenshot"
        QT_MOC_LITERAL(143, 21),  // "slotClusterScreenshot"
        QT_MOC_LITERAL(165, 19),  // "slotGroupScreenshot"
        QT_MOC_LITERAL(185, 14),  // "slotResetColor"
        QT_MOC_LITERAL(200, 17),  // "slotResetObserver"
        QT_MOC_LITERAL(218, 15),  // "slotSelectColor"
        QT_MOC_LITERAL(234, 17),  // "slotColorSelected"
        QT_MOC_LITERAL(252, 5),  // "color"
        QT_MOC_LITERAL(258, 10),  // "slotResize"
        QT_MOC_LITERAL(269, 5),  // "width"
        QT_MOC_LITERAL(275, 6),  // "height"
        QT_MOC_LITERAL(282, 8),  // "slotZoom"
        QT_MOC_LITERAL(291, 20),  // "graphics_utils::Zoom"
        QT_MOC_LITERAL(312, 4),  // "zoom"
        QT_MOC_LITERAL(317, 10),  // "slotSelect"
        QT_MOC_LITERAL(328, 8),  // "selected"
        QT_MOC_LITERAL(337, 5),  // "index"
        QT_MOC_LITERAL(343, 17),  // "slotSelectionMode"
        QT_MOC_LITERAL(361, 32),  // "transfer_function::SelectionMode"
        QT_MOC_LITERAL(394, 13),  // "selectionMode"
        QT_MOC_LITERAL(408, 9),  // "slotGroup"
        QT_MOC_LITERAL(418, 11),  // "slotUngroup"
        QT_MOC_LITERAL(430, 24),  // "slotExecScreenshotDialog"
        QT_MOC_LITERAL(455, 33),  // "slotExecScreenshotDialogForPi..."
        QT_MOC_LITERAL(489, 35),  // "slotExecScreenshotDialogForCl..."
        QT_MOC_LITERAL(525, 33),  // "slotExecScreenshotDialogForGr..."
        QT_MOC_LITERAL(559, 8),  // "slotNext"
        QT_MOC_LITERAL(568, 12),  // "slotPrevious"
        QT_MOC_LITERAL(581, 23)   // "slotSetLogWindowVisible"
    },
    "TFDesignerUIController",
    "slotSetWindowVisible",
    "",
    "visible",
    "slotUpdate",
    "slotUnselectAll",
    "slotErasePlot",
    "slotPlot",
    "slotScreenshot",
    "path",
    "slotPivotScreenshot",
    "slotClusterScreenshot",
    "slotGroupScreenshot",
    "slotResetColor",
    "slotResetObserver",
    "slotSelectColor",
    "slotColorSelected",
    "color",
    "slotResize",
    "width",
    "height",
    "slotZoom",
    "graphics_utils::Zoom",
    "zoom",
    "slotSelect",
    "selected",
    "index",
    "slotSelectionMode",
    "transfer_function::SelectionMode",
    "selectionMode",
    "slotGroup",
    "slotUngroup",
    "slotExecScreenshotDialog",
    "slotExecScreenshotDialogForPivots",
    "slotExecScreenshotDialogForClusters",
    "slotExecScreenshotDialogForGroups",
    "slotNext",
    "slotPrevious",
    "slotSetLogWindowVisible"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTFDesignerUIControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  182,    2, 0x0a,    1 /* Public */,
       1,    0,  185,    2, 0x2a,    3 /* Public | MethodCloned */,
       4,    0,  186,    2, 0x0a,    4 /* Public */,
       5,    0,  187,    2, 0x0a,    5 /* Public */,
       6,    0,  188,    2, 0x0a,    6 /* Public */,
       7,    0,  189,    2, 0x0a,    7 /* Public */,
       8,    1,  190,    2, 0x0a,    8 /* Public */,
      10,    1,  193,    2, 0x0a,   10 /* Public */,
      11,    1,  196,    2, 0x0a,   12 /* Public */,
      12,    1,  199,    2, 0x0a,   14 /* Public */,
      13,    0,  202,    2, 0x08,   16 /* Private */,
      14,    0,  203,    2, 0x08,   17 /* Private */,
      15,    0,  204,    2, 0x08,   18 /* Private */,
      16,    1,  205,    2, 0x08,   19 /* Private */,
      18,    2,  208,    2, 0x08,   21 /* Private */,
      21,    1,  213,    2, 0x08,   24 /* Private */,
      24,    2,  216,    2, 0x08,   26 /* Private */,
      27,    1,  221,    2, 0x08,   29 /* Private */,
      30,    0,  224,    2, 0x08,   31 /* Private */,
      31,    0,  225,    2, 0x08,   32 /* Private */,
      32,    0,  226,    2, 0x08,   33 /* Private */,
      33,    0,  227,    2, 0x08,   34 /* Private */,
      34,    0,  228,    2, 0x08,   35 /* Private */,
      35,    0,  229,    2, 0x08,   36 /* Private */,
      36,    0,  230,    2, 0x08,   37 /* Private */,
      37,    0,  231,    2, 0x08,   38 /* Private */,
      38,    1,  232,    2, 0x08,   39 /* Private */,
      38,    0,  235,    2, 0x28,   41 /* Private | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   25,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TFDesignerUIController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTFDesignerUIControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TFDesignerUIController, std::true_type>,
        // method 'slotSetWindowVisible'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotSetWindowVisible'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotUnselectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotErasePlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotPlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotPivotScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotClusterScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotGroupScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotResetColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotResetObserver'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSelectColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotColorSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'slotResize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotZoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<graphics_utils::Zoom, std::false_type>,
        // method 'slotSelect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotSelectionMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<transfer_function::SelectionMode, std::false_type>,
        // method 'slotGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotUngroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExecScreenshotDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExecScreenshotDialogForPivots'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExecScreenshotDialogForClusters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExecScreenshotDialogForGroups'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotNext'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotPrevious'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetLogWindowVisible'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotSetLogWindowVisible'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TFDesignerUIController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TFDesignerUIController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotSetWindowVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->slotSetWindowVisible(); break;
        case 2: _t->slotUpdate(); break;
        case 3: _t->slotUnselectAll(); break;
        case 4: _t->slotErasePlot(); break;
        case 5: _t->slotPlot(); break;
        case 6: _t->slotScreenshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->slotPivotScreenshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->slotClusterScreenshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->slotGroupScreenshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->slotResetColor(); break;
        case 11: _t->slotResetObserver(); break;
        case 12: _t->slotSelectColor(); break;
        case 13: _t->slotColorSelected((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 14: _t->slotResize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 15: _t->slotZoom((*reinterpret_cast< std::add_pointer_t<graphics_utils::Zoom>>(_a[1]))); break;
        case 16: _t->slotSelect((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 17: _t->slotSelectionMode((*reinterpret_cast< std::add_pointer_t<transfer_function::SelectionMode>>(_a[1]))); break;
        case 18: _t->slotGroup(); break;
        case 19: _t->slotUngroup(); break;
        case 20: _t->slotExecScreenshotDialog(); break;
        case 21: _t->slotExecScreenshotDialogForPivots(); break;
        case 22: _t->slotExecScreenshotDialogForClusters(); break;
        case 23: _t->slotExecScreenshotDialogForGroups(); break;
        case 24: _t->slotNext(); break;
        case 25: _t->slotPrevious(); break;
        case 26: _t->slotSetLogWindowVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 27: _t->slotSetLogWindowVisible(); break;
        default: ;
        }
    }
}

const QMetaObject *TFDesignerUIController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TFDesignerUIController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTFDesignerUIControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TFDesignerUIController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 28;
    }
    return _id;
}
QT_WARNING_POP
