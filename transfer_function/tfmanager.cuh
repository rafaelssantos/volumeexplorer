#ifndef TFMANAGER_CUH
#define TFMANAGER_CUH

#include <utility>
#include "volume/volume.cuh"
#include "transferfunction.cuh"




namespace transfer_function {


class TransferFunctionManager {
public:
	static TransferFunctionManager& instance();

    std::pair<TransferFunction*, TransferFunction*> build(const volume::Volume* hostVolume, const volume::Volume* devVolume) const;

    void free(std::pair<TransferFunction*, TransferFunction*> transferFunc) const;

    static __host__ __device__ void _sobelOperator(const volume::Volume *volume, TransferFunction *transferFunc, int index);

    static __host__ __device__ void _centralDifferences(const volume::Volume *volume, TransferFunction *transferFunc, int index);


    void memcpyColors(TransferFunction* hostTransferFunc, TransferFunction* devTransferFunc);



private:
	TransferFunctionManager();

	virtual ~TransferFunctionManager();



private:
	TransferFunctionManager(const TransferFunctionManager &) = delete;
    void operator=(const TransferFunctionManager &) = delete;
};

}


__global__ void _calcNormalsKernel(const volume::Volume* volume, transfer_function::TransferFunction*transferFunc);



#endif
