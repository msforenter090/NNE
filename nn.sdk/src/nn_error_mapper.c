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

const nn_tuple CL_ERROR_MAPPER_CREATE_CONTEXT[] = {
    {.key = CL_INVALID_PLATFORM, .error = {.code = CODE_OK, .message = "clCreateContext() fail(CL_INVALID_PLATFORM).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clCreateContext() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_INVALID_DEVICE, .error = {.code = CODE_OK, .message = "clCreateContext() fail(CL_INVALID_DEVICE).\0"}},
    {.key = CL_DEVICE_NOT_AVAILABLE, .error = {.code = CODE_OK, .message = "clCreateContext() fail(CL_DEVICE_NOT_AVAILABLE).\0"}},
    {.key = CL_OUT_OF_HOST_MEMORY, .error = {.code = CODE_OK, .message = "clCreateContext() fail(CL_OUT_OF_HOST_MEMORY).\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clCreateContext() success(CL_SUCCESS).\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_CREATE_CONTEXT_LENGTH = array_length(CL_ERROR_MAPPER_CREATE_CONTEXT);

const nn_tuple CL_ERROR_MAPPER_CREATE_COMMAND_QUEUE[] = {
    {.key = CL_INVALID_CONTEXT, .error = {.code = CODE_OK, .message = "clCreateCommandQueue() fail(CL_INVALID_CONTEXT).\0"}},
    {.key = CL_INVALID_DEVICE, .error = {.code = CODE_OK, .message = "clCreateCommandQueue() fail(CL_INVALID_DEVICE).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clCreateCommandQueue() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_INVALID_QUEUE_PROPERTIES, .error = {.code = CODE_OK, .message = "clCreateCommandQueue() fail(CL_INVALID_QUEUE_PROPERTIES).\0"}},
    {.key = CL_OUT_OF_HOST_MEMORY, .error = {.code = CODE_OK, .message = "clCreateCommandQueue() fail(CL_OUT_OF_HOST_MEMORY).\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clCreateCommandQueue() success(CL_SUCCESS).\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_CREATE_COMMAND_QUEUE_LENGTH = array_length(CL_ERROR_MAPPER_CREATE_COMMAND_QUEUE);

const nn_tuple CL_ERROR_MAPPER_CREATE_PROGRAM_WITH_SOURCE[] = {
    {.key = CL_INVALID_CONTEXT, .error = {.code = CODE_OK, .message = "clCreateProgramWithSource() fail(CL_INVALID_CONTEXT).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clCreateProgramWithSource() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_OUT_OF_HOST_MEMORY, .error = {.code = CODE_OK, .message = "clCreateProgramWithSource() fail(CL_OUT_OF_HOST_MEMORY).\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clCreateProgramWithSource() success(CL_SUCCESS).\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_CREATE_PROGRAM_WITH_SOURCE_LENGTH = array_length(CL_ERROR_MAPPER_CREATE_PROGRAM_WITH_SOURCE);

const nn_tuple CL_ERROR_MAPPER_BUILD_PROGRAM[] = {
    {.key = CL_INVALID_PROGRAM, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_PROGRAM).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_INVALID_DEVICE, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_DEVICE).\0"}},
    {.key = CL_INVALID_BINARY, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_BINARY).\0"}},
    {.key = CL_INVALID_BUILD_OPTIONS, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_BUILD_OPTIONS).\0"}},
    {.key = CL_INVALID_OPERATION, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_OPERATION).\0"}},
    {.key = CL_COMPILER_NOT_AVAILABLE, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_COMPILER_NOT_AVAILABLE).\0"}},
    {.key = CL_BUILD_PROGRAM_FAILURE, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_BUILD_PROGRAM_FAILURE).\0"}},
    {.key = CL_INVALID_OPERATION, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_INVALID_OPERATION).\0"}},
    {.key = CL_OUT_OF_HOST_MEMORY, .error = {.code = CODE_OK, .message = "clBuildProgram() fail(CL_OUT_OF_HOST_MEMORY).\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clBuildProgram() success(CL_SUCCESS).\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_BUILD_PROGRAM_LENGTH = array_length(CL_ERROR_MAPPER_BUILD_PROGRAM);

const nn_tuple CL_ERROR_MAPPER_CREATE_KERNEL[] = {
    {.key = CL_INVALID_PROGRAM, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_INVALID_PROGRAM).\0"}},
    {.key = CL_INVALID_PROGRAM_EXECUTABLE, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_INVALID_PROGRAM_EXECUTABLE).\0"}},
    {.key = CL_INVALID_KERNEL_NAME, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_INVALID_KERNEL_NAME).\0"}},
    {.key = CL_INVALID_KERNEL_DEFINITION, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_INVALID_KERNEL_DEFINITION).\0"}},
    {.key = CL_INVALID_VALUE, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_INVALID_VALUE).\0"}},
    {.key = CL_OUT_OF_HOST_MEMORY, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_OUT_OF_HOST_MEMORY).\0"}},
    {.key = CL_SUCCESS, .error = {.code = CODE_OK, .message = "clCreateKernel() fail(CL_INVALID_OPERATION).\0"}},
    {0}
};
const unsigned short CL_ERROR_MAPPER_CREATE_KERNEL_LENGTH = array_length(CL_ERROR_MAPPER_CREATE_KERNEL);

nn_error map_error_code(cl_uint error_code, nn_tuple const * const mapping, const unsigned short length) {
    for(unsigned short i = 0; i < length; i++) {
        if(error_code == mapping[i].key) { return mapping[i].error; }
    }
    return OK;
}