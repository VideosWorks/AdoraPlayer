

cmake_minimum_required(VERSION 3.14)
project(NotifyEvent C CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(NotifyEvent_SOURCES
    NotifyEvent.cpp
    Observer.cpp
   )

set(NotifyEvent_HEADERS
     NotifyEvent.h
     Observer.h
    )

add_library(NotifyEvent
    ${NotifyEvent_SOURCES}
    ${NotifyEvent_HEADERS}
    )

target_include_directories(NotifyEvent PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(NotifyEvent Qt5::Core)
