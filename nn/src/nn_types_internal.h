#ifndef __NN_TYPES_INTERNAL_H__
#define __NN_TYPES_INTERNAL_H__

#include <CL/cl.h>

// -----------------------------------------------------------------------------
// openCL types.
// -----------------------------------------------------------------------------
struct _nn_platform {
    cl_platform_id platform_id;
};
struct _nn_device {
    cl_device_id device_id;
};

typedef struct _nn_tuple_platform_devices {
    cl_platform_id platform;
    cl_device_id *devices;
} nn_tuple_platform_devices;

typedef struct _nn_device_info {
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
} nn_device_info;

#endif // __NN_TYPES_INTERNAL_H__
