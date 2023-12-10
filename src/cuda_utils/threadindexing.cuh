#ifndef THREADINDEXING_CUH
#define THREADINDEXING_CUH


#include <cuda_runtime.h>



class ThreadIndexing{
public:
    static __device__ unsigned globalIdx();

    static __device__ unsigned totalBlockIdx();

    static __device__ unsigned totalBlockDim();


private:
    ThreadIndexing() = delete;
    ThreadIndexing(const ThreadIndexing &) = delete;
    void operator=(const ThreadIndexing &) = delete;
};



#endif // THREADINDEXING_CUH
