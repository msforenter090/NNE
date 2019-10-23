#include "test_nn_callback.h"

#include <stdio.h>
#include "test_nn_include.h"

void *nn_callback_allocate(const unsigned int bytes) {
    return malloc(bytes);
}

void *nn_callback_allocate_null(const unsigned int bytes) {
    return NULL;
}

void nn_callback_deallocate(void *memory) { free(memory); }

void nn_callback_log(unsigned short int type, const char *message) {
    printf("%s\n", message);
}
