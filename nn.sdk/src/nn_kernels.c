#include "nn_kernels.h"

#include "nn.sdk.common/nn_util.h"

const char **simple_kernel_names_list = (const char *[]) {
    "matrix_multiply", NULL
};

const char **simple_kernel_sources_list = (const char *[]) {
    dump_bits(
        __kernel void matrix_multiply(  const unsigned int row_length, const unsigned int column_length,
                                        __global float* synapses, __global float* input_output) {
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
                for(count = 0; count < column_length_private; count++) {
                    sum += synapses[count * row_length_private + global_index] * input_output[count];
                }
                input_output[global_index] = sum;
            }
            return;
    }), NULL
};

void simple_kernel_sources(nn_kernel_source *const sources) {
    sources->kernel_names = simple_kernel_names_list;
    sources->kernel_sources = simple_kernel_sources_list;
    sources->kernel_names_length = 1;
    sources->kernel_sources_length = 1;
    return;
}