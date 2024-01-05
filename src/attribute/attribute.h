#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <cuda_runtime.h>
#include <vector>
#include <string>
#include <thrust/host_vector.h>
#include "attributetype.h"
#include "volume/volume.cuh"



namespace attribute {
class Attribute {
public:
	Attribute();

	virtual ~Attribute();

	AttributeType type() const;

    const std::string& name() const;

	std::vector<float> *extract(const volume::Volume* volume, size_t voxelCount, dim3 blockDim, int mask);


protected:
    void setName(const std::string& description);

	void setType(AttributeType type);

	virtual thrust::host_vector<float> *kernelLaunch(const volume::Volume* volume, size_t voxelCount, dim3 blockDim, int mask) = 0;


private:
	AttributeType m_type;
    std::string m_name;
};
}



#endif // ATTRIBUTE_H
