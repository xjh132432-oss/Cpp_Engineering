cmake_minimum_required(VERSION 3.20)

project(day09_StastiLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(calculator_lib STATIC
            src/calculator.cpp
)   

target_include_directories(calculator_lib
                PUBLIC
                ${PROJECT_SOURCE_DIR}/include
    )

add_executable(day09_app
        src/main.cpp

)

target_link_libraries(day09_app
            PRIVATE
            calculator_lib
)