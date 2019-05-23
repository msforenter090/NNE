#include "nn_matrix.h"
#include "nn_allocation.h"

void new_nn_f_matrix(   const nn_f_matrix_meta * const meta,
                        nn_f_matrix * const matrix  )
{
    matrix->ptr = nn_allocate(  meta->rows * meta->columns *
                                meta->element_size,
                                meta->element_size);
    return;
}

void destroy_nn_matrix( nn_f_matrix * const matrix  )
{
    nn_deallocate(matrix->ptr);
    return;
}

