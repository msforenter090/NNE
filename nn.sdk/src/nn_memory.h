// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
//
// File information:
// Memory management.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-30
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================
#ifndef __NN_SDK_MEMORY_H__
#define __NN_SDK_MEMORY_H__

#include <stddef.h>     // size_t
#include <string.h>     // memset

#define PTR_SIZE sizeof(void *)
void* allocate_aligned(void **top, void *bottom, const size_t size_bytes, const short int alignment);
void free_aligned(void* address, void **top);

#endif // __NN_SDK_MEMORY_H__