#include "attribute.h"

using namespace attribute;
using namespace std;
using namespace volume;



Attribute::Attribute() {
	m_name = "";
}



Attribute::~Attribute() {

}




AttributeType Attribute::type() const {
	return m_type;
}



const string& Attribute::name() const {
	return m_name;
}




vector<float>* Attribute::extract(const Volume* volume, size_t voxelCount, dim3 blockDim, int mask) {
    thrust::host_vector<float> * hostVectorData = kernelLaunch(volume, voxelCount, blockDim, mask);
    vector<float> *data = new vector<float>();

	for(auto i = hostVectorData->begin(); i != hostVectorData->end(); i++){
		data->emplace_back(*i);
	}

	delete hostVectorData;
    hostVectorData = nullptr;

	return data;
}




void Attribute::setType(AttributeType type) {
	m_type = type;
}



void Attribute::setName(const string& description) {
	m_name = description;
}
