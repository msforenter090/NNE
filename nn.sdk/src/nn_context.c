#include "nn_context.h"

#include "nn_memory.h"                  // allocate_alogned, free_aligned
#include "nn_runtime.h"                 // nn_runtime_platform_count, nn_runtime_platforms, etc...
#include "nn_constants.h"               // state and util stack sizes
#include "nn_types_internal.h"          // struct _nn_host_context, STACK_STATE_TOP, STACK_STATE_BOTTOM, etc...

nn_error new_nn_context(CONTEXT) {
    memset(context, 0, sizeof(struct _nn_context));
    return OK;
}

nn_error new_nn_host_context(CONTEXT, nn_allocate allocate, nn_deallocate deallocate,
                            nn_log_callback log_callback) {
    context->host_context = NULL;
    nn_host_context new_context = (nn_host_context)allocate(sizeof(struct _nn_host_context));
    JUMP_IF(LABEL(new_nn_context_allocate), if(new_context == NULL));

    new_context->allocate = allocate;
    new_context->deallocate = deallocate;
    new_context->logger = log_callback;

    new_context->state = allocate(STACK_SIZE_STATE);
    JUMP_IF(LABEL(new_state_stack_allocate), if(new_context->state == NULL));
    new_context->state_top = new_context->state;
    new_context->state_bottom = new_context->state + STACK_SIZE_STATE;

    new_context->util = allocate(STACK_SIZE_UTIL);
    JUMP_IF(LABEL(new_util_stack_allocate), if(new_context->util == NULL));
    new_context->util_top = new_context->util;
    new_context->util_bottom = new_context->util + STACK_SIZE_UTIL;

    context->host_context = new_context;
    return OK;

    // cleanup
LABEL(new_util_stack_allocate):
    LOG(log_callback(LOG_ERROR, "util stack cleanup.\0"));
    deallocate(new_context->util);
LABEL(new_state_stack_allocate):
    LOG(log_callback(LOG_ERROR, "state stack cleanup.\0"));
    deallocate(new_context->state);
LABEL(new_nn_context_allocate):
    LOG(log_callback(LOG_ERROR, "host context cleanup.\0"));
    deallocate(new_context);

    return FAIL_MEMORY_NULL;
}

nn_error new_nn_system_info(CONTEXT) {
    void *util_top = context->host_context->util_top;
    void *util_bottom = context->host_context->util_bottom;

    unsigned int platform_count = 0;
    unsigned int device_count = 0;

    size_t platform_size_bytes;
    size_t device_size_bytes;
    size_t info_size_bytes;

    cl_platform_id *tmp_platforms = NULL;
    cl_device_id *tmp_devices = NULL;
    struct _nn_device_info *tmp_device_info = NULL;

    // Get Platform count and store platforms into tmp memory.
    nn_error error = nn_runtime_platform_count(&platform_count);
    JUMP_IF(LABEL(error), FAIL_CONDITION(error));
    platform_size_bytes = platform_count * sizeof(cl_platform_id);

    tmp_platforms = (cl_platform_id*)allocate_aligned(&util_top, util_bottom, platform_size_bytes, PTR_SIZE);
    error = nn_runtime_platforms(platform_count, tmp_platforms);
    JUMP_IF(LABEL(error), FAIL_CONDITION(error));

    // Get Device count and store devices into tmp memory.
    error = nn_runtime_devices_count(platform_count, tmp_platforms, &device_count);
    JUMP_IF(LABEL(error), FAIL_CONDITION(error));
    device_size_bytes = device_count * sizeof(cl_device_id);

    tmp_devices = (cl_device_id*)allocate_aligned(&util_top, util_bottom, device_size_bytes, PTR_SIZE);
    error = nn_runtime_devices(platform_count, tmp_platforms, tmp_devices, device_count);
    JUMP_IF(LABEL(error), FAIL_CONDITION(error));

    // Get Device info and store info into tmp memory.
    info_size_bytes = device_count * sizeof(struct _nn_device_info);
    tmp_device_info = (struct _nn_device_info*)allocate_aligned(&util_top, util_bottom, info_size_bytes, PTR_SIZE);
    error = nn_runtime_devices_info(device_count, tmp_devices, device_count, tmp_device_info);
    JUMP_IF(LABEL(error), FAIL_CONDITION(error));

    // Persist platforms.
    cl_platform_id *platforms = (cl_platform_id*)allocate_aligned(
        STACK_STATE_TOP, STACK_STATE_BOTTOM, platform_size_bytes, PTR_SIZE);
    memcpy(platforms, tmp_platforms, platform_size_bytes);

    // Persist devices.
    cl_device_id *devices = (cl_device_id*)allocate_aligned(
        STACK_STATE_TOP, STACK_STATE_BOTTOM, device_size_bytes, PTR_SIZE);
    memcpy(devices, tmp_devices, device_size_bytes);

    // Persist device info.
    nn_device_info *device_info = (struct _nn_device_info*)allocate_aligned(STACK_STATE_TOP, STACK_STATE_BOTTOM,
        info_size_bytes, PTR_SIZE);
    memcpy(device_info, tmp_device_info, info_size_bytes);

    nn_system_info info = (nn_system_info)allocate_aligned(STACK_STATE_TOP, STACK_STATE_BOTTOM,
        sizeof(struct _nn_system_info), PTR_SIZE);
    
    info->platform_count = platform_count;
    info->device_count = device_count;
    info->platforms = platforms;
    info->devices = devices;
    info->devices_info = device_info;
    context->system_info = info;

    return OK;

LABEL(error):
    LOG(context->host_context->logger(LOG_ERROR, error.message));
    return error;
}

nn_error new_nn_system_context(CONTEXT) {
    void *util_top = context->host_context->util_top;
    void *util_bottom = context->host_context->util_bottom;

    // Persist system context.
    nn_system_context system_context = (nn_system_context)allocate_aligned(STACK_STATE_TOP, STACK_STATE_BOTTOM,
        sizeof(struct _nn_system_context), PTR_SIZE);
    nn_runtime_select_device(context->system_info, system_context);
    context->system_context = system_context;
    return OK;
}

nn_error delete_nn_context(CONTEXT) {
    if(context->host_context != NULL) {
        context->host_context->deallocate(context->host_context->util);
        context->host_context->deallocate(context->host_context->state);
        context->host_context->deallocate(context->host_context);
    }
    return OK;
}
