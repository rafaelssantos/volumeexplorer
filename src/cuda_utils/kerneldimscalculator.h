#ifndef KERNELDIMSCALCULATOR_H
#define KERNELDIMSCALCULATOR_H


#include <cuda_runtime.h>



class KernelDimsCalculator {
public:
    static KernelDimsCalculator& instance();

    dim3 calc(dim3 &blockDim, size_t n, int gpuIndex = 0);


private:
    KernelDimsCalculator();

    virtual ~KernelDimsCalculator();


private:
    KernelDimsCalculator(const KernelDimsCalculator&) = delete;
    void operator=(const KernelDimsCalculator&) = delete;
};



#endif // KERNELDIMSCALCULATOR_H
