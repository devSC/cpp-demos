cmake_minimum_required(VERSION 3.8)
project(cpp_demos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp student.cpp student.h)
add_executable(cpp_demos ${SOURCE_FILES})