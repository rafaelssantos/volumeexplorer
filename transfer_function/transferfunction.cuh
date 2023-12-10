#ifndef TRANSFERFUNCTION_CUH
#define TRANSFERFUNCTION_CUH


#include "interpolation.h"
#include "illumination.h"
#include "grid/grid3d.cuh"
#include "types_extras/float8.h"




namespace transfer_function {
	class TransferFunctionManager;            //Forward Declaration
	class TFMemManager;
}






namespace transfer_function {
	class TransferFunction : public grid::Grid3D {
			friend class TransferFunctionManager;
			friend class TFMemManager;


		public:
			__host__ __device__ TransferFunction(unsigned x, unsigned y, unsigned z);

			__host__ __device__ TransferFunction(const uint3& dim);

			__host__ __device__ virtual ~TransferFunction() override;

            __host__ __device__ float4 colorAt(float x, float y, float z, const float3& lightPos, const transfer_function::Illumination& illumination, const transfer_function::Interpolation& filterType) const;

            __host__ __device__ float4 colorAt(const float3& pos, const float3& lightPos, const transfer_function::Illumination& illumSpecs, const transfer_function::Interpolation& interpSpecs) const;

			__host__ __device__ float4 sampleAt(int x,  int y, int z) const;

			__host__ __device__ float4 sampleAt(const int3& index) const;

			__host__ __device__ float4 sampleAt(size_t index) const;

			__host__ __device__ void setSampleAt(int x,  int y, int z, const uchar4& value);

			__host__ __device__ void setSampleAt(const int3& index, const uchar4& value);

			__host__ __device__ void setSampleAt(size_t index, const uchar4& value);

            __host__ __device__ const float4& backgroundColor() const;

            __host__ __device__ void setBackGroundColor(const float4& bgColor);

            __host__ __device__ void setBackGroundColor(const uchar4& bgColor);

            __host__ __device__ void setBackGroundColor(float red, float green, float blue, float opacity);

            __host__ __device__ void setBackGroundColor(std::byte red, std::byte green, std::byte blue, std::byte opacity);



		private:
            __host__ __device__ float4 nearestColorAt(const float3& pos) const;

            __host__ __device__ float4 trilinearColorAt(const float3& pos) const;

            __host__ __device__ float3 blinnPhongIllum(const float3 &pos, const float3 &lightPos, const Illumination &illumination) const;


			uchar4* m_colors;
			float3* m_normals;
            float4 m_bgColor;
    };
}


#endif
