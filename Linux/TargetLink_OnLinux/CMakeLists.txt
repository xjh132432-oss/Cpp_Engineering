cmake_minimum_required(VERSION 3.20)

project(student_manager)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(student_lib STATIC src/student.cpp)

add_executable(student_manager
	src/main.cpp
)

target_include_directories(student_lib
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


target_include_directories(student_manager
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(student_lib PRIVATE cxx_std_17)

target_compile_features(student_manager PRIVATE cxx_std_17)

target_link_libraries(student_manager PRIVATE student_lib)
