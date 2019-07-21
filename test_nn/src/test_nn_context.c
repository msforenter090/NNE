#include "test_nn_context.h"

#include "nn_context.h"
#include "test_nn_include.h"

void *allocate(const unsigned int bytes, const unsigned short alignment) {
    return aligned_alloc(alignment, bytes);
}

void deallocate(void *memory) { free(memory); }

nn_error nn_context_create(nn_context *context) {
    return context_new(context, allocate, deallocate);
}

// -----------------------------------------------------------------------------
// Test.
// -----------------------------------------------------------------------------
void test_nn_context_create_success(void **state) {
    UNUSED(state);

    nn_context context = NULL;
    nn_error error = nn_context_create(&context);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(context);

    context_delete(context);
}

void test_nn_context_destroy_success(void **state) {
    UNUSED(state);

    nn_context context = NULL;
    nn_error error = nn_context_create(&context);

    ASSERT_OK(error);
    ASSERT_NOT_NULL(context);
    context_delete(context);
}