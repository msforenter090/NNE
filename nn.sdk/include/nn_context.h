// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
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

#ifndef __NN_SDK_CONTEXT_H__
#define __NN_SDK_CONTEXT_H__

#include "nn_defs.h"                    // DLL_PUBLIC

#include "nn.sdk.common/nn_types.h"     // struct nn_host_context, nn_allocate, nn_deallocate, etc...
#include "nn.sdk.common/nn_error.h"     // nn_error

extern DLL_PUBLIC nn_error new_nn_context(CONTEXT);
extern DLL_PUBLIC nn_error new_nn_host_context(CONTEXT, nn_allocate allocate, nn_deallocate deallocate,
                                            nn_log_callback log_callback);
extern DLL_PUBLIC nn_error new_nn_system_info(CONTEXT);
extern DLL_PUBLIC nn_error new_nn_system_context(CONTEXT);

extern DLL_PUBLIC nn_error delete_nn_context(CONTEXT);

#endif // __CONTEXT_H__
