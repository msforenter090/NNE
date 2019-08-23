#include "test_nn_list.h"

#include "nn_list.h"
#include "test_nn_include.h"

nn_list_node new_node(CONTEXT) {
    byte *key_value = "key_value\0";
    size_t key_len = strlen(key_value);

    byte *value = "value_value\0";
    size_t value_len = strlen(value);

    return nn_list_new_node(context, key_value, value, key_len, value_len);
}

void test_nn_list_new_node_success(void **state) {
    UNUSED(state);
    //    state_context *s_context = (state_context*)*state;
    //
    //    nn_list_node node = new_node(s_context->context);
    //    ASSERT_NOT_NULL(node);
    //    ASSERT_NOT_NULL(node->payload.key);
    //    ASSERT_NOT_NULL(node->payload.value);
    //    ASSERT_NULL(node->next);
}

void test_nn_list_init_success(void **state) {
    state_context *s_context = (state_context *)*state;
    nn_list list = NULL;
    nn_list_init(s_context->context, &list);
    ASSERT_NOT_NULL(list);

    nn_list_free(s_context->context, &list);
}

void test_nn_list_size_success(void **state) {
    state_context *s_context = (state_context *)*state;
    nn_list list;
    nn_list_init(s_context->context, &list);
    uword size = nn_list_size(s_context->context, list);
    ASSERT_INT_EQUAL(size, 0);

    nn_list_node node_1 = new_node(s_context->context);
    nn_list_node node_2 = new_node(s_context->context);
    nn_list_add_last(s_context->context, list, node_1);
    nn_list_add_last(s_context->context, list, node_2);

    size = nn_list_size(s_context->context, list);
    ASSERT_INT_EQUAL(size, 2);

    nn_list_free(s_context->context, &list);
    ASSERT_NULL(list);
}

void test_nn_list_add_last_success(void **state) {
    UNUSED(state);
    // state_context *s_context = (state_context *)*state;
}

void test_nn_list_node_at_success(void **state) { UNUSED(state); }

void test_nn_list_remove_at_success(void **state) { UNUSED(state); }

void test_nn_list_free_success(void **state) {
    state_context *s_context = (state_context *)*state;
    nn_list list;
    nn_list_init(s_context->context, &list);
    uword size = nn_list_size(s_context->context, list);
    ASSERT_INT_EQUAL(size, 0);

    nn_list_node node_1 = new_node(s_context->context);
    nn_list_node node_2 = new_node(s_context->context);
    nn_list_add_last(s_context->context, list, node_1);
    nn_list_add_last(s_context->context, list, node_2);

    size = nn_list_size(s_context->context, list);
    ASSERT_INT_EQUAL(size, 2);

    nn_list_free(s_context->context, &list);
}

void test_nn_list_print_success(void **state) { UNUSED(state); }
