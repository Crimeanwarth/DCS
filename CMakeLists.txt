cmake_minimum_required(VERSION 3.15)
project(DCS)

set(CMAKE_CXX_STANDARD 14)

add_executable(DCS main.cpp libraries/logicgates/logicgates.cpp libraries/logicgates/logicgates.h libraries/graphs/graphs.cpp libraries/graphs/graphs.h libraries/graphs/gateInfo.cpp libraries/graphs/gateInfo.h libraries/parser/parser.cpp libraries/parser/parser.h)