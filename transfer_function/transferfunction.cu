#include "transferfunction.cuh"

#include <cmath>
#include "quaternion/quaternioncalculator.cuh"


using namespace quaternion;
using namespace grid;
using namespace transfer_function;






__host__ __device__ TransferFunction::TransferFunction(unsigned x, unsigned y, unsigned z) : Grid3D(x, y, z) {
    m_colors = nullptr;
    m_normals = nullptr;

    m_bgColor.x = 1.0f;
    m_bgColor.y = 1.0f;
    m_bgColor.z = 1.0f;
    m_bgColor.w = 1.0f;
}





__host__ __device__ TransferFunction::TransferFunction(const uint3& dim) : Grid3D(dim) {
    m_colors = nullptr;
    m_normals = nullptr;

    m_bgColor.x = 1.0f;
    m_bgColor.y = 1.0f;
    m_bgColor.z = 1.0f;
    m_bgColor.w = 1.0f;
}




__host__ __device__ TransferFunction::~TransferFunction() {
#ifndef __CUDA_ARCH__
    delete []  m_colors;
    m_colors = nullptr;

    delete [] m_normals;
    m_normals = nullptr;
#endif
}


__host__ __device__ float4 TransferFunction::colorAt(float x, float y, float z, const float3& lightPos, const Illumination &illumination, const Interpolation &filterType) const {
    float3 pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;

    return colorAt(pos, lightPos, illumination, filterType);
}




__host__ __device__ float4 TransferFunction::colorAt(const float3& pos, const float3& lightPos, const Illumination &illumSpecs, const Interpolation &interpSpecs) const {
    float4 color;

    if(interpSpecs == Interpolation::TRILINEAR) {
        color = trilinearColorAt(pos);
    }
    else {
        color = nearestColorAt(pos);
    }

    if (illumSpecs.enabled){
        float3 illum = blinnPhongIllum(pos, lightPos, illumSpecs);

        color.x = fminf(1.0f, color.x * illum.x + color.x * illum.y + illum.z);
        color.y = fminf(1.0f, color.y * illum.x + color.y * illum.y + illum.z);
        color.z = fminf(1.0f, color.z * illum.x + color.z * illum.y + illum.z);
    }


    return color;
}





__host__ __device__ float4 TransferFunction::sampleAt(int x, int y, int z) const {
    return sampleAt(index3toIndex(x,y,z));
}




__host__ __device__ float4 TransferFunction::sampleAt(const int3& index) const {
    return sampleAt(index3toIndex(index));
}



__host__ __device__ float4 TransferFunction::sampleAt(size_t index) const {
    uchar4 color = *(m_colors + index);
    float4 colorF;


    colorF.x = color.x / 255.0f;
    colorF.y = color.y / 255.0f;
    colorF.z = color.z / 255.0f;
    colorF.w = color.w / 255.0f;

    return colorF;
}



__host__ __device__ float3 TransferFunction::blinnPhongIllum(const float3& pos, const float3& lightPos, const Illumination &illumination) const {
    int3 index3 = roundPosToIndex(pos);

    float3 normal = *(m_normals + index3toIndex(index3));

    float3 lightDir;
    lightDir.x = (lightPos.x - pos.x);
    lightDir.y = (lightPos.y - pos.y);
    lightDir.z = (lightPos.z - pos.z);
    lightDir = QuaternionCalculator::normalize(lightDir);

    float  diffuseLight = fmaxf(QuaternionCalculator::dotProduct(normal, lightDir), 0.0f);

    float ambient = illumination.ambientPower;
    float diffuse = illumination.diffusePower * diffuseLight;
    float specular = 0.0f;

    if(diffuseLight > 0){
        specular = illumination.specularPower * powf(diffuseLight, illumination.shininess);
    }


    float3 light;

    light.x = ambient;
    light.y = diffuse;
    light.z = specular;

    return light;

}



__host__ __device__ void TransferFunction::setSampleAt(int x, int y, int z, const uchar4 &value) {
    *(m_colors + index3toIndex(x, y , z)) = value;
}






__host__ __device__ void TransferFunction::setSampleAt(const int3& index, const uchar4 &value) {
    *(m_colors + index3toIndex(index)) = value;
}




__host__ __device__ void TransferFunction::setSampleAt(size_t index, const uchar4 &value) {
    *(m_colors + index) = value;

}






__host__ __device__ const float4& TransferFunction::backgroundColor() const {
    return m_bgColor;
}





