// =================================================================================================
// Project: nn library
// Platform info extraction, network training.
//
// File information:
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-07-31
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 100 characters
//
// =================================================================================================

#ifndef __NN_RUNTIME_H__
#define __NN_RUNTIME_H__

#include "nn_defs.h"
#include "nn_types.h"
#include "nn_types_internal.h"

#include "nn.common/nn_error.h"

nn_error nn_runtime_platform_count(CONTEXT, short *const count);
nn_error nn_runtime_platforms(CONTEXT, cl_platform_id **platforms);
nn_error nn_runtime_platform_info(CONTEXT, cl_platform_id platform,
                                  byte *values[]);

nn_error nn_runtime_platform_device_count(CONTEXT, cl_platform_id platform,
                                          short *const count);
nn_error nn_runtime_platform_devices(CONTEXT, cl_platform_id platform,
                                     cl_device_id **devices);

nn_error nn_runtime_platform_devices_map(CONTEXT,
                                         nn_tuple_platform_devices **map);

// TODO: This should be filtering by properties.
nn_error nn_runtime_platform_filter_devices_by_properties(
    CONTEXT, nn_tuple_platform_devices *map, nn_tuple_platform_devices *pair);
nn_error nn_runtime_device_properties(CONTEXT, cl_device_id device,
                                      cl_device_info *params,
                                      const short param_length, void *out[]);
nn_error nn_runtime_default_context(CONTEXT, nn_tuple_platform_devices *map[],
                                    cl_device_info *info, const short length);

#endif // __NN_RUNTIME_H__
