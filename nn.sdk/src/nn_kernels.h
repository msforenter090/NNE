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

#include "nn_types_internal.h"

// -----------------------------------------------------------------------------
// Simple kernel.
// -----------------------------------------------------------------------------
#define VECTOR_ADD 0
extern const char **simple_kernel_names_list;
extern const char **simple_kernel_sources_list;
extern void simple_kernel_sources(nn_kernel_source *const sources);

#endif // __NN_KERNELS_H__