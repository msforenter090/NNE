# Example:
# OpenCL_FOUND          - True if OpenCL was found
# OpenCL_INCLUDE_DIRS   - include directories for OpenCL
# OpenCL_LIBRARIES      - link against this library to use OpenCL
# OpenCL_VERSION_STRING - Highest supported OpenCL version (eg. 1.2)
# OpenCL_VERSION_MAJOR  - The major version of the OpenCL implementation
# OpenCL_VERSION_MINOR  - The minor version of the OpenCL implementation
# OpenCL_LIBRARY        - the path to the OpenCL library

# This module defines:
# NN_SDK_COMMON_FOUND,          - if false, do not try to link.
# NN_SDK_COMMON_INCLUDE_DIR,    - include directories for nn.common
# NN_SDK_COMMON_LIBRARIES,      - path to the library
# NN_SDK_COMMON_LIBRARY         - the path to the OpenCL library

SET(SEARCH_PATHS
    /usr/local
    /usr
    ${CMAKE_INSTALL_PREFIX}
)

FIND_PATH(NN_COMMON_INCLUDE_DIR nn_error.h
    PATHS ${SEARCH_PATHS}
)

FIND_LIBRARY(NN_COMMON_LIBRARY
    NAMES nn.common libnn.common
    PATHS ${SEARCH_PATHS}
)

set(NN_SDK_COMMON_FOUND, TRUE)
set(NN_SDK_COMMON_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(NN_SDK_COMMON_LIBRARIES ${CMAKE_INSTALL_PREFIX})
set(NN_SDK_COMMON_LIBRARY nn.sdk.common)
