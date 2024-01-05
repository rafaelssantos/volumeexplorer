#ifndef ATTRIBUTEMANAGER_H
#define ATTRIBUTEMANAGER_H



#include <cuda_runtime.h>
#include <vector>
#include <set>
#include <string>
#include "attribute/attributetype.h"
#include "volume/volume.cuh"


namespace attribute {

class AttributeManager {
public:
	static AttributeManager& instance();

    std::vector<std::vector<float>*>* exec(const std::set<AttributeType>& types, size_t voxelCount, int mask, std::string filePath);

	void setVolume(const volume::Volume* volume);

	void setKernelBlockDim(const dim3& dim);

	void setKernelBlockDim(unsigned x, unsigned y, unsigned z);

    void free(std::vector<std::vector<float>*> *values) const;

    const std::set<AttributeType>& availableTypes() const;

    std::string name(AttributeType type) const;

    void saveToCSV(const std::vector<std::vector<float>*>& data, const std::vector<std::string>& names, std::string filePath) const;

    void saveToAttr(const std::vector<std::vector<float>*>& data, const std::vector<std::string>& names, std::string filePath) const;


private:
	AttributeManager();

	virtual ~AttributeManager();



private:
	AttributeManager(const AttributeManager&) = delete;
	void operator=(const AttributeManager&) = delete;

	const volume::Volume* m_volume;
	dim3 m_kernelBlockDim;
    std::set<AttributeType> m_availableTypes;
};

}

#endif // ATTRIBUTEMANAGER_H
