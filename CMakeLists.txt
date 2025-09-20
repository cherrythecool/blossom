cmake_minimum_required(VERSION 3.16)
project(blossom)

add_subdirectory(vendor/raylib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/main.cpp
    
    src/engine/engine.cpp

    src/engine/game/game.cpp
    src/engine/game/object.cpp
)

if(WIN32)
    set(SOURCES ${SOURCES}
        src/engine/windows.cpp
    )
endif()

add_executable(blossom ${SOURCES})

target_link_libraries(blossom PUBLIC raylib)
target_include_directories(blossom PUBLIC src)

if(WIN32)
    target_link_libraries(blossom PRIVATE dwmapi)
endif()
