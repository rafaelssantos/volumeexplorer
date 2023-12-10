#ifndef VARIANCE_CUH
#define VARIANCE_CUH


#include "attribute.h"



namespace attribute {
class Variance : public Attribute {
public:
	Variance();

	virtual ~Variance() override;

protected:
    virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int texSide) override;
};
}



__global__ void _varianceKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcVariance(const unsigned* histogram, unsigned nVoxels, float* buffer, float mean);


#endif
