#include "volumememmanager.h"
#include <cuda_runtime.h>


#include "cuda_utils/helper_cuda.h"


using namespace std;
using namespace volume;





VolumeMemManager &VolumeMemManager::instance() {
    static VolumeMemManager instance;

    return instance;
}





Volume* VolumeMemManager::cloneToDev(const Volume* hostVolume) {
    m_swapBuffer = *hostVolume;
    m_swapBuffer.m_data = nullptr;

    checkCudaErrors(cudaMalloc((void**)(&m_swapBuffer.m_data), hostVolume->voxelCount() * sizeof(byte)));
    checkCudaErrors(cudaMemcpy(m_swapBuffer.m_data, hostVolume->m_data, hostVolume->voxelCount() * sizeof(byte), cudaMemcpyHostToDevice));

    Volume* devVolume = nullptr;

    checkCudaErrors(cudaMalloc((void**)(&devVolume), sizeof(Volume)));
    checkCudaErrors(cudaMemcpy(devVolume, &m_swapBuffer, sizeof(Volume), cudaMemcpyHostToDevice));

    return devVolume;
}





void VolumeMemManager::hostFree(Volume* hostVolume) {
    delete hostVolume;
}





void VolumeMemManager::devFree(Volume* devVolume) {
    if(devVolume != nullptr) {
        checkCudaErrors(cudaFree(m_swapBuffer.m_data));
        checkCudaErrors(cudaFree(devVolume));
        m_swapBuffer.m_data = nullptr;
    }
}




VolumeMemManager::VolumeMemManager() : m_swapBuffer(0, 0, 0) {
    m_swapBuffer.m_data = nullptr;
}





VolumeMemManager::~VolumeMemManager() {
    m_swapBuffer.m_data = nullptr;
}
