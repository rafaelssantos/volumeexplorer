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
};


}


#endif // VOLUMEMEMMANAGER_H
