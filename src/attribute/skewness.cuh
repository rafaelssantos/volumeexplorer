#ifndef SKEWNESS_CUH
#define SKEWNESS_CUH


#include "attribute.h"



namespace attribute {
class Skewness : public Attribute {
public:
	Skewness();

	virtual ~Skewness() override;

protected:
    virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int texSide) override;
};

}


__global__ void _skewnessKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcSkewness(const unsigned* histogram, unsigned nVoxels, float* buffer, float mean, float standadDeviation);


#endif
