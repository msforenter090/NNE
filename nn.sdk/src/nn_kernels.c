#include "nn_kernels.h"

#include "nn.sdk.common/nn_util.h"

const char **simple_kernel_names_list = (const char *[]) {
    "matrix_multiply", NULL
};

const char **simple_kernel_sources_list = (const char *[]) {
    dump_bits(
        // Expects: ROW_LENGTH, INPUT_LENGTH
        __kernel void matrix_multiply(__global float* lhs, __global float* rhs, __global float* out) {
            __private float sum;
            __private int global_index;
            __private unsigned int count;
            
            sum = 0;
            global_index = get_global_id(0);
            for(count = 0; count < INPUT_LENGTH; count++) {
                sum += lhs[count * ROW_LENGTH + global_index] * rhs[count];
            }
            out[global_index] = sum;
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