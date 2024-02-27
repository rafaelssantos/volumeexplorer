#include "renderingsettings.h"

#include <QSettings>



using namespace rendering;
using namespace transfer_function;
using namespace settings;





RenderingSettings::RenderingSettings() {
    m_HQSpecs.step = m_specs.step = 0;
    m_HQSpecs.maxOpacity = m_specs.maxOpacity = 1.0;
    m_HQSpecs.zoomIncrement = m_specs.zoomIncrement = 0.025f;
    m_HQSpecs.maxSteps = m_specs.maxSteps = 1000;

    m_HQBlockDim = m_blockDim = {192, 1, 1};
    m_HQInterpolation = m_interpolation = Interpolation::NEAREST;

    m_HQIllumination.ambientK = m_illumination.ambientK = 0.1f;
    m_HQIllumination.diffuseK = m_illumination.diffuseK = 0.5;
    m_HQIllumination.specularK = m_illumination.specularK = 0.4f;
    m_HQIllumination.shininess = m_illumination.shininess = 32;
    m_HQIllumination.enabled = m_illumination.enabled = false;

    m_HQRotationDegree = m_rotationDegree = 1.0;

    m_HQEnabled = false;

    m_HQDevSyncronize = m_devSyncronize = false;
}





RenderingSettings::~RenderingSettings() {
}





RenderingSettings& RenderingSettings::instance() {
    static RenderingSettings instance;

    return instance;
}





void RenderingSettings::load() {
    QSettings settings("volumeExplorer", "Rendering");

    m_specs.step = settings.value("step", 1.0).toFloat();
    m_specs.maxOpacity = settings.value("maxOpacity", 1.0).toFloat();
    m_specs.zoomIncrement = settings.value("zoomIncrement", 0.025f).toFloat();
    m_specs.maxSteps = settings.value("maxNumberOfSteps", 1000).toUInt();

    m_blockDim.x = settings.value("blockDimX", 192).toUInt();
    m_blockDim.y = settings.value("blockDimY", 1).toUInt();
    m_blockDim.z = settings.value("blockDimZ", 1).toUInt();
    m_devSyncronize = settings.value("devSyncronize", false).toBool();

    m_illumination.enabled = settings.value("illuminationEnabled", false).toBool();
    m_illumination.ambientK = settings.value("ambientK", 0.1f).toFloat();
    m_illumination.diffuseK = settings.value("diffuseK", 0.5f).toFloat();
    m_illumination.specularK = settings.value("specularK", 0.4f).toFloat();
    m_illumination.shininess = settings.value("shininess", 32).toInt();

    m_interpolation = static_cast<Interpolation>(settings.value("illumination", 0).toInt());

    m_rotationDegree = settings.value("rotationDegree", 1.0).toFloat();


    m_HQSpecs.step = settings.value("HQStep", 1.0).toFloat();
    m_HQSpecs.maxOpacity = settings.value("HQMaxOpacity", 1.0).toFloat();
    m_HQSpecs.zoomIncrement = settings.value("HQZoomIncrement", 0.025f).toFloat();
    m_HQSpecs.maxSteps = settings.value("HQMaxNumberOfSteps", 1000).toUInt();

    m_HQBlockDim.x = settings.value("HQBlockDimX", 192).toUInt();
    m_HQBlockDim.y = settings.value("HQBlockDimY", 1).toUInt();
    m_HQBlockDim.z = settings.value("HQBlockDimZ", 1).toUInt();
    m_HQDevSyncronize = settings.value("HQDevSyncronize", false).toBool();


    m_HQIllumination.enabled = settings.value("HQIlluminationEnabled", false).toBool();
    m_HQIllumination.ambientK = settings.value("HQambientK", 0.1f).toFloat();
    m_HQIllumination.diffuseK = settings.value("HQdiffuseK", 0.5f).toFloat();
    m_HQIllumination.specularK = settings.value("HQspecularK", 0.4f).toFloat();
    m_HQIllumination.shininess = settings.value("HQshininess", 32).toInt();

    m_HQInterpolation = static_cast<Interpolation>(settings.value("HQillumination", 0).toInt());

    m_HQRotationDegree = settings.value("HQRotationDegree", 1.0).toFloat();

    settings.sync();
}





