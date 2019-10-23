#include "test_nn_include.h"

#include "test_nn_context.h"
#include "test_nn_callback.h"
#include "test_nn_kernel_execution.h"

// int setup_context(void **state) {
//     state_context *context_holder = calloc(1, sizeof(state_context));
//     memset(context_holder, 0, sizeof(state_context));
// 
//     nn_host_context context = NULL;
//     new_nn_context(&context, nn_callback_allocate, nn_callback_deallocate, nn_callback_log);
// 
//     // nn_system_info system_info = NULL;
//     // new_nn_system_info(context, &system_info);
// // 
//     // nn_system_context system_context = NULL;
//     // new_nn_system_context(context, system_info, &system_context);
// 
//     context_holder->context = context;
//     // context_holder->system_info = system_info;
//     // context_holder->system_context = system_context;
//     *state = context_holder;
//     return 0;
// }
// 
// int teardown_context(void **state) {
//     state_context *context_holder = *state;
// 
//     // Reverse order of construction.
//     // delete_nn_system_context(context_holder->context, context_holder->system_info, context_holder->system_context);
//     // delete_nn_system_info(context_holder->context, context_holder->system_info, context_holder->system_context);
//     delete_nn_context(context_holder->context/*, context_holder->system_info, context_holder->system_context*/);
//     free(context_holder);
//     return 0;
// }

int main(void) {
    // -------------------------------------------------------------------------
    // Context test.
    // -------------------------------------------------------------------------
    const struct CMUnitTest test_context[] = {
        cmocka_unit_test_setup_teardown(test_new_nn_context_create_success, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_new_nn_host_context_create_success, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_new_nn_host_context_create_fail, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_new_nn_system_info_create_success, NULL, NULL),
        cmocka_unit_test_setup_teardown(test_new_nn_system_context_create_success, NULL, NULL),
        {0}};

    // -------------------------------------------------------------------------
    // Kernel execution.
    // -------------------------------------------------------------------------
    /*const struct CMUnitTest test_platform[] = {
        cmocka_unit_test_setup_teardown(test_kernel_simple_success, NULL, NULL),
        {0}};*/

    int failed =
        cmocka_run_group_tests(test_context, NULL, NULL);// +
        // cmocka_run_group_tests(test_platform, setup_context, teardown_context);

    return failed;
}
