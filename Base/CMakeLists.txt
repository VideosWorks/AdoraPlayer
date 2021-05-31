

cmake_minimum_required(VERSION 3.14)
project(Base C CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(Base_SOURCES
    
   )

set(Base_HEADERS
    Namespace.h
    )

add_library(Base
    ${Base_SOURCES}
    ${Base_HEADERS}
    )

target_include_directories(Base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Base Qt5::Core)