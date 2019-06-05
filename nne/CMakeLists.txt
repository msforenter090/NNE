set(MIN_CMAKE_VERSION 3.10)
set(TARGET nne)

cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})
project(${TARGET} LANGUAGES CXX)

# ------------------------------------------------------------------------------
# Setup.
# ------------------------------------------------------------------------------
set(SRC_DIR             "src")
set(UI_DIR              "ui")

set(HEADER_FILES        ${HEADER_DIR}/mainwindow.h)
set(SRC_FILES           ${SRC_DIR}/mainwindow.cpp ${SRC_DIR}/main.cpp)
set(UI_FILES            ${UI_DIR}/mainwindow.ui)

set(FILES ${SRC_FILES})

# ------------------------------------------------------------------------------
# Set flags & options.
# ------------------------------------------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# ------------------------------------------------------------------------------
# 3.9 min required.
# https://stackoverflow.com/questions/40630820/how-to-place-header-and-ui-file-in-different-folders-using-autouic-in-cmake
# ------------------------------------------------------------------------------
set(CMAKE_AUTOUIC_SEARCH_PATHS ${UI_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${SRC_DIR})
# ------------------------------------------------------------------------------
# Dependencies.
# ------------------------------------------------------------------------------
find_package(Qt5Widgets CONFIG REQUIRED)

# ------------------------------------------------------------------------------
# Create target.
# ------------------------------------------------------------------------------
# Tell CMake to create the helloworld executable
add_executable(${TARGET} WIN32 ${SRC_FILES} ${UI_FILES})
target_link_libraries(${TARGET} Qt5::Widgets)
