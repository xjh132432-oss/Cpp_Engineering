cmake_minimum_required(VERSION 3.20)

project(StudentManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(student_manager
    src/main.cpp
    src/student.cpp
    src/printer.cpp
)