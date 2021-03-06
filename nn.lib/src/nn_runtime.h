// =================================================================================================
// Project: nn library
// Platform info extraction, network training.
//
// File information:
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-07-31
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 100 characters
//
// =================================================================================================

#ifndef __NN_RUNTIME_H__
#define __NN_RUNTIME_H__

#include "nn_defs.h"
#include "nn_types.h"
#include "nn_types_internal.h"

#include "nn.common/nn_error.h"

// -----------------------------------------------------------------------------
// Platform.
// -----------------------------------------------------------------------------
nn_error nn_runtime_platforms(CONTEXT);

// -----------------------------------------------------------------------------
// Devices.
// -----------------------------------------------------------------------------
nn_error nn_runtime_devices(CONTEXT);
nn_error nn_runtime_devices_info(CONTEXT);

#endif // __NN_RUNTIME_H__
