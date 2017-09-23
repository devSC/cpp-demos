cmake_minimum_required(VERSION 3.8)
project(cpp_demos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp student.cpp student.h book.cpp book.h Age.cpp Age.h codingbook.cpp codingbook.h teacher.cpp teacher.h virtualclass.cpp virtualclass.h derived.cpp derived.h purevirtualclass.cpp purevirtualclass.h complex.cpp complex.h pair.cpp pair.h mypair.cpp mypair.h MyArray.cpp MyArray.h Store.cpp Store.h array.cpp array.h)
add_executable(cpp_demos ${SOURCE_FILES})