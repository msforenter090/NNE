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

#ifndef __NN_SDK_RUNTIME_H__
#define __NN_SDK_RUNTIME_H__

#include "nn_cl_include.h"              // cl_platform_id
#include "nn_types_internal.h"          // nn_device_info
#include "nn.sdk.common/nn_error.h"     // nn_error

// -----------------------------------------------------------------------------
// Platform.
// -----------------------------------------------------------------------------
nn_error nn_runtime_platform_count(unsigned int *count);
nn_error nn_runtime_platforms(unsigned int count, cl_platform_id *platforms);

// -----------------------------------------------------------------------------
// Devices.
// -----------------------------------------------------------------------------
nn_error nn_runtime_devices_count(unsigned int platform_count, cl_platform_id * const platforms, unsigned int *count);
nn_error nn_runtime_devices(unsigned int platform_count, cl_platform_id * const platforms,
                            cl_device_id *devices, unsigned int device_count);
nn_error nn_runtime_devices_info(unsigned int device_length, cl_device_id *devices,
                                const unsigned int info_length, struct _nn_device_info *infos);
nn_error nn_runtime_select_device(struct _nn_system_info *system_info,
                                struct _nn_system_context *system_context);

// -----------------------------------------------------------------------------
// OpenCL constructs.
// -----------------------------------------------------------------------------
nn_error nn_runtime_cl_context(CONTEXT);
/*nn_error nn_runtime_cl_command_queue(CONTEXT);
nn_error nn_runtime_cl_program_from_source(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);
nn_error nn_runtime_cl_build_program(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel, const char *options);
nn_error nn_runtime_cl_kernels_from_program(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);
nn_error nn_runtime_cl_kernels_info(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel);
*/
#endif // __NN_SDK_RUNTIME_H__
