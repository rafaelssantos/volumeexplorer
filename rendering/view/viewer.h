#ifndef VIEWER_H
#define VIEWER_H

#include "quaternion/quaternioncalculator.cuh"




namespace rendering {
namespace view {


struct Viewer {
    float zoom;
    float rotationDegree;
    quaternion::RotQuaternion rotation;
};


typedef struct Viewer Viewer;


}
}




#endif // VIEWER_H
