cmake_minimum_required(VERSION 3.17)

project(blackjack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# QTDIR = D:\path\to\Qt\6.4.2\msvc2019_64
# PATH = ${PATH};${QTDIR}\lib;${QTDIR}\bin
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
qt_standard_project_setup()

set(RESOURCES_DIR "${CMAKE_SOURCE_DIR}/resources")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

include_directories(${RESOURCES_DIR})
include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

file(GLOB_RECURSE PROJECT_SOURCES
    "${RESOURCES_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

if(WIN32 AND ${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_executable(blackjack WIN32 ${PROJECT_SOURCES})
else()
    add_executable(blackjack ${PROJECT_SOURCES})
endif()

target_include_directories(blackjack PRIVATE ${RESOURCES_DIR})
target_include_directories(blackjack PRIVATE ${SOURCE_DIR})
target_include_directories(blackjack PRIVATE ${INCLUDE_DIR})

target_link_libraries(blackjack PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
