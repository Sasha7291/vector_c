cmake_minimum_required(VERSION 3.5)

project(vector LANGUAGES C)

file(GLOB HEADERS *.h)
file(GLOB SOURCES main.c)

add_executable(vector ${SOURCES} ${HEADERS})

include(GNUInstallDirs)
install(TARGETS vector
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
