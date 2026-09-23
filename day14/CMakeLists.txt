cmake_minimum_required(VERSION 3.15)

project(day14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(calculator
    src/main.cpp
    src/calculator.cpp
)

target_include_directories(calculator
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)