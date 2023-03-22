cmake_minimum_required(VERSION 3.22)
project(AS)

set(CMAKE_CXX_STANDARD 17)

add_executable(AS main.cpp node.cpp node.h map.cpp map.h lane.cpp lane.h)

