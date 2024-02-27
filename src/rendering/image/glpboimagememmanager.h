#ifndef GLPBOIMAGEMEMMANAGER_H
#define GLPBOIMAGEMEMMANAGER_H


#include "glpboimage.h"




namespace rendering {
namespace image {


class GlPBOImageMemManager {
public:
    static GlPBOImageMemManager& instance();

    GlPBOImage* cloneToDevice(const GlPBOImage* hostImage) const;

    void deviceFree(GlPBOImage* devImage) const;

    void copyToDevice(GlPBOImage* devImage, GlPBOImage *hostImage) const;



private:
    GlPBOImageMemManager();

    virtual ~GlPBOImageMemManager();
};


}
}


#endif // GLPBOIMAGEMEMMANAGER_H
