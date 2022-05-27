file(GLOB_RECURSE CORE_SOURCES ./*.c)

add_library(${PROJECT_NAME} ${CORE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/modulEngine/Core)

message(STATUS "Project ${PROJECT_NAME} has been added from: ${PROJECT_SOURCE_DIR}.")
