cmake_minimum_required (VERSION 2.8)
project (RType)

#Config CMAKE
set(CMAKE_AUTOMOC ON)

cmake_policy(SET CMP0015 NEW)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

############################################
#                   SFML                   #
############################################

# Detect and add SFML
find_path(SFML_INCLUDE_DIR Config.hpp)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 COMPONENTS system window graphics audio)
if(SFML_FOUND)
  message("SFML found")
  include_directories(${SFML_INCLUDE_DIR})
else(SFML_FOUND)
  message(WARNING "SFML not found, you can't run the client")
endif()

############################################
#                  SFML END                #
############################################

find_package(Threads)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")

# Include common
include_directories(common/include/packet)
include_directories(common/include/packet_data)
include_directories(common/include/packet_tools)
include_directories(common/include/tools)

# Files Common
FILE (GLOB_RECURSE common_src "common/src/*.cpp")

# Files Server
FILE (GLOB_RECURSE server_src "server/src/*.cpp")

# Files Client
FILE (GLOB_RECURSE client_src "client/src/*.cpp")

# Flags Unix
IF (UNIX)
	add_definitions(-W -Wall -Wextra -Wshadow)
ENDIF (UNIX)

# Enable C++ 11
add_definitions(-std=c++11)

# add_executable for WIN32
IF (WIN32)
add_executable(RType_server WIN32 ${common_src} ${server_src})
  IF (SFML_FOUND)
  add_executable(RType WIN32 ${common_src} ${client_src})
  ENDIF (SFML_FOUND)
ENDIF (WIN32)

# add_executable for UNIX
IF (UNIX)
add_executable(RType_server ${common_src} ${server_src})
add_executable(RType ${common_src} ${client_src})
ENDIF (UNIX)

# Set lib on Unix
IF (UNIX)
ENDIF (UNIX)

# Set lib on Windows
IF (WIN32)
ENDIF (WIN32)

# Build
IF (UNIX)
	link_directories(./build /usr/local/lib/)
ENDIF (UNIX)

IF (WIN32)
	link_directories(./lib C:/Windows/System32)
ENDIF (WIN32)

# Link librairies
  target_link_libraries(RType_server ${CMAKE_THREAD_LIBS_INIT})
  #target_link_libraries(RType ${SFML_LIBRARIES})
