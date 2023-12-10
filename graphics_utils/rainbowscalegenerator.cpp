#include "rainbowscalegenerator.h"
#include <QColor>




using namespace graphics_utils;



RainbowScaleGenerator::RainbowScaleGenerator(){

}






RainbowScaleGenerator::~RainbowScaleGenerator(){

}







float4 RainbowScaleGenerator::colorAt(int index, int colorCount, float opacity) const{
    float x = static_cast<float>(index) / static_cast<float>(colorCount - 1);

    QColor color = QColor::fromHslF(x, 1.0, 0.5, opacity);

    float4 float4Color;
    float4Color.x = static_cast<float>(color.redF());
    float4Color.y = static_cast<float>(color.greenF());
    float4Color.z = static_cast<float>(color.blueF());
    float4Color.w = static_cast<float>(color.alphaF());

    return float4Color;
}




RainbowScaleGenerator& RainbowScaleGenerator::instance() {
    static RainbowScaleGenerator instance;

    return instance;
}
