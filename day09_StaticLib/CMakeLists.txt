cmake_minimum_required(VERSION 3.20)

project(StudentManager)

add_library(student_lib STATIC
    src/student.cpp
)

add_executable(student_manager)

target_sources(student_manager PRIVATE
    src/main.cpp
    src/printer.cpp
    src/info.cpp
)

target_include_directories(student_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(student_manager PRIVATE
    ${PROJECT_SOURCE_DIR}/include

target_compile_features(student_lib PRIVATE cxx_std_17)
target_compile_features(student_manager PRIVATE cxx_std_17)


)