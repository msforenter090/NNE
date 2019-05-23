#include "nn_error.h"

const char * const error_message( const nn_error error )
{
    return error_str(error.code);
}

