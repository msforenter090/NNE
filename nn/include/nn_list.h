#ifndef __LIST_H__
#define __LIST_H__

#include "nn_defs.h"
#include "nn_error.h"
#include "nn_types.h"

extern DLL_PUBLIC nn_error nn_list_init(    CONTEXT, nn_list_node   *head   );
extern DLL_PUBLIC nn_error nn_list_print(   CONTEXT, nn_list_node    head   );
extern DLL_PUBLIC uword nn_list_size(       CONTEXT, nn_list_node    head   );
extern DLL_PUBLIC nn_list_node nn_list_new_node(CONTEXT,    byte        *key,
                                                            byte        *value,
                                                            udoublew    key_length,
                                                            udoublew    value_lenhth);

// TODO: Return nn_error instead of new node.
extern DLL_PUBLIC nn_list_node nn_list_add_last(    CONTEXT,
                                                    nn_list_node head  );
extern DLL_PUBLIC nn_error nn_list_free(            CONTEXT, nn_list_node   head    );
extern DLL_PUBLIC nn_list_node nn_list_node_at(     CONTEXT, nn_list_node   head,
                                                    udoublew index );
extern DLL_PUBLIC nn_list_node nn_list_remove_at(   CONTEXT, nn_list_node   head,
                                                    udoublew index );

#endif // __LIST_H__

