# ------------------------------------------------------------------------------
# Constants.
# ------------------------------------------------------------------------------
set(TARGET nn)
#set(MIN_CMAKE_VERSION 3.10)

# ------------------------------------------------------------------------------
# Setup.
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(${TARGET} VERSION 0.0.1)

set(PUBLIC_HEADER_DIR   "include")
set(SRC_DIR             "src")

set(PUBLIC_HEADERS      ${PUBLIC_HEADER_DIR}/nn_context.h
                        ${PUBLIC_HEADER_DIR}/nn_defs.h
                        ${PUBLIC_HEADER_DIR}/nn_error.h
                        ${PUBLIC_HEADER_DIR}/nn_list.h
                        ${PUBLIC_HEADER_DIR}/nn_matrix.h
                        ${PUBLIC_HEADER_DIR}/nn_platform.h
                        ${PUBLIC_HEADER_DIR}/nn_types.h
                        )

set(SRC_FILES           ${SRC_DIR}/nn_alloc.h
                        ${SRC_DIR}/nn_alloc.c
                        ${SRC_DIR}/nn_context.c
                        ${SRC_DIR}/nn_error.c
                        ${SRC_DIR}/nn_list.c
                        ${SRC_DIR}/nn_matrix.c
                        ${SRC_DIR}/nn_platform.c
                        ${SRC_DIR}/nn_runtime.c
                        ${SRC_DIR}/nn_runtime.h
                        ${SRC_DIR}/nn_types_internal.h
                        )

set(CMAKE_SKIP_RPATH, TRUE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_C_VISIBILITY_PRESET hidden)
clangformat_setup(${PUBLIC_HEADERS} ${SRC_FILES})

# ------------------------------------------------------------------------------
# Create the library and target.
# ------------------------------------------------------------------------------
add_library(${TARGET} SHARED ${SRC_FILES})

# ------------------------------------------------------------------------------
# Set target properties.
# ------------------------------------------------------------------------------
target_include_directories  (${TARGET} PRIVATE include)
target_include_directories  (${TARGET} PRIVATE src)
set_target_properties       (${TARGET} PROPERTIES VERSION ${PROJECT_VERSION})
#set_target_properties       (${TARGET} PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS})
set_target_properties       (${TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE Debug)

# ------------------------------------------------------------------------------
# Install.
# ------------------------------------------------------------------------------
install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/nn)

