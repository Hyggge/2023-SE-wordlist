cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)
project(Wordlist)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

add_subdirectory("src")
add_subdirectory("core")
add_subdirectory("gui")
add_subdirectory("test")
add_subdirectory("gtest")