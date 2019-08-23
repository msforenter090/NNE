// =================================================================================================
// Project: nn library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-23
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 100 characters
//
// =================================================================================================

#ifndef __NN_MATRIX_H__
#define __NN_MATRIX_H__

#include "nn_defs.h"
#include "nn_types.h"

// -----------------------------------------------------------------------------
// Types.
// -----------------------------------------------------------------------------
// -------------------------------------
// Matrix.
// -------------------------------------

#define F_ELEMENT float

typedef struct _nn_f_matrix {
    float *ptr;
} nn_f_matrix;

typedef struct _nn_f_matrix_meta {
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
extern DLL_PUBLIC void new_nn_f_matrix(CONTEXT, const nn_f_matrix_meta *const meta,
                                       nn_f_matrix *const matrix);

extern DLL_PUBLIC void destroy_nn_matrix(CONTEXT, nn_f_matrix *const matrix);

#endif // __NN_MATRIX_H__
