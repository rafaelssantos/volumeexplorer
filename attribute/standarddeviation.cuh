#ifndef STANDARDDEVIATION_CUH
#define STANDARDDEVIATION_CUH


#include "attribute.h"



namespace attribute {
class StandardDeviation : public Attribute {
public:
	StandardDeviation();

	virtual ~StandardDeviation() override;

protected:
    virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int texSide) override;
};
}


__global__ void _standardDeviationKernel(const volume::Volume* volume, float *data, int texDim);

__device__ void _calcStandardDeviation(const unsigned* histogram, int nVoxels, float* buffer, float mean);



#endif
