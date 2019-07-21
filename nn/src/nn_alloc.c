#include "nn_alloc.h"

nn_error allocate_buffers(CONTEXT, byte *buffers[], unsigned short count,
                          unsigned int *lengths, unsigned int *alignments) {
    int current = 0;
    for (current = 0; current < count; current++) {
        byte *new_buffer =
            (byte *)context->allocate(lengths[current], alignments[current]);
        buffers[current] = new_buffer;
    }
    return OK;
}

void deallocate(CONTEXT, unsigned short count, byte **buffers) {
    int current = 0;
    for (current = 0; current < count; current++) {
        context->deallocate(buffers[current]);
    }
}
