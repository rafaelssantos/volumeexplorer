#ifndef CONSTRAST_CUH
#define CONSTRAST_CUH


#include "attribute.h"


namespace attribute {


class Contrast : public Attribute {
public:
    Contrast();

    virtual ~Contrast() override;
protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int mask) override;
};
}


__global__ void _constrastKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcContrast(const unsigned* histogram, unsigned voxelCount, float* buffer);


#endif
