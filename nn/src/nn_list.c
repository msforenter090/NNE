#include "nn_list.h"

#include "nn_alloc.h"

#include <stdlib.h>
#include <string.h>

// TODO: Consider to remove.
// nn_list_node nn_list_new_node(CONTEXT, byte *key, byte *value,
//                               unsigned int key_length,
//                               unsigned int value_length) {
//     unsigned short buffer_count = 2;
//     byte *new_buffers[2] = {NULL, NULL};
//     unsigned int lengths[2] = {key_length, value_length};
//     unsigned int alignments[] = {1, 1};
//
//     nn_error error = allocate_buffers(context, new_buffers, buffer_count,
//                                       lengths, alignments);
//     memcpy(new_buffers[0], key, key_length);
//     memcpy(new_buffers[1], value, value_length);
//
//     nn_list_node new_node =
//         (nn_list_node)context->allocate(sizeof(struct _nn_list_node),
//         PTR_SIZE);
//     new_node->next = NULL;
//     new_node->payload.key = new_buffers[0];
//     new_node->payload.value = new_buffers[1];
//     return new_node;
// }
//
// nn_error nn_list_init(CONTEXT, nn_list *list) {
//     *list = NULL;
//     *list = context->allocate(sizeof(struct _nn_list), PTR_SIZE);
//     (*list)->node = NULL;
//     return OK;
// }
//
// unsigned short nn_list_size(CONTEXT, nn_list list) {
//     unsigned int size = 0;
//     nn_list_node element = NULL;
//     for (element = list->node; element != NULL; element = element->next)
//         size++;
//     return size;
// }
//
// nn_list_node nn_list_add_last(CONTEXT, nn_list list, nn_list_node node) {
//     nn_list_node *element = &(list->node);
//     while (*element != NULL) {
//         element = &((*element)->next);
//     }
//     *element = node;
//     node->next = NULL;
//     return node;
// }
//
// nn_list_node nn_list_node_at(CONTEXT, nn_list list, unsigned int index) {
//     unsigned int current = 0;
//     nn_list_node node = list->node;
//     for (current = 0; current <= index; current++)
//         node = node->next;
//     return node;
// }
//
// nn_list_node nn_list_remove_at(CONTEXT, nn_list list, unsigned int index) {
//     // TODO: Implement.
//     return NULL;
// }
//
// nn_error nn_list_free(CONTEXT, nn_list *list) {
//     // Iterate backward and free up memory
//     nn_list_node node = (*list)->node;
//     nn_list_node next = NULL;
//     while (node != NULL) {
//         context->deallocate(node->payload.key);
//         context->deallocate(node->payload.value);
//         next = node->next;
//         context->deallocate(node);
//         node = next;
//     }
//     (*list)->node = NULL;
//     context->deallocate(*list);
//     *list = NULL;
//     return OK;
// }
//
// nn_error nn_list_print(CONTEXT, nn_list list) { return OK; }
