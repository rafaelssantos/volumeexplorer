#ifndef GRID3D_CUH
#define GRID3D_CUH


#include <string>
#include <cuda_runtime.h>



namespace grid {


class Grid3D {
public:
	__host__ __device__ Grid3D(unsigned x, unsigned y, unsigned z);

	__host__ __device__ Grid3D(const uint3& dim);

	__host__ __device__ virtual ~Grid3D();

	__host__ __device__ void setSpacing(const float3& spacing);

	__host__ __device__ void setSpacing(float x, float y, float z);

	__host__ __device__ const float3& spacing() const;

    __host__ __device__ const uint3& dim() const;

    __host__ __device__ unsigned int voxelCount() const;

    __host__ __device__ const float3& size() const;

    __host__ __device__ int index3toIndex(int x, int y, int z) const;

    __host__ __device__ int index3toIndex(const int3& index) const;

    __host__ __device__ int3 indexToIndex3(int index) const;

    __host__ __device__ int3 floorPosToIndex(const float3& pos) const;

    __host__ __device__ int3 floorPosToIndex(float x, float y, float z) const;

    __host__ __device__ int3 roundPosToIndex(const float3& pos) const;

    __host__ __device__ int3 roundPosToIndex(float x, float y, float z) const;

    __host__ __device__ int3 ceilPosToIndex(const float3& pos) const;

    __host__ __device__ int3 ceilPosToIndex(float x, float y, float z) const;

    __host__ __device__ bool isPosIn(float x, float y, float z) const;

    __host__ __device__ bool isPosIn(const float3& pos) const;

    __host__ __device__ bool isIndex3In(int x, int y, int z) const;

    __host__ __device__ bool isIndex3In(const int3& index) const;

    __host__ __device__ float diameter() const;

    __host__ __device__ float voxelDiameter() const;

    __host__ __device__ const float3& center() const;

    virtual std::string toString();


private:
    __host__ __device__ virtual void measure();



private:
	float3 m_spacing;
    float3 m_size;
    uint3 m_dim;
    float3 m_center;
    float m_diameter;
    float m_voxelDiameter;

};


}


#endif
