# Generic CMake
cmake_minimum_required(VERSION 3.1)
project(units)

# CMake Variables
set(CMAKE_C_STANDARD 11)

# Variables
set(SOURCES units.h signalHandling.c signalHandling.h runtime.h tests.c)
include_directories(${CMAKE_SOURCE_DIR})

# Main library
add_library(units STATIC ${SOURCES})
