#include "test_nn_callback.h"

#include <stdio.h>
#include "test_nn_include.h"

void *nn_callback_allocate(const unsigned int bytes, const unsigned short alignment) {
    return aligned_alloc(alignment, bytes);
}

void nn_callback_deallocate(void *memory) { free(memory); }

void nn_callback_log(const byte *message, const unsigned int length) {
    UNUSED(length);
    printf("%s\n", message);
}
