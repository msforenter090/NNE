#ifndef __TYPES_H__
#define __TYPES_H__

// -----------------------------------------------------------------------------
// Type.
// -----------------------------------------------------------------------------
#ifndef NULL
#define NULL ((void *)0)
#endif
#define PTR_SIZE sizeof(void *)

typedef char byte;
typedef unsigned char ubyte;

// -----------------------------------------------------------------------------
// Memory callback.
// -----------------------------------------------------------------------------
typedef void *(*nn_allocate)(const unsigned int bytes,
                             const unsigned short alignment);
typedef void (*nn_deallocate)(void *memory);

// -----------------------------------------------------------------------------
// List.
// -----------------------------------------------------------------------------
struct _nn_data {
    byte *key;
    byte *value;
};

struct _nn_list_node {
    struct _nn_list_node *next;
    struct _nn_data payload;
};

struct _nn_list {
    struct _nn_list_node *node;
};
// -----------------------------------------------------------------------------
// Context.
// -----------------------------------------------------------------------------
struct _nn_context {
    // -------------------------------------------------------------------------
    // Memory.
    // -------------------------------------------------------------------------
    nn_allocate allocate;
    nn_deallocate deallocate;
};

// -----------------------------------------------------------------------------
// Platform.
// -----------------------------------------------------------------------------
struct _nn_platform;
struct _nn_device;

// -----------------------------------------------------------------------------
// Rename.
// -----------------------------------------------------------------------------
typedef struct _nn_context *nn_context;
typedef struct _nn_platform *nn_platform;
typedef struct _nn_device *nn_device;

typedef struct _nn_data *nn_data;
typedef struct _nn_list_node *nn_list_node;
typedef struct _nn_list *nn_list;

#define CONTEXT nn_context context

#endif // __TYPES_H__
