// =================================================================================================
// Project: nn.sdk library
// Platform info extraction, network training.
//
// File information:
// Interface for public consumption.
// Author......... Milan Stanarevic <msforenter090@gmail.com>
// Changed at..... 2019-08-23
// License........ MIT license
// Tab-size....... 4 spaces
// Line length.... 120 characters
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

#define ELEMENT_TYPE float

typedef struct _nn_f_matrix_meta {
    unsigned int rows;
    unsigned int columns;
    unsigned int element_size;
} nn_fmatrix_meta;

typedef struct _nn_neural_net {
    ELEMENT_TYPE **biases;
    ELEMENT_TYPE **layers;
    nn_fmatrix_meta *meta_layers;
    nn_fmatrix_meta *meta_biases;
    unsigned short layer_count;
} nn_neural_net;

// -----------------------------------------------------------------------------
// Functions.
// -----------------------------------------------------------------------------
extern DLL_PUBLIC ELEMENT_TYPE cm_read_element(unsigned int column, unsigned int row, ELEMENT_TYPE * const matrix);
extern DLL_PUBLIC ELEMENT_TYPE* new_nn_fmatrix(CONTEXT, const nn_fmatrix_meta *const meta);
extern DLL_PUBLIC void destroy_nn_matrix(CONTEXT, ELEMENT_TYPE *const matrix);

#endif // __NN_MATRIX_H__
