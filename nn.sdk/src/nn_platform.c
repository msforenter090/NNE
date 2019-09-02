#include "nn_platform.h"

#include "nn_kernels.h"
#include "nn_runtime.h"

// input_length & output_length is number of ELEMENT_TYPES
nn_error nn_execute_kernel(CONTEXT, nn_neural_net const * const net, 
                            ELEMENT_TYPE *input, unsigned int input_length,
                            ELEMENT_TYPE *output, unsigned int output_length) {
    cl_int cl_error;
    cl_uint counter;
    nn_kernel kernel;
    nn_kernel_source sources;
 
    simple_kernel_sources(&sources);
    nn_runtime_cl_program_from_source(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_build_program(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_kernels_from_program(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_kernels_info(host_context, system_info, system_context, &sources, &kernel);

    unsigned int input_size_in_bytes = input_length * sizeof(ELEMENT_TYPE);
    unsigned int output_size_in_bytes = output_length * sizeof(ELEMENT_TYPE);
    unsigned int layers_size_in_bytes = 1024 * sizeof(ELEMENT_TYPE);

    // for(unsigned int i = 1; i < net->layers_count; i++) {
    //     layers_size_in_bytes += (net->layer_meta[i] * net->layer_meta[i-1]);
    // }
    // layers_size_in_bytes += (net->fan_in * net->layer_meta[0]);
    // layers_size_in_bytes *= sizeof(ELEMENT_TYPE);

    cl_error = 0;
    // Create buffers.
    cl_mem cl_input_buffer  = clCreateBuffer(system_context->context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, input_size_in_bytes, input, &cl_error);
    cl_mem cl_output_buffer = clCreateBuffer(system_context->context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, output_size_in_bytes, output, &cl_error);
    cl_mem cl_layers_buffer = clCreateBuffer(system_context->context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, layers_size_in_bytes, net->layers, &cl_error);

    clSetKernelArg(kernel.kernels[VECTOR_ADD], 0, input_size_in_bytes, cl_input_buffer);
    clSetKernelArg(kernel.kernels[VECTOR_ADD], 1, output_size_in_bytes, cl_output_buffer);
    clSetKernelArg(kernel.kernels[VECTOR_ADD], 2, layers_size_in_bytes, cl_layers_buffer);

    size_t global = 1024;
    size_t local = 1024;
    cl_error = clEnqueueNDRangeKernel(system_context->command_queue, kernel.kernels[VECTOR_ADD], 1, NULL, &global, &local, 0, NULL, NULL);
    clFlush(system_context->command_queue);

    clReleaseMemObject(cl_layers_buffer);
    clReleaseMemObject(cl_output_buffer);
    clReleaseMemObject(cl_input_buffer);

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
