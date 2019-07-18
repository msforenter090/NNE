#include "test_nn_include.h"

#include "test_nn_context.h"
#include "test_nn_list.h"

int setup (void **state)
{
    UNUSED(state);
    return 0;
}

int teardown (void **state)
{
    UNUSED(state);
    return 0;
}

int main (void)
{
    const struct CMUnitTest tests [] =
    {
        // ---------------------------------------------------------------------
        // Context test.
        // ---------------------------------------------------------------------
        cmocka_unit_test(test_nn_context_create_success),
        cmocka_unit_test(test_nn_context_destroy_success),

        // ---------------------------------------------------------------------
        // List test.
        // ---------------------------------------------------------------------
        {0}
    };

    /* If setup and teardown functions are not
     * needed, then NULL may be passed instead */

    int count_fail_tests =
        cmocka_run_group_tests (tests, setup, teardown);

    return count_fail_tests;
}

