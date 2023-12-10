#include "threadindexing.cuh"


#include <cuda_runtime.h>
#include <cuda_device_runtime_api.h>
#include <device_launch_parameters.h>









__device__ unsigned ThreadIndexing::globalIdx() {
    unsigned blockId;
    unsigned id;

    blockId = blockIdx.x + (blockIdx.y * gridDim.x) + (gridDim.x * gridDim.y * blockIdx.z);
    id = blockId * (blockDim.x * blockDim.y * blockDim.z) + (threadIdx.z * (blockDim.x * blockDim.y)) + (threadIdx.y * blockDim.x) + threadIdx.x;

    return id;
}





__device__ unsigned ThreadIndexing::totalBlockIdx() {
    return (threadIdx.z * blockDim.x * blockDim.y) + (threadIdx.y * blockDim.x) + threadIdx.x;
}





__device__ unsigned ThreadIndexing::totalBlockDim() {
    return blockDim.x * blockDim.y * blockDim.z;
}
