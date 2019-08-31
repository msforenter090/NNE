#include "nn_platform.h"

#include <string.h>

#include "nn_kernels.h"
#include "nn_types_internal.h"

nn_error nn_execute_kernel(CONTEXT) {
    byte *kernel_source = host_context->allocate(1024, PTR_SIZE);
    memset(kernel_source, 0, 1024);
    const char *code[]={kernel_source};
    simple_kernel(kernel_source);
    cl_uint error;
    cl_program program = clCreateProgramWithSource(system_context->context, 1, code, NULL, &error);
    error = clBuildProgram(program, 0, NULL, "", NULL, NULL);
    cl_kernel kernel = clCreateKernel(program, "vector_add", &error);
    size_t global;
    size_t local;  
    error = clGetKernelWorkGroupInfo(kernel, system_context->device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
    global = local;
    error = clEnqueueNDRangeKernel(system_context->command_queue, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
    clFinish(system_context->command_queue);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    return OK;
}
