cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)
project(wordlist)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include/)
add_subdirectory ("src")