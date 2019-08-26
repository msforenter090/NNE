#include "nn_runtime.h"

#include "nn_constants.h"
#include <CL/cl.h>
#include <string.h>

nn_error nn_runtime_platforms(CONTEXT) {
    clGetPlatformIDs(MAX_PLATFORMS, system_info->platforms, NULL);
    return OK;
}

nn_error nn_runtime_devices(CONTEXT) {
    cl_platform_id platform = system_info->platforms[0];
    cl_uint total_devices = 0;
    for (unsigned short i = 0; system_info->platforms[i] != NULL; i++) {
        cl_uint devices_per_platform = 0;
        clGetDeviceIDs(system_info->platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &devices_per_platform);
        clGetDeviceIDs(system_info->platforms[i], CL_DEVICE_TYPE_ALL, devices_per_platform,
                       system_info->devices + devices_per_platform, NULL);
        for (unsigned short j = 0; j < devices_per_platform; j++) {
            system_info->device_platform_mapping[total_devices + j] = i;
        }
        total_devices += devices_per_platform;
    }
    return OK;
}

nn_error nn_runtime_devices_info(CONTEXT) {
    cl_device_id device = NULL;
    for (unsigned short i = 0; system_info->devices[i] != NULL; i++) {
        device = system_info->devices[i];
        nn_device_info *info = &(system_info->device_info[i]);
        // clang-format off
        clGetDeviceInfo(device, CL_DEVICE_AVAILABLE, sizeof(info->available), &(info->available), NULL);
        clGetDeviceInfo(device, CL_DEVICE_COMPILER_AVAILABLE, sizeof(info->compiler), &(info->compiler), NULL);
        clGetDeviceInfo(device, CL_DEVICE_ENDIAN_LITTLE, sizeof(info->little_endian), &(info->little_endian), NULL);
        clGetDeviceInfo(device, CL_DEVICE_EXECUTION_CAPABILITIES, sizeof(info->exec_capabilities), &(info->exec_capabilities), NULL);
        clGetDeviceInfo(device, CL_DEVICE_GLOBAL_MEM_CACHE_SIZE, sizeof(info->global_memory_cache_size), &(info->global_memory_cache_size), NULL);
        clGetDeviceInfo(device, CL_DEVICE_GLOBAL_MEM_CACHE_TYPE, sizeof(info->global_memory_cache_type), &(info->global_memory_cache_type), NULL);
        clGetDeviceInfo(device, CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE, sizeof(info->global_mem_cacheline_size), &(info->global_mem_cacheline_size), NULL);
        clGetDeviceInfo(device, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(info->global_memory_size), &(info->global_memory_size), NULL);
        clGetDeviceInfo(device, CL_DEVICE_LOCAL_MEM_SIZE, sizeof(info->local_memory_size), &(info->local_memory_size), NULL);
        clGetDeviceInfo(device, CL_DEVICE_LOCAL_MEM_TYPE, sizeof(info->local_memory_type), &(info->local_memory_type), NULL);
        clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(info->max_compute_units), &(info->max_compute_units), NULL);
        clGetDeviceInfo(device, CL_DEVICE_MAX_MEM_ALLOC_SIZE, sizeof(info->max_memory_alloc_size), &(info->max_memory_alloc_size), NULL);
        clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(info->max_work_group_size), &(info->max_work_group_size), NULL);
        clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(info->max_work_item_sizes), &(info->max_work_item_sizes), NULL);
        clGetDeviceInfo(device, CL_DEVICE_TYPE, sizeof(info->device_type), &(info->device_type), NULL);
        // clang-format on
    }
    return OK;
}