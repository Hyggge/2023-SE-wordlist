cmake_minimum_required (VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(core)
add_subdirectory(lib)

add_executable(Wordlist main.cpp)

target_link_libraries(Wordlist core lib)

# target_link_libraries(Wordlist core)