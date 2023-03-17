cmake_minimum_required (VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(Wordlist main.cpp ArgParser.cpp Controller.cpp FileParser.cpp)
target_link_directories(Wordlist PUBLIC ../bin)
target_link_libraries(Wordlist coreDll)

##compile with core.cpp and graph.cpp
#include_directories(include ../core/include)
#add_executable(Wordlist main.cpp ArgParser.cpp Controller.cpp FileParser.cpp ../core/Core.cpp ../core/Graph.cpp)
#SET_TARGET_PROPERTIES(Wordlist PROPERTIES LINK_FLAGS "/PROFILE")

