cmake_minimum_required(VERSION 2.8)

project (LIB)
set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ../)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB lib_src "src/AElement.cpp" "src/Ennemy.cpp")
file(GLOB alien_src "src/Alien.cpp")
file(GLOB alf_src "src/Alf.cpp")
add_definitions(-std=c++11)

IF (UNIX)
add_library(Alien SHARED ${lib_src} ${alien_src})
add_library(Alf SHARED ${lib_src} ${alf_src})
ELSEIF (WIN32)
add_library(Alien SHARED ${lib_src} ${alien_src})
add_library(Alf SHARED ${lib_src} ${alf_src})
ENDIF ()
