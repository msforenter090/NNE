#include "test_nn_kernel_execution.h"

#include "test_nn_include.h"
#include "nn.sdk/nn_platform.h"

void test_kernel_simple_success(void **state) {
    state_context *context_holder = (state_context*)*state;
    nn_execute_kernel(context_holder->context, context_holder->system_info, context_holder->system_context);
}