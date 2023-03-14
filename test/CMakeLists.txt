cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)
project(UnitTest)

include_directories(gtest/googletest/include)
include_directories(gtest/googlemock/include)
include_directories(include)

# add_executable(UnitTest main.cpp genChainsAllTest.cpp genChainWordTest.cpp genChainCharTest.cpp include/test.h)
# target_link_libraries(UnitTest gtest gtest_main)
# target_link_libraries(UnitTest gmock gmock_main)
# target_link_libraries(UnitTest core)

add_subdirectory(gtest)
include_directories(../core/include)
add_executable(UnitTest main.cpp genChainsAllTest.cpp genChainWordTest.cpp genChainCharTest.cpp include/test.h ../core/Core.cpp ../core/Graph.cpp)
target_link_libraries(UnitTest gtest gtest_main)
target_link_libraries(UnitTest gmock gmock_main)
# (UnitTest PROPERTIES LINK_FLAGS "/PROFILE")

add_compile_options(-fprofile-arcs -ftest-coverage)
