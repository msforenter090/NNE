#include "nn_platform.h"

#include "nn_kernels.h"
#include "nn_runtime.h"

// CONTEXT, input(one), layers(multiple), bias(per neuron layer),neuron activation function, one for all, output(one)
nn_error nn_execute_kernel(CONTEXT, nn_neural_net const * const net) {
    cl_uint counter;
    nn_kernel kernel;
    nn_kernel_source sources;
 
    simple_kernel_sources(&sources);
    nn_runtime_cl_program_from_source(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_build_program(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_kernels_from_program(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_kernels_info(host_context, system_info, system_context, &sources, &kernel);

    size_t size = net->meta_layers[0].rows * net->meta_layers[0].columns * sizeof(ELEMENT_TYPE);
    cl_int error = 0;
    cl_mem buffer = clCreateBuffer(system_context->context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, net->layers[0], size, &error);
    error = clEnqueueWriteBuffer(system_context->command_queue, buffer, CL_FALSE, 0, size, net->layers[0], 0, NULL, &error);
    
    // size_t global;
    // size_t local;
    // error = clGetKernelWorkGroupInfo(kernel, system_context->device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
    // global = local;

    // error = clEnqueueNDRangeKernel(system_context->command_queue, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
    // clFinish(system_context->command_queue); 

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
