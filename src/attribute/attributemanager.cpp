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
    vector<vector<float>*>* values = new vector<vector<float>*>();
    vector<string> names;
    vector<float>* value = nullptr;


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
        names.emplace_back(name(*t));

		switch (*t) {
            case AttributeType::ABSOLUTE_DEVIATION:
                value = absoluteDeviation.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
            case AttributeType::CONTRAST:
                value = constrast.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
            case AttributeType::ENERGY :
                value = energy.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
            case AttributeType::ENTROPY :
                value = entropy.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
			case AttributeType::GRADIENT :
                value = gradient.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
				break;
            case AttributeType::INERTIA:
                value = inertia.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
            case AttributeType::KURTOSIS:
                value = kurtosis.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
            case AttributeType::INTENSITY :
                value = intensity.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
            case AttributeType::LAPLACIAN :
                value = laplacian.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
			case AttributeType::MEAN :
                value = mean.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
				break;
            case AttributeType::SKEWNESS:
                value = skewness.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
			case AttributeType::STANDARD_DEVIATION:
                value = standardDeviation.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
				break;
            case AttributeType::VARIANCE:
                value = variance.extract(m_volume, voxelCount, m_kernelBlockDim, mask);
                values->emplace_back(value);
                break;
		}
	}

    if(filePath != "" && !names.empty()){
        // saveToCSV(*data, descriptions, filePath);
        saveToAttr(*values, names, filePath);
    }

    return values;
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




void AttributeManager::free(std::vector<std::vector<float>* >* values) const {
    if(values != nullptr){
        for(auto i = 0u; i < values->size(); i++){
            delete values->at(i);
            values->at(i) = nullptr;
		}
	}
    delete values;
    values = nullptr;
}



const std::set<AttributeType>& AttributeManager::availableTypes() const {
	return m_availableTypes;
}



string AttributeManager::name(AttributeType type) const {
    string name = "None";

	switch (type) {
		case AttributeType::ABSOLUTE_DEVIATION:
            name = "Absolute deviation";
			break;
        case AttributeType::CONTRAST:
            name = "Contrast";
            break;
		case AttributeType::ENERGY:
            name = "Energy";
			break;
		case AttributeType::ENTROPY:
            name = "Entropy";
			break;
		case AttributeType::GRADIENT:
            name = "Gradient Magnitude";
			break;
        case AttributeType::INERTIA:
            name = "Inertia";
            break;
		case AttributeType::INTENSITY:
            name = "Intensity";
			break;
		case AttributeType::KURTOSIS:
            name = "Kurtosis";
			break;
        case AttributeType::LAPLACIAN:
            name = "Laplacian Magnitude";
            break;
		case AttributeType::MEAN:
            name = "Mean";
			break;
		case AttributeType::SKEWNESS:
            name = "Skewness";
            break;
		case AttributeType::STANDARD_DEVIATION:
            name = "Standard deviation";
			break;
		case AttributeType::VARIANCE:
            name = "Variance";
			break;
	}

        return name;
}

void AttributeManager::saveToCSV(const std::vector<std::vector<float> *> &data, const std::vector<string> &names, std::string filePath) const {
    std::ofstream file;

    file.open(filePath, ios_base::app);

    for(int i = 0; i < names.size() - 1; i++){
        file << names[i] << ",";
    }
    file << names.back() << "\n";

    for(int i = 0; i < data.front()->size(); i++){
        for(int a = 0; a < data.size(); a++){
            file << data.at(a)->at(i);
            if(a < data.size() - 1){
                file << ",";
            }
            else{
                file << "\n";
            }
        }
    }

    file.close();
}


void AttributeManager::saveToAttr(const std::vector<std::vector<float> *> &data, const std::vector<std::string> &names, std::string filePath) const {
    std::ofstream file;

    file.open(filePath, ios_base::binary | ios::out);
    string strNames = "";

    for(int i = 0; i < names.size() - 1; i++){
        strNames = strNames +  names[i] + ",";
    }
    strNames = strNames + names.back();

    int n = data.front()->size();                                  //Number of instances
    file.write(reinterpret_cast<char*>(&n), sizeof(int));
    int size = strNames.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    file.write(reinterpret_cast<char*>(&strNames[0]), size);

    for(int a = 0; a < data.size(); a++){
        for(int i = 0; i < data.at(a)->size(); i++){
            float value = data.at(a)->at(i);
            file.write(reinterpret_cast<char*>(&value), sizeof(float));
        }
    }

    file.close();
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