void RenderingSettings::save() {
    QSettings settings("volumeExplorer", "Rendering");

    settings.setValue("step", m_specs.step);
    settings.setValue("maxOpacity", m_specs.maxOpacity);
    settings.setValue("zoomIncrement", m_specs.zoomIncrement);
    settings.setValue("maxNumberOfSteps", m_specs.maxSteps);

    settings.setValue("blockDimX", m_blockDim.x);
    settings.setValue("blockDimY", m_blockDim.y);
    settings.setValue("blockDimZ", m_blockDim.z);
    settings.setValue("devSyncronize", m_devSyncronize);


    settings.setValue("illuminationEnabled", m_illumination.enabled);
    settings.setValue("ambientK", m_illumination.ambientK);
    settings.setValue("diffuseK", m_illumination.diffuseK);
    settings.setValue("specularK", m_illumination.specularK);
    settings.setValue("shininess", m_illumination.shininess);
    settings.setValue("illumination", m_interpolation);

    settings.setValue("rotationDegree", m_rotationDegree);


    settings.setValue("HQStep", m_HQSpecs.step);
    settings.setValue("HQMaxOpacity", m_HQSpecs.maxOpacity);
    settings.setValue("HQZoomIncrement", m_HQSpecs.zoomIncrement);
    settings.setValue("HQMaxNumberOfSteps", m_HQSpecs.maxSteps);

    settings.setValue("HQBlockDimX", m_HQBlockDim.x);
    settings.setValue("HQBlockDimY", m_HQBlockDim.y);
    settings.setValue("HQBlockDimZ", m_HQBlockDim.z);
    settings.setValue("HQDevSyncronize", m_HQDevSyncronize);


    settings.setValue("HQIlluminationEnabled", m_HQIllumination.enabled);
    settings.setValue("HQambientK", m_HQIllumination.ambientK);
    settings.setValue("HQdiffuseK", m_HQIllumination.diffuseK);
    settings.setValue("HQspecularK", m_HQIllumination.specularK);
    settings.setValue("HQshininess", m_HQIllumination.shininess);
    settings.setValue("HQillumination", m_HQInterpolation);

    settings.setValue("HQRotationDegree", m_HQRotationDegree);

    settings.sync();
}





float RenderingSettings::rotationDegree() const {
    if(m_HQEnabled){
        return m_HQRotationDegree;
    }
    else{
        return m_rotationDegree;
    }
}





void RenderingSettings::setRotationDegree(float degree) {
    if(m_HQEnabled){
        m_HQRotationDegree = degree;
    }
    else{
        m_rotationDegree = degree;
    }
}





float RenderingSettings::step() const {
    if(m_HQEnabled){
        return m_HQSpecs.step;
    }
    else{
        return m_specs.step;
    }
}





void RenderingSettings::setStep(float step) {
    if(m_HQEnabled){
        m_HQSpecs.step = step;
    }
    else{
        m_specs.step = step;
    }
}





unsigned RenderingSettings::maxNumberOfSteps() const {
    if(m_HQEnabled){
        return m_HQSpecs.maxSteps;
    }
    else {
        return m_specs.maxSteps;
    }
}



void RenderingSettings::setMaxNumberOfSteps(unsigned numberOfSteps) {
    if(m_HQEnabled){
        m_HQSpecs.maxSteps = numberOfSteps;
    }
    else{
        m_specs.maxSteps = numberOfSteps;
    }
}





float RenderingSettings::maxOpacity() const {
    if(m_HQEnabled){
        return m_HQSpecs.maxOpacity;
    }
    else{
        return m_specs.maxOpacity;
    }
}





void RenderingSettings::setMaxOpacity(float max_opacity) {
    if(m_HQEnabled){
        m_HQSpecs.maxOpacity = max_opacity;
    }
    else{
        m_specs.maxOpacity = max_opacity;
    }
}





const dim3 &RenderingSettings::blockDim() const {
    if(m_HQEnabled){
        return m_HQBlockDim;
    }
    else{
        return m_blockDim;
    }
}





