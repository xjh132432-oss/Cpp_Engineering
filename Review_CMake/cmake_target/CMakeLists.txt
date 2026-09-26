cmake_minimum_required(VERSION 3.20)

project(day07_target)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(day07_app
            src/calculator.cpp
            src/main.cpp
)

target_include_directories(day07_app
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include

)