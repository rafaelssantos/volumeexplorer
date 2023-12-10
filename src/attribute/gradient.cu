#include "gradient.cuh"

#include <cmath>
#include <cuda_runtime.h>
#include <thrust/device_vector.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/threadindexing.cuh"
#include "quaternion/quaternioncalculator.cuh"
#include "cuda_utils/helper_cuda.h"

using namespace attribute;

using namespace quaternion;
using namespace std;
using namespace volume;




__global__ void _gradientKernel(const Volume* volume, float *data) {
    unsigned tid = ThreadIndexing::globalIdx();

    if(tid < volume->voxelCount()){
        *(data + tid) = _calcGradient(volume, (int) tid);
	}
}




__device__ float _calcGradient(const Volume* volume, int index){
	int3 voxelIndex = volume->indexToIndex3(index);

	float gX[3][3][3], gY[3][3][3], gZ[3][3][3];
	float hX[3] = {+1, +2, +1}, hY[3] = {+1, +2, +1}, hZ[3] = {+1, +2, +1};
	float hpX[3] = {+1, +0, -1}, hpY[3] = {+1, +0, -1}, hpZ[3] = {+1, +0,-1};

	for(int m = 0; m <= 2; m++){
		for(int n = 0; n <= 2; n++){
			for(int k = 0; k <= 2; k++){
				gY[m][n][k] = hpX[m] * hY[n] * hZ[k];
				gX[m][n][k] = hX[m] * hpY[n] * hZ[k];
				gZ[m][n][k] = hX[m] * hY[n] * hpZ[k];
			}
		}
	}


	float3 gradient = {0, 0, 0};

	for(int m = -1; m <= 1; m++){
		for(int n = -1; n <= 1; n++){
			for(int k = -1; k <= 1; k++){
				if(volume->isIndex3In(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k)){
                    gradient.x += gY[m+1][n+1][k+1] * static_cast<float>(volume->sampleAt(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k));
                    gradient.y += gX[m+1][n+1][k+1] * static_cast<float>(volume->sampleAt(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k));
                    gradient.z += gZ[m+1][n+1][k+1] * static_cast<float>(volume->sampleAt(voxelIndex.x - m, voxelIndex.y - n, voxelIndex.z - k));
				}
			}
		}
	}

    return QuaternionCalculator::norm(gradient);
}



Gradient::Gradient() : Attribute(){
    setType(AttributeType::GRADIENT);
    setDescription("Gradient");
}



Gradient::~Gradient() {

}


thrust::host_vector<float>* Gradient::kernelLaunch(const Volume* volume, size_t threadCount, dim3 blockDim, int) {
    thrust::host_vector<float>* hostVector = new thrust::host_vector<float>(threadCount, 0);
    thrust::device_vector<float> devVector = *hostVector;

    dim3 gridDim = KernelDimsCalculator::instance().calc(blockDim, threadCount);

	_gradientKernel<<<gridDim, blockDim>>>(volume, thrust::raw_pointer_cast(&devVector[0]));
    getLastCudaError("Gradient kernel failed.");
	checkCudaErrors(cudaDeviceSynchronize());

	*hostVector = devVector;

	return hostVector;
}
