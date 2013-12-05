cmake_minimum_required(VERSION 2.6)
project(meta)

enable_testing()
include(Dart)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR})

foreach (test
	meta01
	equals01	equals02	equals03
	find01		find02
	first_equals01
	if01	if02	if03	if04
	ifc01	ifc02	ifc03	ifc04
	isnone01
	)
	add_executable(test_${test} tests/${test}.cpp)
	add_test(test_${test} ${EXECUTABLE_OUTPUT_PATH}/test_${test})
endforeach(test)

# add a target to generate API documentation with Doxygen
#find_package(Doxygen)
#if(DOXYGEN_FOUND)
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
#add_custom_target(doc
#	${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#	COMMENT "Generating API documentation with Doxygen" VERBATIM
#	)
#endif(DOXYGEN_FOUND)
