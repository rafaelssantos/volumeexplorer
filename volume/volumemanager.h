#ifndef VOLUMEMANAGER_H
#define VOLUMEMANAGER_H


#include <cstddef>
#include <list>
#include <string>
#include <utility>
#include "volume.cuh"




namespace volume {


class VolumeManager {
    public:
        static VolumeManager& instance();

        std::pair<Volume*, Volume*> load(const std::list<std::string>& filePaths, const float3& spacing) const;

        void free(std::pair<Volume*, Volume*> volume) const;



    private:
        VolumeManager();

        virtual ~VolumeManager();


    private:
        VolumeManager(const VolumeManager&) = delete;
        void operator=(const VolumeManager&) = delete;
};


}


#endif // VOLUMEMANAGER_H
