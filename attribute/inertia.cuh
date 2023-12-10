#ifndef INERTIA_H
#define INERTIA_H


#include "attribute.h"


namespace attribute {


class Inertia : public Attribute {
public:
    Inertia();

    virtual ~Inertia() override;

protected:
    virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int texSide) override;
};


}


__global__ void _inertiaKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcInertia(const unsigned int *histogram, unsigned int nVoxels, float* buffer);


#endif // INERTIA_H
