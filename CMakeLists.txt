PROJECT(esa-vnc-server)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FILE(GLOB SOURCES src/*.c)
ADD_EXECUTABLE(esa-vnc-server ${SOURCES})
INSTALL(TARGETS esa-vnc-server RUNTIME DESTINATION bin)

# LIBVNC
find_library(LIBVNC NAMES libvncserver vncserver)
target_link_libraries(esa-vnc-server ${LIBVNC})


MESSAGE( STATUS "LIBVNC:         " ${LIBVNC} )
