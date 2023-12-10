#include "glpboimagememmanager.h"


#include "cuda_utils/helper_cuda.h"



using namespace rendering::image;





GlPBOImageMemManager& GlPBOImageMemManager::instance() {
	static GlPBOImageMemManager instance;

    return instance;
}





GlPBOImage* GlPBOImageMemManager::cloneToDevice(const GlPBOImage* hostImage) const {
    GlPBOImage *devImage = nullptr;

    checkCudaErrors(cudaMalloc((void**)&devImage, sizeof(GlPBOImage)));
    checkCudaErrors(cudaMemcpy(devImage, hostImage, sizeof(GlPBOImage), cudaMemcpyHostToDevice));

    return devImage;
}





void GlPBOImageMemManager::deviceFree(GlPBOImage* devImage) const {
    checkCudaErrors(cudaFree(devImage));
}





void GlPBOImageMemManager::copyToDevice(GlPBOImage* devImage, GlPBOImage* hostImage) const {
     checkCudaErrors(cudaMemcpy(devImage, hostImage, sizeof(GlPBOImage), cudaMemcpyHostToDevice));
}





GlPBOImageMemManager::GlPBOImageMemManager() {

}





GlPBOImageMemManager::~GlPBOImageMemManager() {

}
