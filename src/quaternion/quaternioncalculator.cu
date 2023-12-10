#include "quaternioncalculator.cuh"



using namespace quaternion;




Quaternion QuaternionCalculator::sum(const Quaternion& q1, const Quaternion& q2) {
    Quaternion qr;

    qr.s = q1.s + q2.s;
    qr.x = q1.x + q2.x;
    qr.y = q1.y + q2.y;
    qr.z = q1.z + q2.z;

    return qr;
}






__host__ __device__  Quaternion QuaternionCalculator::sub(const Quaternion& q1, const Quaternion& q2) {
    Quaternion qr;

    qr.s = q1.s - q2.s;
    qr.x = q1.x - q2.x;
    qr.y = q1.y - q2.y;
    qr.z = q1.z - q2.z;

    return qr;
}






__host__ __device__ Quaternion QuaternionCalculator::scale(float s, const Quaternion& q) {
    Quaternion qr;

    qr.s = s * q.s;
    qr.x = s * q.x;
    qr.y = s * q.y;
    qr.z = s * q.z;

    return qr;
}


__host__ __device__ float3 QuaternionCalculator::scale(float s, const float3& p) {
    float3 pr;

    pr.x = s * p.x;
    pr.y = s * p.y;
    pr.z = s * p.z;

    return pr;
}







__host__ __device__ Quaternion QuaternionCalculator::crossProduct(Quaternion q1, Quaternion q2) {
    Quaternion qr;

    qr.s = q1.s * q2.s - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
    qr.x = q1.s * q2.x + q2.s * q1.x + q1.y * q2.z - q1.z * q2.y;
    qr.y = q1.s * q2.y + q2.s * q1.y + q1.z * q2.x - q1.x * q2.z;
    qr.z = q1.s * q2.z + q2.s * q1.z + q1.x * q2.y - q1.y * q2.x;

    return qr;
}






__host__ __device__ Quaternion QuaternionCalculator::conjugation(const Quaternion& q) {
    Quaternion qr;

    qr.s = q.s;
    qr.x = -q.x;
    qr.y = -q.y;
    qr.z = -q.z;

    return qr;
}






__host__ __device__ float QuaternionCalculator::norm(const Quaternion& q) {
    return sqrtf(q.s * q.s + q.x * q.x + q.y * q.y + q.z * q.z);
}




__host__ __device__ float QuaternionCalculator::norm(const float3& pos) {
    return sqrtf(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z);
}




__host__ __device__ Quaternion QuaternionCalculator::normalize(const Quaternion& q) {
    float norm = QuaternionCalculator::norm(q);

    if (norm == 0.0f) {
        return q;
    }

    return scale(1.0f / norm, q);
}





__host__ __device__ float3 QuaternionCalculator::normalize(const float3& p) {
    float norm = QuaternionCalculator::norm(p);

    if (norm == 0.0f) {
        return p;
    }

    return scale(1.0f / norm, p);
}






__host__ __device__ Quaternion QuaternionCalculator::multiplicativeInverse(const Quaternion& q) {
    float norm = QuaternionCalculator::norm(q);

    if (norm  == 0.0f) {
        return q;
    }
    else{
        return scale(1.0f / norm, conjugation(q));
    }
}






__host__ __device__ Quaternion QuaternionCalculator::linearInterpolation(const Quaternion& q1, const Quaternion& q2, float t) {
    return sum(scale((1.0f - t), q1), scale(t, q2));
}






__host__ __device__ float QuaternionCalculator::dotProduct(const Quaternion& q1, const Quaternion& q2) {
    return sqrtf(q1.s * q2.s + q1.x * q2.x + q1.y * q2.y + q1.z * q2.z);
}






__host__ __device__ float QuaternionCalculator::dotProduct(const float3& p1, const float3& p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}






__host__ __device__ Quaternion QuaternionCalculator::angularInterpolation(const Quaternion& q1, const Quaternion& q2, float u) {
    const float HALF_PI = 1.57079632679489661923132169164f;
    const float EPSILON = 0.000001f;
    float cos_omega;
    float sin_omega;
    float omega;
    float s1, s2;

    Quaternion q2Clone = q2; //Cópia devido ao const

    if (norm(sub(q1, q2Clone)) > norm(sum(q1, q2Clone))) {
        q2Clone = scale(-1, q2Clone);
    }

    cos_omega = dotProduct(q1, q2Clone);

    if ((1.0f - cos_omega) < EPSILON) {
        return linearInterpolation(q1, q2Clone, u);
    }

    if ((1.0f + cos_omega) < EPSILON) {
        Quaternion q2a;
        q2a.s = -q2Clone.x;
        q2a.x = q2Clone.s;
        q2a.y = -q2Clone.z;
        q2a.z = q2Clone.y;
        s1 = sinf((1.0f - u) * HALF_PI);
        s2 = sinf(u * HALF_PI);
        return sum(scale(s1, q1), scale(s2, q2a));
    }
    omega = acosf(cos_omega);
    sin_omega = sinf(omega);
    s1 = sinf((1.0f - u) * omega) / sin_omega;
    s2 = sinf(u * omega) / sin_omega;

    return sum(scale(s1, q1), scale(s2, q2Clone));
}






