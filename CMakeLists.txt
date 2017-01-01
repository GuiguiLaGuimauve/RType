cmake_minimum_required (VERSION 2.8)
project (RType_server)

#Config CMAKE
cmake_policy(SET CMP0015 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_SUPPRESS_REGENERATION true)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

############################################
#                   SFML                   #
############################################

# Detect and add SFML
find_path(SFML_INCLUDE_DIR Config.hpp)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 COMPONENTS system window graphics audio)
if(SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
  message("SFML found")
  include_directories(${SFML_INCLUDE_DIR})
else(SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
  message(WARNING "SFML not found, you compile the client")
endif()

############################################
#                  SFML END                #
############################################

find_package(Threads)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-pthread")

# Include common
include_directories(common/include/packet)
include_directories(common/include/core)
include_directories(common/include/game)
include_directories(common/include/network)
include_directories(common/include/data)
IF (WIN32)
include_directories(common/include/network/windows)
ELSE ()
include_directories(common/include/network/unix)
ENDIF (WIN32)
include_directories(common/include/data)
include_directories(common/include/packet_tools)
include_directories(common/include/tools)
include_directories(common/include/tools/dlloader)
include_directories(common/include/elements_tools)
include_directories(common/include/elements)

include_directories(client/include/packet)
include_directories(client/include/error)
include_directories(client/include/core)
include_directories(client/include/GUI)
include_directories(client/include/GUI/Audio)
include_directories(client/include/Event)

include_directories(server/include/packet)
include_directories(server/include/error)
include_directories(server/include/core)
include_directories(server/include/game)

# Files Common
FILE (GLOB COMMONDATA "common/src/data/*.cpp")
FILE (GLOB COMMONCORE "common/src/core/*.cpp")
FILE (GLOB COMMONPACKET "common/src/packet/*.cpp")
FILE (GLOB COMMONPACKETT "common/src/packet_tools/*.cpp")
FILE (GLOB COMMONTOOLS "common/src/tools/*.cpp")
FILE (GLOB COMMONDLLOADER "common/src/tools/dlloader/*.cpp")
FILE (GLOB COMMONELEMENTS "common/src/elements/*.cpp")
FILE (GLOB COMMONELEMENTSTOOLS "common/src/elements_tools/*.cpp")
FILE (GLOB COMMONNETWORK "common/src/network/*.cpp")
FILE (GLOB COMMONNETWORKUNIX "common/src/network/unix/*.cpp")
FILE (GLOB COMMONNETWORKWIN "common/src/network/windows/*.cpp")

# Files Server
FILE (GLOB_RECURSE server_src "server/src/*.cpp")

# Files Client
FILE (GLOB_RECURSE client_src "client/src/*.cpp")

# Flags Unix
IF (UNIX)
	add_definitions(-W -Wall -Wextra -Wshadow)
	add_definitions(-g)
ENDIF (UNIX)

# Enable C++ 11
add_definitions(-std=c++11)


# add_executable for WIN32
IF (WIN32)
  add_executable(RType_server assets/rc/server.rc ${COMMONDATA} ${COMMONCORE} ${COMMONPACKET} ${COMMONPACKETT} ${COMMONTOOLS} ${COMMONDLLOADER} ${COMMONELEMENTS} ${COMMONELEMENTSTOOLS} ${COMMONNETWORK} ${COMMONNETWORKWIN} ${server_src})
  IF (SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
  add_executable(RType assets/rc/client.rc ${COMMONDATA} ${COMMONCORE} ${COMMONPACKET} ${COMMONPACKETT} ${COMMONTOOLS} ${COMMONDLLOADER} ${COMMONELEMENTS} ${COMMONELEMENTSTOOLS} ${COMMONNETWORK} ${COMMONNETWORKWIN} ${client_src})
  ENDIF (SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
ENDIF (WIN32)

# add_executable for UNIX
IF (UNIX)
  IF (SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
  add_executable(RType ${COMMONDATA} ${COMMONCORE} ${COMMONPACKET} ${COMMONPACKETT} ${COMMONTOOLS} ${COMMONELEMENTS} ${COMMONELEMENTSTOOLS} ${COMMONNETWORK} ${COMMONNETWORKUNIX} ${client_src})
  ENDIF (SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
add_executable(RType_server ${COMMONDATA} ${COMMONCORE} ${COMMONPACKET} ${COMMONPACKETT} ${COMMONTOOLS} ${COMMONELEMENTS} ${COMMONELEMENTSTOOLS} ${COMMONNETWORK} ${COMMONNETWORKUNIX} ${server_src})
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
  IF (UNIX)
  target_link_libraries(RType_server ${CMAKE_DL_LIBS})
  ENDIF (UNIX)
  target_link_libraries(RType_server ${CMAKE_THREAD_LIBS_INIT})
  IF (SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")
    target_link_libraries(RType ${CMAKE_THREAD_LIBS_INIT})
    target_link_libraries(RType ${SFML_LIBRARIES})
    IF (UNIX)
      target_link_libraries(RType ${CMAKE_DL_LIBS})
    ENDIF (UNIX)
  ENDIF (SFML_FOUND AND ${SFML_VERSION_P} EQUAL "2")


# Make dynamic library
FILE (GLOB ADATA "common/src/data/AData.cpp")
set (CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ennemies_lib/)
set(CMAKE_BUILD_TYPE Release)
#set(EXECUTABLE_OUTPUT_PATH )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB alien_src ${CMAKE_CURRENT_SOURCE_DIR}src/Bydos.cpp)
file(GLOB alf_src ${CMAKE_CURRENT_SOURCE_DIR}src/Alf.cpp)
add_definitions(-std=c++11)

IF (UNIX)
add_library(Bydos SHARED ${COMMONDATA} ${alien_src})
add_library(Alf SHARED ${COMMONDATA} ${alf_src})
ELSEIF (WIN32)
add_library(Bydos SHARED ${COMMONDATA} ${alien_src})
add_library(Alf SHARED ${COMMONDATA} ${alf_src})
ENDIF ()
