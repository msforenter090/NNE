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

#ifndef __DEFS_H__
#define __DEFS_H__
#if defined(__GNUC__)
    #if __GNUC__ < 4
        #error "Min compiler version error."
    #endif
    #define DLL_PUBLIC __attribute__((visibility("default")))
    #define DLL_PRIVATE __attribute__((visibility("hidden")))
#else
    #error "Unknown compiler."
#endif
#endif // __DEFS_H__
