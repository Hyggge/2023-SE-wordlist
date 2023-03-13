cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)
project(UnitTest)

include_directories(../gtest/googletest/include)
include_directories(../gtest/googlemock/include)
include_directories(include)

add_executable(UnitTest main.cpp)

target_link_libraries(UnitTest gtest gtest_main)
target_link_libraries(UnitTest gmock gmock_main)
target_link_libraries(UnitTest core)