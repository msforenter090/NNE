#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "nn_defs.h"
#include "nn_error.h"
#include "nn_types.h"

extern DLL_PUBLIC nn_error context_new(nn_context *context,
                                       nn_allocate allocate,
                                       nn_deallocate deallocate);

extern DLL_PUBLIC nn_error context_delete(CONTEXT);

#endif // __CONTEXT_H__
