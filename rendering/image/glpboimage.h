#ifndef GLPBOIMAGE_CUH
#define GLPBOIMAGE_CUH


#include <cstddef>
#include <cuda_runtime.h>




namespace rendering {
class Render;      //Forward Declaration
}




namespace rendering {
namespace image {
class GlPBOImage {
	friend class rendering::Render;


public:
	__host__ __device__ GlPBOImage();

	__host__ __device__ GlPBOImage(unsigned width, unsigned height);

	__host__ __device__ GlPBOImage(const uint2& size);

	__host__ __device__ virtual ~GlPBOImage();

	__host__ __device__ void setSize(unsigned width, unsigned height);

	__host__ __device__ void setSize(const uint2& size);

	__host__ __device__ const uint2& size() const;

	__host__ __device__ unsigned pixelCount() const;

	__host__ __device__ float pixelAspect() const;

	__host__ __device__ void resizePixelAspect(float diagonal, float zoomFunction);

	__host__ __device__ void setPixelColor(int x, int y, const uchar4& color);

	__host__ __device__ void setPixelColor(const int2& index, const uchar4& color);

	__host__ __device__ int int2ToIntIndex(int x, int y) const;

	__host__ __device__ int int2ToIntIndex(const int2& index) const;



private:
	uint2 m_size;
	float m_pixelAspect;
	std::byte* m_pboData;
};
}
}


#endif
