cmake_minimum_required(VERSION 2.6)
project(meta)
include(${CMAKE_SOURCE_DIR}/cmake/settings.cmake)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
enable_testing()
include(CTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR})

foreach (test
	meta01
	equals01	equals02	equals03
	isconvertible01 isconvertible02 isconvertible03
	isconvertible04 isconvertible05 isconvertible06
	isderivedfrom01 isderivedfrom02 isderivedfrom03
	isderivedfrom04 isderivedfrom05
	find01		find02
	first_equals01
	if01	if02	if03	if04
	ifc01	ifc02	ifc03	ifc04
	kpm01
	removeconstvolatile01
	)
	add_executable(test_${test} tests/${test}.cpp)
	add_test(test_${test} ${EXECUTABLE_OUTPUT_PATH}/test_${test})
endforeach(test)
endif()

