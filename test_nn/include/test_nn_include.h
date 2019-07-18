#ifndef __TEST_NN_INCLUDE_H__
#define __TEST_NN_INCLUDE_H__

#include "nn_types.h"
#include "nn_context.h"

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)

#define ASSERT_OK(error) assert_int_equal(error.code, CODE_OK)
#define ASSERT_FAIL(error) assert_int_not_equal(error.code, CODE_OK)

#define ASSERT_NOT_NULL(obj) assert_int_not_equal(obj, NULL)

#endif // __TEST_NN_INCLUDE_H__

