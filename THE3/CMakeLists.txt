cmake_minimum_required(VERSION 3.20)
project(THE3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(THE3
        test.cpp
        the3.cpp
        the3.h calismio.cpp)
