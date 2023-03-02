cmake_minimum_required(VERSION 3.5)

project(blackjack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")
set(FORMS_DIR "${RESOURCES_DIR}/forms")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${RESOURCES_DIR})
include_directories(${FORMS_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES
    "${RESOURCES_DIR}/*.qrc"
    "${FORMS_DIR}/*.ui"
    "${SOURCE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR} ${RESOURCES_DIR})

if(ANDROID)
    add_library(blackjack SHARED ${PROJECT_SOURCES} )
elseif(WIN32)
    #add_executable(blackjack WIN32 ${PROJECT_SOURCES} )
    add_executable(blackjack ${PROJECT_SOURCES} )
else()
    add_executable(blackjack ${PROJECT_SOURCES} )
endif()

target_include_directories(blackjack PRIVATE ${RESOURCES_DIR})
target_include_directories(blackjack PRIVATE ${FORMS_DIR})
target_include_directories(blackjack PRIVATE ${SOURCE_DIR})

target_link_libraries(blackjack PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)
