cmake_minimum_required(VERSION 3.26)
project(Staff)

set(CMAKE_CXX_STANDARD 17)

add_executable(Staff src/main.cpp
        src/Employee.cpp
        include/Employee.h
        include/Exception.h)
