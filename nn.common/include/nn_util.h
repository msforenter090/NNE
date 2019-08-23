#ifndef __NN_COMMON_UTIL_H__
#define __NN_COMMON_UTIL_H__

#ifndef max
#define max(a,b) \
       ({ __typeof__ (a) _a = (a); \
          __typeof__ (b) _b = (b); \
          _a > _b ? _a : _b; })
#endif
#ifndef min
#define min(a,b) \
       ({ __typeof__ (a) _a = (a); \
          __typeof__ (b) _b = (b); \
          _a < _b ? _a : _b; })
#endif

#endif // __NN_COMMON_UTIL_H__
