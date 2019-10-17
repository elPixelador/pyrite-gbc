set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/olcPixelGameEngine.h)
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/entry.cpp)

add_executable(pyrite-ui ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(pyrite-ui LINK_PUBLIC pyrite-core user32 gdi32 opengl32 gdiplus)
target_include_directories(pyrite-ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../pyrite-core/src)