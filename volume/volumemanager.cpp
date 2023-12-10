#include "volumemanager.h"


#include <opencv4/opencv2/opencv.hpp>
#include "volumememmanager.h"



using namespace std;
using namespace volume;





VolumeManager::VolumeManager() {

}





VolumeManager::~VolumeManager() {

}





VolumeManager& VolumeManager::instance() {
    static VolumeManager instance;

    return instance;
}





std::pair<Volume*, Volume*> VolumeManager::load(const std::list<string>& filePaths, const float3& spacing) const{
    cv::Mat matrix = cv::imread(*filePaths.begin(), cv::IMREAD_GRAYSCALE);

    int3 dim;
    dim.x = matrix.cols;
    dim.y = matrix.rows;
    dim.z = static_cast<int>(filePaths.size());

    byte *data = new byte[static_cast<size_t>(dim.x * dim.y * dim.z)];

    size_t size = static_cast<size_t>(matrix.rows) * static_cast<size_t>(matrix.cols) * sizeof(byte);
    size_t curPointer = 0;

    memcpy(data + curPointer, matrix.data, size);
    curPointer += size;
    matrix.release();

    for(auto f = ++filePaths.begin(); f != filePaths.end(); f++) {
        matrix = imread(*f,  cv::IMREAD_GRAYSCALE);

        memcpy(data + curPointer, matrix.data, size);
        curPointer += size;
        matrix.release();
    }

    Volume* hostVolume = new Volume(dim.x, dim.y, dim.z);
	hostVolume->setSpacing(spacing);
    hostVolume->m_data = data;

    Volume* devVolume = VolumeMemManager::instance().cloneToDev(hostVolume);

    return pair<Volume*, Volume*>(hostVolume, devVolume);
}





void VolumeManager::free(pair<Volume*, Volume*> volume) const {
    VolumeMemManager::instance().hostFree(volume.first);
    VolumeMemManager::instance().devFree(volume.second);
}
