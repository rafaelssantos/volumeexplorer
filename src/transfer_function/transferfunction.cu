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




__host__ __device__ float4 TransferFunction::colorAt(const float3& pos, const float3& lightPos, const Illumination &illum, const Interpolation &interpSpecs) const {
    float4 color;

    if(interpSpecs == Interpolation::TRILINEAR) {
        color = trilinearColorAt(pos);
    }
    else {
        color = nearestColorAt(pos);
    }

    if (illum.enabled){
        float3 shading = blinnPhongIllum(pos, lightPos, illum);

        color.x = fminf(1.0f, color.x * shading.x + color.x * shading.y + shading.z);
        color.y = fminf(1.0f, color.y * shading.x + color.y * shading.y + shading.z);
        color.z = fminf(1.0f, color.z * shading.x + color.z * shading.y + shading.z);
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

    float3 halfwayDir;
    halfwayDir.x = lightPos.x + pos.x;
    halfwayDir.y = lightPos.y + pos.y;
    halfwayDir.z = lightPos.z + pos.z;
    halfwayDir= QuaternionCalculator::normalize(halfwayDir);



    float ambient = illumination.ambientK;
    float diffuse = illumination.diffuseK * fmaxf(QuaternionCalculator::dotProduct(lightDir, normal), 0.0f);
    float specular = illumination.specularK * fmaxf(QuaternionCalculator::dotProduct(halfwayDir, normal), 0.0f);



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





__host__ __device__ float4 TransferFunction::trilinearColorAt(const float3& p) const {
    int3 index0 = floorPosToIndex(p);
    int3 index1 = {index0.x + 1, index0.y + 1, index0.z + 1};

    if(isIndex3In(index0) && isIndex3In(index1)){
        float xD, yD, zD;

        xD = (p.x - index0.x * spacing().x) / spacing().x;
        yD = (p.y - index0.y * spacing().y) / spacing().y;
        zD = (p.z - index0.z * spacing().z) / spacing().z;


        float4 color000, color001, color010, color011, color100, color101, color110, color111;

        color000 = sampleAt(index0.x, index0.y, index0.z);
        color001 = sampleAt(index0.x, index0.y, index1.z);
        color010 = sampleAt(index0.x, index1.y, index0.z);
        color011 = sampleAt(index0.x, index1.y, index1.z);
        color100 = sampleAt(index1.x, index0.y, index0.z);
        color101 = sampleAt(index1.x, index0.y, index1.z);
        color110 = sampleAt(index1.x, index1.y, index0.z);
        color111 = sampleAt(index1.x, index1.y, index1.z);

        float4 color00, color01, color10, color11;

        color00.x = color000.x * (1 - xD) + color100.x * xD;
        color00.y = color000.y * (1 - xD) + color100.y * xD;
        color00.z = color000.z * (1 - xD) + color100.z * xD;
        color00.w = color000.w * (1 - xD) + color100.w * xD;

        color01.x = color001.x * (1 - xD) + color101.x * xD;
        color01.y = color001.y * (1 - xD) + color101.y * xD;
        color01.z = color001.z * (1 - xD) + color101.z * xD;
        color01.w = color001.w * (1 - xD) + color101.w * xD;

        color10.x = color010.x * (1 - xD) + color110.x * xD;
        color10.y = color010.y * (1 - xD) + color110.y * xD;
        color10.z = color010.z * (1 - xD) + color110.z * xD;
        color10.w = color010.w * (1 - xD) + color110.w * xD;

        color11.x = color011.x * (1 - xD) + color111.x * xD;
        color11.y = color011.y * (1 - xD) + color111.y * xD;
        color11.z = color011.z * (1 - xD) + color111.z * xD;
        color11.w = color011.w * (1 - xD) + color111.w * xD;


        float4 color0, color1;

        color0.x = color00.x * (1 - yD) + color10.x * yD;
        color0.y = color00.y * (1 - yD) + color10.y * yD;
        color0.z = color00.z * (1 - yD) + color10.z * yD;
        color0.w = color00.w * (1 - yD) + color10.w * yD;

        color1.x = color01.x * (1 - yD) + color11.x * yD;
        color1.y = color01.y * (1 - yD) + color11.y * yD;
        color1.z = color01.z * (1 - yD) + color11.z * yD;
        color1.w = color01.w * (1 - yD) + color11.w * yD;

        float4 color;

        color.x = color0.x * (1 - zD) + color1.x * zD;
        color.y = color0.y * (1 - zD) + color1.y * zD;
        color.z = color0.z * (1 - zD) + color1.z * zD;
        color.w = color0.w * (1 - zD) + color1.w * zD;

        return color;
    }
    else{
        return sampleAt(index0);
    }
}
