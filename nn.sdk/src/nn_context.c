#include "nn_context.h"

#include "nn_runtime.h"
#include <string.h>

nn_error new_nn_context(nn_host_context *host_context, nn_allocate allocate, nn_deallocate deallocate,
                        nn_info_callback info, nn_warning_callback warning, nn_error_callback error) {
    *host_context = NULL;
    // Alignment must be size of the largest field in the structure.
    nn_host_context new_context = (nn_host_context)allocate(sizeof(struct _nn_host_context), sizeof(nn_allocate));
    new_context->allocate = allocate;
    new_context->deallocate = deallocate;
    new_context->info_logger = info;
    new_context->warning_logger = warning;
    new_context->error_logger = error;
    *host_context = new_context;
    return OK;
}

nn_error new_nn_system_info(nn_host_context host_context, nn_system_info *system_info) {
    *system_info = (nn_system_info)host_context->allocate(sizeof(struct _nn_system_info), PTR_SIZE);
    memset(*system_info, 0, sizeof(struct _nn_system_info));
    nn_error error;
    error = nn_runtime_platforms(host_context, *system_info, NULL);
    error = nn_runtime_devices(host_context, *system_info, NULL);
    error = nn_runtime_devices_info(host_context, *system_info, NULL);
    return OK;
}

nn_error new_nn_system_context(nn_host_context host_context, nn_system_info system_info,
                               nn_system_context *system_context) {
    *system_context = (nn_system_context)host_context->allocate(sizeof(struct _nn_system_context), PTR_SIZE);
    memset(*system_context, 0, sizeof(struct _nn_system_context));
    nn_runtime_select_device(host_context, system_info, *system_context);
    return OK;
}

nn_error delete_nn_system_context(CONTEXT) { return OK; }

nn_error delete_nn_system_info(CONTEXT) {
    host_context->deallocate(system_info);
    return OK;
}

nn_error delete_nn_context(CONTEXT) {
    host_context->deallocate(host_context);
    return OK;
}
