/****************************************************************************
** Meta object code from reading C++ file 'renderinguicontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/rendering/renderinguicontroller.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderinguicontroller.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS = QtMocHelpers::stringData(
    "RenderingUIController",
    "slotRender",
    "",
    "width",
    "height",
    "slotRegisterGlPBOAsResource",
    "GLuint",
    "pbo",
    "slotUnregisterGlPBOAsResource",
    "slotSetWindowVisible",
    "visible",
    "slotZoom",
    "graphics_utils::Zoom",
    "zoom",
    "slotRotate",
    "graphics_utils::RotationAxis",
    "axis",
    "graphics_utils::RotationSense",
    "sense",
    "slotUpdate",
    "slotResetViewer",
    "slotExecScreenshotDialog",
    "slotExportScreenshot",
    "path",
    "slotSetDatasetFilesPath",
    "std::list<std::string>",
    "filesPath",
    "std::string",
    "dirPath",
    "slotSetVolumeSpacing",
    "x",
    "y",
    "z",
    "slotExecOpenDatasetDialog"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS_t {
    uint offsetsAndSizes[68];
    char stringdata0[22];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[7];
    char stringdata5[28];
    char stringdata6[7];
    char stringdata7[4];
    char stringdata8[30];
    char stringdata9[21];
    char stringdata10[8];
    char stringdata11[9];
    char stringdata12[21];
    char stringdata13[5];
    char stringdata14[11];
    char stringdata15[29];
    char stringdata16[5];
    char stringdata17[30];
    char stringdata18[6];
    char stringdata19[11];
    char stringdata20[16];
    char stringdata21[25];
    char stringdata22[21];
    char stringdata23[5];
    char stringdata24[24];
    char stringdata25[23];
    char stringdata26[10];
    char stringdata27[12];
    char stringdata28[8];
    char stringdata29[21];
    char stringdata30[2];
    char stringdata31[2];
    char stringdata32[2];
    char stringdata33[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS_t qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "RenderingUIController"
        QT_MOC_LITERAL(22, 10),  // "slotRender"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 5),  // "width"
        QT_MOC_LITERAL(40, 6),  // "height"
        QT_MOC_LITERAL(47, 27),  // "slotRegisterGlPBOAsResource"
        QT_MOC_LITERAL(75, 6),  // "GLuint"
        QT_MOC_LITERAL(82, 3),  // "pbo"
        QT_MOC_LITERAL(86, 29),  // "slotUnregisterGlPBOAsResource"
        QT_MOC_LITERAL(116, 20),  // "slotSetWindowVisible"
        QT_MOC_LITERAL(137, 7),  // "visible"
        QT_MOC_LITERAL(145, 8),  // "slotZoom"
        QT_MOC_LITERAL(154, 20),  // "graphics_utils::Zoom"
        QT_MOC_LITERAL(175, 4),  // "zoom"
        QT_MOC_LITERAL(180, 10),  // "slotRotate"
        QT_MOC_LITERAL(191, 28),  // "graphics_utils::RotationAxis"
        QT_MOC_LITERAL(220, 4),  // "axis"
        QT_MOC_LITERAL(225, 29),  // "graphics_utils::RotationSense"
        QT_MOC_LITERAL(255, 5),  // "sense"
        QT_MOC_LITERAL(261, 10),  // "slotUpdate"
        QT_MOC_LITERAL(272, 15),  // "slotResetViewer"
        QT_MOC_LITERAL(288, 24),  // "slotExecScreenshotDialog"
        QT_MOC_LITERAL(313, 20),  // "slotExportScreenshot"
        QT_MOC_LITERAL(334, 4),  // "path"
        QT_MOC_LITERAL(339, 23),  // "slotSetDatasetFilesPath"
        QT_MOC_LITERAL(363, 22),  // "std::list<std::string>"
        QT_MOC_LITERAL(386, 9),  // "filesPath"
        QT_MOC_LITERAL(396, 11),  // "std::string"
        QT_MOC_LITERAL(408, 7),  // "dirPath"
        QT_MOC_LITERAL(416, 20),  // "slotSetVolumeSpacing"
        QT_MOC_LITERAL(437, 1),  // "x"
        QT_MOC_LITERAL(439, 1),  // "y"
        QT_MOC_LITERAL(441, 1),  // "z"
        QT_MOC_LITERAL(443, 25)   // "slotExecOpenDatasetDialog"
    },
    "RenderingUIController",
    "slotRender",
    "",
    "width",
    "height",
    "slotRegisterGlPBOAsResource",
    "GLuint",
    "pbo",
    "slotUnregisterGlPBOAsResource",
    "slotSetWindowVisible",
    "visible",
    "slotZoom",
    "graphics_utils::Zoom",
    "zoom",
    "slotRotate",
    "graphics_utils::RotationAxis",
    "axis",
    "graphics_utils::RotationSense",
    "sense",
    "slotUpdate",
    "slotResetViewer",
    "slotExecScreenshotDialog",
    "slotExportScreenshot",
    "path",
    "slotSetDatasetFilesPath",
    "std::list<std::string>",
    "filesPath",
    "std::string",
    "dirPath",
    "slotSetVolumeSpacing",
    "x",
    "y",
    "z",
    "slotExecOpenDatasetDialog"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRenderingUIControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  104,    2, 0x0a,    1 /* Public */,
       1,    0,  109,    2, 0x0a,    4 /* Public */,
       5,    1,  110,    2, 0x0a,    5 /* Public */,
       8,    0,  113,    2, 0x0a,    7 /* Public */,
       9,    1,  114,    2, 0x0a,    8 /* Public */,
       9,    0,  117,    2, 0x2a,   10 /* Public | MethodCloned */,
      11,    1,  118,    2, 0x0a,   11 /* Public */,
      14,    2,  121,    2, 0x0a,   13 /* Public */,
      19,    0,  126,    2, 0x0a,   16 /* Public */,
      20,    0,  127,    2, 0x0a,   17 /* Public */,
      21,    0,  128,    2, 0x0a,   18 /* Public */,
      22,    1,  129,    2, 0x0a,   19 /* Public */,
      24,    2,  132,    2, 0x08,   21 /* Private */,
      29,    3,  137,    2, 0x08,   24 /* Private */,
      33,    0,  144,    2, 0x08,   28 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, 0x80000000 | 25, 0x80000000 | 27,   26,   28,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   30,   31,   32,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject RenderingUIController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRenderingUIControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RenderingUIController, std::true_type>,
        // method 'slotRender'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slotRender'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotRegisterGlPBOAsResource'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GLuint, std::false_type>,
        // method 'slotUnregisterGlPBOAsResource'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotSetWindowVisible'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'slotSetWindowVisible'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotZoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<graphics_utils::Zoom, std::false_type>,
        // method 'slotRotate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<graphics_utils::RotationAxis, std::false_type>,
        QtPrivate::TypeAndForceComplete<graphics_utils::RotationSense, std::false_type>,
        // method 'slotUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotResetViewer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExecScreenshotDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotExportScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slotSetDatasetFilesPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::list<std::string>, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::string, std::false_type>,
        // method 'slotSetVolumeSpacing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'slotExecOpenDatasetDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void RenderingUIController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderingUIController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotRender((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->slotRender(); break;
        case 2: _t->slotRegisterGlPBOAsResource((*reinterpret_cast< std::add_pointer_t<GLuint>>(_a[1]))); break;
        case 3: _t->slotUnregisterGlPBOAsResource(); break;
        case 4: _t->slotSetWindowVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->slotSetWindowVisible(); break;
        case 6: _t->slotZoom((*reinterpret_cast< std::add_pointer_t<graphics_utils::Zoom>>(_a[1]))); break;
        case 7: _t->slotRotate((*reinterpret_cast< std::add_pointer_t<graphics_utils::RotationAxis>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<graphics_utils::RotationSense>>(_a[2]))); break;
        case 8: _t->slotUpdate(); break;
        case 9: _t->slotResetViewer(); break;
        case 10: _t->slotExecScreenshotDialog(); break;
        case 11: _t->slotExportScreenshot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->slotSetDatasetFilesPath((*reinterpret_cast< std::add_pointer_t<std::list<std::string>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<std::string>>(_a[2]))); break;
        case 13: _t->slotSetVolumeSpacing((*reinterpret_cast< std::add_pointer_t<float>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[3]))); break;
        case 14: _t->slotExecOpenDatasetDialog(); break;
        default: ;
        }
    }
}

const QMetaObject *RenderingUIController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderingUIController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRenderingUIControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RenderingUIController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
