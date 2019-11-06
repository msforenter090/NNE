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

#ifndef __NN_SDK_NETWORK_H__
#define __NN_SDK_NETWORK_H__

#include "nn_defs.h"                    // DLL_PUBLIC
#include "nn.sdk.common/nn_types.h"     // CONTEXT, nn_network
#include "nn.sdk.common/nn_error.h"     // nn_error

extern DLL_PUBLIC nn_error new_nn_network(CONTEXT, nn_network *const network, );
// extern DLL_PUBLIC nn_error nn_execute_kernel(CONTEXT, nn_neural_net const * const net,
//                                             ELEMENT_TYPE *input, ELEMENT_TYPE *output);

#endif // __NN_SDK_NETWORK_H__