__host__ __device__ RotQuaternion QuaternionCalculator::toRotation(const Quaternion& q) {
    const float halfpi = 1.57079632679489661923132169164f;

    RotQuaternion rr;
    rr.theta = (acosf(q.s) * 180.0f) / halfpi;
    rr.nx = q.x;
    rr.ny = q.y;
    rr.nz = q.z;

    return rr;
}






__host__ __device__ Quaternion QuaternionCalculator::fromRotation(const RotQuaternion& r) {
    const float HALF_PI = 1.57079632679489661923132169164f;
    const float EPSILON = 0.000001f;
    float halftheta;
    float sinhalftheta;
    float axisnorm;
    Quaternion qr;

    if ((axisnorm = sqrtf(r.nx * r.nx + r.ny * r.ny + r.nz * r.nz)) < EPSILON) {
        qr.s = 1.0;
        qr.x = 0.0;
        qr.y = 0.0;
        qr.z = 0.0;
        return qr;
    }

    halftheta = (r.theta * HALF_PI) / 180.0f;
    sinhalftheta = sinf(halftheta);
    qr.s = cosf(halftheta);
    qr.x = sinhalftheta * (r.nx / axisnorm);
    qr.y = sinhalftheta * (r.ny / axisnorm);
    qr.z = sinhalftheta * (r.nz / axisnorm);

    return qr;
}






__host__ __device__ float3 QuaternionCalculator::toPosition(const Quaternion& q) {
    float3 pr;

    pr.x = q.x;
    pr.y = q.y;
    pr.z = q.z;

    return pr;
}






__host__ __device__ Quaternion QuaternionCalculator::fromPosition(const float3& p) {
    Quaternion qr;

    qr.s = 0.0;
    qr.x = p.x;
    qr.y = p.y;
    qr.z = p.z;

    return qr;
}






__host__ __device__ RotQuaternion QuaternionCalculator::compose(const RotQuaternion& r1, const RotQuaternion& r2) {
    return toRotation(crossProduct(fromRotation(r2), fromRotation(r1)));
}






__host__ __device__ float3 QuaternionCalculator::rotate(const float3& p, const RotQuaternion& r) {
    return toPosition(crossProduct(fromRotation(r), crossProduct(fromPosition(p), conjugation(fromRotation(r)))));
}






 __host__ __device__ float3 QuaternionCalculator::rotate(const float3& p, const RotQuaternion& r, const float3& rotCenter) {
    float3 pClone = p;

    pClone.x -= rotCenter.x;
    pClone.y -= rotCenter.y;
    pClone.z -= rotCenter.z;

    pClone = QuaternionCalculator::rotate(pClone, r);

    pClone.x += rotCenter.x;
    pClone.y += rotCenter.y;
    pClone.z += rotCenter.z;

    return pClone;
}






__host__ __device__ Quaternion QuaternionCalculator::crossProductWithoutValue(const Quaternion& q1, const Quaternion& q2) {
    Quaternion r;

    r.x = q1.y * q2.z - q1.z * q2.y;
    r.y = q1.x * q2.z - q1.z * q2.x;
    r.z = q1.x * q2.y - q1.y * q2.x;

    return r;
}







__host__ __device__ RotQuaternion QuaternionCalculator::calcRotation(const float3& p1, const float3& p2) {
    const float HALFPI = 1.57079632679489661923132169164f;

    float3 p1Clone = toPosition(normalize(fromPosition(p1)));
    float3 p2Clone = toPosition(normalize(fromPosition(p2)));
    RotQuaternion rot = QuaternionCalculator::toRotation(normalize(crossProductWithoutValue(fromPosition(p1), fromPosition(p2))));
    rot.theta = 90.0f * acosf(QuaternionCalculator::dotProduct(p1Clone, p2Clone)) / HALFPI;


    return rot;
}






__host__ __device__ float QuaternionCalculator::distance(const float3& p1, const float3& p2) {
    return sqrtf((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}
