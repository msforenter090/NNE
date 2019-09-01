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

#include "nn_cl_include.h"
#include "nn.sdk.common/nn_error.h"

typedef struct _nn_tuple {
    cl_uint key;
    nn_error error;
} nn_tuple;

extern const nn_tuple CL_ERROR_MAPPER_GET_PLATFORM_IDS[];
extern const unsigned short CL_ERROR_MAPPER_GET_PLATFORM_IDS_LENGTH;

extern const nn_tuple CL_ERROR_MAPPER_GET_DEVICE_IDS[];
extern const unsigned short CL_ERROR_MAPPER_GET_DEVICE_IDS_LENGTH;

nn_error map_error_code(cl_uint error_code, nn_tuple const * const mapping, const unsigned short length);

#endif // __NN_ERROR_MAPPER_H__