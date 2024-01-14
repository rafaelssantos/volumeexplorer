QT       += widgets opengl openglwidgets

TARGET = volumeexplorer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG -= console




HEADERS += \
    attribute/absolutedeviation.cuh \
    attribute/attribute.h \
    attribute/attributemanager.h \
    attribute/attributetype.h \
    attribute/constrast.cuh \
    attribute/energy.cuh \
    attribute/entropy.cuh \
    attribute/gradient.cuh \
    attribute/inertia.cuh \
    attribute/intensity.cuh \
    attribute/kurtosis.cuh \
    attribute/laplacian.cuh \
    attribute/mean.cuh \
    attribute/skewness.cuh \
    attribute/standarddeviation.cuh \
    attribute/variance.cuh \
    clustering/dbscan.h \
    clustering/dbscancell.h \
    clustering/dbscangrid.h \
    clustering/dbscanpoint.h \
    cuda_utils/kerneldimscalculator.h \
    quaternion/quaternion.h \
    quaternion/quaternioncalculator.cuh \
    quaternion/rotquaternion.h \
    cuda_utils/threadindexing.cuh \
    dimensionality_reduction/fastmap.h \
    graphics_utils/rainbowscalegenerator.h \
    graphics_utils/rotatationsense.h \
    graphics_utils/rotationaxis.h \
    graphics_utils/zoom.h \
    grid/grid3d.cuh \
    log_utils/logger.h \
    log_utils/loggerwindow.h \
    cuda_utils/helper_cuda.h \
    cuda_utils/helper_cuda.h \
    cuda_utils/helper_string.h \
    rendering/image/glpboimage.h \
    rendering/image/glpboimagememmanager.h \
    rendering/ray_casting/raycasting.cuh \
    rendering/render.h \
    rendering/renderingspecs.h \
    rendering/view/viewer.h \
    settings/renderingsettings.h \
    settings/tfsettings.h \
    similarity_search/sparsespatialselection.h \
    transfer_function/cluster.h \
    transfer_function/illumination.h \
    transfer_function/interpolation.h \
    transfer_function/lookuptable.h \
    transfer_function/pivot.h \
    transfer_function/pivotui.h \
    transfer_function/selectedtype.h \
    transfer_function/selectionmode.h \
    transfer_function/tfdesigner.h \
    transfer_function/tfmanager.cuh \
    transfer_function/tfmemmanager.h \
    transfer_function/transferfunction.cuh \
    ui/common/directoryfiledialog.h \
    ui/common/observerfiledialog.h \
    ui/common/screenshotfiledialog.h \
    ui/common/tfdesignfiledialog.h \
    ui/rendering/datasetfiledialog.h \
    ui/rendering/renderinguicontroller.h \
    ui/rendering/renderingwidget.h \
    ui/rendering/renderingwindow.h \
    ui/rendering/settings/renderingsettingsdialog.h \
    ui/rendering/settings/renderingsettingsuicontroller.h \
    ui/rendering/voxeldialog.h \
    ui/transfer_function/attribute/attributedialog.h \
    ui/transfer_function/attribute/attributeuicontroller.h \
    ui/transfer_function/clustering/clusteringdialog.h \
    ui/transfer_function/clustering/clusteringuicontroller.h \
    ui/transfer_function/settings/tfsettingsdialog.h \
    ui/transfer_function/settings/tfsettingsuicontroller.h \
    ui/transfer_function/tfdesignerspace.h \
    ui/transfer_function/tfdesigneruicontroller.h \
    ui/transfer_function/tfdesignerviewmanager.h \
    ui/transfer_function/tfdesignerwindow.h \
    types_extras/float8.h \
    volume/volume.cuh \
    volume/volumemanager.h \
    volume/volumememmanager.h \
    volumeexplorer.h

