#ifndef RENDERINGSPECS_H
#define RENDERINGSPECS_H




namespace rendering {


struct RenderingSpecs {
	float maxOpacity;
    unsigned maxSteps;
	float step;
    float zoomIncrement;
};


typedef struct RenderingSpecs RenderingSpecs;


}

#endif // RENDERINGSPECS_H
