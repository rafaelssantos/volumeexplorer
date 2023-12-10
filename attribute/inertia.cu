#include "inertia.cuh"


#include <cmath>
#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"
#include "mean.cuh"
#include "variance.cuh"

using namespace attribute;

using namespace std;
using namespace volume;



__global__ void _inertiaKernel(const Volume* volume, float *data, int texSide) {
    __shared__ unsigned histogram[256];
    __shared__ float buffer[256];
    __shared__ int nVoxels;

    unsigned index = ThreadIndexing::globalIdx() / ThreadIndexing::totalBlockDim();

    if(index < volume->voxelCount()) {
        _calcHistogram(volume, (int)index, texSide, histogram, &nVoxels);

        _calcInertia(histogram, nVoxels, buffer);

        if(ThreadIndexing::totalBlockIdx() == 0){
            *(data + index) = buffer[0];
        }
    }
}


__device__ void _calcInertia(const unsigned *histogram, unsigned nVoxels, float *buffer) {
    unsigned tid = ThreadIndexing::totalBlockIdx();


    if(tid < ThreadIndexing::totalBlockDim()){
        float value = (float) histogram[tid] / (float) nVoxels;
        buffer[tid] = (value * value); //Segundo momento angular

        __syncthreads();

        unsigned n = ThreadIndexing::totalBlockDim();
        unsigned halfN;

        while(n > 1) {
            halfN = n / 2;

            if (tid < halfN){
                buffer[tid] = buffer[tid] + buffer[tid + halfN];
            }
            __syncthreads();

            n = halfN;
        }
    }

    __syncthreads();
}





Inertia::Inertia() : Attribute(){
    setType(AttributeType::INERTIA);
    setDescription("Smoothness");
}



Inertia::~Inertia() {

}


thrust::host_vector<float>* Inertia::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int texSide) {
    thrust:: host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

    blockDim = dim3(256, 1, 1);
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount * 256);

    _inertiaKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]), texSide);
    getLastCudaError("Inertia kernel failed.");
    checkCudaErrors(cudaDeviceSynchronize());

    *hostVector = devVector;

    return hostVector;
}
