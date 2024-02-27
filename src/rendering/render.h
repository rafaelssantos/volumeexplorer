#ifndef RENDER_H
#define RENDER_H

#include <string>
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>
#include "volume/volume.cuh"
#include "transfer_function/transferfunction.cuh"
#include "image/glpboimage.h"
#include "renderingspecs.h"
#include "view/viewer.h"
#include "graphics_utils/zoom.h"
#include "graphics_utils/rotatationsense.h"
#include "graphics_utils/rotationaxis.h"




namespace rendering {



class Render {
public:
    static Render& instance();

    void exec(unsigned width, unsigned height, float diagonal);

	void unregisterGlPBO();

	void registerGlPBO(GLuint pbo);

    void setVolume(const volume::Volume *volume);

	void setTransferFunction(const transfer_function::TransferFunction *transferFunction);

    const RenderingSpecs& prop() const;

    void zoom(graphics_utils::Zoom zoom);

    void rotate(graphics_utils::RotationAxis axis, graphics_utils::RotationSense sense);

	void resetViewer();



private:
    Render();

    virtual ~Render();


	struct cudaGraphicsResource *m_cudaPBOResource;
    rendering::image::GlPBOImage* m_hostImage;
    rendering::image::GlPBOImage* m_devImage;
    const volume::Volume *m_devVolume;
	const transfer_function::TransferFunction*  m_transferFunction;
    rendering::view::Viewer m_viewer;
};


}


#endif // RENDER_H
