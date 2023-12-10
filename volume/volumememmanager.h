#ifndef VOLUMEMEMMANAGER_H
#define VOLUMEMEMMANAGER_H


#include "volume.cuh"



namespace volume {



class VolumeMemManager {
    public:
        static VolumeMemManager& instance();

        Volume* cloneToDev(const Volume* hostVolume);

        void devFree(Volume* devVolume);

        void hostFree(Volume *hostVolume);



    private:
        VolumeMemManager();

        virtual ~VolumeMemManager();

        Volume m_swapBuffer;



    private:
        VolumeMemManager(const VolumeMemManager&) = delete;
        void operator=(const VolumeMemManager&) = delete;
};


}


#endif // VOLUMEMEMMANAGER_H
