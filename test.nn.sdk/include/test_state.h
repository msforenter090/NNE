#ifndef __TEST_STATE_H__
#define __TEST_STATE_H__

#include "nn.sdk/nn_context.h"

typedef struct {
    nn_host_context context;
    nn_system_info system_info;
    nn_system_context system_context;
} state_context;

#endif // __TEST_STATE_H__
