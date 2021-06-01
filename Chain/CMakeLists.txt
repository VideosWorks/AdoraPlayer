

cmake_minimum_required(VERSION 3.14)
project(Chain C CXX)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(Chain_SOURCES
    Chain.cpp
    Request.cpp
    RequestStrategy.cpp
    RequestStrategyFactory.cpp
   )

set(Chain_HEADERS
     Chain.h
     Request.h
     RequestStrategy.h
     RequestStrategyFactory.h
    )

add_library(Chain
    ${Chain_SOURCES}
    ${Chain_HEADERS}
    )

target_include_directories(Chain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Chain Qt5::Core Qt5::Widgets)
