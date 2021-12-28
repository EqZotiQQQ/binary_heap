project(binary_heap_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(../lib/include)

target_link_libraries(${PROJECT_NAME} binary_heap_impl)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)