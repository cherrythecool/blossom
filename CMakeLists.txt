cmake_minimum_required(VERSION 3.16)
project(blossom)

add_subdirectory(vendor/raylib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/main.cpp

    src/engine/engine.cpp

    src/engine/assets/assets.cpp

    src/engine/game/game.cpp
    src/engine/game/object.cpp
    src/engine/game/sprite.cpp

    src/engine/graphics/vectors.cpp
)

if(WIN32)
    set(SOURCES ${SOURCES}
        src/engine/windows.cpp
    )
endif()

add_executable(blossom ${SOURCES})

target_link_libraries(blossom PUBLIC raylib)
target_include_directories(blossom PUBLIC src)
target_include_directories(blossom PRIVATE vendor/imgui)
target_include_directories(blossom PRIVATE vendor/imgui/backends)

if(WIN32)
    target_link_libraries(blossom PRIVATE dwmapi)
endif()

# Copy assets
add_custom_command(TARGET blossom POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/assets"
        $<TARGET_FILE_DIR:blossom>/assets
)