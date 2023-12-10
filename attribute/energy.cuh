#ifndef ENERGY_CUH
#define ENERGY_CUH


#include "attribute.h"



namespace attribute {
class Energy : public Attribute {
public:
	Energy();

	virtual ~Energy() override;



protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int mask) override;
};
}



__global__ void _energyKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcEnergy(const unsigned* histogram, unsigned nVoxels, float* buffer);



#endif
