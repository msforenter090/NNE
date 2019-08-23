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

#ifndef __DEFS_H__
#define __DEFS_H__

// -----------------------------------------------------------------------------
// Min values.
// -----------------------------------------------------------------------------
#if __GNUC__ < 4
#error "Min compiler version error."
#endif

#define DLL_PUBLIC __attribute__((visibility("default")))
#define DLL_PRIVATE __attribute__((visibility("hidden")))

#define CL_TARGET_OPENCL_VERSION 220

#endif // __DEFS_H__
