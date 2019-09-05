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

#include "nn.sdk.common/nn_error.h"
#include "nn_types_internal.h"
#include "nn_types.h"

// -----------------------------------------------------------------------------
// Simple kernel.
// -----------------------------------------------------------------------------
#define KERNEL 0
extern const char **network_execution_kernel_names_list;
extern const char **network_execution_sources_list;
extern nn_error network_execution_sources(nn_kernel_source *const sources);
extern nn_error network_execution_kernel(CONTEXT, nn_kernel **kernel);

#endif // __NN_KERNELS_H__