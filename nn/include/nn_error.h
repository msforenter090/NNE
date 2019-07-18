#ifndef __NN_ERROR_H__
#define __NN_ERROR_H__

#include "nn_types.h"

// #define static_text static const char * const
// #define msg_varaible(type, name, value) type MSG_##name = value
// #define (name, value) static 
// -----------------------------------------------------------------------------
// Error text messages.
// -----------------------------------------------------------------------------
// General.
static const char * const MSG_OK                        = "Ok";
static const char * const MSG_FAIL                      = "Fail";
static const char * const MSG_UNKNOWN                   = "Unknown";
static const char * const MSG_INVALID_PARAM             = "Invalid Param";

// Memory
static const char * const MSG_NO_MEMORY                 = "No Memory";

// -----------------------------------------------------------------------------
// Error codes.
// -----------------------------------------------------------------------------
// General error [0 - 100]
static const udoublew CODE_OK                                       = 0;
static const udoublew CODE_FAIL                                     = 1;
static const udoublew CODE_UNKNOWN                                  = 2;
static const udoublew CODE_INVALID_PARAM                            = 3;

// Memory errors [101 - 200]
static const udoublew CODE_NO_MEMORY                                = 101;

// -----------------------------------------------------------------------------
// Types.
// -----------------------------------------------------------------------------
typedef struct _nn_error
{
    udoublew code;
    const char * const msg;
} nn_error;

// -----------------------------------------------------------------------------
// Errors.
// -----------------------------------------------------------------------------
static nn_error OK              = { .code = CODE_OK,                .msg = MSG_OK };
static nn_error FAIL            = { .code = CODE_FAIL,              .msg = MSG_FAIL };
static nn_error UNKNOWN         = { .code = CODE_UNKNOWN,           .msg = MSG_UNKNOWN };
static nn_error INVALID_PARAM   = { .code = CODE_INVALID_PARAM,     .msg = MSG_INVALID_PARAM };

static nn_error NO_MEMORY       = { .code = CODE_NO_MEMORY,         .msg = MSG_NO_MEMORY };

#endif

