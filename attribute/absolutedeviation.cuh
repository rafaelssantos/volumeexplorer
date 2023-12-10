#ifndef ABSOLUTEDEVIATION_CUH
#define ABSOLUTEDEVIATION_CUH


#include "attribute.h"



namespace attribute {
class AbsoluteDeviation : public Attribute {
public:
	AbsoluteDeviation();

	virtual ~AbsoluteDeviation() override;


protected:
    virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t threadCount, dim3 blockDim, int texSide) override;


};
}



__global__ void _absoluteDeviationKernel(const volume::Volume* volume, float *data, int texSide);

__device__ void _calcAbsoluteDeviation(const unsigned* histogram, unsigned nVoxels, float* buffer, float mean);


#endif
