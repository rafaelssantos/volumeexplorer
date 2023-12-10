#include "attributemanager.h"

#include <fstream>
#include <iostream>
#include "attribute/absolutedeviation.cuh"
#include "attribute/constrast.cuh"
#include "attribute/intensity.cuh"
#include "attribute/gradient.cuh"
#include "attribute/energy.cuh"
#include "attribute/entropy.cuh"
#include "attribute/kurtosis.cuh"
#include "attribute/mean.cuh"
#include "attribute/laplacian.cuh"
#include "attribute/skewness.cuh"
#include "attribute/inertia.cuh"
#include "attribute/standarddeviation.cuh"
#include "attribute/variance.cuh"

using namespace attribute;
using namespace attribute;
using namespace std;
using namespace volume;



AttributeManager& AttributeManager::instance() {
	static AttributeManager instance;

	return instance;
}




vector<vector<float>*>* AttributeManager::exec(const std::set<AttributeType>& types, size_t voxelCount, int mask, string filePath) {
    vector<vector<float>*>* data = new vector<vector<float>*>();
    vector<string> descriptions;
    vector<float>* attrData = nullptr;


	Intensity intensity;
    Contrast constrast;
    Gradient gradient;
    Laplacian laplacian;
	Mean mean;
	Energy energy;
	Entropy entropy;
	Variance variance;
	StandardDeviation standardDeviation;
	AbsoluteDeviation absoluteDeviation;
	Skewness skewness;
	Kurtosis kurtosis;
    Inertia inertia;

	for(auto t = types.begin(); t != types.end(); t++){
        descriptions.emplace_back(description(*t));

		switch (*t) {
            case AttributeType::ABSOLUTE_DEVIATION:
                attrData = absoluteDeviation.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
            case AttributeType::CONTRAST:
                attrData = constrast.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
            case AttributeType::ENERGY :
                attrData = energy.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
            case AttributeType::ENTROPY :
                attrData = entropy.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
			case AttributeType::GRADIENT :
                attrData = gradient.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
				break;
            case AttributeType::INERTIA:
                attrData = inertia.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
            case AttributeType::KURTOSIS:
                attrData = kurtosis.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
            case AttributeType::INTENSITY :
                attrData = intensity.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
            case AttributeType::LAPLACIAN :
                attrData = laplacian.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
			case AttributeType::MEAN :
                attrData = mean.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
				break;
            case AttributeType::SKEWNESS:
                attrData = skewness.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
			case AttributeType::STANDARD_DEVIATION:
                attrData = standardDeviation.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
				break;
            case AttributeType::VARIANCE:
                attrData = variance.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                data->emplace_back(attrData);
                break;
		}
	}

    if(filePath != "" && !descriptions.empty()){
        saveToCSV(*data, descriptions, filePath);
    }

    return data;
}



void AttributeManager::setVolume(const Volume* volume) {
	m_volume = volume;
}




void AttributeManager::setKernelBlockDim(const dim3& dim) {
	m_kernelBlockDim = dim;
}




void AttributeManager::setKernelBlockDim(unsigned x, unsigned y, unsigned z) {
	m_kernelBlockDim.x = x;
	m_kernelBlockDim.y = y;
	m_kernelBlockDim.z = z;
}




void AttributeManager::free(std::vector<std::vector<float>* >* data) const {
	if(data != nullptr){
		for(auto i = 0u; i < data->size(); i++){
			delete data->at(i);
			data->at(i) = nullptr;
		}
	}
	delete data;
	data = nullptr;
}



const std::set<AttributeType>& AttributeManager::availableTypes() const {
	return m_availableTypes;
}



string AttributeManager::description(AttributeType type) const {
	string description = "None";

	switch (type) {
		case AttributeType::ABSOLUTE_DEVIATION:
			description = "Absolute deviation";
			break;
        case AttributeType::CONTRAST:
            description = "Contrast";
            break;
		case AttributeType::ENERGY:
			description = "Energy";
			break;
		case AttributeType::ENTROPY:
			description = "Entropy";
			break;
		case AttributeType::GRADIENT:
            description = "Gradient Magnitude";
			break;
        case AttributeType::INERTIA:
            description = "Inertia";
            break;
		case AttributeType::INTENSITY:
			description = "Intensity";
			break;
		case AttributeType::KURTOSIS:
			description = "Kurtosis";
			break;
        case AttributeType::LAPLACIAN:
            description = "Laplacian Magnitude";
            break;
		case AttributeType::MEAN:
			description = "Mean";
			break;
		case AttributeType::SKEWNESS:
			description = "Skewness";
            break;
		case AttributeType::STANDARD_DEVIATION:
			description = "Standard deviation";
			break;
		case AttributeType::VARIANCE:
			description = "Variance";
			break;
	}

        return description;
}

void AttributeManager::saveToCSV(const std::vector<std::vector<float> *> &data, const std::vector<string> &descriptions, std::string filePath) const {
    std::ofstream outfile;

    outfile.open(filePath, ios_base::app);

    for(int i = 0; i < descriptions.size() - 1; i++){
        outfile << descriptions[i] << ", ";
    }
    outfile << descriptions.back() << "\n";

    for(int i = 0; i < data.front()->size(); i++){
        for(int a = 0; a < data.size(); a++){
            outfile << data.at(a)->at(i);
            if(a < data.size() - 1){
                outfile << ",";
            }
            else{
                outfile << "\n";
            }
        }
    }

    outfile.close();
}




AttributeManager::AttributeManager() {
	m_volume = nullptr;
	m_kernelBlockDim = {192, 1, 1};

	m_availableTypes.emplace(AttributeType::ABSOLUTE_DEVIATION);
    m_availableTypes.emplace(AttributeType::CONTRAST);
	m_availableTypes.emplace(AttributeType::ENERGY);
	m_availableTypes.emplace(AttributeType::ENTROPY);
	m_availableTypes.emplace(AttributeType::GRADIENT);
	m_availableTypes.emplace(AttributeType::INTENSITY);
	m_availableTypes.emplace(AttributeType::KURTOSIS);
    m_availableTypes.emplace(AttributeType::LAPLACIAN);
    m_availableTypes.emplace(AttributeType::MEAN);
	m_availableTypes.emplace(AttributeType::SKEWNESS);
    m_availableTypes.emplace(AttributeType::INERTIA);
	m_availableTypes.emplace(AttributeType::STANDARD_DEVIATION);
	m_availableTypes.emplace(AttributeType::VARIANCE);
}




AttributeManager::~AttributeManager() {

}
