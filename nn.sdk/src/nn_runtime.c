#include "nn_runtime.h"

#include "nn_util.h"
#include "nn_constants.h"
#include "nn_cl_include.h"
#include "nn_error_mapper.h"

nn_error nn_runtime_platforms(CONTEXT) {
    cl_uint cl_error = clGetPlatformIDs(MAX_PLATFORMS, system_info->platforms, NULL);
    nn_error error = map_error_code(cl_error, CL_ERROR_MAPPER_GET_PLATFORM_IDS, CL_ERROR_MAPPER_GET_PLATFORM_IDS_LENGTH);
    check_nn_error_log(host_context, error);
    check_nn_error_jump(error, cleanup_label(clGetPlatformIDs));
    return error;

cleanup_label(clGetPlatformIDs):
    return OK;
}

nn_error nn_runtime_devices(CONTEXT) {
    cl_int cl_error = 0;
    nn_error error;

    cl_platform_id platform = system_info->platforms[0];
    cl_uint devices_per_platform = 0;
    cl_uint total_devices = 0;
    for (unsigned short i = 0; system_info->platforms[i] != NULL; i++) {
        devices_per_platform = 0;
        cl_error = clGetDeviceIDs(system_info->platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &devices_per_platform);
        error = map_error_code(cl_error, CL_ERROR_MAPPER_GET_DEVICE_IDS, CL_ERROR_MAPPER_GET_DEVICE_IDS_LENGTH);
        check_nn_error_log(host_context, error);
        check_nn_error_jump(error, cleanup_label(clGetDeviceIDsLength));

        cl_error = clGetDeviceIDs(system_info->platforms[i], CL_DEVICE_TYPE_ALL, devices_per_platform,
                       system_info->devices + total_devices, NULL);
        error = map_error_code(cl_error, CL_ERROR_MAPPER_GET_DEVICE_IDS, CL_ERROR_MAPPER_GET_DEVICE_IDS_LENGTH);
        check_nn_error_log(host_context, error);
        check_nn_error_jump(error, cleanup_label(clGetDeviceIDs));
        
        for (unsigned short j = 0; j < devices_per_platform; j++) {
            system_info->device_platform_mapping[total_devices + j] = i;
        }
        total_devices += devices_per_platform;
    }
    return OK;

cleanup_label(clGetDeviceIDsLength):
cleanup_label(clGetDeviceIDs):
    memset(system_info->devices, 0, sizeof(cl_device_id) * MAX_DEVICES);
    memset(system_info->device_platform_mapping, 0, sizeof(unsigned short) * MAX_DEVICES);
    return error;
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

nn_error nn_runtime_select_device(CONTEXT) {
    // Use first device.
    // TODO - TASK-1: Changed this. For now use first device, but should usedo dome kind of filtering.
    memcpy(&(system_context->platform), system_info->platforms, sizeof(cl_platform_id));
    memcpy(&(system_context->device), system_info->devices, sizeof(cl_device_id));
    memcpy(&(system_context->device_info), system_info->device_info, sizeof(struct _nn_device_info));
    return OK;
}

nn_error nn_runtime_cl_context(CONTEXT) {
    cl_context_properties properties[] = {CL_CONTEXT_PLATFORM, (cl_context_properties)system_context->platform, 0};

    // Count devices we are using.
    cl_int cl_error;
    unsigned short device_count = 1;
    cl_device_id *devices = &(system_context->device);

    // TODO - TASK-1: For now we are using just one device to do computation.
    // In the future we should extend this to multiple devices.
    // cl_device_id device = system_context->device[device_count];
    // while(device != NULL) { device = system_context->device[++device_count]; }
    // device_count = min(device_count, MAX_DEVICES);

    cl_context new_context = clCreateContext(properties, device_count, devices, NULL, NULL, &cl_error);
    nn_error error = map_error_code(cl_error, CL_ERROR_MAPPER_CREATE_CONTEXT, CL_ERROR_MAPPER_CREATE_CONTEXT_LENGTH);
    check_nn_error_log(host_context, error);
    check_nn_error_jump(error, cleanup_label(clCreateContext));
    system_context->context = new_context;
    return error;

cleanup_label(clCreateContext):
    return error;
}

nn_error nn_runtime_cl_command_queue(CONTEXT) {
    cl_int cl_error;
    cl_command_queue_properties properties;
    cl_command_queue new_queue =
        clCreateCommandQueue(system_context->context, system_context->device, CL_QUEUE_PROFILING_ENABLE, &cl_error);
    nn_error error = map_error_code(cl_error, CL_ERROR_MAPPER_CREATE_COMMAND_QUEUE, CL_ERROR_MAPPER_CREATE_COMMAND_QUEUE_LENGTH);
    check_nn_error_log(host_context, error);
    check_nn_error_jump(error, cleanup_label(clCreateCommandQueue));
    system_context->command_queue = new_queue;
    return error;

cleanup_label(clCreateCommandQueue):
    return error;
}

nn_error nn_runtime_cl_program_from_source(CONTEXT, nn_kernel_source const * const source, nn_kernel *const kernel) {
    cl_uint error;
    kernel->program = clCreateProgramWithSource(system_context->context, source->kernel_sources_length,
                                                source->kernel_sources, NULL, &error);
    return OK;
}

nn_error nn_runtime_cl_build_program(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel) {
    cl_int error = clBuildProgram(kernel->program, 0, NULL, NULL, NULL, NULL);
    return OK;
}

nn_error nn_runtime_cl_kernels_from_program(CONTEXT, nn_kernel_source const * const source, nn_kernel *const kernel) {
    cl_uint error;
    cl_uint count = 0;
    const byte *kernel_name = source->kernel_names[count];
    while(kernel_name != NULL) {
        kernel->kernels[count] = clCreateKernel(kernel->program, kernel_name, &error);
        count++;
        kernel_name = source->kernel_names[count];
    }
    return OK;
}

nn_error nn_runtime_cl_kernels_info(CONTEXT, nn_kernel_source const* const source, nn_kernel *const kernel) {
    cl_uint cl_error;
    cl_uint count = 0;
    cl_kernel cl_kernel = kernel->kernels[count];
    while(cl_kernel != NULL) {
        nn_kernel_info *info = &(kernel->info[count]);
        // clang-format off
        cl_error = clGetKernelWorkGroupInfo(cl_kernel, NULL, CL_KERNEL_WORK_GROUP_SIZE, sizeof(info->kernel_work_group_size), &(info->kernel_work_group_size), NULL);
        cl_error = clGetKernelWorkGroupInfo(cl_kernel, NULL, CL_KERNEL_COMPILE_WORK_GROUP_SIZE, sizeof(info->kernel_compile_work_group_size), &(info->kernel_compile_work_group_size), NULL);
        cl_error = clGetKernelWorkGroupInfo(cl_kernel, NULL, CL_KERNEL_LOCAL_MEM_SIZE, sizeof(info->kernel_local_mem_size), &(info->kernel_local_mem_size), NULL);
        // clang-format on
        count++;
        cl_kernel = kernel->kernels[count];
    }
    return OK;
}