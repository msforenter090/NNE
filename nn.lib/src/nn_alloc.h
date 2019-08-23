#ifndef __NN_ALLOC_H__
#define __NN_ALLOC_H__

#include "nn_error.h"
#include "nn_types.h"

nn_error allocate_buffers(CONTEXT, byte *buffers[], unsigned short count,
                          unsigned int *lengths, unsigned int *alignments);
void deallocate(CONTEXT, unsigned short count, byte **buffers);

#endif // __NN_ALLOC_H__
