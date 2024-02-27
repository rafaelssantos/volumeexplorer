#ifndef THREADINDEXING_CUH
#define THREADINDEXING_CUH


#include <cuda_runtime.h>



class ThreadIndexing{
public:
    static __device__ unsigned globalIdx();

    static __device__ unsigned totalBlockIdx();

    static __device__ unsigned totalBlockDim();
};



#endif // THREADINDEXING_CUH
