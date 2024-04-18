cmake_minimum_required(VERSION 3.16)
project(Snake LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
set(CMAKE_OSX_ARCHITECTURES x86_64)

find_package(SFML 2.6.1 COMPONENTS graphics window REQUIRED)
add_executable(${PROJECT_NAME} src/Main.cpp
        src/Window.h
        src/Window.cpp
        include/core.h
        src/Game.h
        src/Game.cpp
        src/Snake.h
        src/Snake.cpp
        src/World.h
        src/World.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window)