
set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/minunit.h)
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test.cpp)

add_executable(pyrite-tests ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(pyrite-tests LINK_PUBLIC pyrite-core)
target_include_directories(pyrite-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../pyrite-core/src)