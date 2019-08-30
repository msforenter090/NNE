// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-30
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================

#ifndef __NN_KERNELS_H__
#define __NN_KERNELS_H__

#include "nn_types.h"
#include "nn_util.h"

// #define simple_kernel void __kernel foo() { return; }
void simple_kernel(byte *const buffer) {
    dump_bits(buffer, void __kernel vector_add(__global float *in, __global float *out) { return; });
    return;
}

#endif