#include "grid3d.cuh"


#include <cmath>



using namespace std;
using namespace grid;





__host__ __device__ Grid3D::Grid3D(unsigned x, unsigned y, unsigned z) {
    m_dim.x = x;
    m_dim.y = y;
    m_dim.z = z;
	m_spacing.x = m_spacing.y = m_spacing.z = 1;
    m_size.x = m_size.y = m_size.z = 0;
    m_center.x = m_center.y = m_center.z = 0;
    m_diameter = 0;
    m_voxelDiameter = 0;
}





__host__ __device__ Grid3D::Grid3D(const uint3& dim) {
    m_dim = dim;
	m_spacing.x = m_spacing.y = m_spacing.z = 1;
    m_size.x = m_size.y = m_size.z = 0;
    m_center.x = m_center.y = m_center.z = 0;
    m_diameter = 0;
    m_voxelDiameter = 0;
}





__host__ __device__ Grid3D::~Grid3D() {

}





__host__ __device__ void Grid3D::setSpacing(const float3& spacing) {
	m_spacing = spacing;

    measure();
}





__host__ __device__ void Grid3D::setSpacing(float x, float y, float z) {
	m_spacing.x = x;
	m_spacing.y = y;
	m_spacing.z = z;

    measure();
}





__host__ __device__ const float3& Grid3D::spacing() const {
	return m_spacing;
}





__host__ __device__ const uint3& Grid3D::dim() const {
    return m_dim;
}





__host__ __device__ unsigned int Grid3D::voxelCount() const {
    return m_dim.x * m_dim.y * m_dim.z;
}





__host__ __device__ const float3& Grid3D::size() const {
    return m_size;
}





__host__ __device__ int Grid3D::index3toIndex(int x, int y, int z) const {
    if(x < 0 || x >= m_dim.x || y < 0 || y >= m_dim.y || z < 0 || z >= m_dim.z){
        return -1;
    }
    else{
        return z * static_cast<int>(m_dim.y * m_dim.x) + y * static_cast<int>(m_dim.x) + x;
    }
}





__host__ __device__ int Grid3D::index3toIndex(const int3& index) const {
    if(index.x < 0 || index.x >= m_dim.x || index.y < 0 || index.y >= m_dim.y || index.z < 0 || index.z >= m_dim.z){
        return -1;
    }
    else{
        return index.z * static_cast<int>(m_dim.y * m_dim.x) + index.y * static_cast<int>(m_dim.x) + index.x;
    }
}





__host__ __device__ int3 Grid3D::indexToIndex3(int index) const {
    int3 int3Index;

    int3Index.z = (index / static_cast<int>(m_dim.y * m_dim.x));
    int3Index.y = (index % static_cast<int>(m_dim.y * m_dim.x)) / static_cast<int>(m_dim.x);
    int3Index.x = (index % static_cast<int>(m_dim.y * m_dim.x)) % static_cast<int>(m_dim.x);

    return int3Index;
}





__host__ __device__ int3 Grid3D::floorPosToIndex(const float3& pos) const {
    int3 index;

	index.x = static_cast<int>(pos.x /spacing().x);
	index.y = static_cast<int>(pos.y /spacing().y);
	index.z = static_cast<int>(pos.z /spacing().z);

    return index;
}




__host__ __device__ int3 Grid3D::floorPosToIndex(float x, float y, float z) const {
    int3 index;

	index.x = static_cast<int>(x /spacing().x);
	index.y = static_cast<int>(y /spacing().y);
	index.z = static_cast<int>(z /spacing().z);

    return index;
}





__host__ __device__ int3 Grid3D::roundPosToIndex(const float3& pos) const {
    int3 index;

	index.x = static_cast<int>(roundf(pos.x / spacing().x));
	index.y = static_cast<int>(roundf(pos.y / spacing().y));
	index.z = static_cast<int>(roundf(pos.z / spacing().z));

    return index;
}




__host__ __device__ int3 Grid3D::roundPosToIndex(float x, float y, float z) const {
    int3 index;

	index.x = static_cast<int>(roundf(x / spacing().x));
	index.y = static_cast<int>(roundf(y / spacing().y));
	index.z = static_cast<int>(roundf(z / spacing().z));

    return index;
}




__host__ __device__ int3 Grid3D::ceilPosToIndex(const float3& pos) const {
    int3 index;

	index.x = static_cast<int>(ceilf(pos.x / spacing().x));
	index.y = static_cast<int>(ceilf(pos.y / spacing().y));
	index.z = static_cast<int>(ceilf(pos.z / spacing().z));

    return index;
}




__host__ __device__ int3 Grid3D::ceilPosToIndex(float x, float y, float z) const {
    int3 index;

	index.x = static_cast<int>(ceilf(x / spacing().x));
	index.y = static_cast<int>(ceilf(y / spacing().y));
	index.z = static_cast<int>(ceilf(z / spacing().z));

    return index;
}





__host__ __device__ bool Grid3D::isPosIn(float x, float y, float z) const {
    if(x < 0 || y < 0 || z < 0 || x > m_size.x || y > m_size.y || z > m_size.z) {
        return false;
    }
    else{
        return true;
    }
}





__host__ __device__ bool Grid3D::isPosIn(const float3& pos) const {
    if(pos.x < 0 || pos.y < 0 || pos.z < 0 || pos.x > m_size.x || pos.y > m_size.y || pos.z > m_size.z) {
        return false;
    }
    else{
        return true;
    }
}






__host__ __device__ bool Grid3D::isIndex3In(int x, int y, int z) const {
    if(x < 0 || y < 0 || z < 0 || x >= m_dim.x || y >= m_dim.y|| z >= m_dim.z) {
        return false;
    }
    else{
        return true;
    }
}





__host__ __device__ bool Grid3D::isIndex3In(const int3& index) const {
    if(index.x < 0 || index.y < 0 || index.z < 0 || index.x >= m_dim.x || index.y >= m_dim.y || index.z >= m_dim.z) {
        return false;
    }
    else{
        return true;
    }
}



__host__ __device__ float Grid3D::diameter() const {
    return m_diameter;
}




__host__ __device__ float Grid3D::voxelDiameter() const {
    return m_voxelDiameter;
}



__host__ __device__ const float3 &Grid3D::center() const {
    return m_center;
}





string Grid3D::toString() {
    string description;

	description = "Grid: " + to_string(m_dim.x) + "×" + to_string(m_dim.y) + "×" + to_string(m_dim.z) + " | " ;
    description += "Spacing: " + to_string(m_spacing.x) + "×" + to_string(m_spacing.y) + "×" + to_string(m_spacing.z);

    return description;
}





__host__ __device__ void Grid3D::measure() {
	m_size.x = (m_dim.x - 1) * m_spacing.x;
	m_size.y = (m_dim.y - 1) * m_spacing.y;
	m_size.z = (m_dim.z - 1) * m_spacing.z;

    m_center = {m_size.x / 2.0f, m_size.y / 2.0f, m_size.z / 2.0f};
    m_diameter = sqrtf(m_size.x * m_size.x + m_size.y * m_size.y + m_size.z * m_size.z);
    m_voxelDiameter = sqrtf(m_spacing.x * m_spacing.x + m_spacing.y * m_spacing.y + m_spacing.z * m_spacing.z);
}
