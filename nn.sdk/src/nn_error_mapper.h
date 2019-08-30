// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-23
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================

#ifndef __NN_ERROR_MAPPER_H__
#define __NN_ERROR_MAPPER_H__

// TODO - TASK-2: Do it differently.
#define CL_TARGET_OPENCL_VERSION 120

#include <CL/cl.h>
#include "nn.sdk.common/nn_error.h"

typedef struct _nn_tuple {
    cl_uint key;
    nn_error error;
} nn_tuple;

static const nn_tuple CL_ERROR_MAPPER_GET_PLATFORM_IDS[] = {
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clGetPlatformIDs() fail.\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clGetPlatformIDs() success.\0"}},
    {0}
};

nn_error map_error_code(cl_uint error_code, nn_tuple const * const mapping, const unsigned short length);

#endif // __NN_ERROR_MAPPER_H__