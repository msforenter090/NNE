#ifndef __NN_TYPES_INTERNAL_H__
#define __NN_TYPES_INTERNAL_H__

#include "nn_constants.h"
#include <CL/cl.h>

// -----------------------------------------------------------------------------
// Mapping for internal usage.
// -----------------------------------------------------------------------------
typedef struct _nn_device_info nn_device_info;

// -----------------------------------------------------------------------------
// Internal Objects.
// -----------------------------------------------------------------------------
struct _nn_device_info {
    unsigned int id;
    unsigned int device;
    cl_bool available;
    cl_bool has_compiler;
    cl_ulong global_memory_cache_size;
    cl_device_mem_cache_type global_mem_cache_type;
    cl_uint global_mem_cache_line_size;
    cl_ulong global_mem_size;
    cl_ulong local_mem_size;
    cl_device_local_mem_type local_mem_cache_type;
    cl_uint max_compute_units;
    cl_ulong constant_buffer_size;
    cl_ulong max_mem_alloc_size;
    size_t max_argument_size;
    cl_uint max_work_group_size;
};

// -----------------------------------------------------------------------------
// External Objects.
// -----------------------------------------------------------------------------
struct _nn_system_info {
    cl_platform_id platforms[MAX_PLATFORMS_LENGTH];
    cl_device_id devices[MAX_DEVICES_LENGTH];
    nn_device_info device_info[MAX_DEVICES_LENGTH];
    unsigned short device_platform_mapping[MAX_DEVICES_LENGTH];
};

struct _nn_system_context {
    // For now only one platform can be used for kernel execution.
    // nn_runtime_platform platform;
    // nn_runtime_device *devces;
    // nn_runtime_device_info *device_info;
};

#endif // __NN_TYPES_INTERNAL_H__
