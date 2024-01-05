#include "laplacian.cuh"

#include <cmath>
#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"
#include "quaternion/quaternioncalculator.cuh"



using namespace attribute;

using namespace std;
using namespace volume;
using namespace quaternion;


__global__ void _laplacianKernel(const Volume* volume, float *data) {
    unsigned tid = ThreadIndexing::globalIdx();

    if(tid < volume->voxelCount()){
        *(data + tid) = _calcLaplacian(volume, (int) tid);
    }
}


__device__ float _calcLaplacian(const Volume* volume, int index){
    int3 index3 = volume->indexToIndex3(index);
    float3 laplacian;


    if(index3.x > 0){
        if(static_cast<unsigned>(index3.x + 1) < volume->dim().x){
            //Diferença centrada
            laplacian.x = static_cast<float>(volume->sampleAt(index3.x + 1, index3.y, index3.z))
                        - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z))
                        + static_cast<float>(volume->sampleAt(index3.x - 1, index3.y, index3.z));

            laplacian.x = laplacian.x / (volume->spacing().x * volume->spacing().x);
        }
        else{
            //Diferença regressiva
            laplacian.x = static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z))
                      - 2.0f * static_cast<float>(volume->sampleAt(index3.x - 1, index3.y, index3.z))
                      + static_cast<float>(volume->sampleAt(index3.x - 2, index3.y, index3.z));
            laplacian.x = laplacian.x / (volume->spacing().x * volume->spacing().x);
        }
    }
    else{
        //Diferença progressiva
        laplacian.x = static_cast<float>(volume->sampleAt(index3.x + 2, index3.y, index3.z))
                    - 2.0f * static_cast<float>(volume->sampleAt(index3.x + 1, index3.y, index3.z))
                    + static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z));
        laplacian.x = laplacian.x / (volume->spacing().x * volume->spacing().x);
    }


    if(index3.y > 0){
        if(static_cast<unsigned>(index3.y + 1) < volume->dim().y){
            //Diferença centrada
            laplacian.y = static_cast<float>(volume->sampleAt(index3.x, index3.y + 1, index3.z))
                      - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z))
                      + static_cast<float>(volume->sampleAt(index3.x, index3.y - 1, index3.z));
            laplacian.y = laplacian.y / (volume->spacing().y * volume->spacing().y);
        }
        else {
            //Diferença regressiva
            laplacian.y = static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z))
                      - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y - 1, index3.z))
                      + static_cast<float>(volume->sampleAt(index3.x, index3.y - 2, index3.z));
            laplacian.y = laplacian.y / (volume->spacing().y * volume->spacing().y);
        }
    }
    else {
        //Diferença progressiva
        laplacian.y = static_cast<float>(volume->sampleAt(index3.x, index3.y + 2, index3.z))
                  - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y + 1, index3.z))
                  + static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z));
        laplacian.y = laplacian.y / (volume->spacing().y * volume->spacing().y);
    }


    if(index3.z > 0){
        if(static_cast<unsigned>(index3.z + 1) < volume->dim().z){
            //Diferença centrada
            laplacian.z = static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z + 1))
                      - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z))
                      + static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z - 1));
            laplacian.z = laplacian.z / (volume->spacing().z * volume->spacing().z);
        }
        else{
            //Diferença regressiva
            laplacian.z = static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z))
                      - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z - 1))
                      + static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z - 2));
            laplacian.z = laplacian.z / (volume->spacing().z * volume->spacing().z);
        }
    }
    else {
        //Diferença progressiva
        laplacian.z = static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z + 2))
                  - 2.0f * static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z + 1))
                  + static_cast<float>(volume->sampleAt(index3.x, index3.y, index3.z));
        laplacian.z = laplacian.z / (volume->spacing().z * volume->spacing().z);
    }

    return QuaternionCalculator::norm(laplacian);
}



Laplacian::Laplacian() : Attribute(){
    setType(AttributeType::LAPLACIAN);
    setName("Laplacian");
}



Laplacian::~Laplacian() {

}


thrust::host_vector<float>* Laplacian::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int mask) {
    thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount);

    _laplacianKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]));
    getLastCudaError("Laplacian kernel failed.");
    checkCudaErrors(cudaDeviceSynchronize());

    *hostVector = devVector;

    return hostVector;
}
