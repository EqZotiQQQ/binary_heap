cmake_minimum_required(VERSION 3.21)

project(binary_heap)

set(CMAKE_CXX_STANDARD 20)

include_directories(tests)

add_subdirectory(lib)
add_subdirectory(tests)

add_subdirectory(third_party/googletest)

add_compile_options(-Wall -Wextra -pedantic -Werror)
