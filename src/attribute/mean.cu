#include "mean.cuh"

#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"

using namespace attribute;

using namespace std;
using namespace volume;



__global__ void _meanKernel(const Volume* volume, float *data, int texSide) {
	__shared__ unsigned histogram[256];
	__shared__ float buffer[256];
    __shared__ int nVoxels;

    unsigned tid = ThreadIndexing::globalIdx() / ThreadIndexing::totalBlockDim();

    if(tid < volume->voxelCount()) {
        _calcHistogram(volume, (int)tid, texSide, histogram, &nVoxels);
        _calcMean(histogram, nVoxels, buffer);

		if(ThreadIndexing::totalBlockIdx() == 0){
            *(data + tid) = buffer[0];
		}
	}
}


__device__ void _calcMean(const unsigned *histogram, unsigned nVoxels, float *buffer) {
    unsigned tid = ThreadIndexing::totalBlockIdx();

    if(tid < ThreadIndexing::totalBlockDim()){
        buffer[tid] = tid * (float) histogram[tid];

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
            buffer[0] = buffer[0] / nVoxels;
        }
	}

	__syncthreads();
}


__device__ void _calcHistogram(const Volume *volume, int index, int texSide, unsigned* histogram, int* nVoxels) {
    unsigned tid = ThreadIndexing::totalBlockIdx();

    if(tid == 0){
        *nVoxels = 0;
	}

    if(tid < 256){
        histogram[tid] = 0;
	}
	__syncthreads();

    int texDim3 = texSide * texSide * texSide;

    int3 volIndex3;
    int3 texIndex3;

    while(tid < texDim3) {
        texIndex3.z = tid / (texSide * texSide);
        texIndex3.y = (tid % (texSide * texSide)) / texSide;
        texIndex3.x = (tid % (texSide * texSide)) % texSide;

        volIndex3 = volume->indexToIndex3(index);
        volIndex3.x = volIndex3.x - texSide / 2 + texIndex3.x;
        volIndex3.y = volIndex3.y - texSide / 2 + texIndex3.y;
        volIndex3.z = volIndex3.z - texSide / 2 + texIndex3.z;

        if(volume->isIndex3In(volIndex3)) {
            atomicAdd((histogram + (int) volume->sampleAt(volIndex3)), 1);
            atomicAdd(nVoxels, 1);
		}

        tid = tid + ThreadIndexing::totalBlockDim();
	}

	__syncthreads();
}




Mean::Mean() : Attribute(){
	setType(AttributeType::MEAN);
	setName("Mean");
}



Mean::~Mean() {

}


thrust::host_vector<float>* Mean::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int mask) {
    thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

	blockDim = dim3(256, 1, 1);
    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount * 256);

	_meanKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]), mask);
	getLastCudaError("Mean kernel failed.");
	checkCudaErrors(cudaDeviceSynchronize());

	*hostVector = devVector;

	return hostVector;
}
