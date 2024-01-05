#include "constrast.cuh"


#include <cmath>
#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "entropy.cuh"
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"
#include "mean.cuh"

using namespace attribute;

using namespace std;
using namespace volume;



__global__ void _constrastKernel(const Volume* volume, float *data, int texSide) {
    __shared__ unsigned histogram[256];
    __shared__ float buffer[256];
    __shared__ int nVoxels;

    unsigned index = ThreadIndexing::globalIdx() / ThreadIndexing::totalBlockDim();

    if(index < volume->voxelCount()) {
        _calcHistogram(volume, (int)index, texSide, histogram, &nVoxels);

        _calcContrast(histogram, nVoxels, buffer);

        if(ThreadIndexing::totalBlockIdx() == 0){
            *(data + index) = buffer[0];
        }
    }
}


__device__ void _calcContrast(const unsigned *histogram, unsigned nVoxels, float *buffer) {
    unsigned tid = ThreadIndexing::totalBlockIdx();

    if(tid < ThreadIndexing::totalBlockDim()){
        buffer[tid] = (tid * tid) *((float) histogram[tid] / (float) nVoxels);

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
            buffer[tid] = - buffer[tid];
        }
    }

    __syncthreads();
}





Contrast::Contrast() : Attribute(){
    setType(AttributeType::CONTRAST);
    setName("Sum Entropy");
}



Contrast::~Contrast() {

}


thrust::host_vector<float>* Contrast::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int texSide) {
    thrust::host_vector<float>* hostData = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devData = *hostData;

    blockDim = dim3(256, 1, 1);
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount * 256);

    _constrastKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devData[0]), texSide);
    getLastCudaError("Constrast kernel failed.");
    checkCudaErrors(cudaDeviceSynchronize());

    *hostData = devData;

    return hostData;
}
