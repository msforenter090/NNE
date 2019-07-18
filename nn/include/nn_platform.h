#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "nn_defs.h"
#include "nn_error.h"
#include "nn_types.h"

extern DLL_PUBLIC nn_error platform_count(  CONTEXT, word* const count      );
extern DLL_PUBLIC nn_error platforms(       CONTEXT, nn_platform* platforms );
extern DLL_PUBLIC nn_error platform_info(   CONTEXT, nn_platform platform   );

#endif // __PLATFORM_H__

