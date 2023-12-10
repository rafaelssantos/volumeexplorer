#ifndef GRADIENT_CUH
#define GRADIENT_CUH


#include "attribute.h"


namespace attribute {


class Gradient : public Attribute {
public:
    Gradient();

    virtual ~Gradient() override;



protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int) override;
};



}

__global__ void _gradientKernel(const volume::Volume* volume, float *data);

__device__ float _calcGradient(const volume::Volume* volume, int index);


#endif
