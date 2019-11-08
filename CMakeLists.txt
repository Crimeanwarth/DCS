cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp libraries/logicgates/logicgates.cpp libraries/logicgates/logicgates.h libraries/logicgates/logicgates_test.cpp libraries/logicgates/logicgates_test.h)