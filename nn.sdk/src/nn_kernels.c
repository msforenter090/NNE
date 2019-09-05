#include "nn_kernels.h"

#include "nn.sdk.common/nn_util.h"

const char **network_execution_kernel_names_list = (const char *[]) {
    "network_execution", NULL
};

const char **network_execution_sources_list = (const char *[]) {
    dump_bits(
        // #define ACTIVATION_FUNCTION(x) x
        __kernel void network_execution(  const unsigned int row_length, const unsigned int column_length,
                                        __global float* synapses, __global float* biases,
                                        __global float* input_output) {
            __private float sum;
            __private int global_index;
            __private unsigned int count;
            __private unsigned int row_length_private;
            __private unsigned int column_length_private;
            
            sum = 0;
            global_index = get_global_id(0);
            row_length_private = row_length;
            column_length_private = column_length;

            if(global_index < row_length_private) {
                // Matrix multiplication.
                for(count = 0; count < column_length_private; count++) {
                    sum += synapses[count * row_length_private + global_index] * input_output[count];
                }

                // Add bias.
                sum += biases[global_index];

                // Pass through activation function.
                // sum = ACTIVATION_FUNCTION(sum);

                // Write to output.
                input_output[global_index] = sum;
            }
            return;
    }), NULL
};

nn_error network_execution_sources(nn_kernel_source *const sources) {
    sources->kernel_names = network_execution_kernel_names_list;
    sources->kernel_sources = network_execution_sources_list;
    sources->kernel_names_length = 1;
    sources->kernel_sources_length = 1;
    return OK;
}

nn_error network_execution_kernel(CONTEXT, nn_kernel **kernel) {
    *kernel = host_context->allocate(sizeof(struct _nn_kernel), PTR_SIZE);
    (*kernel)->program = host_context->allocate(sizeof(cl_program), PTR_SIZE);
    (*kernel)->kernels = host_context->allocate(sizeof(cl_kernel), PTR_SIZE);
    (*kernel)->info = host_context->allocate(sizeof(struct _nn_kernel_info), PTR_SIZE);
    return OK;
}