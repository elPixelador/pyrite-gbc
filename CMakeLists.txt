cmake_minimum_required (VERSION 3.14)
project(Pyrite)

add_subdirectory(pyrite-ui)
add_subdirectory(pyrite-core)
add_subdirectory(pyrite-tests)

set_property(
	TARGET 
	pyrite-ui 
	PROPERTY 
	VS_DEBUGGER_WORKING_DIRECTORY 
	"${CMAKE_SOURCE_DIR}/resources"
)