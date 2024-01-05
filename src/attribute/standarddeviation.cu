#include "standarddeviation.cuh"


#include <cmath>
#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "mean.cuh"
#include "cuda_utils/helper_cuda.h"

using namespace attribute;

using namespace std;
using namespace volume;



__global__ void _standardDeviationKernel(const Volume* volume, float *data, int texSide) {
    __shared__ unsigned histogram[256];
    __shared__ float buffer[256];
    __shared__ int nVoxels;

    unsigned tid = ThreadIndexing::globalIdx() / ThreadIndexing::totalBlockDim();

    if(tid < volume->voxelCount()) {
        _calcHistogram(volume, (int)tid, texSide, histogram, &nVoxels);
        _calcMean(histogram, nVoxels, buffer);
        _calcStandardDeviation(histogram, nVoxels, buffer, buffer[0]);

        if(ThreadIndexing::totalBlockIdx() == 0){
            *(data + tid) = buffer[0];
        }
    }
}


__device__ void _calcStandardDeviation(const unsigned *histogram, int nVoxels, float *buffer, float mean) {
    unsigned tid = ThreadIndexing::totalBlockIdx();

    if(tid < ThreadIndexing::totalBlockDim()){
        buffer[tid] = (tid * (float) histogram[tid] - mean) * (tid * (float) histogram[tid] - mean);

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
        if(tid == 0) {
            buffer[tid] = sqrtf(buffer[tid] / nVoxels);
        }
    }

    __syncthreads();
}





StandardDeviation::StandardDeviation() : Attribute(){
    setType(AttributeType::STANDARD_DEVIATION);
    setName("Standard Deviation");
}



StandardDeviation::~StandardDeviation() {

}


thrust::host_vector<float>* StandardDeviation::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int texSide) {
    thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

    blockDim = dim3(256, 1, 1);
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount * 256);

    _standardDeviationKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]), texSide);
    getLastCudaError("Standard deviation kernel failed.");
    checkCudaErrors(cudaDeviceSynchronize());

    *hostVector = devVector;

    return hostVector;
}
