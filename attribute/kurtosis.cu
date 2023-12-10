#include "kurtosis.cuh"


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



__global__ void _kurtosisKernel(const Volume* volume, float *data, int texSide) {
    __shared__ unsigned histogram[256];
    __shared__ float buffer[256];
    __shared__ int nVoxels;

    unsigned index = ThreadIndexing::globalIdx() / ThreadIndexing::totalBlockDim();

    if(index < volume->voxelCount()) {
        _calcHistogram(volume, (int)index, texSide, histogram, &nVoxels);
        _calcMean(histogram, nVoxels, buffer);
        float mean = buffer[0];
        _calcStandardDeviation(histogram, nVoxels, buffer, mean);
        float standardDeviation = buffer[0];

        _calcKurtosis(histogram, nVoxels, buffer, mean, standardDeviation);

        if(ThreadIndexing::totalBlockIdx() == 0){
            *(data + index) = buffer[0];
        }
    }
}


__device__ void _calcKurtosis(const unsigned *histogram, unsigned nVoxels, float *buffer, float mean, float standadDeviation) {
    unsigned tid = ThreadIndexing::totalBlockIdx();


    if(tid <  ThreadIndexing::totalBlockIdx()){
        float value = tid  - mean;
        buffer[tid] = value * value * value * value * (float) histogram[tid];

        __syncthreads();

        unsigned n =  ThreadIndexing::totalBlockIdx();
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
                buffer[tid] = buffer[tid] / (standadDeviation * standadDeviation * standadDeviation * standadDeviation) - 3;
            }
            else{
                buffer[tid] = 0;
            }
        }
    }

    __syncthreads();
}





Kurtosis::Kurtosis() : Attribute(){
    setType(AttributeType::KURTOSIS);
    setDescription("Kurtosis");
}



Kurtosis::~Kurtosis() {

}


thrust::host_vector<float>* Kurtosis::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int mask) {
    thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

    blockDim = dim3(256, 1, 1);
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount * 256);

    _kurtosisKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]), mask);
    getLastCudaError("Kurtosis kernel failed.");
    checkCudaErrors(cudaDeviceSynchronize());

    *hostVector = devVector;

    return hostVector;
}
