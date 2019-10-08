#include "nn_kernels.h"

#include "nn.sdk.common/nn_util.h"

const char **network_solve_tight_kernel_names_list = (const char *[]) {
    "solve_tight", NULL
};
/*
const char **network_execution_sources_list = (const char *[]) {
    dump_bits(
        // synapse, biases          <-  Regular vectors
        // inout                    <-  Vector for storing in / reading out results.
        //                              Must be large enought to match largest layer length.
        // intermediate             <-  Vector for storing intermediate results.
        //                              Must be large enought to match largest layer length.
        // miscellaneous            <-  Other data.
        //                              Requires topology info. length, [fan_in, l1, l2, ..., ln(fan_out)]
        __kernel void solve_tight( __global float *synapse, __global float *biases,
                __global float *inout, __global float *intermediate, __global float *miscellaneous) {
            __private float sum, layer;
            __private unsigned int topology_length, layer_count, row_length, column_length;
            __private unsigned int local_id, segnemt, group_size;

            sum = layer = 0;
            topology_length = miscellaneous[0];
            layer_count = topology_length - 1;
            row_length = column_length = 0;

            local_id = get_local_id(0);
            segnemt = 0;
            group_size = get_local_size(0);

            for (layer = 0; layer < layer_count; ++layer)
            {
                column_length   = miscellaneous[2 * layer + 1];
                row_length      = miscellaneous[2 * layer + 2];
            }
            if (global_id < row_length)
            {
                for (current_row = 0; current_row < column_length; ++current_row)
                {
                    sum += synapse[current_row * row_length + global_id + synapse_offset] * in_out[current_row];
                }
                sum += biases[global_id + bias_offset];
                // sum = activation_function(sum);
                // sum = 1 / sum;
            }
            barrier(CLK_GLOBAL_MEM_FENCE);
            if (global_id < row_length)
            {
                in_out[global_id] = sum;
            }
            return;
    }), NULL
};
*/

// clang-off
const char **network_solve_tight_sources_list = (const char *[]) {
    dump_bits(
        // synapse, biases          <-  Regular vectors
        // inout                    <-  Vector for storing in / reading out results.
        //                              Must be large enought to match largest layer length.
        // intermediate             <-  Vector for storing intermediate results.
        //                              Must be large enought to match largest layer length.
        // miscellaneous            <-  Other data.
        //                              Requires topology info. length, [fan_in, l1, l2, ..., ln(fan_out)]
        __kernel void solve_tight(__global float *synapse, __global float *biases,
                __global float *inout, __global float *intermediate, __global float *miscellaneous) {
            __private float sum;
            __private unsigned int topology_length, layer_count, row_length, column_length;
            __private unsigned int layer, column_id, local_id, segment, total_segments, group_size, current_row;
            __private unsigned int synapse_offset, bias_offset;

            sum = layer = 0;
            topology_length = miscellaneous[0];
            layer_count = topology_length - 1;
            row_length = column_length = 0;

            local_id = get_local_id(0);
            segment = 0;
            group_size = get_local_size(0);

            // For each layer.
            for (layer = 0; layer < layer_count; ++layer) {
                column_length   = (unsigned int) miscellaneous[layer + 1];
                row_length      = (unsigned int) miscellaneous[layer + 2];

                // For each horizontal segment.
                segment = 0;
                column_id = 0;
                total_segments = (row_length / group_size) + 1;
                for(segment = 0; segment < total_segments; ++segment) {
                    column_id = segment * group_size + local_id;
                    if(column_id < row_length) {
                        bias_offset = synapse_offset = 0;
                        for(current_row = 0; current_row < row_length; ++current_row) {
                            sum += synapse[current_row * row_length + local_id + synapse_offset] * inout[current_row + bias_offset];
                        }
                        sum = 1 / sum;
                        synapse_offset += column_length * row_length;
                        bias_offset += row_length;
                        intermediate[] = sum;
                    }
                    barrier(CLK_GLOBAL_MEM_FENCE | CLK_LOCAL_MEM_FENCE);
                }
            }

            // if (global_id < row_length) {
            //     for (current_row = 0; current_row < column_length; ++current_row) {
            //         sum += synapse[current_row * row_length + global_id + synapse_offset] * in_out[current_row];
            //     }
            //     sum += biases[global_id + bias_offset];
            //     // sum = activation_function(sum);
            //     // sum = 1 / sum;
            // }
            // barrier(CLK_GLOBAL_MEM_FENCE);
            // if (global_id < row_length) {
            //     in_out[global_id] = sum;
            // }
            return;
    }), NULL
};
// clang-on

nn_error network_solve_tight_sources(nn_kernel_source *const sources) {
    sources->kernel_names = network_solve_tight_kernel_names_list;
    sources->kernel_sources = network_solve_tight_sources_list;
    sources->kernel_names_length = 1;
    sources->kernel_sources_length = 1;
    return OK;
}

nn_error network_solve_tight_kernel(CONTEXT, nn_kernel **kernel) {
    *kernel = host_context->allocate(sizeof(struct _nn_kernel), PTR_SIZE);
    (*kernel)->program = host_context->allocate(sizeof(cl_program), PTR_SIZE);
    (*kernel)->kernels = host_context->allocate(sizeof(cl_kernel), PTR_SIZE);
    (*kernel)->info = host_context->allocate(sizeof(struct _nn_kernel_info), PTR_SIZE);
    return OK;
}