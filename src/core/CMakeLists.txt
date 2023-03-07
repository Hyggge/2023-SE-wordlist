cmake_minimum_required (VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)

project(core)

include_directories(${INCLUDE_DIR})
#add_library(core SHARED  Core.cpp) #TODO
#ADD_EXECUTABLE(Wordlist Core.cpp)
add_library(core SHARED Core.cpp)

#include(FindOpenMP)
#if(OPENMP_FOUND)
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
#    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
#else(OPENMP_FOUND)
#    message("ERROR: OpenMP could not be found.")
#endif(OPENMP_FOUND)
#
#add_definitions(-DF_PIC)
#
#add_library(core SHARED ${INCLUDE_DIR}/core.h core.cpp ${INCLUDE_DIR}/Solution.h Solution.cpp ${INCLUDE_DIR}/Graph.h Graph.cpp ${INCLUDE_DIR}/Node.h Node.cpp)