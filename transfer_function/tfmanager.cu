#include "tfmanager.cuh"

#include <cuda_runtime_api.h>
#include <device_launch_parameters.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "quaternion/quaternioncalculator.cuh"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"
#include "settings/renderingsettings.h"
#include "tfmemmanager.h"




using namespace quaternion;
using namespace transfer_function;
using namespace volume;
using namespace settings;
using namespace std;



__global__ void _calcNormalsKernel(const Volume* volume, TransferFunction *transferFunc) {
    const unsigned tid = ThreadIndexing::globalIdx();

    if(tid < volume->voxelCount()) {
        TransferFunctionManager::_sobelOperator(volume, transferFunc, static_cast<int>(tid));
    }
}





TransferFunctionManager& TransferFunctionManager::instance() {
    static TransferFunctionManager instance;

    return instance;
}





std::pair<TransferFunction*, TransferFunction*> TransferFunctionManager::build(const Volume* hostVolume, const Volume* devVolume) const {
    TransferFunction* hostTransferFunc = new TransferFunction(hostVolume->dim());
    hostTransferFunc->setSpacing(hostVolume->spacing());

    hostTransferFunc->m_colors = new uchar4[hostVolume->dim().x * hostVolume->dim().y * hostVolume->dim().z];
    hostTransferFunc->m_normals = new float3[hostVolume->dim().x * hostVolume->dim().y * hostVolume->dim().z];

    for(auto x = 0; static_cast<unsigned>(x) < hostTransferFunc->dim().x; x++) {
        for(auto y = 0; static_cast<unsigned>(y) < hostTransferFunc->dim().y; y++) {
            for(auto z = 0; static_cast<unsigned>(z) < hostTransferFunc->dim().z; z++) {
                uchar4 color;
                color.x = color.y = color.z = color.w = static_cast<unsigned char>(hostVolume->sampleAt(x, y, z));
                hostTransferFunc->setSampleAt(x, y, z, color);
            }
        }
    }

    TransferFunction* devTransferFunc = TFMemManager::instance().cloneToDev(hostTransferFunc);

    dim3 blockDim = RenderingSettings::instance().blockDim();
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, hostVolume->voxelCount());

    _calcNormalsKernel<<<gridDim, RenderingSettings::instance().blockDim()>>>(devVolume, devTransferFunc);

    getLastCudaError("Transfer function normals kernel failed.");
    TFMemManager::instance().memcpyNormalsFromBuffer(hostTransferFunc);


    return std::pair<TransferFunction*, TransferFunction*>(hostTransferFunc, devTransferFunc);
}





void TransferFunctionManager::free(std::pair<TransferFunction*, TransferFunction*> transferFunc) const {
    TFMemManager::instance().freeHost(transferFunc.first);
    TFMemManager::instance().freeDevice(transferFunc.second);
}





TransferFunctionManager::TransferFunctionManager() {

}




TransferFunctionManager::~TransferFunctionManager() {

}




__host__ __device__ void TransferFunctionManager::_sobelOperator(const Volume* volume, TransferFunction* transferFunc, int index) {
    int3 voxelIndex = volume->indexToIndex3(index);

    float gX[3][3][3], gY[3][3][3], gZ[3][3][3];
    float hX[3] = {+1, +2, +1}, hY[3] = {+1, +2, +1}, hZ[3] = {+1, +2, +1};
    float hpX[3] = {+1, +0, -1}, hpY[3] = {+1, +0, -1}, hpZ[3] = {+1, +0,-1};

    for(int m = 0; m <= 2; m++){
        for(int n = 0; n <= 2; n++){
            for(int k = 0; k <= 2; k++){
                gY[m][n][k] = hpX[m] * hY[n] * hZ[k];
                gX[m][n][k] = hX[m] * hpY[n] * hZ[k];
                gZ[m][n][k] = hX[m] * hY[n] * hpZ[k];
            }
        }
    }


    float3 gradient = {0, 0, 0};

    for(int m = -1; m <= 1; m++){
        for(int n = -1; n <= 1; n++){
            for(int k = -1; k <= 1; k++){
                if(volume->isIndex3In(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k)){
                    gradient.x += gY[m+1][n+1][k+1] * static_cast<float>(volume->sampleAt(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k));
                    gradient.y += gX[m+1][n+1][k+1] * static_cast<float>(volume->sampleAt(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k));
                    gradient.z += gZ[m+1][n+1][k+1] * static_cast<float>(volume->sampleAt(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k));
                }
            }
        }
    }

    gradient.x = -gradient.x;
    gradient.y = -gradient.y;
    gradient.z = -gradient.z;

    *(transferFunc->m_normals + index) = QuaternionCalculator::normalize(gradient);
}




__host__ __device__ void TransferFunctionManager::_centralDifferences(const volume::Volume *volume, TransferFunction *transferFunc, int index) {
    int3 index3 = volume->indexToIndex3(index);
    float3 gradient = {0, 0, 0};

    if(index3.x - 1 >= 0 && index3.x + 1 <transferFunc->dim().x){
        gradient.x = (static_cast<float>(volume->sampleAt(index3.x + 1, index3.y, index3.z)) - static_cast<float>(volume->sampleAt(index3.x - 1, index3.y, index3.z))) / (2 * volume->spacing().x);
    }
    if(index3.y - 1 >= 0 && index3.y + 1 <transferFunc->dim().y){
        gradient.y = (static_cast<float>(volume->sampleAt(index3.x, index3.y + 1, index3.z)) - static_cast<float>(volume->sampleAt(index3.x, index3.y - 1, index3.z))) / (2 * volume->spacing().y);
    }
    if(index3.z - 1 >= 0 && index3.z + 1 < transferFunc->dim().z){
        gradient.z = (static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z + 1)) - static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z - 1))) / (2  *volume->spacing().z);
    }

    *(transferFunc->m_normals + index) = QuaternionCalculator::normalize(gradient);
}





void TransferFunctionManager::memcpyColors(TransferFunction* hostTransferFunc, TransferFunction* devTransferFunc) {
    TFMemManager::instance().memcpyColors(devTransferFunc, hostTransferFunc);
}
