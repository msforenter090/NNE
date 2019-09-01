#include "nn_error_mapper.h"

#define array_length(x) (sizeof(x) / sizeof((x)[0]))

const nn_tuple CL_ERROR_MAPPER_GET_PLATFORM_IDS[] = {
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clGetPlatformIDs() fail.\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clGetPlatformIDs() success.\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_GET_PLATFORM_IDS_LENGTH = array_length(CL_ERROR_MAPPER_GET_PLATFORM_IDS);

const nn_tuple CL_ERROR_MAPPER_GET_DEVICE_IDS[] = {
    {.key = CL_INVALID_PLATFORM, .error = {.code = CODE_OK, .message = "clGetDeviceIDs() fail(CL_INVALID_PLATFORM).\0"}},
    {.key = CL_INVALID_DEVICE_TYPE, .error = {.code = CODE_OK, .message = "clGetDeviceIDs() fail(CL_INVALID_DEVICE_TYPE).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clGetDeviceIDs() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_DEVICE_NOT_FOUND, .error = {.code = CODE_OK, .message = "clGetDeviceIDs() fail(CL_DEVICE_NOT_FOUND).\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clGetDeviceIDs() success(CL_SUCCESS).\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_GET_DEVICE_IDS_LENGTH = array_length(CL_ERROR_MAPPER_GET_DEVICE_IDS);

nn_error map_error_code(cl_uint error_code, nn_tuple const * const mapping, const unsigned short length) {
    for(unsigned short i = 0; i < length; i++) {
        if(error_code == mapping[i].key) { return mapping[i].error; }
    }
    return OK;
}