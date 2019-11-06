// =================================================================================================
// Project: nn.sdk.common library
// Common constructs used by nn.sdk and nn.sdk client.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-23
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================

#ifndef __NN_SDK_COMMON_DEFS_H__
#define __NN_SDK_COMMON_DEFS_H__

// -----------------------------------------------------------------------------
// Memory callback.
// -----------------------------------------------------------------------------
typedef void *(*nn_allocate)(const unsigned int bytes);
typedef void (*nn_deallocate)(void *memory);

// -----------------------------------------------------------------------------
// Log callback.
// -----------------------------------------------------------------------------
#define LOG_INFO     1
#define LOG_WARNING  1 < 2
#define LOG_ERROR    1 < 3
typedef void (*nn_log_callback)(unsigned short int type, const char *message);

// -----------------------------------------------------------------------------
// Context.
// -----------------------------------------------------------------------------
typedef struct _nn_host_context *nn_host_context;
typedef struct _nn_system_info *nn_system_info;
typedef struct _nn_system_context *nn_system_context;
typedef struct _nn_context {
    nn_host_context host_context;
    nn_system_info system_info;
    nn_system_context system_context;
} nn_context;

#define CONTEXT nn_context *context

// -----------------------------------------------------------------------------
// Network.
// -----------------------------------------------------------------------------
typedef struct _nn_network {
    void * const tag;
    unsigned int * const topology;
    float *const synapses;
} nn_network;
#endif // __NN_SDK_COMMON_DEFS_H__