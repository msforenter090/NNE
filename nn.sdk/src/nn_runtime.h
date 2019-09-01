// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
//
// File information:
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-07-31
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================

#ifndef __NN_RUNTIME_H__
#define __NN_RUNTIME_H__

#include "nn_defs.h"
#include "nn_types.h"
#include "nn_kernels.h"
#include "nn_types_internal.h"

#include "nn.sdk.common/nn_error.h"

// -----------------------------------------------------------------------------
// Platform.
// -----------------------------------------------------------------------------
nn_error nn_runtime_platforms(CONTEXT);

// -----------------------------------------------------------------------------
// Devices.
// -----------------------------------------------------------------------------
nn_error nn_runtime_devices(CONTEXT);
nn_error nn_runtime_devices_info(CONTEXT);
nn_error nn_runtime_select_device(CONTEXT);

// -----------------------------------------------------------------------------
// OpenCL constructs.
// -----------------------------------------------------------------------------
nn_error nn_runtime_cl_context(CONTEXT);
nn_error nn_runtime_cl_command_queue(CONTEXT);
nn_error nn_runtime_cl_program_from_source(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);
nn_error nn_runtime_cl_build_program(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);
nn_error nn_runtime_cl_kernels_from_program(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);
nn_error nn_runtime_cl_kernels_info(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);

#endif // __NN_RUNTIME_H__
