// =================================================================================================
// Project: nn.sdk.common library
// Common constructs used by nn.sdk and nn.sdk client.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-30
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
//
// =================================================================================================

#ifndef __NN_COMMON_UTIL_H__
#define __NN_COMMON_UTIL_H__

#ifndef max
#define max(a,b) \
       ({ __typeof__ (a) _a = (a); \
          __typeof__ (b) _b = (b); \
          _a > _b ? _a : _b; })
#endif   // max

#ifndef min
#define min(a,b) \
       ({ __typeof__ (a) _a = (a); \
          __typeof__ (b) _b = (b); \
          _a < _b ? _a : _b; })
#endif   // min

#ifndef dump_bits
#define dump_bits(buffer, ...) \
      sprintf(buffer, "%s", #__VA_ARGS__)
#endif // dump_bits

#endif // __NN_COMMON_UTIL_H__
