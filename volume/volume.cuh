#ifndef VOLUME_CUH
#define VOLUME_CUH


#include <cuda_runtime.h>
#include <vector>
#include "grid/grid3d.cuh"



namespace volume {


class VolumeManager;            //Forward Declaration
class VolumeMemManager;


}




namespace volume {


class Volume : public grid::Grid3D {
        friend class VolumeManager;
        friend class VolumeMemManager;



    public:
        __host__ __device__ Volume(unsigned x, unsigned y, unsigned z);

        __host__ __device__ Volume(const uint3& dim);

        __host__ __device__ virtual ~Volume() override;

        __host__ __device__ std::byte sampleAt(int x, int y, int z) const;

        __host__ __device__ std::byte sampleAt(const int3& index) const;

        __host__ __device__ bool isInCircumsphere(float x, float y, float z) const;

        __host__ __device__ bool isInCircumsphere(const float3& pos) const;

        virtual std::string toString() override;




    private:        
        std::byte* m_data;
};


}

#endif
