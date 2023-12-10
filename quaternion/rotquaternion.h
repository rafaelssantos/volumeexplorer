#ifndef ROTQUATERNION_H
#define ROTQUATERNION_H



namespace quaternion {
struct RotQuaternion {
    float theta;
    float nx;
    float ny;
    float nz;
};


typedef  struct RotQuaternion RotQuaternion;
}



#endif // ROTQUATERNION_H
