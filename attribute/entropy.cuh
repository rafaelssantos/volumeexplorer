#ifndef ENTROPY_CUH
#define ENTROPY_CUH


#include "attribute.h"


namespace attribute {


class Entropy : public Attribute {
public:
    Entropy();

    virtual ~Entropy() override;
protected:
    virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int texSide) override;
};
}


__global__ void _entropyKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcEntropy(const unsigned* histogram, unsigned voxelCount, float* buffer);


#endif
