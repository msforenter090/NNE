#include "test_nn_include.h"

#include "test_nn_context.h"
#include "test_nn_platform.h"

int setup_context(void **state) {
    state_context *s_context = calloc(1, sizeof(state_context));
    nn_error error = nn_context_create(&(s_context->context));
    *state = s_context;
    return 0; // error.code;
}

int teardown_context(void **state) {
    state_context *s_context = *state;
    context_delete(s_context->context);
    free(s_context);
    return 0;
}

int main(void) {
    // -------------------------------------------------------------------------
    // Context test.
    // -------------------------------------------------------------------------
    const struct CMUnitTest test_context[] = {
        cmocka_unit_test_setup_teardown(test_nn_context_create_success, NULL,
                                        NULL),
        cmocka_unit_test_setup_teardown(test_nn_context_destroy_success, NULL,
                                        NULL),
        {0}};

    // -------------------------------------------------------------------------
    // Platform test.
    // -------------------------------------------------------------------------
    const struct CMUnitTest test_platform[] = {
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
        {0}};
    /* If setup and teardown functions are not
     * needed, then NULL may be passed instead */

    int failed =
        cmocka_run_group_tests(test_context, NULL, NULL) +
        cmocka_run_group_tests(test_platform, setup_context, teardown_context);

    return failed;
}