void RenderingSettings::setBlockDim(unsigned x, unsigned y, unsigned z) {
    if(m_HQEnabled){
        m_HQBlockDim.x = x;
        m_HQBlockDim.y = y;
        m_HQBlockDim.z = z;
    }
    else{
        m_blockDim.x = x;
        m_blockDim.y = y;
        m_blockDim.z = z;
    }
}





void RenderingSettings::setBlockDim(const dim3 &blockDim) {
    if(m_HQEnabled){
        m_HQBlockDim = blockDim;
    }
    else{
        m_blockDim  = blockDim;
    }
}





Interpolation RenderingSettings::interpolation() const {
    if(m_HQEnabled){
        return m_HQInterpolation;
    }
    else{
        return m_interpolation;
    }
}





void RenderingSettings::setInterpolation(Interpolation interpolation) {
    if(m_HQEnabled){
        m_HQInterpolation = interpolation;
    }
    else{
        m_interpolation = interpolation;
    }
}





void RenderingSettings::setZoomIncrement(float zoom_increment) {
    if(m_HQEnabled){
        m_HQSpecs.zoomIncrement = zoom_increment;
    }
    else{
        m_specs.zoomIncrement = zoom_increment;
    }
}





float RenderingSettings::zoomIncrement() const {
    if(m_HQEnabled){
        return m_HQSpecs.zoomIncrement;
    }
    else{
        return m_specs.zoomIncrement;
    }
}





void RenderingSettings::setIllumEnabled(bool enabled) {
    if(m_HQEnabled){
        m_HQIllumination.enabled = enabled;
    }
    else{
        m_illumination.enabled = enabled;
    }
}





bool RenderingSettings::illumEnabled() const {
    if(m_HQEnabled){
        return m_HQIllumination.enabled;
    }
    else{
        return m_illumination.enabled;
    }
}





void RenderingSettings::setIllumAmbientK(float k) {
    if(m_HQEnabled){
        m_HQIllumination.ambientK = k;
    }
    else{
        m_illumination.ambientK = k;
    }
}





float RenderingSettings::illumAmbientK() const {
    if(m_HQEnabled){
        return m_HQIllumination.ambientK;
    }
    else{
        return m_illumination.ambientK;
    }
}





void RenderingSettings::setIllumDiffuseK(float k) {
    if(m_HQEnabled){
        m_HQIllumination.diffuseK = k;
    }
    else{
        m_illumination.diffuseK = k;
    }
}





float RenderingSettings::illumDiffuseK() const {
    if(m_HQEnabled){
        return m_HQIllumination.diffuseK;
    }
    else{
        return m_illumination.diffuseK;
    }
}





void RenderingSettings::setIllumSpecularK(float k) {
    if(m_HQEnabled){
        m_HQIllumination.specularK = k;
    }
    else{
        m_illumination.specularK = k;
    }
}





float RenderingSettings::illumSpecularK() const {
    if(m_HQEnabled){
        return m_HQIllumination.specularK;
    }
    else{
        return m_illumination.specularK;
    }
}



void RenderingSettings::setIllumShininess(int shininess) {
    if(m_HQEnabled){
        m_HQIllumination.shininess = shininess;
    }
    else{
        m_illumination.shininess = shininess;
    }
}





int RenderingSettings::illumShininess() const {
    if(m_HQEnabled){
        return m_HQIllumination.shininess;
    }
    else{
        return m_illumination.shininess;
    }
}



const RenderingSpecs &RenderingSettings::specs() const{
    if(m_HQEnabled){
        return m_HQSpecs;
    }
    else{
        return m_specs;
    }
}


void RenderingSettings::setHQEnabled(bool enabled){
    m_HQEnabled = enabled;
}



bool RenderingSettings::HQEnabled() const{
    return m_HQEnabled;
}



const Illumination &RenderingSettings::illumination() const {
    if(m_HQEnabled) {
        return m_HQIllumination;
    }
    else{
        return m_illumination;
    }
}




void RenderingSettings::setDevSyncronizeEnable(bool enabled) {
    if(m_HQEnabled){
        m_HQDevSyncronize = enabled;
    }
    else{
        m_devSyncronize = enabled;
    }
}


bool RenderingSettings::devSyncronizeEnabled() const {
    if(m_HQEnabled){
        return m_HQDevSyncronize;
    }
    else{
        return m_devSyncronize;
    }
}
