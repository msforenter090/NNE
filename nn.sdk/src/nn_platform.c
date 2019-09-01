#include "nn_platform.h"

#include "nn_kernels.h"
#include "nn_runtime.h"
#include "nn_types_internal.h"

// CONTEXT, input(one), layers(multiple), bias(per neuron layer),neuron activation function, one for all, output(one)
nn_error nn_execute_kernel(CONTEXT) {
    cl_uint counter;
    nn_kernel kernel;
    nn_kernel_source sources;
 
    simple_kernel_sources(&sources);
    nn_runtime_cl_program_from_source(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_build_program(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_kernels_from_program(host_context, system_info, system_context, &sources, &kernel);

// 
    // size_t global;
    // size_t local;
    // error = clGetKernelWorkGroupInfo(kernel, system_context->device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
    // global = local;
// 
    // error = clEnqueueNDRangeKernel(system_context->command_queue, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
    // clFinish(system_context->command_queue); 
// 
    // clReleaseKernel(kernel);

    counter = 0;
    cl_kernel cl_kernel = kernel.kernels[counter];
    while(cl_kernel != NULL) {
        clReleaseKernel(cl_kernel);
        counter++;
        cl_kernel = kernel.kernels[counter];
    }
    clReleaseProgram(kernel.program);
    return OK;
}
