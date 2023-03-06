cmake_minimum_required (VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory ("core")

add_executable (wordlist main.cpp)

# target_link_libraries(Wordlist core)