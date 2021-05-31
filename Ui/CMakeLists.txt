

cmake_minimum_required(VERSION 3.14)
project(Ui C CXX)

add_definitions(-DGL_SILENCE_DEPRECATION)

find_package(Qt5 COMPONENTS OpenGL Gui Core Widgets REQUIRED)


if(APPLE)
    list(APPEND EXTRA_LIBS
        "-framework OpenGL"
    )

elseif(WIN32)
    list(APPEND EXTRA_LIBS
        "-lglu32 -lopengl32"
    )
    set(CMAKE_EXE_LINKER_FLAGS "-std=gnu99 -static -static-libgcc -static-libstdc++ -mwindows")

else()
    list(APPEND EXTRA_LIBS
         "lGL -lGLU lX11"
    )

endif()

set(Ui_SOURCES
    MainWindow.cpp
    FrameWidget.cpp
   )

set(Ui_HEADERS
    MainWindow.h
    FrameWidget.h
    )

set(Ui_UI
    MainWindow.ui
    )

add_library(Ui
    ${Ui_SOURCES}
    ${Ui_HEADERS}
    ${Ui_UI}
    )


target_include_directories(Ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Ui Qt5::OpenGL Qt5::Gui Qt5::Core Qt5::Widgets ${EXTRA_LIBS})
