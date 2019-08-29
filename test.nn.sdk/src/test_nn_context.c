#include "test_nn_context.h"

#include <stdio.h>
#include "nn.sdk/nn_context.h"
#include "test_nn_include.h"
#include "test_nn_callback.h"

nn_error nn_context_create(nn_host_context *context) {
    return new_nn_context(context, nn_callback_allocate, nn_callback_deallocate,
                            nn_callback_log, nn_callback_log, nn_callback_log);
}

// -----------------------------------------------------------------------------
// Test.
// -----------------------------------------------------------------------------
void test_new_nn_context_create_success(void **state) {
    UNUSED(state);

    nn_host_context context = NULL;
    nn_error error = nn_context_create(&context);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(context);

    delete_nn_context(context, NULL, NULL);
}

void test_new_nn_system_info_create_success(void **state) {
    UNUSED(state);

    nn_host_context context = NULL;
    nn_error error = nn_context_create(&context);

    nn_system_info system_info = NULL;
    new_nn_system_info(context, &system_info);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(system_info);

    delete_nn_system_info(context, system_info, NULL);
    delete_nn_context(context, NULL, NULL);
}

void test_new_nn_system_context_create_success(void **state) {
    UNUSED(state);

    nn_host_context context = NULL;
    nn_error error = nn_context_create(&context);

    nn_system_info system_info = NULL;
    new_nn_system_info(context, &system_info);

    nn_system_context system_context = NULL;
    error = new_nn_system_context(context, system_info, &system_context);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(system_context);

    delete_nn_system_context(context, system_info, system_context);
    delete_nn_system_info(context, system_info, NULL);
    delete_nn_context(context, NULL, NULL);
}