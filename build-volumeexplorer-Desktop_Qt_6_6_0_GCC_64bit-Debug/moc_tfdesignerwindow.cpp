/****************************************************************************
** Meta object code from reading C++ file 'tfdesignerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ui/transfer_function/tfdesignerwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tfdesignerwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS = QtMocHelpers::stringData(
    "TFDesignerWindow",
    "signalLeft",
    "",
    "signalRight",
    "signalZoom",
    "graphics_utils::Zoom",
    "zoom",
    "signalSelectionModeChanged",
    "transfer_function::SelectionMode",
    "selectionMode",
    "signalClustering",
    "signalSettingsDialog",
    "signalFeaturesExtraction",
    "signalUnselectAll",
    "signalUpdate",
    "signalRestorePos",
    "signalRestoreColor",
    "signalShowRenderingWindow",
    "signalColorChoose",
    "signalBenchmarkEnabled",
    "enabled",
    "signalGroup",
    "signalUngroup",
    "signalScreenshot",
    "signalScreenshotForPivots",
    "signalScreenshotForClusters",
    "signalScreenshotForGroups",
    "signalSaveViewerPos",
    "signalLoadViewerPos",
    "signalSaveTFDesign",
    "signalLoadTFDesign",
    "signalShowLogWindow",
    "slotEmitSignalFeaturesExtraction",
    "slotEmitSignalClustering",
    "slotEmitSignalSettingsDialog",
    "slotEmitSignalUnselectAll",
    "slotEmitSignalResetObserver",
    "slotEmitSignalResetColor",
    "slotEmitSignalUpdate",
    "slotEmitSignalZoomIn",
    "slotEmitSignalZoomOut",
    "slotEmitSignalRight",
    "slotEmitSignalLeft",
    "slotEmitSignalShowRenderingWindow",
    "slotEmitSignalColorChoose",
    "slotEmitSignalPointSelection",
    "slotEmitSignalClusterSelection",
    "slotEmitSignalGroupSelection",
    "slotEmitSignalGroup",
    "slotEmitSignalUngroup",
    "slotEmitSignalScreenshot",
    "slotEmitSignalScreenshotForPivots",
    "slotEmitSignalScreenshotForClusters",
    "slotEmitSignalScreenshotForGroups",
    "slotEmitSignalShowLogWindow"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS_t {
    uint offsetsAndSizes[110];
    char stringdata0[17];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[11];
    char stringdata5[21];
    char stringdata6[5];
    char stringdata7[27];
    char stringdata8[33];
    char stringdata9[14];
    char stringdata10[17];
    char stringdata11[21];
    char stringdata12[25];
    char stringdata13[18];
    char stringdata14[13];
    char stringdata15[17];
    char stringdata16[19];
    char stringdata17[26];
    char stringdata18[18];
    char stringdata19[23];
    char stringdata20[8];
    char stringdata21[12];
    char stringdata22[14];
    char stringdata23[17];
    char stringdata24[26];
    char stringdata25[28];
    char stringdata26[26];
    char stringdata27[20];
    char stringdata28[20];
    char stringdata29[19];
    char stringdata30[19];
    char stringdata31[20];
    char stringdata32[33];
    char stringdata33[25];
    char stringdata34[29];
    char stringdata35[26];
    char stringdata36[28];
    char stringdata37[25];
    char stringdata38[21];
    char stringdata39[21];
    char stringdata40[22];
    char stringdata41[20];
    char stringdata42[19];
    char stringdata43[34];
    char stringdata44[26];
    char stringdata45[29];
    char stringdata46[31];
    char stringdata47[29];
    char stringdata48[20];
    char stringdata49[22];
    char stringdata50[25];
    char stringdata51[34];
    char stringdata52[36];
    char stringdata53[34];
    char stringdata54[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS_t qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "TFDesignerWindow"
        QT_MOC_LITERAL(17, 10),  // "signalLeft"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 11),  // "signalRight"
        QT_MOC_LITERAL(41, 10),  // "signalZoom"
        QT_MOC_LITERAL(52, 20),  // "graphics_utils::Zoom"
        QT_MOC_LITERAL(73, 4),  // "zoom"
        QT_MOC_LITERAL(78, 26),  // "signalSelectionModeChanged"
        QT_MOC_LITERAL(105, 32),  // "transfer_function::SelectionMode"
        QT_MOC_LITERAL(138, 13),  // "selectionMode"
        QT_MOC_LITERAL(152, 16),  // "signalClustering"
        QT_MOC_LITERAL(169, 20),  // "signalSettingsDialog"
        QT_MOC_LITERAL(190, 24),  // "signalFeaturesExtraction"
        QT_MOC_LITERAL(215, 17),  // "signalUnselectAll"
        QT_MOC_LITERAL(233, 12),  // "signalUpdate"
        QT_MOC_LITERAL(246, 16),  // "signalRestorePos"
        QT_MOC_LITERAL(263, 18),  // "signalRestoreColor"
        QT_MOC_LITERAL(282, 25),  // "signalShowRenderingWindow"
        QT_MOC_LITERAL(308, 17),  // "signalColorChoose"
        QT_MOC_LITERAL(326, 22),  // "signalBenchmarkEnabled"
        QT_MOC_LITERAL(349, 7),  // "enabled"
        QT_MOC_LITERAL(357, 11),  // "signalGroup"
        QT_MOC_LITERAL(369, 13),  // "signalUngroup"
        QT_MOC_LITERAL(383, 16),  // "signalScreenshot"
        QT_MOC_LITERAL(400, 25),  // "signalScreenshotForPivots"
        QT_MOC_LITERAL(426, 27),  // "signalScreenshotForClusters"
        QT_MOC_LITERAL(454, 25),  // "signalScreenshotForGroups"
        QT_MOC_LITERAL(480, 19),  // "signalSaveViewerPos"
        QT_MOC_LITERAL(500, 19),  // "signalLoadViewerPos"
        QT_MOC_LITERAL(520, 18),  // "signalSaveTFDesign"
        QT_MOC_LITERAL(539, 18),  // "signalLoadTFDesign"
        QT_MOC_LITERAL(558, 19),  // "signalShowLogWindow"
        QT_MOC_LITERAL(578, 32),  // "slotEmitSignalFeaturesExtraction"
        QT_MOC_LITERAL(611, 24),  // "slotEmitSignalClustering"
        QT_MOC_LITERAL(636, 28),  // "slotEmitSignalSettingsDialog"
        QT_MOC_LITERAL(665, 25),  // "slotEmitSignalUnselectAll"
        QT_MOC_LITERAL(691, 27),  // "slotEmitSignalResetObserver"
        QT_MOC_LITERAL(719, 24),  // "slotEmitSignalResetColor"
        QT_MOC_LITERAL(744, 20),  // "slotEmitSignalUpdate"
        QT_MOC_LITERAL(765, 20),  // "slotEmitSignalZoomIn"
        QT_MOC_LITERAL(786, 21),  // "slotEmitSignalZoomOut"
        QT_MOC_LITERAL(808, 19),  // "slotEmitSignalRight"
        QT_MOC_LITERAL(828, 18),  // "slotEmitSignalLeft"
        QT_MOC_LITERAL(847, 33),  // "slotEmitSignalShowRenderingWi..."
        QT_MOC_LITERAL(881, 25),  // "slotEmitSignalColorChoose"
        QT_MOC_LITERAL(907, 28),  // "slotEmitSignalPointSelection"
        QT_MOC_LITERAL(936, 30),  // "slotEmitSignalClusterSelection"
        QT_MOC_LITERAL(967, 28),  // "slotEmitSignalGroupSelection"
        QT_MOC_LITERAL(996, 19),  // "slotEmitSignalGroup"
        QT_MOC_LITERAL(1016, 21),  // "slotEmitSignalUngroup"
        QT_MOC_LITERAL(1038, 24),  // "slotEmitSignalScreenshot"
        QT_MOC_LITERAL(1063, 33),  // "slotEmitSignalScreenshotForPi..."
        QT_MOC_LITERAL(1097, 35),  // "slotEmitSignalScreenshotForCl..."
        QT_MOC_LITERAL(1133, 33),  // "slotEmitSignalScreenshotForGr..."
        QT_MOC_LITERAL(1167, 27)   // "slotEmitSignalShowLogWindow"
    },
    "TFDesignerWindow",
    "signalLeft",
    "",
    "signalRight",
    "signalZoom",
    "graphics_utils::Zoom",
    "zoom",
    "signalSelectionModeChanged",
    "transfer_function::SelectionMode",
    "selectionMode",
    "signalClustering",
    "signalSettingsDialog",
    "signalFeaturesExtraction",
    "signalUnselectAll",
    "signalUpdate",
    "signalRestorePos",
    "signalRestoreColor",
    "signalShowRenderingWindow",
    "signalColorChoose",
    "signalBenchmarkEnabled",
    "enabled",
    "signalGroup",
    "signalUngroup",
    "signalScreenshot",
    "signalScreenshotForPivots",
    "signalScreenshotForClusters",
    "signalScreenshotForGroups",
    "signalSaveViewerPos",
    "signalLoadViewerPos",
    "signalSaveTFDesign",
    "signalLoadTFDesign",
    "signalShowLogWindow",
    "slotEmitSignalFeaturesExtraction",
    "slotEmitSignalClustering",
    "slotEmitSignalSettingsDialog",
    "slotEmitSignalUnselectAll",
    "slotEmitSignalResetObserver",
    "slotEmitSignalResetColor",
    "slotEmitSignalUpdate",
    "slotEmitSignalZoomIn",
    "slotEmitSignalZoomOut",
    "slotEmitSignalRight",
    "slotEmitSignalLeft",
    "slotEmitSignalShowRenderingWindow",
    "slotEmitSignalColorChoose",
    "slotEmitSignalPointSelection",
    "slotEmitSignalClusterSelection",
    "slotEmitSignalGroupSelection",
    "slotEmitSignalGroup",
    "slotEmitSignalUngroup",
    "slotEmitSignalScreenshot",
    "slotEmitSignalScreenshotForPivots",
    "slotEmitSignalScreenshotForClusters",
    "slotEmitSignalScreenshotForGroups",
    "slotEmitSignalShowLogWindow"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTFDesignerWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      48,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      25,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  302,    2, 0x06,    1 /* Public */,
       3,    0,  303,    2, 0x06,    2 /* Public */,
       4,    1,  304,    2, 0x06,    3 /* Public */,
       7,    1,  307,    2, 0x06,    5 /* Public */,
      10,    0,  310,    2, 0x06,    7 /* Public */,
      11,    0,  311,    2, 0x06,    8 /* Public */,
      12,    0,  312,    2, 0x06,    9 /* Public */,
      13,    0,  313,    2, 0x06,   10 /* Public */,
      14,    0,  314,    2, 0x06,   11 /* Public */,
      15,    0,  315,    2, 0x06,   12 /* Public */,
      16,    0,  316,    2, 0x06,   13 /* Public */,
      17,    0,  317,    2, 0x06,   14 /* Public */,
      18,    0,  318,    2, 0x06,   15 /* Public */,
      19,    1,  319,    2, 0x06,   16 /* Public */,
      21,    0,  322,    2, 0x06,   18 /* Public */,
      22,    0,  323,    2, 0x06,   19 /* Public */,
      23,    0,  324,    2, 0x06,   20 /* Public */,
      24,    0,  325,    2, 0x06,   21 /* Public */,
      25,    0,  326,    2, 0x06,   22 /* Public */,
      26,    0,  327,    2, 0x06,   23 /* Public */,
      27,    0,  328,    2, 0x06,   24 /* Public */,
      28,    0,  329,    2, 0x06,   25 /* Public */,
      29,    0,  330,    2, 0x06,   26 /* Public */,
      30,    0,  331,    2, 0x06,   27 /* Public */,
      31,    0,  332,    2, 0x06,   28 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      32,    0,  333,    2, 0x08,   29 /* Private */,
      33,    0,  334,    2, 0x08,   30 /* Private */,
      34,    0,  335,    2, 0x08,   31 /* Private */,
      35,    0,  336,    2, 0x08,   32 /* Private */,
      36,    0,  337,    2, 0x08,   33 /* Private */,
      37,    0,  338,    2, 0x08,   34 /* Private */,
      38,    0,  339,    2, 0x08,   35 /* Private */,
      39,    0,  340,    2, 0x08,   36 /* Private */,
      40,    0,  341,    2, 0x08,   37 /* Private */,
      41,    0,  342,    2, 0x08,   38 /* Private */,
      42,    0,  343,    2, 0x08,   39 /* Private */,
      43,    0,  344,    2, 0x08,   40 /* Private */,
      44,    0,  345,    2, 0x08,   41 /* Private */,
      45,    0,  346,    2, 0x08,   42 /* Private */,
      46,    0,  347,    2, 0x08,   43 /* Private */,
      47,    0,  348,    2, 0x08,   44 /* Private */,
      48,    0,  349,    2, 0x08,   45 /* Private */,
      49,    0,  350,    2, 0x08,   46 /* Private */,
      50,    0,  351,    2, 0x08,   47 /* Private */,
      51,    0,  352,    2, 0x08,   48 /* Private */,
      52,    0,  353,    2, 0x08,   49 /* Private */,
      53,    0,  354,    2, 0x08,   50 /* Private */,
      54,    0,  355,    2, 0x08,   51 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TFDesignerWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTFDesignerWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TFDesignerWindow, std::true_type>,
        // method 'signalLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalZoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<graphics_utils::Zoom, std::false_type>,
        // method 'signalSelectionModeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<transfer_function::SelectionMode, std::false_type>,
        // method 'signalClustering'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalSettingsDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalFeaturesExtraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalUnselectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRestorePos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalRestoreColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalShowRenderingWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalColorChoose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalBenchmarkEnabled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'signalGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalUngroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalScreenshotForPivots'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalScreenshotForClusters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalScreenshotForGroups'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalSaveViewerPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalLoadViewerPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalSaveTFDesign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalLoadTFDesign'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'signalShowLogWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalFeaturesExtraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalClustering'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalSettingsDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalUnselectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalResetObserver'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalResetColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalZoomIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalZoomOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalShowRenderingWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalColorChoose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalPointSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalClusterSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalGroupSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalUngroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalScreenshot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalScreenshotForPivots'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalScreenshotForClusters'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalScreenshotForGroups'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slotEmitSignalShowLogWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TFDesignerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TFDesignerWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalLeft(); break;
        case 1: _t->signalRight(); break;
        case 2: _t->signalZoom((*reinterpret_cast< std::add_pointer_t<graphics_utils::Zoom>>(_a[1]))); break;
        case 3: _t->signalSelectionModeChanged((*reinterpret_cast< std::add_pointer_t<transfer_function::SelectionMode>>(_a[1]))); break;
        case 4: _t->signalClustering(); break;
        case 5: _t->signalSettingsDialog(); break;
        case 6: _t->signalFeaturesExtraction(); break;
        case 7: _t->signalUnselectAll(); break;
        case 8: _t->signalUpdate(); break;
        case 9: _t->signalRestorePos(); break;
        case 10: _t->signalRestoreColor(); break;
        case 11: _t->signalShowRenderingWindow(); break;
        case 12: _t->signalColorChoose(); break;
        case 13: _t->signalBenchmarkEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->signalGroup(); break;
        case 15: _t->signalUngroup(); break;
        case 16: _t->signalScreenshot(); break;
        case 17: _t->signalScreenshotForPivots(); break;
        case 18: _t->signalScreenshotForClusters(); break;
        case 19: _t->signalScreenshotForGroups(); break;
        case 20: _t->signalSaveViewerPos(); break;
        case 21: _t->signalLoadViewerPos(); break;
        case 22: _t->signalSaveTFDesign(); break;
        case 23: _t->signalLoadTFDesign(); break;
        case 24: _t->signalShowLogWindow(); break;
        case 25: _t->slotEmitSignalFeaturesExtraction(); break;
        case 26: _t->slotEmitSignalClustering(); break;
        case 27: _t->slotEmitSignalSettingsDialog(); break;
        case 28: _t->slotEmitSignalUnselectAll(); break;
        case 29: _t->slotEmitSignalResetObserver(); break;
        case 30: _t->slotEmitSignalResetColor(); break;
        case 31: _t->slotEmitSignalUpdate(); break;
        case 32: _t->slotEmitSignalZoomIn(); break;
        case 33: _t->slotEmitSignalZoomOut(); break;
        case 34: _t->slotEmitSignalRight(); break;
        case 35: _t->slotEmitSignalLeft(); break;
        case 36: _t->slotEmitSignalShowRenderingWindow(); break;
        case 37: _t->slotEmitSignalColorChoose(); break;
        case 38: _t->slotEmitSignalPointSelection(); break;
        case 39: _t->slotEmitSignalClusterSelection(); break;
        case 40: _t->slotEmitSignalGroupSelection(); break;
        case 41: _t->slotEmitSignalGroup(); break;
        case 42: _t->slotEmitSignalUngroup(); break;
        case 43: _t->slotEmitSignalScreenshot(); break;
        case 44: _t->slotEmitSignalScreenshotForPivots(); break;
        case 45: _t->slotEmitSignalScreenshotForClusters(); break;
        case 46: _t->slotEmitSignalScreenshotForGroups(); break;
        case 47: _t->slotEmitSignalShowLogWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalLeft; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalRight; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)(graphics_utils::Zoom );
            if (_t _q_method = &TFDesignerWindow::signalZoom; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)(transfer_function::SelectionMode );
            if (_t _q_method = &TFDesignerWindow::signalSelectionModeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalClustering; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalSettingsDialog; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalFeaturesExtraction; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalUnselectAll; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalRestorePos; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalRestoreColor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalShowRenderingWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalColorChoose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)(bool );
            if (_t _q_method = &TFDesignerWindow::signalBenchmarkEnabled; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalGroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalUngroup; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalScreenshot; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalScreenshotForPivots; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalScreenshotForClusters; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalScreenshotForGroups; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalSaveViewerPos; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalLoadViewerPos; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalSaveTFDesign; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalLoadTFDesign; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (TFDesignerWindow::*)();
            if (_t _q_method = &TFDesignerWindow::signalShowLogWindow; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
    }
}

