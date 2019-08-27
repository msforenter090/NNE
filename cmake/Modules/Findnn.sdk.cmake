# Example:
# OpenCL_FOUND          - True if OpenCL was found
# OpenCL_INCLUDE_DIRS   - include directories for OpenCL
# OpenCL_LIBRARIES      - link against this library to use OpenCL
# OpenCL_VERSION_STRING - Highest supported OpenCL version (eg. 1.2)
# OpenCL_VERSION_MAJOR  - The major version of the OpenCL implementation
# OpenCL_VERSION_MINOR  - The minor version of the OpenCL implementation
# OpenCL_LIBRARY        - the path to the OpenCL library

# This module defines
# NN_SDK_FOUND          - True if NN was found
# NN_SDK_INCLUDE_DIR    - include directories for NN
# NN_SDK_LIBRARIES      - link against this library to use OpenCL
# NN_SDK_LIBRARY        - the path to the NN library

SET(SEARCH_PATHS
    /usr/local
    /usr
    ${CMAKE_INSTALL_PREFIX}
)

FIND_PATH(NN_SDK_INCLUDE_DIR nn_context.h
    PATHS ${SEARCH_PATHS}
)

FIND_LIBRARY(NN_SDK_LIBRARY
    NAMES nn.sdk libnn.sdk
    PATHS ${SEARCH_PATHS}
)

set(NN_SDK_FOUND, TRUE)
set(NN_SDK_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(NN_SDK_LIBRARY ${CMAKE_INSTALL_PREFIX})
set(NN_SDK_LIBRARIES nn.sdk)
