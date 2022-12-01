cmake_minimum_required(VERSION 3.9.1)

project(School)

include_directories(${.})
add_executable(generator_main generator_main.cpp generator_util.cpp)

