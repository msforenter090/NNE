#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include "nn.sdk/nn_types.h"
#include "nn.sdk.common/nn_error.h"

void *nn_callback_allocate (const unsigned int bytes, const unsigned short alignment);
void nn_callback_deallocate (void *memory);
void nn_callback_log(const byte *message, const unsigned int length);

#endif // __CALLBACK_H__
