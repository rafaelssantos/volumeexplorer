#ifndef LAPLACIAN_CUH
#define LAPLACIAN_CUH


#include "attribute.h"



namespace attribute {
class Laplacian : public Attribute {
public:
    Laplacian();

    virtual ~Laplacian() override;



protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int mask) override;
};
}

__global__ void _laplacianKernel(const volume::Volume* volume, float *data);

__device__ float _calcLaplacian(const volume::Volume* volume, int index);


#endif
