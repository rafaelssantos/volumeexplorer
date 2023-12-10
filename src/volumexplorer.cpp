#include "volumeexplorer.h"


#include "attribute/attributemanager.h"
#include "log_utils/logger.h"
#include "cuda_utils/helper_cuda.h"
#include "rendering/render.h"
#include "volume/volumemanager.h"
#include "transfer_function/tfmanager.cuh"
#include "transfer_function/tfdesigner.h"


using namespace attribute;
using namespace graphics_utils;
using namespace log_utils;
using namespace rendering;
using namespace std;
using namespace transfer_function;
using namespace volume;



VolumeExplorer& VolumeExplorer::instance() {
	static VolumeExplorer instance;
	return instance;
}





string VolumeExplorer::loadDataset(const std::list<string>& filesPath, float x, float y, float z) {
	pair<Volume*, Volume*> volumes (m_hostVolume, m_devVolume);
	VolumeManager::instance().free(volumes);
    volumes = VolumeManager::instance().load(filesPath, {x, y, z});
	m_hostVolume = volumes.first;
	m_devVolume = volumes.second;


	pair<TransferFunction*, TransferFunction*> transferFuncs (m_hostTransferFunc, m_devTransferFunc);
	TransferFunctionManager::instance().free(transferFuncs);
	transferFuncs = TransferFunctionManager::instance().build(m_hostVolume, m_devVolume);
	m_hostTransferFunc = transferFuncs.first;
	m_devTransferFunc = transferFuncs.second;

	AttributeManager::instance().setVolume(m_devVolume);
	Render::instance().setVolume(m_devVolume);
	Render::instance().setTransferFunction(m_devTransferFunc);

	TFDesigner::instance().setTransferFunction(m_hostTransferFunc, m_devTransferFunc);
	TFDesigner::instance().free();

	return m_hostVolume->toString();
}




void VolumeExplorer::selectAttributes(const set<AttributeType> &types, int mask, string filePath) {
	if(types.size() > 0){
		vector<vector<float>*>* data;

		Logger::instance().startTimer(0);
        data = AttributeManager::instance().exec(types, m_hostVolume->voxelCount(), mask, filePath);
		Logger::instance().stopTimer(0, "Runtime Attribute Extraction");

		TFDesigner::instance().free();

		Logger::instance().startTimer(0);
		TFDesigner::instance().execDimReduction(*m_hostVolume, *data);
		Logger::instance().stopTimer(0, "Runtime Fastmap");

		AttributeManager::instance().free(data);
	}
}



void VolumeExplorer::render(unsigned width, unsigned height) const {
	if(isDatasetLoaded()) {
        Render::instance().exec(width, height, m_hostVolume->diameter());
    }
}




void VolumeExplorer::registerGlPBOAsCudaResource(GLuint pbo) const {
	Render::instance().registerGlPBO(pbo);
}



void VolumeExplorer::unregisterGlPBOAsCudaResource() const {
	Render::instance().unregisterGlPBO();
}



void VolumeExplorer::zoom(Zoom zoom) const {
	Render::instance().zoom(zoom);
}



void VolumeExplorer::rotate(RotationAxis axis, RotationSense sense) const {
	Render::instance().rotate(axis, sense);
}




void VolumeExplorer::resetViewer() const {
	Render::instance().resetViewer();
}




VolumeExplorer::VolumeExplorer() {
	m_hostVolume = nullptr;
	m_devVolume = nullptr;
	m_hostTransferFunc = nullptr;
	m_devTransferFunc = nullptr;
	checkCudaErrors(cudaDeviceReset());
}




VolumeExplorer::~VolumeExplorer() {
    pair<Volume*, Volume*> volumes (m_hostVolume, m_devVolume);
    VolumeManager::instance().free(volumes);
    pair<TransferFunction*, TransferFunction*> transferFuncs (m_hostTransferFunc, m_devTransferFunc);
    TransferFunctionManager::instance().free(transferFuncs);
}




bool VolumeExplorer::isDatasetLoaded() const {
	return m_hostTransferFunc != nullptr && m_hostVolume != nullptr;
}



const Volume& VolumeExplorer::volume() const {
	return *m_hostVolume;
}




const std::set<AttributeType> &VolumeExplorer::availableAttributes() const {
	return AttributeManager::instance().availableTypes();
}
