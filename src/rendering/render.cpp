#include "render.h"


#include <cmath>
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>
#include "cuda_utils/helper_cuda.h"
#include "cuda_utils/kerneldimscalculator.h"
#include "image/glpboimagememmanager.h"
#include "ray_casting/raycasting.cuh"
#include "settings/renderingsettings.h"


using namespace std;

using namespace quaternion;
using namespace graphics_utils;
using namespace rendering;
using namespace rendering::image;
using namespace rendering::ray_casting;
using namespace settings;
using namespace transfer_function;
using namespace volume;





Render& Render::instance() {
    static Render instance;

    return instance;
}




void Render::exec(unsigned width, unsigned height, float volumeDiagonal) {
	m_viewer.rotationDegree = RenderingSettings::instance().rotationDegree();
    m_hostImage->setSize(width, height);
	m_hostImage->resizePixelAspect(volumeDiagonal, m_viewer.zoom);

	checkCudaErrors(cudaGraphicsMapResources(1, &m_cudaPBOResource, nullptr));
    size_t numBytes;
	checkCudaErrors(cudaGraphicsResourceGetMappedPointer((void**)&m_hostImage->m_pboData, &numBytes, m_cudaPBOResource));

    RayCasting::instance().kernelLaunch(*m_hostImage, m_devVolume, m_transferFunction, RenderingSettings::instance().specs(), m_viewer, RenderingSettings::instance().blockDim(), width * height, RenderingSettings::instance().illumination(), RenderingSettings::instance().interpolation());

    if(RenderingSettings::instance().devSyncronizeEnabled()){
        checkCudaErrors(cudaDeviceSynchronize());
    }
	checkCudaErrors(cudaGraphicsUnmapResources(1, &m_cudaPBOResource, nullptr));
}



void Render::registerGlPBO(GLuint pbo) {
	checkCudaErrors(cudaGraphicsGLRegisterBuffer(&m_cudaPBOResource, pbo, cudaGraphicsMapFlagsWriteDiscard));
}




void Render::setVolume(const Volume* volume) {
    m_devVolume = volume;
}




void Render::setTransferFunction(const TransferFunction* transferFunction) {
	m_transferFunction = transferFunction;
}




void Render::zoom(Zoom zoom) {
    if(zoom == Zoom::IN) {
        m_viewer.zoom = fmaxf(m_viewer.zoom - RenderingSettings::instance().specs().zoomIncrement, 0);
    }
    else{
        m_viewer.zoom = m_viewer.zoom + RenderingSettings::instance().specs().zoomIncrement;
    }
}





void Render::rotate(RotationAxis axis, RotationSense sense) {
    RotQuaternion rotation;

	m_viewer.rotationDegree = RenderingSettings::instance().rotationDegree();

    if(sense == RotationSense::CLOCKWISE) {
		rotation.theta = - m_viewer.rotationDegree;
    }
    else {
		rotation.theta = + m_viewer.rotationDegree;
    }

    rotation.nx = rotation.ny = rotation.nz = 0;
    if(axis == RotationAxis::X) {
        rotation.nx = 1.0;
    }
    else if(axis == RotationAxis::Y) {
        rotation.ny = 1.0;
    }
    else{
        rotation.nz = 1.0;
    }

	m_viewer.rotation = QuaternionCalculator::compose(m_viewer.rotation, rotation);
}




void Render::resetViewer() {
	m_viewer.rotation.nx = m_viewer.rotation.ny = m_viewer.rotation.nz = m_viewer.rotation.theta = 0.0;
	m_viewer.zoom = 1.0;
}




void Render::unregisterGlPBO() {
	checkCudaErrors(cudaGraphicsUnregisterResource(m_cudaPBOResource));
}





Render::Render() {
	m_cudaPBOResource = nullptr;

    m_hostImage = new GlPBOImage();
    m_devImage = GlPBOImageMemManager::instance().cloneToDevice(m_hostImage);

    m_devVolume = nullptr;
	m_transferFunction = nullptr;

	m_viewer.zoom = 1.0;
	m_viewer.rotationDegree = 2.0;
	m_viewer.rotation.nx = m_viewer.rotation.ny = m_viewer.rotation.nz = m_viewer.rotation.theta = 0.0;
}





Render::~Render() {
    delete m_hostImage;
    m_hostImage = nullptr;

    GlPBOImageMemManager::instance().deviceFree(m_devImage);
    m_devImage = nullptr;
}
