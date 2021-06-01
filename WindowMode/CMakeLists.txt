

cmake_minimum_required(VERSION 3.14)
project(WindowMode C CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(WindowMode_SOURCES
    WindowMode.cpp
    RestoredMode.cpp
    FullScreenMode.cpp
    MaximizedMode.cpp
    WindowModeFactory.cpp
   )

set(WindowMode_HEADERS
    WindowMode.h
    RestoredMode.h
    FullScreenMode.h
    MaximizedMode.h
    WindowModeFactory.h
    )

add_library(WindowMode
    ${Base_SOURCES}
    ${Base_HEADERS}
    )

target_include_directories(WindowMode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(WindowMode Qt5::Core)