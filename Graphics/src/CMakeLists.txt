file(GLOB GRAPHICS_SOURCES ./*.c)

add_library(${PROJECT_NAME} ${GRAPHICS_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include/ModulEngine/Graphics)

target_link_libraries(${PROJECT_NAME} Core)

message(STATUS "Project ${PROJECT_NAME} has been added from: ${PROJECT_SOURCE_DIR}.")
