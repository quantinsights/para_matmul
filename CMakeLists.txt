cmake_minimum_required(VERSION 3.30.3)
project(para_matmul)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
)

add_executable(para_matmul ${SOURCES})	