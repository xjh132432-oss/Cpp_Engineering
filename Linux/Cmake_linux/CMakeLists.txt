cmake_minimum_required(VERSION 3.20)

project(student_manager)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student
	src/main.cpp
	src/student.cpp
)

target_include_directories(student
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
