#include "intensity.cuh"

#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "cuda_utils/helper_cuda.h"


using namespace attribute;

using namespace std;
using namespace volume;





__global__ void _instensityKernel(const Volume* volume, float *data) {
	unsigned id = ThreadIndexing::globalIdx();

	if(id < volume->voxelCount()){
        *(data + id) = Intensity::_calcIntensity(volume, (int) id);
	}
}


__device__ float Intensity::_calcIntensity(const Volume* volume, int index){
    return static_cast<float>(volume->sampleAt(volume->indexToIndex3(index)));
}



Intensity::Intensity() : Attribute(){
	setType(AttributeType::INTENSITY);
	setName("Intesity");
}



Intensity::~Intensity() {

}


thrust::host_vector<float>* Intensity::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int) {
	thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
	thrust::device_vector<float> devVector = *hostVector;

    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount);

	_instensityKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]));
    getLastCudaError("Intensity kernel failed.");
	checkCudaErrors(cudaDeviceSynchronize());

	*hostVector = devVector;

	return hostVector;
}
