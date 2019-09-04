#include "test_nn_kernel_execution.h"

#include "nn.sdk/nn_matrix.h"
#include "test_nn_include.h"
#include "nn.sdk/nn_platform.h"

void test_kernel_simple_success(void **state) {
    state_context *context_holder = (state_context*)*state;

    float input[] = {1, 2, 3};
    float output[] = {110, 110, 110, 110};
    float synapses[] = {
        1, 1, 1, 1,
        2, 2, 2, 2,
        3, 3, 3, 3
    };
    float biases[] = {1, 2, 3, 4};
    unsigned int layer_meta[] = {3, 4};

    nn_neural_net net;
    net.synapses = &synapses[0];
    net.biases = &biases[0];
    net.layer_meta = &layer_meta[0];
    net.layer_meta_length = 2;

    nn_execute_kernel(context_holder->context, context_holder->system_info, context_holder->system_context,
        &net, input, output);
}