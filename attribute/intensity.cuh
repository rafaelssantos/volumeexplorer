#ifndef INTENSITY_CUH
#define INTENSITY_CUH


#include "attribute.h"



namespace attribute {
class Intensity : public Attribute {
public:
	Intensity();

	virtual ~Intensity() override;

    static __device__ float _calcIntensity(const volume::Volume *volume, int index);


protected:
	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int) override;
};
}


__global__ void _instensityKernel(const volume::Volume* volume, float *data);

#endif






