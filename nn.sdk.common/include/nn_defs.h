// =================================================================================================
// Project: nn.common
// Common constructs used by nn.library and nn.library client.
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
#if defined(__GNUC__) || defined(__GNUG__)
#if __GNUC__ < 4
#error "Min compiler version error."
#endif
#endif

#if defined(_MSC_VER)
#if _MSC_VER < 1912
#error "Min compiler version error."
#endif
#endif

#endif // __DEFS_H__
