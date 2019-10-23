#include "nn_runtime.h"

#include "nn_cl_include.h"              // cl_uint, clGetPlatformIDs
#include "nn_error_mapper.h"            // map_error_code
#include "nn.sdk.common/nn_util.h"      // min

nn_error nn_runtime_platform_count(unsigned int* count) {
    cl_uint cl_error = clGetPlatformIDs(0, NULL, count);
    return map_error_code(cl_error, CL_ERROR_MAPPER_GET_PLATFORM_IDS, CL_ERROR_MAPPER_GET_PLATFORM_IDS_LENGTH);
}

nn_error nn_runtime_platforms(unsigned int count, cl_platform_id *platforms) {
    cl_uint cl_error = clGetPlatformIDs(count, platforms, NULL);
    return map_error_code(cl_error, CL_ERROR_MAPPER_GET_PLATFORM_IDS, CL_ERROR_MAPPER_GET_PLATFORM_IDS_LENGTH);
}

nn_error nn_runtime_devices_count(unsigned int platform_count, cl_platform_id * const platforms, unsigned int *count) {
    nn_error error;
    cl_int cl_error = CL_SUCCESS;
    cl_uint per_platform = 0;
    for(int i = 0; i< platform_count; i++) {
        cl_error = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &per_platform);
        if(cl_error != CL_SUCCESS) break;
        *count += per_platform;
    }
    return map_error_code(cl_error, CL_ERROR_MAPPER_GET_DEVICE_IDS, CL_ERROR_MAPPER_GET_DEVICE_IDS_LENGTH);
}

nn_error nn_runtime_devices(unsigned int platform_count, cl_platform_id * const platforms,
                            cl_device_id *devices, unsigned int device_count) {
    cl_int cl_error = CL_SUCCESS;
    cl_int total_devices = 0;
    for(int i = 0; i < platform_count; i++) {
        cl_int devices_per_platform = 0;
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &devices_per_platform);
        cl_error = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, devices_per_platform,
                                devices + total_devices, NULL);
        if(cl_error != CL_SUCCESS) break;
        total_devices += devices_per_platform;
    }
    return map_error_code(cl_error, CL_ERROR_MAPPER_GET_DEVICE_IDS, CL_ERROR_MAPPER_GET_DEVICE_IDS_LENGTH);
}

nn_error nn_runtime_devices_info(unsigned int device_length, cl_device_id *devices,
                                const unsigned int info_length, struct _nn_device_info *infos) {
    cl_device_id device = NULL;
    for (unsigned int i = 0; i < min(device_length, info_length); i++) {
        device = devices[i];
        nn_device_info *info = infos + i;
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
        clGetDeviceInfo(device, CL_DEVICE_PLATFORM, sizeof(info->platform), &(info->platform), NULL);
        clGetDeviceInfo(device, CL_DEVICE_TYPE, sizeof(info->device_type), &(info->device_type), NULL);
        // clang-format on
    }
    return OK;
}

nn_error nn_runtime_select_device(struct _nn_system_info *system_info,
                                struct _nn_system_context *system_context) {
    system_context->device = system_info->devices + 0;
    system_context->device_info = system_info->devices_info + 0;
    return OK;
}
/*
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
    cl_uint cl_error;
    kernel->program = clCreateProgramWithSource(system_context->context, source->kernel_sources_length,
                                                source->kernel_sources, NULL, &cl_error);
    nn_error error = map_error_code(cl_error, CL_ERROR_MAPPER_CREATE_PROGRAM_WITH_SOURCE, CL_ERROR_MAPPER_CREATE_PROGRAM_WITH_SOURCE_LENGTH);
    check_nn_error_log(host_context, error);
    check_nn_error_jump(error, cleanup_label(clCreateProgramWithSource));
    return error;

cleanup_label(clCreateProgramWithSource):
    kernel->program = NULL;
    return error;
}

nn_error nn_runtime_cl_build_program(CONTEXT, nn_kernel_source  const* const source, nn_kernel *const kernel, const char *options) {
    cl_int cl_error = clBuildProgram(kernel->program, 0, NULL, options, NULL, NULL);
    // TODO:
    if(cl_error != CL_SUCCESS) {
        char *message;
        size_t param_size;
        cl_error = clGetProgramBuildInfo(kernel->program, system_context->device, CL_PROGRAM_BUILD_LOG, 0, NULL, &param_size);

        message = (char*)host_context->allocate(param_size, 1);
        memset(message, 0, param_size);
        cl_error = clGetProgramBuildInfo(kernel->program, system_context->device, CL_PROGRAM_BUILD_LOG, param_size, message, NULL);
        host_context->error_logger(message, param_size);
        host_context->deallocate(message);
    }
    nn_error error = map_error_code(cl_error, CL_ERROR_MAPPER_BUILD_PROGRAM, CL_ERROR_MAPPER_BUILD_PROGRAM_LENGTH);
    check_nn_error_log(host_context, error);
    check_nn_error_jump(error, cleanup_label(clBuildProgram));
    return error;

cleanup_label(clBuildProgram):
    kernel->program = NULL;
    // TODO: Get & Print program log.
    // clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
    return error;
}

nn_error nn_runtime_cl_kernels_from_program(CONTEXT, nn_kernel_source const * const source, nn_kernel *const kernel) {
    cl_int cl_error;
    nn_error error;
    cl_uint count = 0;
    const byte *kernel_name = source->kernel_names[count];
    while(kernel_name != NULL) {
        kernel->kernels[count] = clCreateKernel(kernel->program, kernel_name, &cl_error);
        error = map_error_code(cl_error, CL_ERROR_MAPPER_CREATE_KERNEL, CL_ERROR_MAPPER_CREATE_KERNEL_LENGTH);
        check_nn_error_log(host_context, error);
        check_nn_error_jump(error, cleanup_label(clCreateKernel));
        count++;
        kernel_name = source->kernel_names[count];
    }
    return error;

cleanup_label(clCreateKernel):
    return error;
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
}*/