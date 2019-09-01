#ifndef __NN_UTIL_H__
#define __NN_UTIL_H__

#include <string.h>

#include "nn_types.h"
#define check_nn_error_log(CONTEXT_HOST, error) \
    if(error.code != CODE_OK) { host_context->error_logger(error.message, strlen(error.message)); } \
    else { host_context->info_logger(error.message, strlen(error.message)); }

#define check_nn_error_jump(error, label) if(error.code != CODE_OK) { goto label; }

#define cleanup_label(function) function##Cleanup

#endif // __NN_UTIL_H__