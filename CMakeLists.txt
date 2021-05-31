

cmake_minimum_required(VERSION 3.14)
project(AdoraPlayer C CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(WIN32)
set (CMAKE_PREFIX_PATH "C:/Qt1/5.15.2/msvc2019_64/lib/cmake/Qt5" )
endif()

find_package(Qt5 COMPONENTS Gui Core Widgets REQUIRED)

add_subdirectory(Ui)

list(APPEND SOURCES
    main.cpp
    )


    
    
if(WIN32)
#set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/Resources/Resources-win/Raina.rc")
add_executable(AdoraPlayer WIN32 ${SOURCES})  #${APP_ICON_RESOURCE_WINDOWS} )


elseif(APPLE)
#set(MACOSX_BUNDLE_ICON_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Resources/Resources-mac/logo.icns)
#set(APP_ICON_MACOSX ${CMAKE_CURRENT_SOURCE_DIR}/Resources/Resources-mac/logo.icns)
#    set_source_files_properties(${APP_ICON_MACOSX} PROPERTIES
#           MACOSX_PACKAGE_LOCATION "Resources")
#add_executableAdoraPlayer MACOSX_BUNDLE ${SOURCES} ${APP_ICON_MACOSX})
add_executable(AdoraPlayer ${SOURCES})
else()


endif()

target_link_libraries(AdoraPlayer Ui Qt5::Gui Qt5::Core Qt5::Widgets  )

