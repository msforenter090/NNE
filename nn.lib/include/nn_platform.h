// =================================================================================================
// Project: nn library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-07-31
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 100 characters
//
// =================================================================================================

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "nn_defs.h"
#include "nn_types.h"

#include "nn.common/nn_error.h"

// -----------------------------------------------------------------------------
// Platform.
// -----------------------------------------------------------------------------
extern DLL_PUBLIC nn_error nn_platform_count(CONTEXT, short *const count);
extern DLL_PUBLIC nn_error nn_platforms(CONTEXT, nn_platform *platforms[]);

// Returns five attributes.
// Should pass in byte buffer of atleast 5 elements.
extern DLL_PUBLIC nn_error nn_platform_info(CONTEXT, nn_platform platform,
                                            byte *values[]);

// -----------------------------------------------------------------------------
// Device.
// -----------------------------------------------------------------------------
extern DLL_PUBLIC nn_error nn_platform_device_count(CONTEXT,
                                                    nn_platform platform,
                                                    short *const count);

extern DLL_PUBLIC nn_error nn_platform_devices(CONTEXT, nn_platform platform,
                                               nn_device *devices[]);

extern DLL_PUBLIC nn_error nn_platform_setup(CONTEXT);

#endif // __PLATFORM_H__
