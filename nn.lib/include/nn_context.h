// =================================================================================================
// Project: nn library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-23
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 100 characters
//
// =================================================================================================

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "nn_defs.h"
#include "nn_error.h"
#include "nn_types.h"

extern DLL_PUBLIC nn_error context_new(nn_context *context,
                                       nn_allocate allocate,
                                       nn_deallocate deallocate,
                                       nn_info_callback info,
                                       nn_warning_callback warning,
                                       nn_error_callback error);

extern DLL_PUBLIC nn_error context_delete(CONTEXT);

#endif // __CONTEXT_H__
