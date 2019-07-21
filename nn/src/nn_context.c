#include "nn_context.h"

nn_error context_new(nn_context *context, nn_allocate allocate,
                     nn_deallocate deallocate) {
    *context = NULL;
    // Alignment must be size of the largest field in the structure.
    nn_context new_context =
        (nn_context)allocate(sizeof(struct _nn_context), sizeof(nn_allocate));
    new_context->allocate = allocate;
    new_context->deallocate = deallocate;
    *context = new_context;
    return OK;
}

nn_error context_delete(CONTEXT) {
    context->deallocate(context);
    return OK;
}
