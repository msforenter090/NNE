#include "nn_memory.h"

void* allocate_aligned(void **top, void *bottom, const size_t size_bytes, const short int alignment) {
        size_t expanded_size_bytes = size_bytes + alignment;
    size_t raw_address = (size_t)(*top);
    // size_t raw_address = (size_t)(*top) + expanded_size_bytes;
    size_t new_top = (size_t)(*top) + (size_t)expanded_size_bytes;
    *top = (void*)new_top;

    const size_t mask = alignment - 1;
    const size_t misalignment = (raw_address & mask);
    const unsigned char adjustment = alignment - misalignment;
    const size_t aligned_address = raw_address + adjustment;
    unsigned char* p_adjustment = (unsigned char*)(aligned_address - 1);
    (*p_adjustment) = adjustment;
    return (void*)aligned_address;
}

void free_aligned(void* address, void **top) {
    size_t aligned_address = (size_t)address;
    unsigned char* p_adjustment = (unsigned char*)(aligned_address - 1);
    unsigned char adjustment = (unsigned char)*p_adjustment;
    size_t raw_address = aligned_address - adjustment;
    *top = (void*)raw_address;
}