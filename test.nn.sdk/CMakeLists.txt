# ------------------------------------------------------------------------------
# Constants.
# ------------------------------------------------------------------------------
set(TARGET test.nn)

# ------------------------------------------------------------------------------
# Setup.
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(${TARGET} VERSION 0.0.1)

set(PUBLIC_HEADER_DIR   "include")
set(SRC_DIR             "src")

set(PUBLIC_HEADERS      ${PUBLIC_HEADER_DIR}/test_nn_callback.h
                        ${PUBLIC_HEADER_DIR}/test_nn_context.h
                        ${PUBLIC_HEADER_DIR}/test_nn_include.h
                        ${PUBLIC_HEADER_DIR}/test_nn_platform.h
                        ${PUBLIC_HEADER_DIR}/test_state.h )

set(SRC_FILES           ${SRC_DIR}/test_nn_callback.c
                        ${SRC_DIR}/main.c
                        ${SRC_DIR}/test_nn_context.c
                        ${SRC_DIR}/test_nn_platform.c )

set(CMAKE_SKIP_RPATH, TRUE)

# ------------------------------------------------------------------------------
# Create target.
# ------------------------------------------------------------------------------
add_executable(${TARGET} ${SRC_FILES})

# ------------------------------------------------------------------------------
# Set target properties.
# ------------------------------------------------------------------------------
include_directories         (include)
set_target_properties       (${TARGET} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties       (${TARGET} PROPERTIES POSITION_INDEPENDENT_CODE ON)

# ------------------------------------------------------------------------------
# Dependencies.
# ------------------------------------------------------------------------------
find_package(nn.sdk.common)
find_package(nn.sdk)
find_package(cmocka)

target_include_directories(${TARGET} PUBLIC ${NN_SDK_COMMON_INCLUDE_DIR}
                                            ${NN_SDK_INCLUDE_DIR})
target_link_directories(${TARGET} PUBLIC ${NN_SDK_LIBRARY})
target_link_libraries(${TARGET} cmocka ${NN_SDK_LIBRARIES} -lOpenCL)

#target_include_directories(${TARGET} PUBLIC ${NN_COMMON_INCLUDE_DIR})
#target_link_directories(${TARGET} PUBLIC ${NN_COMMON_LIBRARY_DIR})

# ------------------------------------------------------------------------------
# Compile options.
# ------------------------------------------------------------------------------
target_compile_options(${TARGET} PRIVATE -Wall -pedantic)

#-------------------------------------------------------------------------------
# Install.
# ------------------------------------------------------------------------------
install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_PREFIX})

