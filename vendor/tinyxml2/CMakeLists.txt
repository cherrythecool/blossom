cmake_minimum_required(VERSION 3.14)
project(tinyxml2 VERSION 11.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(tinyxml2 STATIC
    tinyxml2.cpp
)

target_include_directories(tinyxml2 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

install(DIRECTORY include/
    DESTINATION include
)