SOURCES += \
    attribute/absolutedeviation.cu \
    attribute/attribute.cu \
    attribute/attributemanager.cpp \
    attribute/constrast.cu \
    attribute/energy.cu \
    attribute/entropy.cu \
    attribute/gradient.cu \
    attribute/inertia.cu \
    attribute/intensity.cu \
    attribute/kurtosis.cu \
    attribute/laplacian.cu \
    attribute/mean.cu \
    attribute/skewness.cu \
    attribute/standarddeviation.cu \
    attribute/variance.cu \
    clustering/dbscan.cpp \
    clustering/dbscancell.cpp \
    clustering/dbscangrid.cpp \
    clustering/dbscanpoint.cpp \
    cuda_utils/kerneldimscalculator.cpp \
    quaternion/quaternioncalculator.cu \
    cuda_utils/threadindexing.cu \
    dimensionality_reduction/fastmap.cpp \
    graphics_utils/rainbowscalegenerator.cpp \
    grid/grid3d.cu \
    log_utils/logger.cpp \
    log_utils/loggerwindow.cpp \
    main.cpp \
    rendering/image/glpboimage.cu \
    rendering/image/glpboimagememmanager.cpp \
    rendering/ray_casting/raycasting.cu \
    rendering/render.cpp \
    settings/renderingsettings.cpp \
    settings/tfsettings.cpp \
    similarity_search/sparsespatialselection.cpp \
    transfer_function/cluster.cpp \
    transfer_function/lookuptable.cpp \
    transfer_function/pivot.cpp \
    transfer_function/pivotui.cpp \
    transfer_function/tfdesigner.cpp \
    transfer_function/tfmanager.cu \
    transfer_function/tfmemmanager.cpp \
    transfer_function/transferfunction.cu \
    ui/common/directoryfiledialog.cpp \
    ui/common/observerfiledialog.cpp \
    ui/common/screenshotfiledialog.cpp \
    ui/common/tfdesignfiledialog.cpp \
    ui/rendering/datasetfiledialog.cpp \
    ui/rendering/renderinguicontroller.cpp \
    ui/rendering/renderingwidget.cpp \
    ui/rendering/renderingwindow.cpp \
    ui/rendering/settings/renderingsettingsdialog.cpp \
    ui/rendering/settings/renderingsettingsuicontroller.cpp \
    ui/rendering/voxeldialog.cpp \
    ui/transfer_function/attribute/attibuteuicontroller.cpp \
    ui/transfer_function/attribute/attributedialog.cpp \
    ui/transfer_function/clustering/clusteringdialog.cpp \
    ui/transfer_function/clustering/clusteringuicontroller.cpp \
    ui/transfer_function/settings/tfsettingsdialog.cpp \
    ui/transfer_function/settings/tfsettingsuicontroller.cpp \
    ui/transfer_function/tfdesignerspace.cpp \
    ui/transfer_function/tfdesigneruicontroller.cpp \
    ui/transfer_function/tfdesignerviewmanager.cpp \
    ui/transfer_function/tfdesignerwindow.cpp \
    volume/volume.cu \
    volume/volumemanager.cpp \
    volume/volumememmanager.cpp \
    volumexplorer.cpp




FORMS += \
    log_utils/loggerwindow.ui \
    ui/rendering/renderingwindow.ui \
    ui/rendering/settings/renderingsettingsdialog.ui \
    ui/rendering/voxeldialog.ui \
    ui/transfer_function/attribute/attributedialog.ui \
    ui/transfer_function/clustering/clusteringdialog.ui \
    ui/transfer_function/settings/tfsettingsdialog.ui \
    ui/transfer_function/tfdesignerwindow.ui

RESOURCES += \
    volumexplorerrsrc.qrc


##########################################################################################################
############################################# CUDA  SOURCES #############################################
##########################################################################################################

CUDA_SOURCES += \
    attribute/absolutedeviation.cu \
    attribute/attribute.cu \
    attribute/energy.cu \
    attribute/entropy.cu \
    attribute/gradient.cu \
    attribute/inertia.cu \
    attribute/intensity.cu \
    attribute/kurtosis.cu \
    attribute/laplacian.cu \
    attribute/mean.cu \
    attribute/skewness.cu \
    attribute/standarddeviation.cu \
    attribute/constrast.cu \
    attribute/variance.cu \
    quaternion/quaternioncalculator.cu \
    cuda_utils/threadindexing.cu \
    grid/grid3d.cu \
    rendering/image/glpboimage.cu \
    rendering/ray_casting/raycasting.cu \
    transfer_function/tfmanager.cu \
    transfer_function/transferfunction.cu \
    volume/volume.cu



