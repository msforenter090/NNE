#include "test_nn_context.h"

#include <stdio.h>
#include "nn.sdk/nn_context.h"

#include "test_nn_include.h"
#include "test_nn_callback.h"

// -----------------------------------------------------------------------------
// Test.
// -----------------------------------------------------------------------------
void test_new_nn_context_create_success (void **state) {
    nn_context context;
    nn_error error = new_nn_context(&context);
    ASSERT_OK(error);
}

void test_new_nn_host_context_create_success(void **state) {
    UNUSED(state);

    nn_context context;
    nn_error error = new_nn_context(&context);
    error = new_nn_host_context(&context, nn_callback_allocate, nn_callback_deallocate, nn_callback_log);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(context.host_context);

    delete_nn_context(&context);
}

void test_new_nn_host_context_create_fail(void **state) {
    UNUSED(state);

    nn_context context;
    nn_error error = new_nn_context(&context);
    error = new_nn_host_context(&context, nn_callback_allocate_null, nn_callback_deallocate, nn_callback_log);

    ASSERT_FAIL(error);
    ASSERT_NULL(context.host_context);

    delete_nn_context(&context);
}

void test_new_nn_system_info_create_success(void **state) {
    UNUSED(state);

    nn_context context;
    nn_error error = new_nn_context(&context);
    error = new_nn_host_context(&context, nn_callback_allocate, nn_callback_deallocate, nn_callback_log);
    error = new_nn_system_info(&context);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(context.system_info);

    delete_nn_context(&context);
}

void test_new_nn_system_context_create_success(void **state) {
    UNUSED(state);

    nn_context context;
    nn_error error = new_nn_context(&context);
    error = new_nn_host_context(&context, nn_callback_allocate, nn_callback_deallocate, nn_callback_log);
    error = new_nn_system_info(&context);
    error = new_nn_system_context(&context);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(context.system_info);
    ASSERT_NOT_NULL(context.system_context);

    delete_nn_context(&context);
}