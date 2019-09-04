#include "nn_platform.h"

#include <stdio.h>
#include "nn_kernels.h"
#include "nn_runtime.h"

static void network_info(unsigned int * const fan_in, unsigned int * const fan_out, unsigned int * const bias_length,
                        unsigned int * const longest_layer, unsigned int * const synapses_length, 
                        unsigned int * const max_synapse_layer, unsigned int const * const layer_meta,
                        unsigned int layer_meta_length) {
    *bias_length = 0;
    *synapses_length = 0;
    *max_synapse_layer = 0;
    *fan_in = layer_meta[0];
    *fan_out = layer_meta[layer_meta_length - 1];
    unsigned int sum;
    for(unsigned int i = 1; i < layer_meta_length; i++) {
        sum = layer_meta[i] * layer_meta[i -1];
        *synapses_length += sum;
        *bias_length += layer_meta[i];
        if(sum > *max_synapse_layer){ *max_synapse_layer = sum; }
    }
    return;
}

// input_length & output_length is number of ELEMENT_TYPES
nn_error nn_execute_kernel(CONTEXT, nn_neural_net const * const net, ELEMENT_TYPE *input, ELEMENT_TYPE *output) {
    // TODO: Check if any of the layers, or input is larger than MAX_BUFFER_ALLOC
    cl_int cl_error;
    cl_uint counter;
    nn_kernel kernel;
    nn_kernel_source sources;

    unsigned int fan_in, fan_out, bias_length, longest_layer, synapses_length, max_synapse_layer;
    unsigned int layer_count = net->layer_meta_length - 1;
    network_info(&fan_in, &fan_out, &bias_length, &longest_layer,
        &synapses_length, &max_synapse_layer, net->layer_meta, net->layer_meta_length);
 
    simple_kernel_sources(&sources);
    nn_runtime_cl_program_from_source(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_build_program(host_context, system_info, system_context, &sources, &kernel, NULL);
    nn_runtime_cl_kernels_from_program(host_context, system_info, system_context, &sources, &kernel);
    nn_runtime_cl_kernels_info(host_context, system_info, system_context, &sources, &kernel);

    unsigned int input_output_size_in_bytes = longest_layer * sizeof(ELEMENT_TYPE);
    unsigned int synapse_size_in_bytes = max_synapse_layer * sizeof(ELEMENT_TYPE);

    cl_error = 0;
    // Largest buffers we need.
    cl_mem cl_input_output_buffer = clCreateBuffer(
        system_context->context, CL_MEM_HOST_READ_ONLY | CL_MEM_HOST_WRITE_ONLY | CL_MEM_READ_WRITE | CL_MEM_ALLOC_HOST_PTR,
        input_output_size_in_bytes, NULL, &cl_error);

    cl_mem cl_synapses_buffer = clCreateBuffer(
        system_context->context, CL_MEM_HOST_WRITE_ONLY | CL_MEM_READ_ONLY | CL_MEM_ALLOC_HOST_PTR,
        synapse_size_in_bytes, NULL, &cl_error);

    cl_error = clEnqueueWriteBuffer(system_context->command_queue, cl_input_output_buffer, CL_FALSE, 0,
            fan_in * sizeof(ELEMENT_TYPE), input, 0, NULL, NULL);

    unsigned int synapses_matrix_size = 0;
    unsigned int synapses_matrix_offset = 0;
    unsigned int row_length, column_length; 
    for(unsigned int layer = 1; layer <= layer_count; layer++) {
        // Load in memory in the buffers.
        row_length = net->layer_meta[layer - 1];
        column_length = net->layer_meta[layer - 2];
        synapses_matrix_size = net->layer_meta[layer - 1] * net->layer_meta[layer - 2];
        cl_error = clEnqueueWriteBuffer(system_context->command_queue, cl_synapses_buffer, CL_FALSE, 0,
            synapses_matrix_size, net->synapses + synapses_matrix_offset, 0, NULL, NULL);

        // Setup kernel args.
        cl_error = clSetKernelArg(kernel.kernels[VECTOR_ADD], 0, sizeof(unsigned int), &row_length);
        cl_error = clSetKernelArg(kernel.kernels[VECTOR_ADD], 1, sizeof(unsigned int), &column_length);
        cl_error = clSetKernelArg(kernel.kernels[VECTOR_ADD], 3, sizeof(cl_mem), &cl_synapses_buffer);
        cl_error = clSetKernelArg(kernel.kernels[VECTOR_ADD], 4, sizeof(cl_mem), &cl_synapses_buffer);

        size_t global = 1024;
        size_t local = 1024;
        cl_error = clEnqueueNDRangeKernel(system_context->command_queue, kernel.kernels[VECTOR_ADD], 1, NULL, &global, &local, 0, NULL, NULL);
        synapses_matrix_offset += synapses_matrix_size;
        clFlush(system_context->command_queue);
    }

    cl_error = clEnqueueReadBuffer(system_context->command_queue, cl_input_output_buffer, CL_TRUE, 0, fan_out * sizeof(ELEMENT_TYPE), output, 0, 0, NULL);
    clFlush(system_context->command_queue);

    clReleaseMemObject(cl_synapses_buffer);
    clReleaseMemObject(cl_input_output_buffer);

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
