cmake_minimum_required(VERSION 3.20)

project(day06_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(day06_app
    src/main.cpp
    src/calculator.cpp        
)   