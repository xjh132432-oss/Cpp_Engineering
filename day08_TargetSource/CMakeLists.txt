cmake_minimum_required(VERSION 3.20)

project(StudentManager)

set(SOURCES
    src/main.cpp
    src/student.cpp
    src/printer.cpp
    src/info.cpp
)

include_directories(include)

add_executable(student_manager)

target_sources(student_manager PRIVATE
    ${SOURCES})   

target_compile_features(student_manager PRIVATE cxx_std_20)

target_include_directories(student_manager PRIVATE
                            
                            $(PROJECT_SOURCE_DIR)/include())