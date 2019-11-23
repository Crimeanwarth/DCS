cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp libraries/logicgates/logicgates.cpp libraries/logicgates/logicgates.h libraries/logicgates/logicgates_test.cpp libraries/logicgates/logicgates_test.h libraries/graphs/graphs.cpp libraries/graphs/graphs.h libraries/graphs/gateInfo.cpp libraries/graphs/gateInfo.h libraries/graphs/graphs_test.cpp libraries/graphs/graphs_test.h libraries/parser/parser.cpp libraries/parser/parser.h libraries/parser/parser_test.cpp libraries/parser/parser_test.h libraries/parser/log.cpp libraries/parser/log.h libraries/parser/log_test.cpp libraries/parser/log_test.h)