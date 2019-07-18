#include "nn_list.h"

nn_error nn_list_init(  CONTEXT, nn_list_node *head )
{
    *head = NULL;
    return OK;
}

nn_error nn_list_print( CONTEXT, nn_list_node head  )
{
    return OK;
}

uword nn_list_size( CONTEXT, nn_list_node head  )
{
    udoublew size = 0;
    nn_list_node element;
    for(element = head; element != NULL; element = element->next)
    {
        size++;
    }
    return size;
}

nn_list_node nn_list_new_node(CONTEXT,    byte          *key,
                                          byte          *value,
                                          udoublew      key_length,
                                          udoublew      value_lenhth)
{
    return NULL;
}

nn_list_node nn_list_add_last(  CONTEXT, nn_list_node node  )
{
    nn_list_node element;
    for(element = node; element->next != NULL; element = element->next) { }
    element->next = node;
    node->next = NULL;
    return node;
}

nn_error nn_list_free(  CONTEXT, nn_list_node   head)
{
    return OK;
}

nn_list_node nn_list_node_at(   CONTEXT,    nn_list_node    head,
                                            udoublew        index )
{
    udoublew current = 0;
    nn_list_node node = head;
    for(current = 0; current <= index; current++)
    {
        node = node->next;
    }
    return node;
}

nn_list_node nn_list_remove_at( CONTEXT, nn_list_node head,
                                udoublew index )
{
    return NULL;
}