const QMetaObject *TFDesignerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TFDesignerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTFDesignerWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TFDesignerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 48)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 48;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 48)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 48;
    }
    return _id;
}

// SIGNAL 0
void TFDesignerWindow::signalLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TFDesignerWindow::signalRight()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TFDesignerWindow::signalZoom(graphics_utils::Zoom _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TFDesignerWindow::signalSelectionModeChanged(transfer_function::SelectionMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TFDesignerWindow::signalClustering()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void TFDesignerWindow::signalSettingsDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TFDesignerWindow::signalFeaturesExtraction()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TFDesignerWindow::signalUnselectAll()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void TFDesignerWindow::signalUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void TFDesignerWindow::signalRestorePos()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TFDesignerWindow::signalRestoreColor()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void TFDesignerWindow::signalShowRenderingWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void TFDesignerWindow::signalColorChoose()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void TFDesignerWindow::signalBenchmarkEnabled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void TFDesignerWindow::signalGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void TFDesignerWindow::signalUngroup()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void TFDesignerWindow::signalScreenshot()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void TFDesignerWindow::signalScreenshotForPivots()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void TFDesignerWindow::signalScreenshotForClusters()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void TFDesignerWindow::signalScreenshotForGroups()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void TFDesignerWindow::signalSaveViewerPos()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void TFDesignerWindow::signalLoadViewerPos()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void TFDesignerWindow::signalSaveTFDesign()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void TFDesignerWindow::signalLoadTFDesign()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void TFDesignerWindow::signalShowLogWindow()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}
QT_WARNING_POP
