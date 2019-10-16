set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(
    HEADER_FILES
    ${SRC_DIR}/cpu.h 
    ${SRC_DIR}/memory.h
)

set(
    SOURCE_FILES 
    ${SRC_DIR}/entry.c 
    ${SRC_DIR}/cpu.c 
    ${SRC_DIR}/memory.c
)

add_library(pyrite-core STATIC ${HEADER_FILES} ${SOURCE_FILES})