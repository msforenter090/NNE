#include "test_nn_kernel_execution.h"

#include "nn.sdk/nn_matrix.h"
#include "test_nn_include.h"
#include "nn.sdk/nn_platform.h"

void test_kernel_simple_success(void **state) {
    state_context *context_holder = (state_context*)*state;

    // nn_neural_net const * const net, 
    //                         ELEMENT_TYPE *input, unsigned int input_length,
    //                         ELEMENT_TYPE *output, unsigned int output_length

    #define MAX_L 1024
    float * input = (float*)malloc(MAX_L * sizeof(ELEMENT_TYPE));
    float * output = (float*)malloc(MAX_L * sizeof(ELEMENT_TYPE));
    float * layers = (float*)malloc(MAX_L * sizeof(ELEMENT_TYPE));

    for(int i = 0; i < MAX_L; i++) {
        input[i] = i;
        output[i] = 0;
        layers[i] = i;
    }

    nn_neural_net net;

    net.layers = layers;

    nn_execute_kernel(context_holder->context, context_holder->system_info, context_holder->system_context,
        &net, input, MAX_L, output, MAX_L);
}