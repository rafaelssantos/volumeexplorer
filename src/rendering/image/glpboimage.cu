#include "glpboimage.h"

#include <cmath>


using namespace std;
using namespace rendering::image;





__host__ __device__ GlPBOImage::GlPBOImage() {
    m_size.x = 0;
    m_size.y = 0;
    m_pixelAspect = 1;
    m_pboData = nullptr;
}





__host__ __device__ GlPBOImage::GlPBOImage(unsigned width, unsigned height) {
    m_size.x = width;
    m_size.y = height;
    m_pixelAspect = 1;
    m_pboData = nullptr;
}





__host__ __device__ GlPBOImage::GlPBOImage(const uint2& size) {
    m_size.x = size.x;
    m_size.y = size.y;
    m_pixelAspect = 1;
    m_pboData = nullptr;
}




__host__ __device__ GlPBOImage::~GlPBOImage() {

}





__host__ __device__ void GlPBOImage::setSize(unsigned width, unsigned height) {
    m_size.x = width;
    m_size.y = height;
}





__host__ __device__ void GlPBOImage::setSize(const uint2& size) {
    m_size = size;
}





__host__ __device__ const uint2& GlPBOImage::size() const {
    return m_size;
}





__host__ __device__ unsigned GlPBOImage::pixelCount() const {
    return m_size.x * m_size.y;
}





__host__ __device__ float GlPBOImage::pixelAspect() const {
    return m_pixelAspect;
}





__host__ __device__ void GlPBOImage::resizePixelAspect(float diagonal, float zoomFunction) {
    m_pixelAspect = (diagonal * zoomFunction) / fminf(m_size.x, m_size.y);
}





__host__ __device__ void GlPBOImage::setPixelColor(int x, int y, const uchar4 &color) {
    int globalIndex = int2ToIntIndex(x, y);

    *(m_pboData + globalIndex * 4 + 0) = static_cast<byte>(color.x);
    *(m_pboData + globalIndex * 4 + 1) = static_cast<byte>(color.y);
    *(m_pboData + globalIndex * 4 + 2) = static_cast<byte>(color.z);
    *(m_pboData + globalIndex * 4 + 3) = static_cast<byte>(color.w);
}





__host__ __device__ void GlPBOImage::setPixelColor(const int2& index, const uchar4 &color) {
    int globalIndex = int2ToIntIndex(index);

    *(m_pboData + globalIndex * 4 + 0) = static_cast<byte>(color.x);
    *(m_pboData + globalIndex * 4 + 1) = static_cast<byte>(color.y);
    *(m_pboData + globalIndex * 4 + 2) = static_cast<byte>(color.z);
    *(m_pboData + globalIndex * 4 + 3) = static_cast<byte>(color.w);
}





__host__ __device__ int GlPBOImage::int2ToIntIndex(int x, int y) const {
    return y * static_cast<int>(m_size.x) + x;
}





__host__ __device__ int GlPBOImage::int2ToIntIndex(const int2& index) const {
    return int2ToIntIndex(index.x, index.y);
}
