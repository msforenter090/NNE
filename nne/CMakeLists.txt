cmake_minimum_required(VERSION ${MIN_CMAKE_VERSION})

project(TestQtQuick LANGUAGES CXX)

# ------------------------------------------------------------------------------
# Setup.
# ------------------------------------------------------------------------------
set(PUBLIC_HEADER_DIR   "include")
set(SRC_DIR             "src")

set(PUBLIC_HEADERS      )

set(SRC_FILES           ${SRC_DIR}/main.cpp)

# ------------------------------------------------------------------------------
# Turn on Auto Moc & RCC / Flags.
# ------------------------------------------------------------------------------
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------------------
# Dependencies.
# ------------------------------------------------------------------------------
find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# ------------------------------------------------------------------------------
# Create target.
# ------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)

