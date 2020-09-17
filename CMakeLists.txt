cmake_minimum_required (VERSION 2.8)
project (matrix_demo)

set(CMAKE_BUILD_TYPE Release)

include_directories("./")

add_library(matrix ./matrix.cpp)

add_executable(demo ./demo.cpp)
target_link_libraries (demo matrix)
