// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-07-31
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================

#ifndef __TYPES_H__
#define __TYPES_H__

// -----------------------------------------------------------------------------
// Type.
// -----------------------------------------------------------------------------
#ifndef NULL
#define NULL ((void *)0)
#endif
#define PTR_SIZE sizeof(void *)

typedef char byte;
typedef unsigned char ubyte;

// -----------------------------------------------------------------------------
// Memory callback.
// -----------------------------------------------------------------------------
typedef void *(*nn_allocate)(const unsigned int bytes, const unsigned short alignment);
typedef void (*nn_deallocate)(void *memory);

// -----------------------------------------------------------------------------
// Log callback.
// -----------------------------------------------------------------------------
typedef void (*nn_info_callback)(const byte *message, const unsigned int length);
typedef void (*nn_warning_callback)(const byte *message, const unsigned int length);
typedef void (*nn_error_callback)(const byte *message, const unsigned int length);

// -----------------------------------------------------------------------------
// Context.
// -----------------------------------------------------------------------------
struct _nn_host_context {
    // -------------------------------------------------------------------------
    // Memory.
    // -------------------------------------------------------------------------
    nn_allocate allocate;
    nn_deallocate deallocate;

    // -------------------------------------------------------------------------
    // Logging.
    // -------------------------------------------------------------------------
    nn_info_callback info_logger;
    nn_warning_callback warning_logger;
    nn_error_callback error_logger;
};

// -----------------------------------------------------------------------------
// System.
// -----------------------------------------------------------------------------
struct _nn_system_info;
struct _nn_system_context;
struct _nn_system_platform;
struct _nn_system_device;

// -----------------------------------------------------------------------------
// Rename.
// -----------------------------------------------------------------------------
typedef struct _nn_host_context *nn_host_context;
typedef struct _nn_system_info *nn_system_info;
typedef struct _nn_system_context *nn_system_context;
typedef struct _nn_system_platform *nn_system_platform;
typedef struct _nn_system_device *nn_system_device;

#define CONTEXT_HOST nn_host_context host_context
#define CONTEXT_SYSTEM_INFO nn_system_info system_info
#define CONTEXT_SYSTEM nn_system_context system_context
#define CONTEXT CONTEXT_HOST, CONTEXT_SYSTEM_INFO, CONTEXT_SYSTEM

#endif // __TYPES_H__
