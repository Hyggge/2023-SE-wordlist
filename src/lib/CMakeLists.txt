cmake_minimum_required (VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)

include_directories(${INCLUDE_DIR})
target_link_libraries(core)
add_library(lib ArgParser.cpp FileParser.cpp Controller.cpp)

#target_link_libraries(Wordlist core)