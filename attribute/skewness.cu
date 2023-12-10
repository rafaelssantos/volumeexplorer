#include "skewness.cuh"


#include <cmath>
#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"
#include "mean.cuh"
#include "standarddeviation.cuh"

using namespace attribute;

using namespace std;
using namespace volume;



__global__ void _skewnessKernel(const Volume* volume, float *data, int texSide) {
    __shared__ unsigned histogram[256];
    __shared__ float buffer[256];
    __shared__ int nVoxels;

    unsigned tid = ThreadIndexing::globalIdx() / ThreadIndexing::totalBlockDim();

    if(tid < volume->voxelCount()) {
        _calcHistogram(volume, (int)tid, texSide, histogram, &nVoxels);
        _calcMean(histogram, nVoxels, buffer);
        float mean = buffer[0];

        _calcStandardDeviation(histogram, nVoxels, buffer, mean);
        float standardDeviation = buffer[0];

        _calcSkewness(histogram, nVoxels, buffer, mean, standardDeviation);

        if(ThreadIndexing::totalBlockIdx() == 0){
            *(data + tid) = buffer[0];
        }
    }
}


__device__ void _calcSkewness(const unsigned *histogram, unsigned nVoxels, float *buffer, float mean, float standadDeviation) {
    unsigned tid = ThreadIndexing::totalBlockIdx();

    if(tid < ThreadIndexing::totalBlockDim()){
        float value = tid  - mean;
        buffer[tid] =  value * value * value * (float) histogram[tid];

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

        if(tid == 0){
            if(standadDeviation != 0) {
                buffer[tid] = buffer[tid] / nVoxels;
                buffer[tid] = buffer[tid] / (standadDeviation * standadDeviation * standadDeviation);
            }
            else{
                buffer[tid] = 0;
            }
        }
    }

    __syncthreads();
}





Skewness::Skewness() : Attribute(){
    setType(AttributeType::SKEWNESS);
    setDescription("Skewness");
}



Skewness::~Skewness() {

}


thrust::host_vector<float>* Skewness::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int texSide) {
    thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

    blockDim = dim3(256, 1, 1);
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount * 256);

    _skewnessKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]), texSide);
    getLastCudaError("Skewness kernel failed.");
    checkCudaErrors(cudaDeviceSynchronize());

    *hostVector = devVector;

    return hostVector;
}
