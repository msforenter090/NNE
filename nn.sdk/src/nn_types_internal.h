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

#ifndef __NN_TYPES_INTERNAL_H__
#define __NN_TYPES_INTERNAL_H__

#include "nn_constants.h"
#include "nn_cl_include.h"

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
    cl_platform_id platforms[MAX_PLATFORMS];
    cl_device_id devices[MAX_DEVICES];
    nn_device_info device_info[MAX_DEVICES];
    unsigned short device_platform_mapping[MAX_DEVICES];
};

struct _nn_system_context {
    cl_platform_id platform;

    // For now use just one device.
    // TODO - TASK-1: In the future this should be expanded.
    cl_device_id device;
    nn_device_info device_info;

    cl_context context;
    cl_command_queue command_queue;
};

#endif // __NN_TYPES_INTERNAL_H__
