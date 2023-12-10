#include "kerneldimscalculator.h"


#include <cmath>
#include <cuda_runtime.h>
#include <cuda_runtime.h>
#include "cuda_utils/helper_cuda.h"








KernelDimsCalculator& KernelDimsCalculator::instance() {
    static KernelDimsCalculator instance;

    return instance;
}





dim3 KernelDimsCalculator::calc(dim3& blockDim, size_t n, int gpuIndex) {
    cudaDeviceProp prop;
    size_t blockDimTotal;
    dim3 gridDim;

    blockDimTotal = blockDim.x * blockDim.y * blockDim.z;
    checkCudaErrors(cudaGetDeviceProperties(&prop, gpuIndex));

    if (n <= blockDimTotal ) {
        gridDim = dim3(1, 1, 1);
    }

    else if (n <= blockDimTotal * prop.maxGridSize[2]) {
        gridDim.z = static_cast<unsigned>(ceil((1.0 * n) / blockDimTotal));
        gridDim.y = 1;
        gridDim.x = 1;
    }

    else if (n <= blockDimTotal * prop.maxGridSize[2] * prop.maxGridSize[1]) {
        gridDim.z = static_cast<unsigned>(prop.maxGridSize[2]);
        gridDim.y = static_cast<unsigned>(ceil((1.0 * n) / (blockDimTotal * static_cast<unsigned>(prop.maxGridSize[2]))));
        gridDim.x = 1;
    }

    else if (n <= blockDimTotal * prop.maxGridSize[2] * prop.maxGridSize[1] * prop.maxGridSize[0]) {
        gridDim.z = static_cast<unsigned>(prop.maxGridSize[2]);
        gridDim.y = static_cast<unsigned>(prop.maxGridSize[1]);
        gridDim.x = static_cast<unsigned>(ceil((1.0 * n) / (blockDimTotal *  static_cast<unsigned>(prop.maxGridSize[2] * prop.maxGridSize[1]))));  //Restante em X
    }

    else {
        gridDim.z = static_cast<unsigned>(prop.maxGridSize[2]);;
        gridDim.y = static_cast<unsigned>(prop.maxGridSize[1]);;
        gridDim.x = static_cast<unsigned>(prop.maxGridSize[0]);;
        blockDim.z = 1;
        blockDim.y = 1;
        blockDim.x = static_cast<unsigned>(ceil(1.0 * n) /  static_cast<unsigned>(prop.maxGridSize[2] * prop.maxGridSize[1] * prop.maxGridSize[0]));
    }

    return gridDim;
}



KernelDimsCalculator::KernelDimsCalculator() {

}





KernelDimsCalculator::~KernelDimsCalculator() {

}
