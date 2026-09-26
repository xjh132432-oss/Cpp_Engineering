cmake_minimum_required(VERSION 3.20)

project(Comprehensive)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(student_lib STATIC
        src/student.cpp
)

target_include_directories(student_lib PUBLIC
            ${PROJECT_SOURCE_DIR}/include

)

add_executable(student_manager
        src/printer.cpp
        src/main.cpp

)

target_link_libraries(student_manager
        PRIVATE
        student_lib        

)