__host__ __device__ void TransferFunction::setBackGroundColor(const float4& bgColor) {
    m_bgColor = bgColor;
}






__host__ __device__ void TransferFunction::setBackGroundColor(const uchar4 &bgColor) {
    m_bgColor.x = bgColor.x / 255.0f;
    m_bgColor.y = bgColor.y / 255.0f;
    m_bgColor.z = bgColor.z / 255.0f;
    m_bgColor.w = bgColor.w / 255.0f;
}






__host__ __device__ void TransferFunction::setBackGroundColor(float red, float green, float blue, float opacity) {
    m_bgColor.x = red;
    m_bgColor.y = green;
    m_bgColor.z = blue;
    m_bgColor.w = opacity;
}






__host__ __device__ void TransferFunction::setBackGroundColor(std::byte red, std::byte green, std::byte blue, std::byte opacity) {
    m_bgColor.x = static_cast<unsigned char>(red) / 255.0f;
    m_bgColor.y = static_cast<unsigned char>(green) / 255.0f;
    m_bgColor.z = static_cast<unsigned char>(blue) / 255.0f;
    m_bgColor.w = static_cast<unsigned char>(opacity)/ 255.0f;
}





__host__ __device__ float4 TransferFunction::nearestColorAt(const float3& pos) const {
    return sampleAt(roundPosToIndex(pos));
}





__host__ __device__ float4 TransferFunction::trilinearColorAt(const float3& pos) const {
    int3 index = floorPosToIndex(pos);

    if(isIndex3In(index.x, index.y, index.z) && isIndex3In(index.x + 1, index.y + 1, index.z + 1)){
        float4 color = {0, 0, 0, 0};

        float x, y, z;

        x = pos.x - index.x * spacing().x;
        y = pos.y - index.y * spacing().y;
        z = pos.z - index.z * spacing().z;

        float4 color000, color001, color010, color011, color100, color101, color110, color111;

        color000 = sampleAt(index.x, index.y, index.z);
        color001 = sampleAt(index.x, index.y, index.z + 1);
        color010 = sampleAt(index.x, index.y + 1, index.z);
        color011 = sampleAt(index.x, index.y + 1, index.z + 1);
        color100 = sampleAt(index.x + 1, index.y, index.z);
        color101 = sampleAt(index.x + 1, index.y, index.z + 1);
        color110 = sampleAt(index.x + 1, index.y + 1, index.z);
        color111 = sampleAt(index.x + 1, index.y + 1, index.z + 1);



        color.x =  (1 - x) * (1 - y) * (1 - z) * color000.x +
                        (1 - x) * (1 - y) * (z) * color001.x +
                        (1 - x) * (y) * (1 - z) * color010.x +
                        (1 - x) * (y) * (z) * color011.x +
                        (x) * (1 - y) * (1 - z) * color100.x +
                        (x) * (1 - y) * (z) * color101.x +
                        (x) * (y) * (1 - z) * color110.x +
                        (x) * (y) * (z) * color111.x;

        color.y =  (1 - x) * (1 - y) * (1 - z) * color000.y +
                        (1 - x) * (1 - y) * (z) * color001.y +
                        (1 - x) * (y) * (1 - z) * color010.y +
                        (1 - x) * (y) * (z) * color011.y +
                        (x) * (1 - y) * (1 - z) * color100.y +
                        (x) * (1 - y) * (z) * color101.y +
                        (x) * (y) * (1 - z) * color110.y +
                        (x) * (y) * (z) * color111.y;

        color.z = (1 - x) * (1 - y) * (1 - z) * color000.z +
                       (1 - x) * (1 - y) * (z) * color001.z +
                       (1 - x) * (y) * (1 - z) * color010.z +
                       (1 - x) * (y) * (z) * color011.z +
                       (x) * (1 - y) * (1 - z) * color100.z +
                       (x) * (1 - y) * (z) * color101.z +
                       (x) * (y) * (1 - z) * color110.z +
                       (x) * (y) * (z) * color111.z;

        color.w = (1 - x) * (1 - y) * (1 - z) * color000.w +
                       (1 - x) * (1 - y) * (z) * color001.w +
                       (1 - x) * (y) * (1 - z) * color010.w +
                       (1 - x) * (y) * (z) * color011.w +
                       (x) * (1 - y) * (1 - z) * color100.w +
                       (x) * (1 - y) * (z) * color101.w +
                       (x) * (y) * (1 - z) * color110.w +
                       (x) * (y) * (z) * color111.w;

        return color;
    }
    else{
        return sampleAt(index);
    }
}
