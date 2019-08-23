#include "nn_platform.h"

#include "nn_runtime.h"

nn_error nn_platform_count(CONTEXT, short *const count) {
    return nn_runtime_platform_count(context, count);
}

nn_error nn_platforms(CONTEXT, nn_platform *platforms[]) { return OK; }

nn_error nn_platform_info(CONTEXT, nn_platform platform, byte *values[]) {
    return OK;
}

nn_error nn_platform_device_count(CONTEXT, nn_platform platform,
                                  short *const count) {
    return OK;
}

nn_error nn_platform_devices(CONTEXT, nn_platform platform,
                             nn_device *devices[]) {
    return OK;
}

nn_error nn_platform_setup(CONTEXT) {
    nn_tuple_platform_devices *map = NULL;
    nn_runtime_platform_devices_map(context, &map);
    return OK;
}
