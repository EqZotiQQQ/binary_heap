cmake_minimum_required(VERSION 3.16)

project(binary_heap_impl)

set(CMAKE_CXX_STANDARD 20)

set(HEADERS include/binary_heap.h)

set(SOURCES src/binary_heap.cpp)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
