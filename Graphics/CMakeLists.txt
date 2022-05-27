project(Graphics LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)

find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(glfw3 REQUIRED FATAL_ERROR)

add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
