#ifndef QUATERNIONCALCULATOR_CUH
#define QUATERNIONCALCULATOR_CUH


#include <cmath>
#include <cuda_runtime.h>
#include "quaternion.h"
#include "rotquaternion.h"



namespace quaternion {
class QuaternionCalculator {
public:
    static __host__ __device__ Quaternion sum(const Quaternion& q1, const Quaternion& q2);

    static __host__ __device__ Quaternion sub(const Quaternion& q1, const Quaternion& q2);

    static __host__ __device__ Quaternion scale(float s, const Quaternion& q);

    static __host__ __device__ float3 scale(float s, const float3& p);

    static __host__ __device__ Quaternion crossProduct(Quaternion q1, Quaternion q2);

    static __host__ __device__ Quaternion conjugation(const Quaternion& q);

    static __host__ __device__ float norm(const Quaternion& q);

    static __host__ __device__ float norm(const float3& pos);

    static __host__ __device__ Quaternion normalize(const Quaternion& q);

    static __host__ __device__ float3 normalize(const float3& p);

    static __host__ __device__ Quaternion multiplicativeInverse(const Quaternion& q);

    static __host__ __device__ float dotProduct(const Quaternion& q1, const Quaternion& q2);

    static __host__ __device__ float dotProduct(const float3& p1, const float3& p2);

    static __host__ __device__ RotQuaternion toRotation(const Quaternion& q);

    static __host__ __device__ Quaternion fromRotation(const RotQuaternion& r);

    static __host__ __device__ float3 toPosition(const Quaternion& q);

    static __host__ __device__ Quaternion fromPosition(const float3& p);

    static __host__ __device__ RotQuaternion compose(const RotQuaternion& r1, const RotQuaternion& r2);

    static __host__ __device__ float3 rotate(const float3& p, const RotQuaternion& r);

    static __host__ __device__ float3 rotate(const float3& p, const RotQuaternion& r, const float3& rotCenter);

    static __host__ __device__ Quaternion crossProductWithoutValue(const Quaternion& q1, const Quaternion& q2);

    static __host__ __device__ RotQuaternion calcRotation(const float3& p1, const float3& p2);

    static __host__ __device__ float distance(const float3& p1, const float3& p2);


protected:
    static __host__ __device__ Quaternion linearInterpolation(const Quaternion& q1, const Quaternion& q2, float t);

    static __host__ __device__ Quaternion angularInterpolation(const Quaternion& q1, const Quaternion& q2, float u);


private:
    QuaternionCalculator() = delete;

    ~QuaternionCalculator() = delete;

    QuaternionCalculator(const QuaternionCalculator &) = delete;

    void operator=(const QuaternionCalculator &) = delete;
};
}



#endif // QUATERNIONCALCULATOR_CUH
