#ifndef KURTOSIS_CUH
#define KURTOSIS_CUH


#include "attribute.h"



namespace attribute {
class Kurtosis : public Attribute {
public:
	Kurtosis();

	virtual ~Kurtosis() override;

protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int mask) override;
};
}



__global__ void _kurtosisKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcKurtosis(const unsigned* histogram, unsigned nVoxels, float* buffer, float mean, float standadDeviation);


#endif
