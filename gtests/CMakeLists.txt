cmake_minimum_required(VERSION 3.17)
project(test C)

set(CMAKE_CXX_STANDARD 14)

message(STATUS "start building test...")

include_directories("../include")

include_directories(../)
add_executable(test sxml_test.c)
#[[
link_directories(../out/)



add_executable(test main.cpp)

target_link_libraries(test ImageProcess)]]
