#ifndef __NN_MATRIX_H__
#define __NN_MATRIX_H__

// -----------------------------------------------------------------------------
// Types.
// -----------------------------------------------------------------------------
// -------------------------------------
// Matrix.
// -------------------------------------

#define F_ELEMENT float

typedef struct _nn_f_matrix
{
    float *ptr;
} nn_f_matrix;

typedef struct _nn_f_matrix_meta
{
    unsigned int rows;
    unsigned int columns;
    unsigned int element_size;
} nn_f_matrix_meta;

// -----------------------------------------------------------------------------
// Functions.
// -----------------------------------------------------------------------------
// -------------------------------------
// Matrix related.
// -------------------------------------
void new_nn_f_matrix(   const nn_f_matrix_meta * const meta,
                        nn_f_matrix * const matrix  );

void destroy_nn_matrix( nn_f_matrix * const matrix  );

#endif

