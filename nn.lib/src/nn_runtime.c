#include "nn_runtime.h"

#include "nn_constants.h"
#include <CL/cl.h>
#include <string.h>

nn_error nn_runtime_platforms(CONTEXT) {
    clGetPlatformIDs(MAX_PLATFORMS, system_info->platforms, NULL);
    return OK;
}

// nn_error nn_runtime_devices(CONTEXT, nn_system_info system_info) {
//     cl_platform_id platform = system_info->platforms[0];
//     cl_uint total_devices = 0;
//     for (unsigned short i = 0; system_info->platforms[i] != NULL; i++) {
//         cl_uint devices_per_platform = 0;
//         clGetDeviceIDs(system_info->platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL,
//                        &devices_per_platform);
//         clGetDeviceIDs(system_info->platforms[i], CL_DEVICE_TYPE_ALL, devices_per_platform,
//                        system_info->devices + devices_per_platform, NULL);
//         for (unsigned short j = 0; j < devices_per_platform; j++) {
//             system_info->device_platform_mapping[total_devices + j] = i;
//         }
//         total_devices += devices_per_platform;
//     }
//     return OK;
// }
//
// nn_error nn_runtime_devices_info(CONTEXT, nn_system_info system_info) {}