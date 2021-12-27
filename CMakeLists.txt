cmake_minimum_required(VERSION 3.21)

message("ID: ${CMAKE_CXX_COMPILER}")
project(binary_heap)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_library(binary_heap main.cpp include/binary_heap.h src/binary_heap.cpp)
