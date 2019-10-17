set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(
    HEADER_FILES
    ${SRC_DIR}/z80.h 
    ${SRC_DIR}/memory.h
)

set(
    SOURCE_FILES 
    ${SRC_DIR}/z80.cpp
    ${SRC_DIR}/memory.cpp
)

add_library(pyrite-core STATIC ${HEADER_FILES} ${SOURCE_FILES})