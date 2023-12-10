#include "tfmemmanager.h"
#include <cuda_device_runtime_api.h>



#include <cuda_runtime.h>
#include "cuda_utils/helper_cuda.h"



using namespace transfer_function;





TFMemManager& TFMemManager::instance() {
	static TFMemManager instance;

    return instance;
}





TransferFunction* TFMemManager::cloneToDev(const TransferFunction* hostTransferFunction) {
	checkCudaErrors(cudaMemcpy(&m_swapBuffer, hostTransferFunction, sizeof(TransferFunction), cudaMemcpyHostToHost));

    checkCudaErrors(cudaMalloc((void**)(&m_swapBuffer.m_colors), hostTransferFunction->voxelCount() * sizeof(uchar4)));
    checkCudaErrors(cudaMemcpy(m_swapBuffer.m_colors, hostTransferFunction->m_colors, hostTransferFunction->voxelCount() * sizeof(uchar4), cudaMemcpyHostToDevice));

    checkCudaErrors(cudaMalloc((void**)(&m_swapBuffer.m_normals), hostTransferFunction->voxelCount() * sizeof(float3)));
    checkCudaErrors(cudaMemcpy(m_swapBuffer.m_normals, hostTransferFunction->m_normals, hostTransferFunction->voxelCount() * sizeof(float3), cudaMemcpyHostToDevice));

	TransferFunction* devTransferFunction = nullptr;
	checkCudaErrors(cudaMalloc((void**)&devTransferFunction, sizeof(TransferFunction)));
	checkCudaErrors(cudaMemcpy(devTransferFunction, &m_swapBuffer, sizeof(TransferFunction), cudaMemcpyHostToDevice));

    return devTransferFunction;
}





void TFMemManager::freeDevice(TransferFunction* devTransferFunction) {
    if(devTransferFunction != nullptr) {
        checkCudaErrors(cudaFree(m_swapBuffer.m_colors));
        checkCudaErrors(cudaFree(m_swapBuffer.m_normals));
        checkCudaErrors(cudaFree(devTransferFunction));

        m_swapBuffer.m_colors = nullptr;
        m_swapBuffer.m_normals = nullptr;
    }
}






void TFMemManager::freeHost(TransferFunction* hostTransferFunction) {
    delete hostTransferFunction;
}






void TFMemManager::memcpyColors(TransferFunction* devTransferFunction, TransferFunction* hostTransferFunction) {
    uchar4* colors = m_swapBuffer.m_colors;
    float3* normals = m_swapBuffer.m_normals;

	checkCudaErrors(cudaMemcpy(&m_swapBuffer, hostTransferFunction, sizeof(TransferFunction), cudaMemcpyHostToHost));
    m_swapBuffer.m_colors = colors;
    m_swapBuffer.m_normals = normals;

    checkCudaErrors(cudaMemcpy(m_swapBuffer.m_colors, hostTransferFunction->m_colors, hostTransferFunction->voxelCount() * sizeof (uchar4), cudaMemcpyHostToDevice));
	checkCudaErrors(cudaMemcpy(devTransferFunction, &m_swapBuffer, sizeof(TransferFunction), cudaMemcpyHostToDevice));
}




void TFMemManager::memcpySettings(TransferFunction* devTransferFunction, TransferFunction* hostTransferFunction) {
    uchar4* colors = m_swapBuffer.m_colors;
    float3* normals = m_swapBuffer.m_normals;

	checkCudaErrors(cudaMemcpy(&m_swapBuffer, hostTransferFunction, sizeof(TransferFunction), cudaMemcpyHostToHost));
    m_swapBuffer.m_colors = colors;
    m_swapBuffer.m_normals = normals;

	checkCudaErrors(cudaMemcpy(devTransferFunction, &m_swapBuffer, sizeof(TransferFunction), cudaMemcpyHostToDevice));
}





void TFMemManager::memcpyNormalsFromBuffer(TransferFunction* hostTransferFunction) {
    checkCudaErrors(cudaMemcpy(hostTransferFunction->m_normals, m_swapBuffer.m_normals, hostTransferFunction->voxelCount() * sizeof(float3), cudaMemcpyDeviceToHost));
}






TFMemManager::TFMemManager() : m_swapBuffer(0, 0, 0) {
    m_swapBuffer.m_colors = nullptr;
    m_swapBuffer.m_normals = nullptr;
}






TFMemManager::~TFMemManager() {
    m_swapBuffer.m_colors = nullptr;
    m_swapBuffer.m_normals = nullptr;
}
