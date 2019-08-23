#ifndef __TEST_NN_CONTEXT_H__
#define __TEST_NN_CONTEXT_H__

#include "nn_types.h"
#include "nn.common/nn_error.h"

void *allocate (const unsigned int bytes, const unsigned short alignment);
void deallocate (void *memory);
nn_error nn_context_create (nn_context *context);

void test_nn_context_create_success (void **state);
void test_nn_context_destroy_success (void **state);

#endif // __TEST_NN_CONTEXT_H__
