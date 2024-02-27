#ifndef RAYCASTING_CUH
#define RAYCASTING_CUH


#include <cuda_runtime.h>
#include <cuda_gl_interop.h>
#include "volume/volume.cuh"
#include "transfer_function/transferfunction.cuh"
#include "rendering/image/glpboimage.h"
#include "rendering/renderingspecs.h"
#include "rendering/view/viewer.h"




namespace rendering {
namespace ray_casting {


class RayCasting{
public:
    static RayCasting& instance();

    void kernelLaunch(image::GlPBOImage &image, const volume::Volume* volume, const transfer_function::TransferFunction* transferFunction, const rendering::RenderingSpecs& renderingSpecs, const rendering::view::Viewer &observer, dim3 blockDim, unsigned threadsCount, const transfer_function::Illumination &illumination, const transfer_function::Interpolation &interpolation);


private:
    RayCasting();

    virtual ~RayCasting();
};


}
}

__global__ void _rayCastingKernel(rendering::image::GlPBOImage *image, const volume::Volume* volume, const transfer_function::TransferFunction* transferFunc, const rendering::RenderingSpecs renderingSpecs, const rendering::view::Viewer viewer, const transfer_function::Illumination illumination, const transfer_function::Illumination filterType);



#endif // RAYCASTING_H
