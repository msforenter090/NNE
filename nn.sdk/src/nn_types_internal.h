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

#ifndef __NN_SDK_TYPES_INTERNAL_H__
#define __NN_SDK_TYPES_INTERNAL_H__

#include "nn_constants.h"
#include "nn_cl_include.h"
#include "nn.sdk.common/nn_types.h"

// -----------------------------------------------------------------------------
// Innernal types.
// Types used by the library.
// -----------------------------------------------------------------------------
typedef struct _nn_device_info {
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
    cl_platform_id platform;
    cl_device_type device_type;
} nn_device_info;

// -----------------------------------------------------------------------------
// Opaque types.
// Types used by the library client.
// -----------------------------------------------------------------------------
struct _nn_host_context {
    // -------------------------------------------------------------------------
    // Memory.
    // -------------------------------------------------------------------------
    nn_allocate allocate;
    nn_deallocate deallocate;

    // -------------------------------------------------------------------------
    // Logging.
    // -------------------------------------------------------------------------
    nn_log_callback logger;

    // -------------------------------------------------------------------------
    // Stack.
    // -------------------------------------------------------------------------
    void *util, *state;
    void *util_top, *util_bottom, *state_top, *state_bottom;
};

struct _nn_system_info {
    unsigned int platform_count;
    cl_platform_id *platforms;

    unsigned int device_count;
    cl_device_id *devices;

    nn_device_info *devices_info;
};

struct _nn_system_context {
    cl_device_id *device;
    struct _nn_device_info *device_info;
};

// -----------------------------------------------------------------------------
// Usefull macro.
// -----------------------------------------------------------------------------
#define STACK_STATE_TOP &(context->host_context->state_top)
#define STACK_STATE_BOTTOM context->host_context->state_bottom

// 
// // -----------------------------------------------------------------------------
// // Kernel construction.
// // -----------------------------------------------------------------------------
// typedef struct _nn_kernel_source {
//     const char **kernel_names;
//     const char **kernel_sources;
//     unsigned short kernel_names_length;
//     unsigned short kernel_sources_length;
// } nn_kernel_source;
// 
// typedef struct _nn_kernel_info {
//     size_t kernel_work_group_size;
//     size_t kernel_compile_work_group_size[3];
//     cl_ulong kernel_local_mem_size;
// } nn_kernel_info;
// 
// typedef struct _nn_kernel {
//     cl_program program;
//     cl_kernel *kernels;
//     nn_kernel_info *info;
// } nn_kernel;
// 
// // -----------------------------------------------------------------------------
// // External Objects.
// // -----------------------------------------------------------------------------
// struct _nn_system_info {
//     cl_platform_id platforms[MAX_PLATFORMS];
//     cl_device_id devices[MAX_DEVICES];
//     nn_device_info device_info[MAX_DEVICES];
//     unsigned short device_platform_mapping[MAX_DEVICES];
// };
// 
// struct _nn_system_context {
//     cl_platform_id platform;
// 
//     // For now use just one device.
//     // TODO - TASK-1: In the future this should be expanded.
//     cl_device_id device;
//     nn_device_info device_info;
// 
//     cl_context context;
//     cl_command_queue command_queue;
// };
 
#endif // __NN_SDK_TYPES_INTERNAL_H__