cmake_minimum_required(VERSION 3.24)
project(DataStructures VERSION 1.0.0 LANGUAGES C)
set( CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(test)
