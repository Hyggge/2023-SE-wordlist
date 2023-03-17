cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 14)

project(GUI LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(GUI SHARED
    main.cpp
    widget.cpp
    include/widget.h
    include/Core.h
    include/Constant.h
    widget.ui
  )
else()
  add_executable(GUI
    main.cpp
    widget.cpp
    include/widget.h
    include/Core.h
    include/Constant.h
    widget.ui
  )
endif()
include_directories(include)
#target_link_directories(GUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_directories(GUI PUBLIC ../bin)
target_link_libraries(GUI PRIVATE Qt5::Widgets coreDll)

