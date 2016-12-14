cmake_minimum_required (VERSION 3.0)
project (NetworkRtype)

#Config CMAKE
set(CMAKE_AUTOMOC ON)

cmake_policy(SET CMP0015 NEW)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_SUPPRESS_REGENERATION true)


file(GLOB SRCCLI "src/client/*.cpp")
file(GLOB SRCSERV "src/server/*.cpp")
file(GLOB SRCNET "src/network/*.cpp")
file(GLOB SRCERR "src/error/*.cpp")
file(GLOB SRCNETUNIX "src/network/unix/*.cpp")
file(GLOB SRCNETWIN "src/network/windows/*.cpp")

include_directories(includes/network/)
include_directories(includes/error/)

IF (UNIX)

	add_definitions(-W -Wall -Wextra -Wshadow)

ENDIF (UNIX)

IF (WIN32)
	include_directories(includes/network/windows/)
	add_executable (rtype_server ${SRCSERV} ${SRCNET} ${SRCNETWIN})
	add_executable (rtype_client ${SRCCLI} ${SRCNET} ${SRCNETWIN})
ENDIF (WIN32)

IF (UNIX)
	include_directories(includes/network/unix)
	add_executable (rtype_server ${SRCSERV} ${SRCNET} ${SRCNETUNIX})
	add_executable (rtype_client ${SRCCLI} ${SRCNET} ${SRCNETUNIX})
ENDIF (UNIX)
