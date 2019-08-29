#include "test_nn_include.h"

#include "test_nn_context.h"
#include "test_nn_platform.h"
#include "test_nn_callback.h"

int setup_context(void **state) {
    state_context *context_holder = calloc(1, sizeof(state_context));
    memset(context_holder, 0, sizeof(state_context));

    nn_error error; 
    error = new_nn_context(&(context_holder->context), nn_callback_allocate, nn_callback_deallocate, nn_callback_log, nn_callback_log, nn_callback_log);
    error = new_nn_system_info(context_holder->context, &(context_holder->system_info));

    *state = context_holder;
    return 0;
}

int teardown_context(void **state) {
    state_context *context_holder = *state;

    // Reverse order of construction.
    delete_nn_system_info(context_holder->context, context_holder->system_info, context_holder->system_context);
    delete_nn_context(context_holder->context, context_holder->system_info, context_holder->system_context);
    free(context_holder);
    return 0;
}

int main(void) {
    // -------------------------------------------------------------------------
    // Context test.
    // -------------------------------------------------------------------------
    const struct CMUnitTest test_context[] = {
        cmocka_unit_test_setup_teardown(test_new_nn_context_create_success, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_new_nn_system_info_create_success, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_new_nn_system_context_create_success, NULL, NULL),
        {0}};

    // -------------------------------------------------------------------------
    // Platform test.
    // -------------------------------------------------------------------------
    /*const struct CMUnitTest test_platform[] = {
        cmocka_unit_test_setup_teardown(test_nn_platform_count_success, NULL,
                                        NULL),
        cmocka_unit_test_setup_teardown(test_nn_platforms_success, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_nn_platform_info_success, NULL,
                                        NULL),
        cmocka_unit_test_setup_teardown(test_nn_platform_device_count_success,
                                        NULL, NULL),
        cmocka_unit_test_setup_teardown(test_nn_platform_devices_success, NULL,
                                        NULL),
        cmocka_unit_test_setup_teardown(test_nn_platform_setup, NULL, NULL),
        {0}};*/
    /* If setup and teardown functions are not
     * needed, then NULL may be passed instead */

    int failed =
        cmocka_run_group_tests(test_context, NULL, NULL);// +
//        cmocka_run_group_tests(test_platform, setup_context, teardown_context);

    return failed;
}
