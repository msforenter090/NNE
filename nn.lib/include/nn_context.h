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
#include "nn_types.h"

#include "nn.common/nn_error.h"

extern DLL_PUBLIC nn_error new_nn_context(nn_host_context *host_context, nn_allocate allocate,
                                          nn_deallocate deallocate, nn_info_callback info,
                                          nn_warning_callback warning, nn_error_callback error);
extern DLL_PUBLIC nn_error new_nn_system_info(nn_host_context host_context,
                                              nn_system_info *system_info);
extern DLL_PUBLIC nn_error new_nn_system_context(nn_host_context host_context,
                                                 nn_system_info system_info,
                                                 nn_system_context *system_context);

extern DLL_PUBLIC nn_error delete_nn_system_context(CONTEXT);
extern DLL_PUBLIC nn_error delete_nn_system_info(CONTEXT);
extern DLL_PUBLIC nn_error delete_nn_context(CONTEXT);

#endif // __CONTEXT_H__
