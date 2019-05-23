#ifndef __NN_ERROR_H__
#define __NN_ERROR_H__

// -----------------------------------------------------------------------------
// Constants.
// -----------------------------------------------------------------------------
static const char * const error_str[] =
{
    "Ok\0",
    "Fail\0",
    0
};

static const unsigned int OK                                            = 0000;
static const unsigned int FAIL                                          = 0001;
static const unsigned int error_count = sizeof(error_str);

// -----------------------------------------------------------------------------
// Types.
// -----------------------------------------------------------------------------
typedef struct _nn_error
{
    unsigned int code;
} nn_error;

// -----------------------------------------------------------------------------
// Helpper functions.
// -----------------------------------------------------------------------------

extern const char * const error_message( const nn_error error );

#endif

