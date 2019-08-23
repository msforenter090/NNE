# ------------------------------------------------------------------------------
# Constants.
# ------------------------------------------------------------------------------
set(TARGET test_nn)

# ------------------------------------------------------------------------------
# Setup.
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(${TARGET} VERSION 0.0.1)

set(PUBLIC_HEADER_DIR   "include")
set(SRC_DIR             "src")

set(PUBLIC_HEADERS      ${PUBLIC_HEADER_DIR}/test_nn_context.h
                        ${PUBLIC_HEADER_DIR}/test_nn_include.h
                        ${PUBLIC_HEADER_DIR}/test_nn_platform.h
                        ${PUBLIC_HEADER_DIR}/test_state.h )

set(SRC_FILES           ${SRC_DIR}/main.c
                        ${SRC_DIR}/test_nn_context.c
                        ${SRC_DIR}/test_nn_platform.c )

set(CMAKE_SKIP_RPATH, TRUE)

find_package(nn)

# ------------------------------------------------------------------------------
# Create target.
# ------------------------------------------------------------------------------
add_executable(${TARGET} ${SRC_FILES})
target_include_directories(${TARGET} PUBLIC ${NN_INCLUDE_DIR})
target_link_directories(${TARGET} PUBLIC ${NN_LIBRARY})
target_link_libraries(${TARGET} -lnn -lcmocka -lOpenCL)

# ------------------------------------------------------------------------------
# Set target properties.
# ------------------------------------------------------------------------------
target_include_directories  (${TARGET} PRIVATE include)
set_target_properties       (${TARGET} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties       (${TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)

# ------------------------------------------------------------------------------
# Dependencies.
# ------------------------------------------------------------------------------
find_package(nn.common)
target_include_directories(${TARGET} PUBLIC ${NN_COMMON_INCLUDE_DIR})
target_link_directories(${TARGET} PUBLIC ${NN_COMMON_LIBRARY_DIR})

# ------------------------------------------------------------------------------
# Compile options.
# ------------------------------------------------------------------------------
set(CMAKE_BUILD_TYPE Debug)
target_compile_options(${TARGET} PRIVATE -Wall -Wextra -pedantic)

#-------------------------------------------------------------------------------
# Install.
# ------------------------------------------------------------------------------
install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_PREFIX})

