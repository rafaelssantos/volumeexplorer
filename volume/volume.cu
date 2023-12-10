#include "volume.cuh"

#include <cmath>
#include <string>



using namespace std;
using namespace volume;
using namespace grid;





__host__ __device__ Volume::Volume(unsigned x, unsigned y, unsigned z) : Grid3D(x, y, z) {
    m_data = nullptr;
}





__host__ __device__ Volume::Volume(const uint3& dim) : Grid3D(dim) {
    m_data = nullptr;
}





__host__ __device__ Volume::~Volume() {
#ifndef __CUDA_ARCH__
    delete []  m_data;
    m_data = nullptr;
#endif
}





__host__ __device__ std::byte Volume::sampleAt(int x, int y, int z) const {
    return *(m_data + index3toIndex(x, y, z));
}





__host__ __device__ std::byte Volume::sampleAt(const int3& index) const {
    return *(m_data + index3toIndex(index));
}



__host__ __device__ bool Volume::isInCircumsphere(float x, float y, float z) const {
    float opCatheter;
    float adjCatheter;
    float ray;
    float posToCenter;

    opCatheter = diameter()/2.0f;
    adjCatheter = diameter();
    ray = sqrtf(opCatheter * opCatheter + adjCatheter * adjCatheter);

    float dist_x = (x - center().x);
    float dist_y = (y - center().y);
    float dist_z = (z - center().z);

    posToCenter = sqrtf(dist_x * dist_x + dist_y * dist_y + dist_z * dist_z);

    return posToCenter <= ray;
}





__host__ __device__ bool Volume::isInCircumsphere(const float3& pos) const {
    float opCatheter;
    float adjCatheter;
    float ray;
    float posToCenter;

    opCatheter = diameter() / 2.0f;
    adjCatheter = diameter();
    ray = sqrtf(opCatheter * opCatheter + adjCatheter * adjCatheter);

    float dist_x = (pos.x - center().x);
    float dist_y = (pos.y - center().y);
    float dist_z = (pos.z - center().z);

    posToCenter = sqrtf(dist_x * dist_x + dist_y * dist_y + dist_z * dist_z);

    return posToCenter <= ray;
}



std::string Volume::toString() {
    return Grid3D::toString() + " | Voxels: " + to_string(voxelCount());
}
