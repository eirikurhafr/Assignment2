cmake_minimum_required(VERSION 3.7)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Base.cpp Base.h FoxAndHound.cpp FoxAndHound.h)
add_executable(Assignment_2 ${SOURCE_FILES})