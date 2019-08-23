#include "test_nn_platform.h"

#include "nn_platform.h"
#include "test_nn_include.h"

void test_nn_platform_count_success(void **state) {
    UNUSED(state);
    //    state_context *s_context = (state_context *)*state;
    //    word platform_count      = 0;
    //    nn_platform_count (s_context->context, &platform_count);
    //    ASSERT_INT_EQUAL (platform_count, 1);
}

void test_nn_platforms_success(void **state) {
    UNUSED(state);
    //    state_context *s_context = (state_context *)*state;
    //    word platform_count      = 1;
    //
    //    nn_platform platforms[] = { NULL };
    //    nn_platforms (s_context->context, platforms, platform_count);
    //    ASSERT_NOT_NULL (platforms[0]);
    //
    //    s_context->context->deallocate (platforms[0]);
}

void test_nn_platform_info_success(void **state) {
    UNUSED(state);
    //    state_context *s_context = (state_context *)*state;
    //    word platform_count      = 1;
    //
    //    nn_platform platforms[] = { NULL };
    //    nn_platforms (s_context->context, platforms, platform_count);
    //
    //    byte *attributes[] = { NULL, NULL, NULL, NULL, NULL };
    //    nn_error error     = nn_platform_info (s_context->context,
    //    platforms[0], attributes);
    //
    //    ASSERT_NOT_NULL (attributes[0]);
    //    ASSERT_NOT_NULL (attributes[1]);
    //    ASSERT_NOT_NULL (attributes[2]);
    //    ASSERT_NOT_NULL (attributes[3]);
    //    ASSERT_NOT_NULL (attributes[4]);
    //
    //    s_context->context->deallocate (attributes[0]);
    //    s_context->context->deallocate (attributes[1]);
    //    s_context->context->deallocate (attributes[2]);
    //    s_context->context->deallocate (attributes[3]);
    //    s_context->context->deallocate (attributes[4]);
    //
    //    s_context->context->deallocate (platforms[0]);
}

void test_nn_platform_device_count_success(void **state) {
    UNUSED(state);
    //    state_context *s_context = (state_context *)*state;
    //    word platform_count      = 1;
    //
    //    nn_platform platforms[] = { NULL };
    //    nn_platforms (s_context->context, platforms, platform_count);
    //    ASSERT_NOT_NULL (platforms[0]);
    //
    //    word device_count = 0;
    //    nn_platform_device_count (s_context->context, platforms[0],
    //    &device_count);
    //
    //    ASSERT_INT_EQUAL (device_count, 1);
    //    s_context->context->deallocate (platforms[0]);
}

void test_nn_platform_devices_success(void **state) {
    UNUSED(state);
    //    state_context *s_context = (state_context *)*state;
    //    word platform_count      = 1;
    //
    //    nn_platform platforms[] = { NULL };
    //    nn_device devices[]     = { NULL };
    //
    //    nn_platforms (s_context->context, platforms, platform_count);
    //    nn_platform_devices (s_context->context, platforms[0], devices, 1);
    //    ASSERT_NOT_NULL (devices[0]);
    //
    //    s_context->context->deallocate (devices[0]);
    //    s_context->context->deallocate (platforms[0]);
}

void test_nn_platform_setup(void **state) {
    UNUSED(state);
    // state_context *s_context = (state_context *)*state;
    // nn_platform_setup(s_context->context);
}
