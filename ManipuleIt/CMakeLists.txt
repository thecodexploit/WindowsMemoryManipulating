cmake_minimum_required(VERSION 3.6)
project(ManipuleIt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES manipule.cpp)
add_executable(ManipuleIt ${SOURCE_FILES})