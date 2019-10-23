// =================================================================================================
// Project: nn.sdk.common library
// Common constructs used by nn.sdk and nn.sdk client.
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

#ifndef __NN_SDK_COMMON_H__
#define __NN_SDK_COMMON_H__

// -----------------------------------------------------------------------------
// Errors.
// -----------------------------------------------------------------------------
// General error [0 - 100]
#define CODE_OK 0
#define CODE_FAIL 1

typedef struct _nn_error {
    unsigned int code;
    char *message;
} nn_error;

// Predefined error messages.
// General
#define MESSAGE_OK      "Ok"
#define MESSAGE_FAIL    "Fail"
// Memory
#define MESSAGE_MEMORY_ALLOCATION_FAIL "Fail. Reason: Failed to allocate memory."

static const nn_error OK =      { .code = CODE_OK, .message = MESSAGE_OK };
static const nn_error FAIL =    { .code = CODE_FAIL, .message = MESSAGE_FAIL };

static const nn_error FAIL_MEMORY_NULL = { .code = CODE_FAIL, .message = MESSAGE_MEMORY_ALLOCATION_FAIL };

#define SUCCESS_CONDITION(error) if(error.code == 0)
#define FAIL_CONDITION(error) if(error.code != 0)
// #define JUMP_IF_NOT(label, ...) __VA_ARGS__ goto label
#define JUMP_IF(label, ...) __VA_ARGS__ goto label
#define LABEL(function_name) cleanup_##function_name

// Logging macro
#define LOG_IF_FAILED(error, ...) FAIL_CONDITION(error) __VA_ARGS__
#define LOG(...) __VA_ARGS__

#endif