# This module defines
# NN_COMMON_FOUND, if false, do not try to link.
# NN_COMMON_LIBRARY_DIR, path to the library.
# NN_COMMON_INCLUDE_DIR, where to find library.

SET(SEARCH_PATHS
    /usr/local
    /usr
    ${CMAKE_INSTALL_PREFIX}
)

FIND_PATH(NN_COMMON_INCLUDE nn_error.h
    PATHS ${SEARCH_PATHS}
)

FIND_LIBRARY(NN_COMMON_LIBRARY
    NAMES nn.common libnn.common
    PATHS ${SEARCH_PATHS}
)

set(NN_COMMON_FOUND, TRUE)
set(NN_COMMON_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include)
set(NN_COMMON_LIBRARY_DIR ${CMAKE_INSTALL_PREFIX})

#IF(NOT NN_INCLUDE OR NOT NN_LIBRARY)
#    set(NN_FOUND, FALSE)
#    message("!Found.")
#ELSE()
#    set(NN_FOUND, TRUE)
#    message("Found.")
#ENDIF()

