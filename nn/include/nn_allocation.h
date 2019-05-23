#ifndef __NN_ALLOCATION_H__
#define __NN_ALLOCATION_H__

// -----------------------------------------------------------------------------
// Allocation functions.
// -----------------------------------------------------------------------------
extern void* nn_allocate(   const unsigned int bytes,
                            const unsigned short alignmenti );

// -----------------------------------------------------------------------------
// De-Allocation functions.
// -----------------------------------------------------------------------------
extern void nn_deallocate(  const void * const memory   );

#endif

