cmake_minimum_required(VERSION 3.27)
project(UnixShell)

set(CMAKE_CXX_STANDARD 17)

add_executable(UnixShell main.cpp
        shelpers.h
        shelpers.cpp
        shelpers.cpp)
