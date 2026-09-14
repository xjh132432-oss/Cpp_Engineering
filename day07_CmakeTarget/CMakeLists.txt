cmake_minimum_required(VERSION 3.20)

project(StudentManager)

include_directories(include)

add_executable(student_manager
    src/main.cpp
    src/student.cpp
    src/printer.cpp
)

target_compile_features(student_manager PRIVATE cxx_std_20)
