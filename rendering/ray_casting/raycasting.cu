#include "raycasting.cuh"


#include <device_launch_parameters.h>
#include "cuda_utils/kerneldimscalculator.h"
#include "cuda_utils/helper_cuda.h"
#include "cuda_utils/threadindexing.cuh"
#include "quaternion/quaternioncalculator.cuh"




using namespace quaternion;
using namespace rendering::view;
using namespace rendering::image;
using namespace rendering;
using namespace rendering::ray_casting;
using namespace transfer_function;
using namespace volume;





__global__ void _rayCastingKernel(GlPBOImage image, const Volume* volume, const TransferFunction* transferFunc, const RenderingSpecs renderingSpecs, const Viewer viewer, const Illumination illumination, const Interpolation interpolation) {
    const unsigned tid = ThreadIndexing::globalIdx();


    if(tid < image.pixelCount()) {
        uint2 pixel;        //Pixel associado à thread atual
        pixel.x = tid % image.size().x;
        pixel.y = tid / image.size().x;

        float3 eye;     /* Posição do observador associada à thread atual. Projeção ortogonal em relação ao plano de imagem.Será iterada até entrar e sair do volume.*/
        eye.x = pixel.x * image.pixelAspect() - (image.pixelAspect() * image.size().x - volume->size().x) / 2.0f;
        eye.y = pixel.y * image.pixelAspect() - (image.pixelAspect() * image.size().y - volume->size().y) / 2.0f;
        eye.z = volume->center().z + volume->diameter() / 2.0f + renderingSpecs.step;

        float3 pos;
        pos.x = eye.x;
        pos.y = eye.y;
        pos.z = eye.z - renderingSpecs.step;

        eye = QuaternionCalculator::rotate(eye, viewer.rotation, volume->center());
        pos = QuaternionCalculator::rotate(pos, viewer.rotation, volume->center());

        unsigned nSteps = 1;
        float3 step;
        step.x = pos.x - eye.x;
        step.y = pos.y - eye.y;
        step.z = pos.z - eye.z;

        float4 colorOut;  //Cor acumulada que será atribuida ao pixel
        colorOut.x = 0;   //Vermelho
        colorOut.y = 0;   //verde
        colorOut.z = 0;   //Azul
        colorOut.w = 0;   //Opacidade

        float opacityCorrFactor = renderingSpecs.step / volume->voxelDiameter();

        while(nSteps <= renderingSpecs.maxSteps && volume->isInCircumsphere(pos)) {                                                  //Dentro da esfera circunscrita ao volume
            if(volume->isPosIn(pos)) {
                while(nSteps <= renderingSpecs.maxSteps && volume->isPosIn(pos) && colorOut.w <= renderingSpecs.maxOpacity) {       //Dentro do volume
                    float4 colorIn = transferFunc->colorAt(pos, eye, illumination, interpolation);

                    colorIn.w = 1.0f - powf(1.0f - colorIn.w, opacityCorrFactor);

                    colorOut.x = colorOut.x + colorIn.x * colorIn.w * (1 - colorOut.w);
                    colorOut.y = colorOut.y + colorIn.y * colorIn.w * (1 - colorOut.w);
                    colorOut.z = colorOut.z + colorIn.z * colorIn.w * (1 - colorOut.w);
                    colorOut.w = colorOut.w + colorIn.w * (1 - colorOut.w);

                    nSteps++;
                    pos.x = ((nSteps * renderingSpecs.step) * step.x) / renderingSpecs.step + eye.x;
                    pos.y = ((nSteps * renderingSpecs.step) * step.y) / renderingSpecs.step + eye.y;
                    pos.z = ((nSteps * renderingSpecs.step) * step.z) / renderingSpecs.step + eye.z;
                }
                break;
            }

            nSteps++;
            pos.x = ((nSteps * renderingSpecs.step) * step.x) / renderingSpecs.step + eye.x;
            pos.y = ((nSteps * renderingSpecs.step) * step.y) / renderingSpecs.step + eye.y;
            pos.z = ((nSteps * renderingSpecs.step) * step.z) / renderingSpecs.step + eye.z;
        }

        colorOut.x += (transferFunc->backgroundColor().x * transferFunc->backgroundColor().w * (1.0f - colorOut.w));
        colorOut.y += (transferFunc->backgroundColor().y * transferFunc->backgroundColor().w * (1.0f - colorOut.w));
        colorOut.z += (transferFunc->backgroundColor().z * transferFunc->backgroundColor().w * (1.0f - colorOut.w));
        colorOut.w += transferFunc->backgroundColor().w  * (1.0f - colorOut.w);

        uchar4 accumByteColor;

        accumByteColor.x = static_cast<unsigned char>(colorOut.x * 255.0f);
        accumByteColor.y = static_cast<unsigned char>(colorOut.y * 255.0f);
        accumByteColor.z = static_cast<unsigned char>(colorOut.z * 255.0f);
        accumByteColor.w = static_cast<unsigned char>(colorOut.w * 255.0f);

        image.setPixelColor(pixel.x, pixel.y, accumByteColor);
    }
}





RayCasting::RayCasting() {

}





RayCasting::~RayCasting() {

}





RayCasting& RayCasting::instance() {
    static RayCasting instance;

    return instance;
}





void RayCasting::kernelLaunch(GlPBOImage& image, const Volume* volume, const TransferFunction* transferFunc, const RenderingSpecs& renderingSpecs, const view::Viewer& observer, dim3 blockDim, unsigned threadsCount, const Illumination& illumination, const Interpolation& interpolation) {
    dim3 gridDim;
    gridDim = KernelDimsCalculator::instance().calc(blockDim, threadsCount);

    _rayCastingKernel<<<gridDim, blockDim>>>(image, volume, transferFunc, renderingSpecs, observer, illumination, interpolation);
    getLastCudaError("Ray casting kernel failed.");
}
