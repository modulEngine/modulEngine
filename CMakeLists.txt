cmake_minimum_required(VERSION 3.18)
project(modulEngine)

if (BUILD_VERBOSE)
    set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)
endif ()

# path to local CMake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake/Modules)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake)

# set build type to Debug if not specified otherwise
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()

# disable building in the source tree
set(CMAKE_DISABLE_SOURCE_CHANGE ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# error message explaining this
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(STATUS "\n-- ###############################################\n")
    message(STATUS "Please run the build outside of the source tree.\n\n")
    message(STATUS "Hint: create a 'build' folder and run CMake from there..")
    message(STATUS "###############################################\n\n")
    message(FATAL_ERROR "Build launched in the source tree.")
endif ()


if (BUILD_TESTING)
    enable_testing()
    include(FetchGoogleTest)
    include(GoogleTest)
endif ()

add_subdirectory(Core)
add_subdirectory(Graphics)
add_subdirectory(Samples)
