#ifndef __TEST_NN_INCLUDE_H__
#define __TEST_NN_INCLUDE_H__

// clang-format off
#include "nn.sdk/nn_types.h"
#include "test_state.h"

#include <string.h>

#include <stddef.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>
#include <cmocka.h>
// clang-format on

#define UNUSED(x) (void)(x)

#define ASSERT_OK(error) assert_int_equal (error.code, CODE_OK)
#define ASSERT_FAIL(error) assert_int_not_equal (error.code, CODE_OK)

#define ASSERT_NULL(obj) assert_int_equal (obj, NULL)
#define ASSERT_NOT_NULL(obj) assert_int_not_equal (obj, NULL)
#define ASSERT_INT_EQUAL(actual, expected) assert_int_equal (actual, expected)

#endif // __TEST_NN_INCLUDE_H__
