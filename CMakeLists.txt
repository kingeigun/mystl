cmake_minimum_required(VERSION 3.30)
project(mystl)

set(CMAKE_CXX_STANDARD 14)

add_executable(mystl main.cpp
        src/list.h
        test/test_list.h
)
