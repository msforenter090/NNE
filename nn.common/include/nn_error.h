// =================================================================================================
// Project: nn library
// Common constructs used by nn.library and nn.library client.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-23
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 100 characters
//
// =================================================================================================

#ifndef __NN_ERROR_H__
#define __NN_ERROR_H__

// -----------------------------------------------------------------------------
// Error codes.
// -----------------------------------------------------------------------------
// General error [0 - 100]
static const unsigned int CODE_OK = 0;
static const unsigned int CODE_FAIL = 1;
static const unsigned int CODE_UNKNOWN = 2;
static const unsigned int CODE_INVALID_PARAM = 3;

// Memory errors [101 - 200]
static const unsigned int CODE_NO_MEMORY = 101;

// -----------------------------------------------------------------------------
// Types.
// -----------------------------------------------------------------------------
typedef struct _nn_error {
    unsigned int code;
} nn_error;

// -----------------------------------------------------------------------------
// Errors.
// -----------------------------------------------------------------------------
static const nn_error OK = {.code = CODE_OK};
static const nn_error FAIL = {.code = CODE_FAIL};
static const nn_error UNKNOWN = {.code = CODE_UNKNOWN};
static const nn_error INVALID_PARAM = {.code = CODE_INVALID_PARAM};
static const nn_error NO_MEMORY = {.code = CODE_NO_MEMORY};

#endif // __NN_ERROR_H__