SOURCES -= \
    attribute/absolutedeviation.cu \
    attribute/attribute.cu \
    attribute/energy.cu \
    attribute/entropy.cu \
    attribute/gradient.cu \
    attribute/inertia.cu \
    attribute/intensity.cu \
    attribute/kurtosis.cu \
    attribute/laplacian.cu \
    attribute/mean.cu \
    attribute/skewness.cu \
    attribute/standarddeviation.cu \
    attribute/constrast.cu \
    attribute/variance.cu \
    quaternion/quaternioncalculator.cu \
    cuda_utils/threadindexing.cu \
    grid/grid3d.cu \
    rendering/image/glpboimage.cu \
    rendering/ray_casting/raycasting.cu \
    transfer_function/tfmanager.cu \
    transfer_function/transferfunction.cu \
    volume/volume.cu

##########################################################################################################





##########################################################################################################
################################################# OPENCV #################################################
##########################################################################################################

INCLUDEPATH += /usr/include/opencv4
LIBS += -L/usr/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui

##########################################################################################################
##########################################################################################################
##########################################################################################################



##########################################################################################################
################################################# OPENMP #################################################
##########################################################################################################

QMAKE_CXXFLAGS += -finput-charset=UTF-8
QMAKE_LFLAGS +=  -finput-charset=UTF-8

##########################################################################################################
##########################################################################################################
##########################################################################################################




##########################################################################################################
################################################## CUDA ##################################################
##########################################################################################################

QMAKE_CXXFLAGS_RELEASE += -O3

CUDA_DIR                = /usr/local/cuda
SYSTEM_TYPE             = 64                            # '32' or '64', depending on your system
CUDA_ARCH               = sm_50                         # Type of CUDA architecture
NVCC_COMPILER_OPTIONS   = -O3 -use_fast_math    # NVCC Options
NVCC_FLAGS              = ""                # NVCC Flags

CUDA_INC = $$join($$CUDA_DIR/include,'" -I"','-I"','"')
CUDA_LIB_NAMES = cudart cuda
for(lib, CUDA_LIB_NAMES) {
    CUDA_LIBS += -l$$lib
}

INCLUDEPATH += $$CUDA_DIR/include             # include paths
QMAKE_LIBDIR += $$CUDA_DIR/lib64
LIBS += $$CUDA_LIBS

CONFIG(debug, debug|release) {
    DESTDIR = debug
    OBJECTS_DIR = debug/obj

    cuda_compiler_debug.input = CUDA_SOURCES
    cuda_compiler_debug.output = $${OBJECTS_DIR}/${QMAKE_FILE_BASE}.o
    cuda_compiler_debug.commands = $$CUDA_DIR/bin/nvcc $$CUDA_INC $$CUDA_LIBS \
                    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
                    --device-c -G ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT} \
                    -I $$PWD
    cuda_compiler_debug.variable_out = CUDA_OBJECTS OBJECTS
    QMAKE_EXTRA_COMPILERS += cuda_compiler_debug

    cuda_linker_debug.input = CUDA_OBJECTS
    cuda_linker_debug.CONFIG = combine
    cuda_linker_debug.output = $${OBJECTS_DIR}/device-link.o
    cuda_linker_debug.commands = $$CUDA_DIR/bin/nvcc \
                    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
                    --device-link -G ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT} \
                    -I $$PWD
    cuda_linker_debug.dependency_type = TYPE_C
    cuda_linker_debug.variable_out = OBJECTS
    QMAKE_EXTRA_COMPILERS += cuda_linker_debug
}

else{
    DESTDIR = release
    OBJECTS_DIR = release/obj

    cuda_compiler.input = CUDA_SOURCES
    cuda_compiler.output = $${OBJECTS_DIR}/${QMAKE_FILE_BASE}.o
    cuda_compiler.commands = $$CUDA_DIR/bin/nvcc $$NVCC_COMPILER_OPTIONS $$CUDA_INC $$CUDA_LIBS \
                    --machine $$SYSTEM_TYPE --gpu-architecture=$$CUDA_ARCH \
                    --device-c ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT} \
                    -I $$PWD
    cuda_compiler.variable_out = CUDA_OBJECTS OBJECTS
    QMAKE_EXTRA_COMPILERS += cuda_compiler

    cuda_linker.input = CUDA_OBJECTS
    cuda_linker.CONFIG = combine
    cuda_linker.output = $${OBJECTS_DIR}/device-link.o
    cuda_linker.commands = $$CUDA_DIR/bin/nvcc \
                    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH \
                    --device-link ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT} \
                    -I $$PWD
    cuda_linker.dependency_type = TYPE_C
    cuda_linker.variable_out = OBJECTS
    QMAKE_EXTRA_COMPILERS += cuda_linker
}

##########################################################################################################
##########################################################################################################
##########################################################################################################


