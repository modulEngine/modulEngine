project(Core LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)

add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()
