# Generic CMake
cmake_minimum_required(VERSION 3.1)
project(units)

# CMake Variables
set(CMAKE_C_STANDARD 11)

# Main Library
include_directories(src)
add_subdirectory(src)

# Example Executables
add_subdirectory(examples)