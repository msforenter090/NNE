#include "nn_matrix.h"
#include "nn_types.h"

void new_nn_f_matrix(CONTEXT, const nn_f_matrix_meta *const meta, nn_f_matrix *const matrix) {
    matrix->ptr =
        host_context->allocate(meta->rows * meta->columns * meta->element_size, meta->element_size);
    return;
}

void destroy_nn_matrix(CONTEXT, nn_f_matrix *const matrix) {
    host_context->deallocate(matrix->ptr);
    return;
}
