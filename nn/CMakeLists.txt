# ------------------------------------------------------------------------------
# Constants.
# ------------------------------------------------------------------------------
set(TARGET nn)

# ------------------------------------------------------------------------------
# Setup.
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(${TARGET} VERSION 0.0.1)


set(PUBLIC_HEADER_DIR   "include")
set(SRC_DIR             "src")

set(PUBLIC_HEADERS      ${PUBLIC_HEADER_DIR}/nn_allocation.h
                        ${PUBLIC_HEADER_DIR}/nn_error.h
                        ${PUBLIC_HEADER_DIR}/nn_matrix.h
                        )

set(SRC_FILES           ${SRC_DIR}/nn_error.c
                        ${SRC_DIR}/nn_matrix.c
                        )

# ------------------------------------------------------------------------------
# Create the library and target.
# ------------------------------------------------------------------------------
add_library(${TARGET} SHARED ${SRC_FILES})

# ------------------------------------------------------------------------------
# Set target properties.
# ------------------------------------------------------------------------------
target_include_directories  (${TARGET} PRIVATE include)
set_target_properties       (${TARGET} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties       (${TARGET} PROPERTIES PUBLIC_HEADER ${PUBLIC_HEADERS})
set_target_properties       (${TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)

