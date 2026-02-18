cmake_minimum_required(VERSION 3.20)
project(SDL3Chess)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL3 REQUIRED)

add_executable(chess
    src/main.cpp
    src/core/app.cpp
    src/board/board.cpp
    src/rendering/boardRenderer.cpp
)

target_link_libraries(chess PRIVATE SDL3::SDL3)

