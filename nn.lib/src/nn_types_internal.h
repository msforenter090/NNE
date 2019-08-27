#ifndef __NN_TYPES_INTERNAL_H__
#define __NN_TYPES_INTERNAL_H__

#include <CL/cl.h>
#include "nn_constants.h"

// -----------------------------------------------------------------------------
// Mapping for internal usage.
// -----------------------------------------------------------------------------
typedef struct _nn_device_info nn_device_info;

// -----------------------------------------------------------------------------
// Internal Objects.
// -----------------------------------------------------------------------------
struct _nn_device_info {
    cl_bool available;
    cl_bool compiler;
    cl_bool little_endian;
    cl_device_exec_capabilities exec_capabilities;
    cl_ulong global_memory_cache_size;
    cl_device_mem_cache_type global_memory_cache_type;
    cl_uint global_mem_cacheline_size;
    cl_ulong global_memory_size;
    cl_ulong local_memory_size;
    cl_device_local_mem_type local_memory_type;
    cl_uint max_compute_units;
    cl_ulong max_memory_alloc_size; // Max size of memory object allocation in bytes.
    size_t max_work_group_size;     // Maximum number of work-items in a work-group executing a kernel
                                    // using the data parallel execution model.
    size_t max_work_item_sizes[3];  // Maximum number of work-items that can be specified in each
                                    // dimension of the work-group.
    cl_device_type device_type;
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
    int a;
};

#endif // __NN_TYPES_INTERNAL_H__
