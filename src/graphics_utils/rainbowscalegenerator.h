#ifndef RAINBOWSCALEGENERATOR_H
#define RAINBOWSCALEGENERATOR_H


#include <vector>
#include <cuda_runtime.h>


namespace graphics_utils {



class RainbowScaleGenerator {
public:
    static RainbowScaleGenerator& instance();

    float4 colorAt(int index, int colorCount, float opacity) const;



protected:
    RainbowScaleGenerator();

    virtual ~RainbowScaleGenerator();
};



}



#endif // RAINBOWSCALEGENERATOR_H
