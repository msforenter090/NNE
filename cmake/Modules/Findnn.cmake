# This module defines
# NN_LIBRARY, the name of the library to link against
# NN_FOUND, if false, do not try to link to SDL2
# NN_INCLUDE_DIR, where to find SDL.h

SET(NN_SEARCH_PATHS
    /usr/local
    /usr
    ${NN_PATH}
    ${CMAKE_INSTALL_PREFIX}
)

FIND_PATH(NN_INCLUDE nn_context.h
    PATHS ${NN_SEARCH_PATHS}
)

FIND_LIBRARY(NN_LIBRARY
    NAMES nn libnn
    PATHS ${NN_SEARCH_PATHS}
)


set(NN_FOUND, TRUE)
set(NN_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/nn)
set(NN_LIBRARY ${CMAKE_INSTALL_PREFIX})

#IF(NOT NN_INCLUDE OR NOT NN_LIBRARY)
#    set(NN_FOUND, FALSE)
#    message("!Found.")
#ELSE()
#    set(NN_FOUND, TRUE)
#    message("Found.")
#ENDIF()

