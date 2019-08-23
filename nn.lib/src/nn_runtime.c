#include "nn_runtime.h"

#include <CL/cl.h>
#include <string.h>

nn_error nn_runtime_platform_count(CONTEXT, short *const count) {
    *count = 0;
    cl_uint platform_count = 0;
    clGetPlatformIDs(0, NULL, &platform_count);
    *count = platform_count;
    return OK;
}

nn_error nn_runtime_platforms(CONTEXT, cl_platform_id **platforms) {
    short platform_count = 0;
    short device_count = 0;
    nn_runtime_platform_count(context, &platform_count);

    // +1 for NULL value at the end of the array.
    unsigned int bytes = (platform_count + 1) * sizeof(cl_platform_id);
    *platforms = (cl_platform_id *)context->allocate(bytes, PTR_SIZE);
    memset(*platforms, 0, bytes);
    clGetPlatformIDs(platform_count, *platforms, NULL);
    return OK;
}

nn_error nn_runtime_platform_info(CONTEXT, cl_platform_id platform,
                                  byte *values[]) {
    const short platform_attribute_count = 5;
    const cl_platform_info attribute[5] = {
        CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_VERSION,
        CL_PLATFORM_PROFILE, CL_PLATFORM_EXTENSIONS};

    for (int i = 0; i < platform_attribute_count; i++) {
        size_t attribute_size = 0;
        clGetPlatformInfo(platform, attribute[i], 0, NULL, &attribute_size);

        attribute_size++;
        byte *buffer =
            (byte *)context->allocate(attribute_size * sizeof(byte), 1);
        clGetPlatformInfo(platform, attribute[i], attribute_size - 1, buffer,
                          NULL);
        buffer[attribute_size - 1] = '\0';
        values[i] = buffer;
    }
    return OK;
}

nn_error nn_runtime_platform_device_count(CONTEXT, cl_platform_id platform,
                                          short *const count) {
    cl_uint devices_count = 0;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &devices_count);
    *count = devices_count;
    return OK;
}

nn_error nn_runtime_platform_devices(CONTEXT, cl_platform_id platform,
                                     cl_device_id **devices) {
    short device_count = 0;
    nn_runtime_platform_device_count(context, platform, &device_count);

    // +1 for NULL value at the end of the array.
    unsigned int bytes = (device_count + 1) * sizeof(cl_device_id);
    *devices = (cl_device_id *)context->allocate(bytes, PTR_SIZE);
    memset(*devices, 0, bytes);

    clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, device_count, *devices, NULL);
    return OK;
}

nn_error nn_runtime_platform_devices_map(CONTEXT,
                                         nn_tuple_platform_devices **map) {
    short platform_count = 0;
    short device_count = 0;

    cl_platform_id *platforms = NULL;
    cl_device_id *devices = NULL;

    nn_runtime_platform_count(context, &platform_count);
    nn_runtime_platforms(context, &platforms);

    // +1 for NULL value
    unsigned int bytes =
        (platform_count + 1) * sizeof(nn_tuple_platform_devices);
    *map = (nn_tuple_platform_devices *)context->allocate(bytes, PTR_SIZE);
    memset(*map, 0, bytes);

    for (short i = 0; i < platform_count; i++) {
        // Fetch all devices.
        short device_count = 0;
        nn_runtime_platform_device_count(context, platforms[i], &device_count);
        nn_runtime_platform_devices(context, platforms[i], &devices);

        (*map[i]).platform = platforms[i];
        (*map[i]).devices = devices;

        devices = NULL;
    }

    context->deallocate(platforms);
    return OK;
}

nn_error nn_runtime_platform_filter_devices_by_properties(
    CONTEXT, nn_tuple_platform_devices *map, nn_tuple_platform_devices *pair) {
    // TODO: Dummy implementation.
    // It will work for now.
    short index = 0;
    cl_platform_id platform = map[index].platform;
    cl_device_id *devices = map[index].devices;
    pair->platform = platform;
    pair->devices = devices;
    return OK;
}

nn_error nn_runtime_device_properties(CONTEXT, cl_device_id device,
                                      cl_device_info *params,
                                      const short param_length, void *out[]) {
    short i = 0;
    for (i = 0; i < param_length; i++) {
        clGetDeviceInfo(device, params[i], 0, out[i], NULL);
    }
    return OK;
}

nn_error nn_runtime_default_context(CONTEXT, nn_tuple_platform_devices *map[],
                                    cl_device_info *info, const short length) {

    return OK;
}
