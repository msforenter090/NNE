#ifndef __DEFS_H__
#define __DEFS_H__

// -----------------------------------------------------------------------------
// Min values.
// -----------------------------------------------------------------------------
#if __GNUC__ < 4
#error "Min compiler version error."
#endif

#define DLL_PUBLIC      __attribute__ ((visibility ("default")))
#define DLL_PRIVATE     __attribute__ ((visibility ("hidden")))

#endif // __DEFS_H__

