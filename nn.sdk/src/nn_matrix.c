#include "nn_matrix.h"
#include "nn_types.h"

ELEMENT_TYPE* new_nn_fmatrix(CONTEXT, const nn_fmatrix_meta *const meta) {
    return host_context->allocate(meta->rows * meta->columns * meta->element_size, meta->element_size);
}

void destroy_nn_matrix(CONTEXT, ELEMENT_TYPE *const matrix) {
    host_context->deallocate(matrix);
}
