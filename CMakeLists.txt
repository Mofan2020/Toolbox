cmake_minimum_required(VERSION 3.26)
project(test_progp)

set(CMAKE_CXX_STANDARD 23)

add_executable(test_progp main.cpp
        basic_plugin.h
        basics.h
        my_plugin00.h
)
