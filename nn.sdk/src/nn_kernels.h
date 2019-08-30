#ifndef __NN_KERNELS_H__
#define __NN_KERNELS_H__

#include "nn_util.h"
#include "nn_types.h"

// #define simple_kernel void __kernel foo() { return; }
void simple_kernel(byte *const buffer) {
    dump_bits(buffer,
        void __kernel vector_add(__global float *in, __global float *out) {
            return; 
        }
    );
    return;
}

#endif