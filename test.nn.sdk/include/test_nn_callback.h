#ifndef __CALLBACK_H__
#define __CALLBACK_H__

// #include "nn.sdk.comm/nn_types.h"
// #include "nn.sdk.common/nn_error.h"

// 
void *nn_callback_allocate (const unsigned int bytes);
void *nn_callback_allocate_null(const unsigned int bytes);
void nn_callback_deallocate (void *memory);
void nn_callback_log(unsigned short int type, const char *message);

#endif // __CALLBACK_H__
