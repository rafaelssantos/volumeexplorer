#ifndef MEAN_CUH
#define MEAN_CUH


#include "attribute.h"


namespace attribute {


class Mean : public Attribute {
public:
	Mean();

	virtual ~Mean() override;



protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int mask) override;
};


}


__global__ void _meanKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcMean(const unsigned* histogram, unsigned nVoxels, float* buffer);

__device__ void _calcHistogram(const volume::Volume *volume, int index, int texSide, unsigned* histogram, int *count);



#endif
